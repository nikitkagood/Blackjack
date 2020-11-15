#include <iostream>
#include <stdexcept>
#include <map>
#include <vector>
#include <sstream>
#include <chrono> //может не работать в gcc или на unix

#define DEBUG

#include "Blackjack.h"
#include "IPlayer.h"
#include "Dealer.h"
#include "AI_Player.h"

using namespace std;


int main()
{
    srand(time(nullptr)); //генератор рандома для вытаскивания карт

    

    try
    {
        //Создаем игру и устанавливаем правила
        Blackjack bj;
        bj.SetRules(17, 100);

        //Создаем игрока или игроков
        IPlayer player1(bj);
        bj.AddPlayer(player1); //добавляем игрока в вектор игроков
        

        while (true) //игровой цикл
        {
            //Создаем дилера
            //Здесь чтобы обнулить все его поля в следующем раунде
            Dealer dealer;

            //Раунд начался
            //Ставки. Игроки не могут не ставить
            for (size_t player_number = 1; player_number <= bj.GetNumberOfPlayers(); player_number++)
            {
                unsigned int bet = 0;
                while (bet <= 0)
                {
                    bet = bj.players[player_number].bet();
                }

                dealer.players_current_bets.insert({ player_number, bet });
            }
            

            //Первая раздача
            //Дилер раздает игрокам
            for (size_t player_number = 1; player_number <= bj.GetNumberOfPlayers(); player_number++)
            {
                for (size_t i = 0; i < 2; i++) //2 - количество стартовых карт
                {
                    dealer.GiveCard(bj.players[player_number]);
                }
                
            }
            //Показываем карты игроков
            for (size_t player_number = 1; player_number <= bj.GetNumberOfPlayers(); player_number++)
            {
                bj.players[player_number].ShowCards();
            }
            

            for (size_t i = 0; i < 2; i++) //2 - количество стартовых карт
            {
                dealer.GiveCard(dealer);
            }
            dealer.ShowOneCard();

            //Проверка что уже не 21, решения игроков
            for (size_t player_number = 1; player_number <= bj.GetNumberOfPlayers(); player_number++)
            {
                unsigned int score = dealer.CountScore(bj.players[player_number]); //Считаем стоимость первых двух карт

                if (score < 21)
                {
                    //Решение игрока
                    IPlayer& current_player = bj.players[player_number];

                    current_player.ShowGameDecisions(); //Показываем возможные решения

                    while (true)
                    {
                        string decision = current_player.MakeGameDecision(dealer, current_player);

                        score = dealer.CountScore(bj.players[player_number]);
                        
                        cout << "Debug: Player1 score is: " << score << endl;

                        if (decision == "Stand" || decision == "stand" || decision == "3" || score >= 21)
                        {
                            break;
                        }

                    }

                    dealer.players_scores.insert({ player_number, score });

                }
                else if (score == 21)
                {
                    //21 с первых двух кард - это 1.5x выигрыш
                    //Точно победа, но нужно проверить других игроков
                    cout << "Blackjack!" << endl;
                    dealer.players_scores.insert({ player_number, score });

                }
                else throw runtime_error("Could not handle the score value!");

            }

            if (true)
            for (size_t player_number = 1; player_number <= bj.GetNumberOfPlayers(); player_number++)
            {
                dealer.CheckScores();

            }
            else
            for (size_t i = 0; i < 2; i++) //Дилер берет 2 карты себе. Только если все игроки еще не проиграли
            {
                dealer.GiveCard(dealer);
            }

            unsigned int score = dealer.CountScore(dealer);
            while (score < bj.GetDealerStopsOn())
            {
                dealer.GiveCard(dealer);

                score = dealer.CountScore(dealer);
            }

            dealer.players_scores.insert({ 0, score });

            //Подсчет очков всех игроков, определение победителя, выдача выигрыша
            

            //Раунд закончился
            bj.UpdateNumberOfPlayers();
            bj.CountRound();
        }
        return -99;

    }
    catch (const runtime_error& re)
    {
        cerr << re.what() << endl;
    }


    return 0;
}
