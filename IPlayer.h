#pragma once

//#define TESTING

#include "Blackjack.h"

using namespace std;

//#define TESTING

class IPlayer
{
public:


    //IPlayer(Blackjack& bj); //Default name. Unused

    IPlayer(Blackjack& bj, const string& name);

    //IPlayer(const IPlayer& other); //Copy constructor, unused

    IPlayer& operator = (const IPlayer& player);

    virtual void bet();
    // virtual unsigned int bet();

    void bet_double();

    void make_insurance();

    virtual void MakeGameDecision(Dealer& d, const unsigned int& player_number);

    virtual void MakeInsuranceDecision();

    void JoinGame();

    void SetPlayerNumber();

    void GetPlayerNumber();

    const unsigned int GetCurrentBet() const;

    unsigned int GetInsuranceBet() const;

    void ReceiveCard(const pair<string, string>& to_receive);

    void ShowCards() const;

    void ShowGameDecisions() const;

    void LeaveGame(Blackjack bj); //delete from players container?
        
    const vector<pair<string, string>> GetHand() const;
    vector<pair<string, string>>& GetHandLink();

    const string GetName() const;

    const unsigned int GetBank() const;

    void ChangeBank(const int& ammount);

    void Reset();

protected:
    IPlayer(); //Only for Dealer!

    vector<pair<string, string>> hand; //first is card, second is suit 

    string SetName(string name);
    string name;
    unsigned int player_number = 0; //not used yet, 0 is always dealer

    unsigned int bank = 0; //ammount of chips
    unsigned int current_bet = 0;
    unsigned int insurance_bet = 0;

private:
    const map<int, string> game_decisions{ {1, "Hit"}, {2, "Double"}, {3, "Stand"} };
};

