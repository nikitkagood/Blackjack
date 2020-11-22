#include "Blackjack.h"
#include "IPlayer.h"
#include "Dealer.h"

//#define DEBUG

using namespace std;

    void Blackjack::SetRules(const unsigned int& dealer_stops_on, const unsigned int& bank_per_player)
    {
        this->dealer_stops_on = dealer_stops_on;
        this->bank_per_player = bank_per_player;
    }

    void Blackjack::ShowPlayers()
    {
        cout << "Players are: " << endl;
        for (size_t i = 1; i < players.size(); i++)
        {
            cout << i << ". " << players[i].GetName() << endl;
        }
        cout << endl;
    }

    unsigned int Blackjack::GetBankPerPlayer()
    {
        return bank_per_player;
    }

    int Blackjack::GetNumberOfPlayers()
    {
        return number_of_players;
    }

    void Blackjack::UpdateNumberOfPlayers()
    {
        number_of_players = players.size();
    }

    void Blackjack::CheckNumberOfPlayers()
    {
        if (number_of_players == 1) EndGame();
    }

    void Blackjack::AddPlayer(const IPlayer& player)
    {
        players.push_back(player);
    }

    const void Blackjack::ShowRoundNumber() const
    {
        cout << "Round " << round_number << endl;
        cout << "###################" << endl;
    }

    void Blackjack::CountRound()
    {
        ++round_number;
    }

    unsigned int Blackjack::GetDealerStopsOn() const
    {
        return dealer_stops_on;
    }

    //void Blackjack::CheckPlayersBanks() //не компилируется
    //{
    //    for (size_t i = 1; i < players.size(); i++)
    //    {
    //        auto it = find(players.begin(), players.end(), i);
    //        if (players[i].GetBank() <= 0)
    //        {
    //            cout << players[i].GetName() << " ran out of chips and left the game" << endl;
    //            players.erase(it);
    //        }

    //        if (players.empty()) break;
    //    }
    //}

    void Blackjack::ErasePlayer(unsigned int player_number)
    {
        //players[player_number].~IPlayer();
        players.erase(players.begin() + player_number);
    }

    void Blackjack::ResetRound(Dealer& d)
    {
        d.ResetRound();
        d.GetHandLink().clear();
        ResetPlayersHands();
    }

    void Blackjack::ResetPlayersHands()
    {
        for (size_t i = 0; i < players.size(); i++)
        {
            players[i].GetHandLink().clear();
        }
    }

    void Blackjack::EndGame()
    {
        cout << "There are no more players left!" << endl;
        cout << "Exiting..." << endl;
        exit(1);
    }
