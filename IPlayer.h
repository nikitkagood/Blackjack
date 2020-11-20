#pragma once

//#include <vector>

#include "Blackjack.h"

using namespace std;



class IPlayer
{
public:
    IPlayer();

    IPlayer(Blackjack& bj);

    IPlayer(Blackjack& bj, const string& name);

    //IPlayer(const IPlayer& other); //����������� �����������

    //~IPlayer();

    //IPlayer& operator = (const IPlayer& player) = delete;
    IPlayer& operator = (const IPlayer& player);

    unsigned int bet();

    void bet_double(Dealer d, unsigned int player_number);

    void MakeGameDecision(Dealer& d, IPlayer& player_himself, const unsigned int& player_number);

    void JoinGame();

    void ReceiveCard(const pair<string, string>& to_receive);

    void ShowCards() const;

    void ShowGameDecisions() const;

    void LeaveGame(Blackjack bj); //������� �� ���������� �������
        
    const vector<pair<string, string>> GetHand() const;
    vector<pair<string, string>>& GetHandLink();

    const string GetName() const;

    const unsigned int GetBank() const;

    void ChangeBank(const int& ammount);

//#ifdef DEBUG
//    ~IPlayer()
//    {
//        cout << "IPlayer destructor" << endl;
//    }
//#endif // DEBUG

protected:
    //������������ � IPlayer, � Dealer
    vector<pair<string, string>> hand; //������� �����, ����� �����
    unsigned int score = 0;

    string SetName(string name);
    string name;

    
private:


    //unsigned int player_number = 1; //����� ������, ����� ��� ������� 0 ��� �����
    unsigned int bank = 0; //���-�� �����
    //unsigned int current_bet = 0; //������� ��� ����������

    const map<int, string> game_decisions{ {1, "Hit"}, {2, "Double"}, {3, "Stand"} };

};

