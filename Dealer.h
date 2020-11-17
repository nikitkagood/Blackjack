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
        int card_number = rand() % 12 + 0; // �� 0 �� 13
        int suit_number = rand() % 3 + 0; // �� 0 �� 3

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
        unsigned int score1 = 0; //����, ��� ��� ����� 1
        unsigned int scoreA = 0; //��� ����� 11
        //unsigned int count_aces = 0;

        //TODO: ��������� ����� ����������� ��� 11 � 1

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

    void ReceiveGameDecision(const string& game_decision, IPlayer& player)
    {
        if (game_decision == "1" || game_decision == "Hit" || game_decision == "hit")
        {
            Dealer::GiveCard(player);
            player.ShowCards();
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

        cout << "Scores before check" << endl;
        ShowScores();
        cout << endl;
        
        unsigned int dealer_score = players_scores[0];
        players_scores.erase(0);

        if (dealer_score > 21) dealer_score = 0;
        //����� ����� ����� � players_scores ������ �������� ������ �� �����������
        for (auto i : players_scores)
        {
            if (i.second > 21 || i.second < dealer_score) 
                players_scores.erase(i.first);
            else if (i.second == dealer_score) 
                players_draws.insert({i.first, true});
            if (players_scores.empty()) break;
        }

        cout << "Scores after check" << endl;
        ShowScores();
        cout << endl;
    }

    void ShowScores() //������ ��� ������
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

            if (players_draws.count(i.first)) //���� �����
            {
                ammount = players_current_bets[i.first];
                //bj.players[i.first].ChangeBank(ammount);
                bj.players[i.first].ChangeBank(ammount);
                cout << bj.players[i.first].GetName() << " draw " << "he received his bet back: " << ammount << endl;
            }
            else if (players_blackjack.count(i.first)) //���� ��������
            {
                ammount = players_current_bets[i.first] * 2 * 1.5;
                bj.players[i.first].ChangeBank(ammount);
                cout << bj.players[i.first].GetName() << " has Blackjack " << "he received: " << ammount << endl;
            }
            else
            {
                ammount = players_current_bets[i.first] * 2;
                bj.players[i.first].ChangeBank(ammount);
                cout << bj.players[i.first].GetName() << " wins " << "he received: " << ammount << endl;
            }
        }
    }

    map<unsigned int, unsigned int> players_current_bets; //player_number, bet
    map<unsigned int, unsigned int> players_scores; //player_number, score.  0 ������� ��� �����
    map<unsigned int, bool> players_draws; //player_number, if draw
    map<unsigned int, bool> players_blackjack; //player_number, if blackjack 



private:
    void ResetRound() //������ ��� ������ �����
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

    //TODO: � ���� (� ����) 4 ������. ��� �������� ��������
    const map<string, vector<string>> deck
    {
        { suits[0], deck_template },
        { suits[1], deck_template },
        { suits[2], deck_template },
        { suits[3], deck_template }

    };
};