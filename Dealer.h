#pragma once

#include "IPlayer.h"

using namespace std;


class Dealer : public IPlayer
{
public:

    tuple<string, string> GiveCard(IPlayer player, DrawCard())
    {
        int card_number = rand() % 12 + 0; // от 0 до 13
        int s = rand() % 3 + 0; // от 0 до 3

        string card = deck.at(suits[s])[card_number];
        return tie(suits[s], card);
    }

private:
    //const map<string, int> deck_template
    //{
    //    {"2", 2},
    //    {"3", 3},
    //    {"4", 4},
    //    {"5", 5},
    //    {"6", 6},
    //    {"7", 7},
    //    {"7", 7},
    //    {"9", 9},
    //    {"10", 10},
    //    {"Jack", 10},
    //    {"Queen", 10},
    //    {"King", 10},
    //    {"Ace", 1}
    //};

    //в игре (в шузе) 4 колоды
    //const map<string, map<string, int>> deck
    //{
    //    { "clubs", deck_template },
    //    { "diamonds", deck_template },
    //    { "hearts", deck_template },
    //    { "spades", deck_template },

    //};


    const vector<string> deck_template
    {
        "2",
        "3",
        "4",
        "5",
        "6",
        "7",
        "8",
        "9",
        "10",
        "Jack",
        "Queen",
        "King",
        "Ace"
    };

    const map<string, vector<string>> deck
    {
        { "clubs", deck_template },
        { "diamonds", deck_template },
        { "hearts", deck_template },
        { "spades", deck_template }

    };

    const vector<string> suits{ "clubs", "diamonds", "hearts", "spades" };
};