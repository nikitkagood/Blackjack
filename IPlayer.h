#pragma once

#include <vector>

#include "Blackjack.h"

#define DEBUG

using namespace std;

//class Dealer;

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

    unsigned int bet(unsigned int ammount)
    {
        if (bank > ammount)
        {
            bank -= ammount;
            return ammount;
        }
        else
        {
            cout << "You don't have that much" << endl;
            return 0;
        }
    }
    void bet_double()
    {

    }

    void JoinGame()
    {

    }

    void ReceiveCard(const pair<string, string>& to_receive)
    {

        hand.push_back(to_receive);

    }

    void ShowCards() const
    {
        for (auto i : hand)
        {
            cout << i.first << " of " << i.second << endl;
        }
    }

    //void TakeCard()
    //{

    //}

    void Hold()
    {

    }

    void loseGame(Blackjack bj)
    {
        if (true) LeaveGame(bj);
    }

    void LeaveGame(Blackjack bj)
    {
        //удалить из контейнера игроков
    }

//#ifdef DEBUG
//    ~IPlayer()
//    {
//        cout << "IPlayer destructor" << endl;
//    }
//#endif // DEBUG

private:
    string SetName(string name)
    {
        return this->name = name;
    }

    string name;
    unsigned int player_number = 1; //номер игрока
    unsigned int bank = 0; //кол-во фишек
    //vector<string> hand; //рука 
    //tuple<string, string> hand;
    vector<pair<string, string>> hand; //сначала карта, потом масть

};

