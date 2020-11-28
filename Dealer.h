#pragma once

#include "IPlayer.h"

using namespace std;

//#define TESTING

class Dealer : public IPlayer
{
public:
    friend class Blackjack;

    Dealer(Blackjack& bj)
    {
        SetName("Dealer");
        ResetShoe();
        bj.AddPlayer(this);
    }

    void GiveCard(IPlayer& player)
    {
        //int card_number = rand() % 13 + 0; // from 0 до 12 included
        //int suit_number = rand() % 4 + 0; // from 0 to 3 included
        //int deck_number = rand() % 5 + 0; // from 0 to 4 included

        //Cards are given from the end due to vector implementation
        pair<string, string> card = shoe.back();
        shoe.pop_back();

        player.ReceiveCard(card);
    }

    void StartingDeal(Blackjack& bj)
    {
        //1 card for players, 1 card for dealer and then again
        for (size_t player_number = 1; player_number < bj.GetNumberOfPlayers(); player_number++)
        {
            GiveCard(*bj.players[player_number]);
        }

        for (size_t i = 0; i < 1; i++)
        {
            GiveCard(*this);
        }

        for (size_t player_number = 1; player_number < bj.GetNumberOfPlayers(); player_number++)
        {
            GiveCard(*bj.players[player_number]);
        }

        for (size_t i = 0; i < 1; i++)
        {
            GiveCard(*this);
        }
    }

    void ShowOneCard()
    {
        cout << "Dealer has:" << endl;
        cout << hand[0].first << " of " << hand[0].second << endl;
        cout << "### of ###" << endl;
        cout << endl;

    }

    const unsigned int CountScore(const IPlayer& player)
    {
        unsigned int score = 0; 

        auto hand = player.GetHand();
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

        return score;
    }

    bool ReceiveGameDecision(const string& game_decision, IPlayer& player, const unsigned int& player_number)
    {
        while (true)
        {
            if (Dealer::CountScore(player) >= 21)
                break;

            if (game_decision == "1" || game_decision == "Hit" || game_decision == "hit")
            {
                //цикл продолжается, т.к можно взять еще карту
                Dealer::GiveCard(player);
                cout << player.GetName() << " gets another card" << endl;
                player.ShowCards();
                
            }
            else if (game_decision == "2" || game_decision == "Double" || game_decision == "double")
            {
                player.bet_double();
                Dealer::GiveCard(player);
                break;
            }
            else if (game_decision == "3" || game_decision == "Stand" || game_decision == "stand")
            {
                cout << player.GetName() << " stands" << endl << endl;
                break;
            }
            else
            {
                //цикл продолжается, т.к неверная команда
                cout << "Wrong command" << endl;
            }

        }

        return true;
    }

    void CheckScores()
    {
        cout << "DEBUG: Scores before check" << endl;
        ShowScores();
        cout << endl;
        
        unsigned int dealer_score = players_scores[0];
        players_scores.erase(0);

        if (dealer_score > 21) dealer_score = 0;

        vector<int> players_to_erase;
        for (auto i : players_scores)  //After this loop in players_scores must only remain players who haven't lost
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

        //cout << "Scores after check" << endl;
        //ShowScores();
        cout << endl;
    }

    void CheckInsurance(Blackjack bj)
    {
        if (Dealer::hand.size() == 2 && Dealer::CountScore(*this) == 21)
        {
            //Win insurance
            for (auto p : bj.players)
            {
                int i_bet = p->GetInsuranceBet();
                if (i_bet > 0)
                {
                    p->ChangeBank(i_bet * 2);
                }
            }
            //Losses are not checked, cause they will be cleared automatically at the end of the round
        }
    }

    void ShowScores() //Только для дебага
    {
        for (auto i : players_scores)
        {
            cout << "Player" << i.first << ": " << i.second << endl;
        }
    }

    void OfferInsurance(Blackjack bj) //Changes flag isInsurance for all players
    {
        cout << "Dealer has open Ace. Players can make insurance." << endl;

        for (size_t player_number = 1; player_number < bj.GetNumberOfPlayers(); player_number++)
        {
            //bj.players[player_number].ReceiveInsuranceOffer();
            bj.players[player_number]->MakeInsuranceDecision();
        }

    }

    //void GiveWin(Blackjack& bj)
    //{
    //    for (auto i : players_scores)
    //    {
    //        unsigned int ammount = 0;

    //        if (players_draws.count(i.first)) //Если ничья
    //        {
    //            ammount = players_current_bets[i.first];
    //            bj.players[i.first]->ChangeBank(ammount);
    //            cout << "Draw! " << bj.players[i.first]->GetName() << " received his bet back: " << ammount << endl;
    //        }
    //        else if (players_blackjack.count(i.first)) //Если блекджек
    //        {
    //            ammount = players_current_bets[i.first] * 2 * 1.5;
    //            bj.players[i.first]->ChangeBank(ammount);
    //            cout << bj.players[i.first]->GetName() << " has Blackjack!" << " He received 1.5x bet: " << ammount << endl;
    //        }
    //        else //Просто победа
    //        {
    //            ammount = players_current_bets[i.first] * 2;
    //            bj.players[i.first]->ChangeBank(ammount);
    //            cout << bj.players[i.first]->GetName() << " wins!" << " He received: " << ammount << endl;
    //        }
    //    }
    //}

    void GiveWin(Blackjack& bj)
    {
        for (auto i : players_scores)
        {
            unsigned int ammount = 0;

            if (players_draws.count(i.first)) //Если ничья
            {
                ammount = bj.players[i.first]->GetCurrentBet();
                bj.players[i.first]->ChangeBank(ammount);
                cout << "Draw! " << bj.players[i.first]->GetName() << " received his bet back: " << ammount << endl;
            }
            else if (players_blackjack.count(i.first)) //Если блекджек
            {
                ammount = bj.players[i.first]->GetCurrentBet() * 2 * 1.5;
                bj.players[i.first]->ChangeBank(ammount);
                cout << bj.players[i.first]->GetName() << " has Blackjack!" << " He received 1.5x bet: " << ammount << endl;
            }
            else //Просто победа
            {
                ammount = bj.players[i.first]->GetCurrentBet() * 2;
                bj.players[i.first]->ChangeBank(ammount);
                cout << bj.players[i.first]->GetName() << " wins!" << " He received: " << ammount << endl;
            }
        }
    }

    void ResetShoe()
    {
        shoe.reserve(208);
        for (size_t a = 0; a < 4; a++) //4 decks
        {
            for (size_t i = 0; i < 4; i++) //4 suits
            {
                for (size_t j = 0; j < 13; j++) //13 cards
                {
                    shoe.push_back({ cards_template[j], suits[i] });
                }
            }
        }
        random_shuffle(shoe.begin(), shoe.end());
    }

    void CheckShoe()
    {
        if (shoe.size() <= 208 / 100 * 66)
        {
            ResetShoe();
        }
    }

    //map<unsigned int, unsigned int> players_current_bets; //player_number, bet
    map<unsigned int, unsigned int> players_scores; //player_number, score.  0 элемент это дилер
    map<unsigned int, bool> players_draws; //player_number, if draw
    map<unsigned int, bool> players_blackjack; //player_number, if blackjack 

private:

    bool isDealer = true;

    void ResetRound() //только для вызова извне
    {
        Dealer::hand.clear();

        //players_current_bets.clear();
        players_scores.clear();
        players_draws.clear();
        players_blackjack.clear();
    }

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

    const vector<string> cards_template
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

    vector<pair<string, string>> shoe; //card, suit

    //TODO: В игре (в шузе) 4 колоды. Или добавить проверку
    //const map<string, vector<string>> deck_template
    //{
    //    { suits[0], cards_template },
    //    { suits[1], cards_template },
    //    { suits[2], cards_template},
    //    { suits[3], cards_template }

    //};

    //vector<pair<string, vector<string>>> deck_template
    //{
    //    { suits[0], cards_template },
    //    { suits[1], cards_template },
    //    { suits[2], cards_template},
    //    { suits[3], cards_template }

    //};

    //vector<map<string, vector<string>>> shoe
    //{
    //    deck_template, deck_template, deck_template, deck_template
    //};
};