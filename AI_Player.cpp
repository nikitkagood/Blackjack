#include "AI_Player.h"
#include "IPlayer.h"
#include "Dealer.h"

AI_Player::AI_Player(Blackjack& bj, const string& name)
{
    //JoinGame();
    SetName(name);
    bank = bj.GetBankPerPlayer();
    //bj.AddPlayer(*this);
    bj.AddAIPlayer(this);
}

void AI_Player::bet()
{
    cout << GetName() << " has: " << GetBank() << " chips" << endl;
    //cout << "Enter yor bet: ";

    unsigned int ammount = DecideBet();
    //cin >> ammount;

    if (ammount == 0)
    {
        cout << "You can't bet nothing" << endl;
        cout << endl;
        //return 0;
    }
    else if (bank >= ammount)
    {
        bank -= ammount;
        cout << GetName() << " betted " << ammount << endl;
        cout << endl;
        current_bet += ammount;
        //return ammount;
    }
    else
    {
        cout << "You don't have that much" << endl;
        cout << endl;
        //return 0;
    }
}


unsigned int AI_Player::DecideBet()
{
    unsigned int ammount = 0;
    unsigned int r = rand() % (bank / 100 * 10 / 2) + 0; // from 0 till *half of 10% of bank* included
    ammount = (bank / 100 * 10) + r;

    return ammount;
}

void AI_Player::MakeGameDecision(Dealer& d, const unsigned int& player_number)
{
    string game_decision;

    do
    {
        //cin >> game_decision;
        game_decision = DecideGameDecision();
        cout << endl;
    } while (!d.ReceiveGameDecision(game_decision, *this, player_number));
    //если функция возвращает true, то выход из цикла
}

pair<unsigned int, unsigned int> AI_Player::CountScoreAndAces()
{
    unsigned int score = 0;

    auto hand = GetHand();
    unsigned int count_aces = 0;

    for (size_t i = 0; i < hand.size(); i++) //Counting not aces first
    {
        if (hand[i].first != "Ace")
        {
            score += scores_map[hand[i].first];
        }
        else if (hand[i].first == "Ace")
        {
            count_aces++;
        }
        else throw(runtime_error("Undefined card"));
    }

    score += count_aces;

    for (size_t i = 0; i < count_aces; i++)
    {
        if ((score + 10) <= 21) //If Ace, we add 10pts to score only if it will be below 21
                                //i.e. for example 5 of hearts + ace = 16, if we add another ace, the score will increase just by 1 
        {
            score += 10;
        }
    }

    return { score, count_aces };
}


string AI_Player::DecideGameDecision()
{
    string decision;
    auto result = CountScoreAndAces();
    int score = result.first;
    int aces = result.second;

    if (hand.size() == 2)
    {
        if (aces == 1)
        {
            if (score < 16)
            {
                return "Double";
            }
            else if (score <= 17 )
            {
                return "Hit";
            }
            else return "Stand";
        }

        else if (aces == 2)
        {
            if (score < 16)
            {
                return "Hit";
            }
            else if (score == 16)
            {
                return "Stand";
            }
            else return "Stand";
        }
    }
    else
    {
        if (score <= 8)
        {
        return "Hit";
        }
        else if (score == 11 || score == 12)
        {
        return "Double";
        }
        else if (score <= 15)
        {
        return "Hit";
        }
    }

    return "Stand";
}

void AI_Player::MakeInsuranceDecision()
{
    //Bot never uses insurance
    //So it should be empty
}
