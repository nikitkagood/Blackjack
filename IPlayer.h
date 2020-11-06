#pragma once

#include <vector>

#include "Blackjack.h"

using namespace std;

class IPlayer
{
public:
    IPlayer()
    {
#ifdef DEBUG
        cout << "HumanPlayer constructor" << endl;
#endif // DEBUG

        JoinGame();
        SetName("Player " + player_number);
    }

#ifdef DEBUG
    ~IPlayer()
    {
        cout << "HumanPlayer destructor" << endl;
    }
#endif // DEBUG

    IPlayer(string name)
    {
#ifdef DEBUG
        cout << "HumanPlayer constructor" << endl;
#endif // DEBUG
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

    pair<string, string> ReceiveCard(pair<string, string> to_receive)
    {

        hand.push_back(to_receive);

    }

    //void TakeCard(Dealer dealer)
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

    /*  tuple<string, string> operator += (tuple<string, string>, tuple<string, string>)
      {

      }*/

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
    vector<pair<string, string>> hand;

};

