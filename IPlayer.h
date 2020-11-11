#pragma once

//#include <vector>

#include "Blackjack.h"

#define DEBUG

using namespace std;



class IPlayer
{
public:
    IPlayer();

    IPlayer(string name);

    unsigned int bet(unsigned int ammount);

    void bet_double();

    void Hold(); //переименовать в stand

    void Hit();

    void MakeGameDecision(const Dealer& d);

    //string GameDecision(string decision) const;
    //int GameDecision(int decision) const; //перегруза дл€ int

    void JoinGame();

    void ReceiveCard(const pair<string, string>& to_receive);

    virtual void ShowCards() const;

    void ShowGameDecisions() const;

    void loseGame(Blackjack bj);

    void LeaveGame(Blackjack bj); //удалить из контейнера игроков
        

//#ifdef DEBUG
//    ~IPlayer()
//    {
//        cout << "IPlayer destructor" << endl;
//    }
//#endif // DEBUG

    
protected:
    //»спользуетс€ и IPlayer, и Dealer
    vector<pair<string, string>> hand; //сначала карта, потом масть
private:
    //“олько IPlayer
    string SetName(string name);

    string name;
    unsigned int player_number = 1; //номер игрока
    unsigned int bank = 0; //кол-во фишек
    string game_decision;
    const map<int, string> game_decisions{ {1, "Hit"}, {2, "Double"}, {3, "Stand"} };

};

