#pragma once

#include "Player.h"
#include "Blackjack.h"

using namespace std;

class HumanPlayer : public Player
{
public:
    HumanPlayer()
    {
#ifdef DEBUG
        cout << "HumanPlayer constructor" << endl;
#endif // DEBUG

        joinGame();
        setName("Player");
    }

#ifdef DEBUG
    ~HumanPlayer()
    {
        cout << "HumanPlayer destructor" << endl;
    }
#endif // DEBUG
    HumanPlayer(string name)
    {
        joinGame();
        setName(name);
    }

    virtual void bet() override
    {

    }
    virtual void bet_double() override
    {

    }

private:

};