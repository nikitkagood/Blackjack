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
        Blackjack bj;
        bj.SetRules(17, 100);

        Dealer dealer;

        //vector<HumanPlayer>
        IPlayer player1;

        while (true)
        {
            for (size_t player_number = 1; player_number <= bj.GetNumberOfPlayers(); player_number++)
            {
                for (size_t i = 0; i < 2; i++) //2 - количество стартовых карт
                {
                    //dealer.GiveCard();
                    player1.
                }
                
            }
            

           

            break;
        }
        return -99;


    }
    catch (const runtime_error& re)
    {
        cerr << re.what() << endl;
    }


    return 0;
}
