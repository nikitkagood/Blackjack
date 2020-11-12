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
    srand(time(nullptr)); //генератор рандома дл€ вытаскивани€ карт

    

    try
    {
        //—оздаем игру и устанавливаем правила
        Blackjack bj;
        bj.SetRules(17, 100);

        //—оздаем дилера
        Dealer dealer;

        //—оздаем игрока или игроков
        IPlayer player1(bj);
        bj.AddPlayer(player1); //добавл€ем игрока в вектор игроков
        

        while (true) //игровой цикл
        {
            //–аунд началс€
            //—тавки. »гроки не могут не ставить
            while (player1.bet() <= 0){} //контроль за правильностью ставок пока что вынесен сюда

            //ѕерва€ раздача
            //ƒилер раздает игрокам
            for (size_t player_number = 1; player_number <= bj.GetNumberOfPlayers(); player_number++)
            {
                for (size_t i = 0; i < 2; i++) //2 - количество стартовых карт
                {
                    dealer.GiveCard(bj.players[player_number]);
                }
                
            }

            for (size_t player_number = 1; player_number <= bj.GetNumberOfPlayers(); player_number++)
            {
                bj.players[player_number].ShowCards();
            }
            

            for (size_t i = 0; i < 2; i++) //2 - количество стартовых карт
            {
                dealer.GiveCard(dealer);
            }
            dealer.ShowOneCard();

            //ѕроверка что не 21. ≈сли да - игрок не может сделать решение
            for (size_t player_number = 1; player_number <= bj.GetNumberOfPlayers(); player_number++)
            {
                unsigned int score = dealer.CountScore(bj.players[player_number]);
                if (score < 21)
                {
                    //–ешение игрока
                    bj.players[player_number].ShowGameDecisions();

                    bj.players[player_number].MakeGameDecision(dealer);

                }
                else if (score == 21)
                {
                    //21 с первых двух кард - это 1.5x выигрыш
                    //“очно победа, но нужно проверить других игроков
                }
                else if (score > 21)
                {
                    //ѕроигрыш
                }
                else throw runtime_error("Could not handle the score value!");
            }
            //ѕодсчет очков всех игроков, определение победител€


            //–аунд закончилс€
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
