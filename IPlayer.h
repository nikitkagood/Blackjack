#pragma once

//#include <vector>

#include "Blackjack.h"

using namespace std;



class IPlayer
{
public:
    IPlayer();

    IPlayer(Blackjack& bj);

    IPlayer(Blackjack& bj, string name);

    unsigned int bet();

    void bet_double();

    string MakeGameDecision(Dealer& d, IPlayer& player_himself);

    void JoinGame();

    void ReceiveCard(const pair<string, string>& to_receive);

    void ShowCards() const;

    void ShowGameDecisions() const;

    //void loseGame(Blackjack bj);

    void LeaveGame(Blackjack bj); //удалить из контейнера игроков
        
    const vector<pair<string, string>> GetHand() const;

    const string GetName() const;

    const unsigned int GetBank() const;

//#ifdef DEBUG
//    ~IPlayer()
//    {
//        cout << "IPlayer destructor" << endl;
//    }
//#endif // DEBUG

protected:
    //Используется и IPlayer, и Dealer
    vector<pair<string, string>> hand; //сначала карта, потом масть

    string SetName(string name);
    string name;
private:


    //unsigned int player_number = 1; //номер игрока, игрока под номером 0 не может быть
    unsigned int bank = 0; //кол-во фишек
    //unsigned int current_bet = 0; //сколько уже поставлено
    string game_decision;
    const map<int, string> game_decisions{ {1, "Hit"}, {2, "Double"}, {3, "Stand"} };

};

