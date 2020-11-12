#include <iostream>
#include <stdexcept>
#include <map>
#include <vector>
#include <sstream>
#include <chrono> //����� �� �������� � gcc ��� �� unix

#define DEBUG

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

        //������� ������
        Dealer dealer;

        //������� ������ ��� �������
        IPlayer player1(bj);
        bj.AddPlayer(player1); //��������� ������ � ������ �������
        

        while (true) //������� ����
        {
            //����� �������
            //������. ������ �� ����� �� �������
            while (player1.bet() <= 0){} //�������� �� ������������� ������ ���� ��� ������� ����

            //������ �������
            //����� ������� �������
            for (size_t player_number = 1; player_number <= bj.GetNumberOfPlayers(); player_number++)
            {
                for (size_t i = 0; i < 2; i++) //2 - ���������� ��������� ����
                {
                    dealer.GiveCard(bj.players[player_number]);
                }
                
            }

            for (size_t player_number = 1; player_number <= bj.GetNumberOfPlayers(); player_number++)
            {
                bj.players[player_number].ShowCards();
            }
            

            for (size_t i = 0; i < 2; i++) //2 - ���������� ��������� ����
            {
                dealer.GiveCard(dealer);
            }
            dealer.ShowOneCard();

            //�������� ��� �� 21. ���� �� - ����� �� ����� ������� �������
            for (size_t player_number = 1; player_number <= bj.GetNumberOfPlayers(); player_number++)
            {
                unsigned int score = dealer.CountScore(bj.players[player_number]);
                if (score < 21)
                {
                    //������� ������
                    bj.players[player_number].ShowGameDecisions();

                    bj.players[player_number].MakeGameDecision(dealer);

                }
                else if (score == 21)
                {
                    //21 � ������ ���� ���� - ��� 1.5x �������
                    //����� ������, �� ����� ��������� ������ �������
                }
                else if (score > 21)
                {
                    //��������
                }
                else throw runtime_error("Could not handle the score value!");
            }
            //������� ����� ���� �������, ����������� ����������


            //����� ����������
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
