#pragma once
//Blackjack - ��� ������� ����� ����


//����������, ������� ������������ � ������ ������ ����
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

    void ShowPlayers();

    unsigned int GetBankPerPlayer();

    int GetNumberOfPlayers();

    void UpdateNumberOfPlayers();

    void AddPlayer(const IPlayer& player);

    //unsigned int GetRoundNumber();

    const void ShowRoundNumber() const;

    void CountRound();

    unsigned int GetDealerStopsOn() const;

    void DetermineWinner();

    void ResetRound(Dealer& d);

    //const vector<IPlayer> GetPlayers() const;

    //void SetPlayers(vector<IPlayer> players);

    vector<IPlayer> players;
    
private:
    //���������� �������� - ��� ����������� �������
    unsigned int dealer_stops_on = 17;
    unsigned int bank_per_player = 100;
    const unsigned int max_number_of_players = 7;

    unsigned int number_of_players = 1;
    unsigned int round_number = 0;

};