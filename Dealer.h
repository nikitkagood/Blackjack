#pragma once

#include "IPlayer.h"

using namespace std;

//class Dealer : public IPlayer
class Dealer
{
public:

    void GiveCard(IPlayer player)
    {
        int card_number = rand() % 12 + 0; // �� 0 �� 13
        int suit_number = rand() % 3 + 0; // �� 0 �� 3

        string card = deck.at(suits[suit_number])[card_number];

        player.ReceiveCard(make_pair(card, suits[suit_number]));
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

    //� ���� (� ����) 4 ������
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