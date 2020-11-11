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

        //Создаем дилера
        Dealer dealer;

        //Создаем игрока или игроков
        IPlayer player1;
        bj.AddPlayer(player1); //добавляем игрока в вектор игроков
        

        while (true) //игровой цикл
        {

            //Раунд начался
            //Ставки
            player1.bet(20);

            //Первая раздача
            //Дилер раздает игрокам
            for (size_t player_number = 1; player_number <= bj.GetNumberOfPlayers(); player_number++)
            {
                
                for (size_t i = 0; i < 2; i++) //2 - количество стартовых карт
                {
                    dealer.GiveCard(player1);
                }
                
            }
            player1.ShowCards();

            for (size_t i = 0; i < 2; i++) //2 - количество стартовых карт
            {
                dealer.GiveCard(dealer);
            }

            //TODO: Проверить, не 21 ли

            //for (size_t player_number = 1; player_number <= bj.GetNumberOfPlayers(); player_number++) //перебор игроков, если их несколько           

            //Ставки. Игроки не могут не ставить
            

            //Решение игрока
            player1.ShowGameDecisions();
            
            player1.MakeGameDecision(dealer);
            //cin >> player1.game_decision;
            //player1.GameDecision(player1.game_decision);

            
            //Подсчет очков, определение победителя


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
