#include <iostream>
#include <stdexcept>
#include <map>
#include <vector>
#include <sstream>
#include <chrono> //может не работать в gcc или на unix

#include "Blackjack.h"
#include "IPlayer.h"
#include "Dealer.h"
#include "AI_Player.h"

using namespace std;

//TODO
//Страховка (когда у дилера открыт туз)
//Протестировать тузы
//Сделать перемешку колоды: 4 колоды. Мешаются когда 
//Декомпозировать побольше, меньше вызывать IPlayer извне
//Пофиксить баг, который происходит после Scores before check (вроде пофикшено)
//Бот
//Сеть если будет время (TCP, или boost::asio)

int main()
{
    setlocale(0, "");
    srand(time(nullptr)); //генератор рандома для вытаскивания карт

    try
    {
        //Создаем игру и устанавливаем правила
        Blackjack bj;
        bj.SetRules(17, 100);

        //Создаем дилера
        Dealer dealer(bj);

        //Создаем игрока или игроков
        IPlayer player1(bj, "Никита");
        IPlayer player2(bj);
        //добавляем игрока в вектор игроков
        
        

        while (true) //игровой цикл
        {
            bj.UpdateNumberOfPlayers(); //также проверяет есть ли игроки в игре
            bj.CountRound();
            bj.ShowRoundNumber();

            //Показать игроков
            bj.ShowPlayers();

            //Раунд начался
            //Ставки. Игроки не могут не ставить
            for (size_t player_number = 1; player_number < bj.GetNumberOfPlayers(); player_number++)
            {
                unsigned int bet = 0;
                while (bet <= 0)
                {
                    bet = bj.players[player_number].bet();
                }

                dealer.players_current_bets.insert({ player_number, bet });
            }
            
 /*           for_each(bj.players.begin() + 1, bj.players.end(), [](IPlayer& player)
                {
                    dealer.players_current_bets.insert({ player_number, player.bet() });
                });*/

            //Первая раздача
            //Дилер раздает игрокам
            for (size_t player_number = 1; player_number < bj.GetNumberOfPlayers(); player_number++)
            {
                for (size_t i = 0; i < 2; i++) //2 - количество стартовых карт
                {
                    dealer.GiveCard(bj.players[player_number]);
                }
                
            }
            //Показываем карты игроков
            for (size_t player_number = 1; player_number < bj.GetNumberOfPlayers(); player_number++)
            {
                bj.players[player_number].ShowCards();
            }
            
            //Дилер дает себе
            for (size_t i = 0; i < 2; i++) //2 - количество стартовых карт
            {
                dealer.GiveCard(dealer);
            }
            dealer.ShowOneCard();

            //Проверка что уже не 21, решения игроков
            for (size_t player_number = 1; player_number < bj.GetNumberOfPlayers(); player_number++)
            {
                unsigned int score = dealer.CountScore(bj.players[player_number]);

                if (score < 21)
                {
                    //Решение игрока

                    IPlayer& current_player = bj.players[player_number];

                    //while (true)
                    //{
                        current_player.ShowGameDecisions(); //Показываем возможные решения

                        current_player.MakeGameDecision(dealer, current_player, player_number);

                        score = dealer.CountScore(current_player);
                        

                        //if (decision == "Stand" || decision == "stand" || decision == "3" || score >= 21) break;
                        //if (decision == "Double" || decision == "dobule" || decision == "2")
                        //{
                        //    dealer.GiveCard(current_player);
                        //    score = dealer.CountScore(current_player);
                        //    //break;
                        //}
                    //}

                    dealer.players_scores.insert({ player_number, score });

                }
                else if (score == 21)
                {
                    //21 с первых двух кард - это 1.5x выигрыш
                    //Точно победа, но нужно проверить других игроков
                    cout << "Blackjack!" << endl;
                    dealer.players_blackjack.insert({ player_number, true });
                    dealer.players_scores.insert({ player_number, score });

                }
                else throw runtime_error("Could not handle the score value!");

            }

            unsigned int d_score = dealer.CountScore(dealer);
            while (d_score <= bj.GetDealerStopsOn())
            {
                dealer.GiveCard(dealer);

                d_score = dealer.CountScore(dealer);
            }
            //TODO: Баг. Иногда дилер показывает слишком много карт и, возможно, неправильно считает очки
            dealer.ShowCards();

            dealer.players_scores.insert({ 0, d_score });

            //Подсчет очков всех игроков, определение победителя, выдача выигрыша
            dealer.CheckScores();
            dealer.GiveWin(bj);

            //Если банк = 0, то выход из игры
            for (size_t player_number = 1; player_number < bj.GetNumberOfPlayers(); player_number++)
            {
                if (bj.players[player_number].GetBank() == 0)
                {
                    cout << bj.players[player_number].GetName() << " has 0 chips and leaves the game" << endl;
                    bj.ErasePlayer(player_number);
                }
            }
            

            //Раунд закончился
            bj.ResetRound(dealer);
        }

        throw runtime_error("Unexpected main loop exit");

    }
    catch (const runtime_error& re)
    {
        cerr << re.what() << endl;
    }


    return 0;
}
