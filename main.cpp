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
        IPlayer player1;
        bj.AddPlayer(player1); //��������� ������ � ������ �������
        

        while (true) //������� ����
        {

            //����� �������
            //������
            player1.bet(20);

            //������ �������
            //����� ������� �������
            for (size_t player_number = 1; player_number <= bj.GetNumberOfPlayers(); player_number++)
            {
                
                for (size_t i = 0; i < 2; i++) //2 - ���������� ��������� ����
                {
                    dealer.GiveCard(player1);
                }
                
            }
            player1.ShowCards();

            for (size_t i = 0; i < 2; i++) //2 - ���������� ��������� ����
            {
                dealer.GiveCard(dealer);
            }

            //TODO: ���������, �� 21 ��

            //for (size_t player_number = 1; player_number <= bj.GetNumberOfPlayers(); player_number++) //������� �������, ���� �� ���������           

            //������. ������ �� ����� �� �������
            

            //������� ������
            player1.ShowGameDecisions();
            
            player1.MakeGameDecision(dealer);
            //cin >> player1.game_decision;
            //player1.GameDecision(player1.game_decision);

            
            //������� �����, ����������� ����������


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
