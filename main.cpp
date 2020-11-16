#include <iostream>
#include <stdexcept>
#include <map>
#include <vector>
#include <sstream>
#include <chrono> //����� �� �������� � gcc ��� �� unix

//#define DEBUG

#include "Blackjack.h"
#include "IPlayer.h"
#include "Dealer.h"
#include "AI_Player.h"

using namespace std;


int main()
{
    srand(time(nullptr)); //��������� ������� ��� ������������ ����

    

    try
    {
        //������� ���� � ������������� �������
        Blackjack bj;
        bj.SetRules(17, 100);


        //������� ������ ��� �������
        IPlayer player1(bj);
        //��������� ������ � ������ �������
        
        //������� ������
        Dealer dealer(bj);

        while (true) //������� ����
        {
            bj.UpdateNumberOfPlayers();
            bj.CountRound();
            bj.ShowRoundNumber();


            //�������� �������
            bj.ShowPlayers();

            //����� �������
            //������. ������ �� ����� �� �������
            for (size_t player_number = 1; player_number < bj.GetNumberOfPlayers(); player_number++)
            {
                unsigned int bet = 0;
                while (bet <= 0)
                {
                    bet = bj.players[player_number].bet();
                }

                dealer.players_current_bets.insert({ player_number, bet });
            }
            

            //������ �������
            //����� ������� �������
            for (size_t player_number = 1; player_number < bj.GetNumberOfPlayers(); player_number++)
            {
                for (size_t i = 0; i < 2; i++) //2 - ���������� ��������� ����
                {
                    dealer.GiveCard(bj.players[player_number]);
                }
                
            }
            //���������� ����� �������
            for (size_t player_number = 1; player_number < bj.GetNumberOfPlayers(); player_number++)
            {
                bj.players[player_number].ShowCards();
            }
            

            for (size_t i = 0; i < 2; i++) //2 - ���������� ��������� ����
            {
                dealer.GiveCard(dealer);
            }
            dealer.ShowOneCard();

            //�������� ��� ��� �� 21, ������� �������
            for (size_t player_number = 1; player_number < bj.GetNumberOfPlayers(); player_number++)
            {
                unsigned int score = dealer.CountScore(bj.players[player_number]); //������� ��������� ������ ���� ����

                if (score < 21)
                {
                    //������� ������
                    IPlayer& current_player = bj.players[player_number];

                    current_player.ShowGameDecisions(); //���������� ��������� �������

                    while (true)
                    {
                        string decision = current_player.MakeGameDecision(dealer, current_player);

                        score = dealer.CountScore(bj.players[player_number]);
                        
                        //cout << "Debug: Player1 score is: " << score << endl;

                        if (decision == "Stand" || decision == "stand" || decision == "3" || score >= 21)
                        {
                            break;
                        }

                    }

                    dealer.players_scores.insert({ player_number, score });

                }
                else if (score == 21)
                {
                    //21 � ������ ���� ���� - ��� 1.5x �������
                    //����� ������, �� ����� ��������� ������ �������
                    cout << "Blackjack!" << endl;
                    dealer.players_scores.insert({ player_number, score });

                }
                else throw runtime_error("Could not handle the score value!");

            }

            if (true)
            for (size_t player_number = 1; player_number < bj.GetNumberOfPlayers(); player_number++)
            {
                dealer.CheckScores();
            }
            else
            for (size_t i = 0; i < 2; i++) //����� ����� 2 ����� ����. ������ ���� ��� ������ ��� �� ���������
            {
                dealer.GiveCard(dealer);
            }

            unsigned int score = dealer.CountScore(dealer);
            while (score < bj.GetDealerStopsOn())
            {
                dealer.GiveCard(dealer);

                score = dealer.CountScore(dealer);
            }

            dealer.ShowCards();

            dealer.players_scores.insert({ 0, score });

            //������� ����� ���� �������, ����������� ����������, ������ ��������
            

            //����� ����������
            bj.ResetRound(dealer);
        }
        return -99;

    }
    catch (const runtime_error& re)
    {
        cerr << re.what() << endl;
    }


    return 0;
}
