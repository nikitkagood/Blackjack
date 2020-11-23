#include <iostream>
#include <stdexcept>
#include <map>
#include <vector>
#include <sstream>
#include <thread>
#include <Windows.h>
#include <chrono> //может не работать в gcc или на unix

#include "Blackjack.h"
#include "IPlayer.h"
#include "Dealer.h"
#include "AI_Player.h"

using namespace std;

//TODO
//Страховка (когда у дилера открыт туз)
//Проверить и возможно переделать выдачу карт. 
//Сейчас: 2 игрокам, 2 дилеру. Игроки играют. Потом дилер добирает. Возможно это не правильно
//Протестировать тузы
//Сделать перемешку колоды: 4 колоды. Мешаются когда 
//Декомпозировать побольше, меньше вызывать IPlayer извне
//Пофиксить баг, который происходит после Scores before check (вроде пофикшено)
//Бот
//Сеть если будет время (TCP, или boost::asio)



int main()
{
    SetConsoleTitle("Blackjack by Nikita Belov");

    setlocale(0, "");
    srand(time(nullptr)); //Setting the seed for rangom generator

    try
    {
        //Creating the game and setting the rules
        Blackjack bj;
        bj.SetRules(17, 100);

        //Сreating dealer (only in this order)
        Dealer dealer(bj);

        //Creating players
        IPlayer player1(bj, "Никита");
        //IPlayer player2(bj);

        while (true) //The game loop
        {
            bj.UpdateNumberOfPlayers();
            bj.CheckNumberOfPlayers();
            bj.CountRound();
            bj.ShowRoundNumber();

            bj.ShowPlayers();

            //Bets. Players can't not to bet
            for (size_t player_number = 1; player_number < bj.GetNumberOfPlayers(); player_number++)
            {
                unsigned int bet = 0;
                while (bet <= 0)
                {
                    bet = bj.players[player_number].bet();
                }

                dealer.players_current_bets.insert({ player_number, bet });
            }


            //Starting dealing the cards
            //Dealer gives cards to players
            for (size_t player_number = 1; player_number < bj.GetNumberOfPlayers(); player_number++)
            {
                for (size_t i = 0; i < 2; i++) //2 - количество стартовых карт
                {
                    dealer.GiveCard(bj.players[player_number]);
                }

            }

            //Showing player's cards
            for (size_t player_number = 1; player_number < bj.GetNumberOfPlayers(); player_number++)
            {
                bj.players[player_number].ShowCards();
            }

            //Dealer gives cards to himself
            for (size_t i = 0; i < 2; i++) //2 - количество стартовых карт
            {
                dealer.GiveCard(dealer);
            }
            dealer.ShowOneCard();


            if (dealer.GetHand()[0].first == "Ace")
            {
                dealer.OfferInsurance();
            }


            //Checking it's not 21 already. Letting players decide what to do
            for (size_t player_number = 1; player_number < bj.GetNumberOfPlayers(); player_number++)
            {
                unsigned int score = dealer.CountScore(bj.players[player_number]);

                if (score < 21)
                {
                    //Player's decision
                    IPlayer& current_player = bj.players[player_number];

                    current_player.ShowGameDecisions();

                    current_player.MakeGameDecision(dealer, current_player, player_number);

                    score = dealer.CountScore(current_player);
                    dealer.players_scores.insert({ player_number, score });

                }
                else if (score == 21)
                {
                    //21 from 2 first cards means 1.5x win
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

            //Counting all the scores
            dealer.CheckScores();
            //Defining winners, giving away wins
            dealer.GiveWin(bj);

            //If bank == 0, player is exits the game
            bj.CheckPlayersBanks();

            //The round has ended. Clearing variables
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
