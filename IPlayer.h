#pragma once

//#include <vector>

#include "Blackjack.h"

#define DEBUG

using namespace std;



class IPlayer
{
public:
    IPlayer();

    IPlayer(Blackjack& bj);

    IPlayer(Blackjack& bj, string name);

    unsigned int bet();

    void bet_double();

    void Hold(); //переименовать в stand

    void Hit();

    void MakeGameDecision(const Dealer& d);

    //string GameDecision(string decision) const;
    //int GameDecision(int decision) const; //перегруза для int

    void JoinGame();

    void ReceiveCard(const pair<string, string>& to_receive);

    void ShowCards() const;

    void ShowGameDecisions() const;

    void loseGame(Blackjack bj);

    void LeaveGame(Blackjack bj); //удалить из контейнера игроков
        
    const vector<pair<string, string>> GetHand() const;

//#ifdef DEBUG
//    ~IPlayer()
//    {
//        cout << "IPlayer destructor" << endl;
//    }
//#endif // DEBUG

    
protected:
    //Используется и IPlayer, и Dealer
    vector<pair<string, string>> hand; //сначала карта, потом масть


private:
    //Только IPlayer
    string SetName(string name);

    string name;
    unsigned int player_number = 1; //номер игрока, игрока под номером 0 не может быть
    unsigned int bank = 0; //кол-во фишек
    string game_decision;
    const map<int, string> game_decisions{ {1, "Hit"}, {2, "Double"}, {3, "Stand"} };

};

