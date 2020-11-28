#include "Blackjack.h"
#include "IPlayer.h"
#include "Dealer.h"
#include "AI_Player.h"

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
            cout << i << ". " << players[i]->GetName() << endl;
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

    void Blackjack::AddPlayer(IPlayer* player)
    {
        //players.push_back(new IPlayer(player));
        players.push_back(player);
    }

    void Blackjack::AddAIPlayer(AI_Player* player)
    {
        players.push_back(player);
    }

    const void Blackjack::ShowRoundNumber() const
    {
        cout << "####################" << endl;
        cout << "Round " << round_number << endl;
        cout << "####################" << endl;
    }

    void Blackjack::CountRound()
    {
        ++round_number;
    }

    unsigned int Blackjack::GetDealerStopsOn() const
    {
        return dealer_stops_on;
    }

    void Blackjack::CheckPlayersBanks()
    {
        for (size_t player_number = 1; player_number < GetNumberOfPlayers(); player_number++)
        {
            if (players[player_number]->GetBank() == 0)
            {
                cout << players[player_number]->GetName() << " has 0 chips and leaves the game" << endl;
                ErasePlayer(player_number);
            }
        }
    }

    void Blackjack::ErasePlayer(unsigned int player_number)
    {
        //players[player_number].~IPlayer();
        players.erase(players.begin() + player_number);
    }

    void Blackjack::ResetRound(Dealer& d)
    {
        d.ResetRound();
        ResetPlayers();
    }

    void Blackjack::ResetPlayers()
    {
        for (size_t i = 1; i < players.size(); i++)
        {
            players[i]->Reset();
        }
    }

    void Blackjack::ClearConsole()
    {
        //this_thread::sleep_for(chrono::seconds(5));

        system("CLS");
    }

    void Blackjack::EndGame()
    {
        cout << "There are no more players left!" << endl;
        cout << "Exiting..." << endl;
        exit(1);
    }
