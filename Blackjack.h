#pragma once

#include<map>

//#include "Player.h"
//#include "HumanPlayer.h"
//#include "Dealer.h"

using namespace std;

class Blackjack
{
public:
    Blackjack()
    {
#ifdef DEBUG
        cout << "Blackjack constructor" << endl;
#endif // DEBUG
        //Dealer d;
    }

    ~Blackjack()
    {
#ifdef DEBUG  
        cout << "Blackjack destructor" << endl;
#endif // DEBUG
    }

    void showCards()
    {

    }

    void setRules(int dealer_stops_on, int bank_per_player)
    {
        this->dealer_stops_on = dealer_stops_on;
        this->bank_per_player = bank_per_player;
    }

private:
    //The order: clubs, diamonds, hearts, spades
    //map<string, string> deck
    //{
    //    {"2C", "2 of clubs"},
    //    {"3C", "3 of clubs"},
    //    {"4C", "4 of clubs"},
    //    {"5C", "5 of clubs"},
    //    {"6C", "6 of clubs"},
    //    {"7C", "7 of clubs"},
    //    {"7C", "7 of clubs"},
    //    {"9C", "9 of clubs"},
    //    {"10C", "10 of clubs"},
    //    {"JackC", "Jack of clubs"},
    //    {"QueenC", "Queen of clubs"},
    //    {"KingC", "King of clubs"},
    //    {"AceC", "Ace of clubs"}
    //};

    const map<string, int> deck_template
    {
        {"2", 2},
        {"3", 3},
        {"4", 4},
        {"5", 5},
        {"6", 6},
        {"7", 7},
        {"7", 7},
        {"9", 9},
        {"10", 10},
        {"Jack", 10},
        {"Queen", 10},
        {"King", 10},
        {"Ace", 1}
    };

    //� ���� (� ����) 4 ������
    const map<string, map<string, int>> deck
    {
        { "clubs", deck_template },
        { "diamonds", deck_template },
        { "hearts", deck_template },
        { "spades", deck_template },

    };





    //default rules
    unsigned int dealer_stops_on = 17;
    unsigned int bank_per_player = 100;
    const unsigned int max_number_of_players = 7;
    unsigned int number_of_players = 0;
};