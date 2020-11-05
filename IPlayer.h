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
        SetName("Player");
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

    void bet()
    {

    }
    void bet_double()
    {

    }

    void JoinGame()
    {

    }

    void TakeCard()
    {

    }
    void Hold()
    {

    }

    void loseGame()
    {
        if (true) LeaveGame();
    }

    void LeaveGame()
    {

    }

private:
    string SetName(string name)
    {
        return this->name = name;
    }

    string name;
    unsigned int player_number = 1; //номер игрока
    unsigned int bank = 0; //кол-во фишек
    //vector<string> hand; //рука 
    tuple<string, string> hand;

}

