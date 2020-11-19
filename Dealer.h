#pragma once

#include "IPlayer.h"

using namespace std;

class Dealer : public IPlayer
{
public:
    friend class Blackjack;

    Dealer(Blackjack& bj)
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

        //TODO: Проверить правильность подсчета тузов

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

    void ReceiveGameDecision(const string& game_decision, IPlayer& player, const unsigned int& player_number)
    {
        if (game_decision == "1" || game_decision == "Hit" || game_decision == "hit")
        {
            Dealer::GiveCard(player);
            player.ShowCards();
        }
        else if (game_decision == "2" || game_decision == "Double" || game_decision == "double")
        {
            //player.ChangeBank(players_current_bets[player_number] * 2);
            //players_current_bets[player_number] *= 2;
            //cout << player.GetName() << " betted double" << endl;
            player.bet_double(*this, player_number);
        }
        else if (game_decision == "3" || game_decision == "Stand" || game_decision == "stand")
        {
            //nothing
        }
        else cout << "Wrong command" << endl;

    }

    //void ReceiveGameDecision(const string& game_decision, IPlayer& player)
    //{
    //    if (game_decision == "1" || game_decision == "Hit" || game_decision == "hit")
    //    {
    //        Dealer::GiveCard(player);
    //        player.ShowCards();
    //    }
    //    else if (game_decision == "2" || game_decision == "Double" || game_decision == "double")
    //    {
    //        //player.ChangeBank(players_current_bets[player_number] * 2);
    //        //players_current_bets[player_number] *= 2;
    //        //cout << GetName() << " betted double" << endl;
    //    }
    //    else if (game_decision == "3" || game_decision == "Stand" || game_decision == "stand")
    //    {
    //        //nothing
    //    }
    //    else cout << "Wrong command" << endl;

    //}

    void CheckScores()
    {
        cout << "Scores before check" << endl;
        ShowScores();
        cout << endl;
        
        //TODO: ГДЕ-ТО ЗДЕСЬ БАГ
        unsigned int dealer_score = players_scores[0];
        players_scores.erase(0);

        if (dealer_score > 21) dealer_score = 0;
        //после этого цикла в players_scores должны остаться только не проигравшие
        vector<int> players_to_erase;
        for (auto i : players_scores)
        {
            if (i.second > 21 || i.second < dealer_score)
                //players_scores.erase(i.first);
                players_to_erase.push_back(i.first);
            else if (i.second == dealer_score) 
                players_draws.insert({i.first, true});
        }

        for (auto i : players_to_erase)
        {
            players_scores.erase(i);
        }

        cout << "Scores after check" << endl;
        ShowScores();
        cout << endl;
    }

    void ShowScores() //Только для дебага
    {
        for (auto i : players_scores)
        {
            cout << "Player" << i.first << ": " << i.second << endl;
        }
    }

    void GiveWin(Blackjack& bj)
    {
        for (auto i : players_scores)
        {
            unsigned int ammount = 0;

            if (players_draws.count(i.first)) //Если ничья
            {
                ammount = players_current_bets[i.first];
                //bj.players[i.first].ChangeBank(ammount);
                bj.players[i.first].ChangeBank(ammount);
                cout << " draw! " << bj.players[i.first].GetName() << " received his bet back: " << ammount << endl;
            }
            else if (players_blackjack.count(i.first)) //Если блекджек
            {
                ammount = players_current_bets[i.first] * 2 * 1.5;
                bj.players[i.first].ChangeBank(ammount);
                cout << bj.players[i.first].GetName() << " has Blackjack!" << " He received 1.5x bet: " << ammount << endl;
            }
            else
            {
                ammount = players_current_bets[i.first] * 2;
                bj.players[i.first].ChangeBank(ammount);
                cout << bj.players[i.first].GetName() << " wins!" << " He received: " << ammount << endl;
            }
        }
    }

    map<unsigned int, unsigned int> players_current_bets; //player_number, bet
    map<unsigned int, unsigned int> players_scores; //player_number, score.  0 элемент это дилер
    map<unsigned int, bool> players_draws; //player_number, if draw
    map<unsigned int, bool> players_blackjack; //player_number, if blackjack 



private:
    void ResetRound() //только для вызова извне
    {
        players_current_bets.clear();
        players_scores.clear();
        players_draws.clear();
        players_blackjack.clear(); 
    }

    //void ChangeBank(IPlayer& player, unsigned int ammount)
    //{
    //    player.ChangeBank(ammount);
    //}

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