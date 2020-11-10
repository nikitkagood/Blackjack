#pragma once

//#include <vector>

#include "Blackjack.h"

#define DEBUG

using namespace std;

class IPlayer
{
public:
    IPlayer()
    {
//#ifdef DEBUG
//        cout << "IPlayer constructor" << endl;
//#endif // DEBUG

        JoinGame();
        SetName("Player " + player_number);
    }

    IPlayer(string name)
    {
//#ifdef DEBUG
//        cout << "IPlayer constructor" << endl;
//#endif // DEBUG
        JoinGame();
        SetName(name);
    }

    unsigned int bet(unsigned int ammount);

    void bet_double();

    void Hold();

    void MakeGameDecision();

    string GameDecision(string decision) const;
    int GameDecision(int decision) const; //overloaded for int

    void JoinGame();

    void ReceiveCard(const pair<string, string>& to_receive);

    void ShowCards() const;

    void ShowGameDecisions() const;

    //void TakeCard()
    //{

    //}

    void loseGame(Blackjack bj);

    void LeaveGame(Blackjack bj); //удалить из контейнера игроков
        

//#ifdef DEBUG
//    ~IPlayer()
//    {
//        cout << "IPlayer destructor" << endl;
//    }
//#endif // DEBUG

    

private:
    string SetName(string name);

    string name;
    unsigned int player_number = 1; //номер игрока
    unsigned int bank = 0; //кол-во фишек
    //vector<string> hand; //рука 
    //tuple<string, string> hand;
    vector<pair<string, string>> hand; //сначала карта, потом масть
    string game_decision;
    const map<int, string> game_decisions{ {1, "Take"}, {2, "Double"}, {3, "Hold"} };

};

