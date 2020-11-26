#pragma once

#include "IPlayer.h"

using namespace std;


class AI_Player : public IPlayer
{
public:
    AI_Player(Blackjack& bj, const string& name);

    unsigned int bet() override;

    unsigned int DecideBet();

    void MakeGameDecision(Dealer& d, const unsigned int& player_number) override;

    string DecideGameDecision();

    void MakeInsuranceDecision() override;

    pair<unsigned int, unsigned int> CountScoreAndAces();

private:

    //unsigned int bank = 0; //ammount of chips
    //unsigned int current_bet = 0;
    //unsigned int insurance_bet = 0;

    map<string, unsigned int> scores_map
    {
        {"2", 2},
        {"3", 3},
        {"4", 4},
        {"5", 5},
        {"6", 6},
        {"7", 7},
        {"8", 8},
        {"9", 9},
        {"10", 10},
        {"Jack", 10},
        {"Queen", 10},
        {"King", 10},
        {"Ace", 1}
    };

};