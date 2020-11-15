#pragma once
//Blackjack - это главный класс игры


//ќбъ€влени€, которые подгружаютс€ в другие классы тоже
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stdexcept>

using namespace std;

class IPlayer;
class Dealer;

class Blackjack
{
public:
    Blackjack();

    ~Blackjack();

    //void ShowCards();

    void SetRules(const unsigned int& dealer_stops_on, const unsigned int& bank_per_player);

    unsigned int GetBankPerPlayer();

    int GetNumberOfPlayers();

    void UpdateNumberOfPlayers();

    void AddPlayer(const IPlayer& player);

    unsigned int RoundNumber();

    void CountRound();

    unsigned int GetDealerStopsOn() const;

    void DetermineWinner();

    //const vector<IPlayer> GetPlayers() const;

    //void SetPlayers(vector<IPlayer> players);

    vector<IPlayer> players;
    
private:
    //ќбъ€вленые значени€ - это стандартные правила
    unsigned int dealer_stops_on = 17;
    unsigned int bank_per_player = 100;
    const unsigned int max_number_of_players = 7;

    unsigned int number_of_players = 1;
    unsigned int round_number = 1;

};