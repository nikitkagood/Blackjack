#pragma once

#include <vector>

#include "Blackjack.h"

using namespace std;

//class Player : public Blackjack
class Player
{
protected:
    string setName(string name)
    {
        return this->name = name;
    }

    virtual void bet()
    {

    }
    virtual void bet_double()
    {

    }
    void takeCard()
    {

    }
    void hold()
    {

    }

    void joinGame()
    {

    }

    void loseGame()
    {
        if (true) leaveGame();
    }

    void leaveGame()
    {

    }

    string name;
    unsigned int player_number = 1; //����� ������
    unsigned int bank = 0; //���-�� �����
    vector<string> hand; //���� 


private:

};

