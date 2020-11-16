#pragma once

#include "IPlayer.h"

using namespace std;

class Dealer : public IPlayer
{
public:
    friend class Blackjack;

    Dealer(Blackjack bj)
    {
        SetName("Dealer");
        bj.AddPlayer(*this);
    }

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
        cout << endl;
    }

    const unsigned int CountScore(const IPlayer& player)
    {
        unsigned int score1 = 0; //очки, где туз равен 1
        unsigned int scoreA = 0; //туз равен 11
        //unsigned int count_aces = 0;

        //TODO: Несколько тузов учитываются как 11 и 1

        auto hand = player.GetHand();
        for (size_t i = 0; i < hand.size(); i++)
        {
            score1 += scores_map[hand[i].first];

            scoreA += scores_map[hand[i].first];
            if (hand[i].first == "Ace") scoreA += 10;
        }

        if (scoreA > score1 && scoreA <= 21)
        {
            return scoreA;
        }
        else return score1;

    }

    //void ReceiveGameDecision(const string& game_decision, IPlayer& player)
    //{
    //    while (true)
    //    {
    //        if (game_decision == "Hit" || game_decision == "hit" || game_decision == "1")
    //        {
    //            Dealer::GiveCard(player);
    //        }
    //        else if (game_decision == "Double" || game_decision == "double" || game_decision == "2")
    //        {
    //            player.bet_double();
    //            break;
    //        }
    //        else if (game_decision == "Stand" || game_decision == "stand" || game_decision == "3")
    //        {
    //            break;
    //        }
    //    }

    //}

    void ReceiveGameDecision(const string& game_decision, IPlayer& player)
    {
        if (game_decision == "1" || game_decision == "Hit" || game_decision == "hit")
        {
            Dealer::GiveCard(player);
        }
        else if (game_decision == "2" || game_decision == "Double" || game_decision == "double")
        {
            player.bet_double();
        }
        else if (game_decision == "3" || game_decision == "Stand" || game_decision == "stand")
        {
            //nothing
        }
        else cout << "Wrong command" << endl;

    }

    void CheckScores()
    {
        //sort(players_scores.begin(), players_scores.end());

        ShowScores();
        
        unsigned int dealer_score = players_scores[0];

        for (auto i : players_scores)
        {
            
            if (i.second > 21) players_scores.erase(i.first);
        }

        ShowScores();
    }

    void ShowScores() //Только для дебага
    {
        for (auto i : players_scores)
        {
            cout << "Player" << i.first << ": " << i.second << endl;
        }
    }

    map<unsigned int, unsigned int> players_current_bets; //player_number, bet
    map<unsigned int, unsigned int> players_scores; //player_number, score.  0 элемент это дилер


private:
    void ResetRound() //только для вызова извне
    {
        players_current_bets.clear();
        players_scores.clear();
    }

    map<string, unsigned int> scores_map
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

    const vector<string> suits{ "clubs", "diamonds", "hearts", "spades" };

    //TODO: В игре (в шузе) 4 колоды. Или добавить проверку
    const map<string, vector<string>> deck
    {
        { suits[0], deck_template },
        { suits[1], deck_template },
        { suits[2], deck_template },
        { suits[3], deck_template }

    };
};