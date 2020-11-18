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

    void SetRules(const unsigned int& dealer_stops_on, const unsigned int& bank_per_player);

    void ShowPlayers();

    unsigned int GetBankPerPlayer();

    int GetNumberOfPlayers();

    void UpdateNumberOfPlayers();

    void AddPlayer(const IPlayer& player);

    const void ShowRoundNumber() const;

    void CountRound();

    unsigned int GetDealerStopsOn() const;

    void CheckPlayersBanks();

    void ResetRound(Dealer& d);

    void ResetPlayersHands();

    vector<IPlayer> players;
    
private:
    //ќбъ€вленные значени€ - это стандартные правила
    unsigned int dealer_stops_on = 17;
    unsigned int bank_per_player = 100;
    const unsigned int max_number_of_players = 7;

    unsigned int number_of_players = 1;
    unsigned int round_number = 0;

};