#pragma once

#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <stdexcept>

using namespace std;

class IPlayer;

class Blackjack
{
public:
    Blackjack();

    ~Blackjack();

    //void ShowCards();

    void SetRules(const unsigned int& dealer_stops_on, const unsigned int& bank_per_player);

    int GetNumberOfPlayers();

    void UpdateNumberOfPlayers();

    void AddPlayer(const IPlayer& player);

    unsigned int RoundNumber();

    void CountRound();

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


    //const map<string, map<string, int>> deck
    //{
    //    { "clubs", deck_template },
    //    { "diamonds", deck_template },
    //    { "hearts", deck_template },
    //    { "spades", deck_template }

    //};

    //const vector<string> deck_template
    //{
    //    "2",
    //    "3",
    //    "4",
    //    "5",
    //    "6",
    //    "7",
    //    "7",
    //    "9",
    //    "10",
    //    "Jack",
    //    "Queen",
    //    "King",
    //    "Ace"
    //};

    ////в игре (в шузе) 4 колоды
    //const map<string, vector<string>> deck
    //{
    //    { "clubs", deck_template },
    //    { "diamonds", deck_template },
    //    { "hearts", deck_template },
    //    { "spades", deck_template }

    //};

    //default rules
    unsigned int dealer_stops_on = 17;
    unsigned int bank_per_player = 100;
    const unsigned int max_number_of_players = 7;
    vector<IPlayer> players;
    unsigned int number_of_players = 1;
    const int max_score = 21;
    unsigned int round_number = 1;

};