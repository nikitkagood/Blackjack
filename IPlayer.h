#pragma once

//#define TESTING

#include "Blackjack.h"

using namespace std;

//#define TESTING

class IPlayer
{
public:
    IPlayer();

    IPlayer(Blackjack& bj);

    IPlayer(Blackjack& bj, const string& name);

    //IPlayer(const IPlayer& other); //конструктор копирования

    IPlayer& operator = (const IPlayer& player);

    unsigned int bet();

    void bet_double(Dealer d, unsigned int player_number);

    void MakeGameDecision(Dealer& d, IPlayer& player_himself, const unsigned int& player_number);

    void JoinGame();

    void SetPlayerNumber();

    void GetPlayerNumber();

    void ReceiveCard(const pair<string, string>& to_receive);

    void ShowCards() const;

    void ShowGameDecisions() const;

    void LeaveGame(Blackjack bj); //delete from players container?
        
    const vector<pair<string, string>> GetHand() const;
    vector<pair<string, string>>& GetHandLink();

    const string GetName() const;

    const unsigned int GetBank() const;

    void ChangeBank(const int& ammount);

protected:

    //Used by IPlayer and Dealer
    vector<pair<string, string>> hand; //сначала карта, потом масть
    unsigned int score = 0;

    string SetName(string name);
    string name;
    unsigned int player_number = 0; //number 0 is dealer, not used yet

private:


    unsigned int bank = 0; //ammount of chips
    //unsigned int current_bet = 0; 

    const map<int, string> game_decisions{ {1, "Hit"}, {2, "Double"}, {3, "Stand"} };

};

