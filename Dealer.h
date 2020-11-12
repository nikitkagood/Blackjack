#pragma once

#include "IPlayer.h"

using namespace std;

class Dealer : public IPlayer
{
public:

    void GiveCard(IPlayer& player)
    {
        int card_number = rand() % 12 + 0; // от 0 до 13
        int suit_number = rand() % 3 + 0; // от 0 до 3

        string card = deck.at(suits[suit_number])[card_number];

        player.ReceiveCard(make_pair(card, suits[suit_number]));
    }

    void ShowOneCard() const
    {
        cout << "Dealer has:" << endl;
        cout << hand[0].first << " of " << hand[0].second << endl;
        cout << "### of ###" << endl;
    }

    unsigned int CountScore(const IPlayer& player)
    {
        unsigned int score1 = 0; //очки, где туз равен 1
        unsigned int scoreA = 0; //туз равен 11
        //unsigned int count_aces = 0;
        //TODO: Несколько тузов учитываются как 11 и 1
        for (auto i : player.GetHand())
        {
            score1 += scores_map.at(i.second);

            scoreA += scores_map.at(i.second);
            if (i.first == "Ace") scoreA += 10;
        }

        if (scoreA > score1 && scoreA <= 21)
        {
            return scoreA;
        }
        else return score1;

    }

private:
    //в игре (в шузе) 4 колоды
    //const map<string, map<string, int>> deck
    //{
    //    { "clubs", deck_template },
    //    { "diamonds", deck_template },
    //    { "hearts", deck_template },
    //    { "spades", deck_template },

    //};


    const map<string, int> scores_map
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