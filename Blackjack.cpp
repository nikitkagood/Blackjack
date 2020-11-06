#include "Blackjack.h"
#include "IPlayer.h"

using namespace std;

     Blackjack::Blackjack()
    {
#ifdef DEBUG
        cout << "Blackjack constructor" << endl;
#endif // DEBUG
        //Dealer d;
    }

     Blackjack::~Blackjack()
    {
#ifdef DEBUG  
        cout << "Blackjack destructor" << endl;
#endif // DEBUG
    }

    void Blackjack::ShowCards()
    {

    }

    void Blackjack::SetRules(int dealer_stops_on, int bank_per_player)
    {
        this->dealer_stops_on = dealer_stops_on;
        this->bank_per_player = bank_per_player;
    }

    int Blackjack::GetNumberOfPlayers()
    {
        return number_of_players;
    }

    void Blackjack::UpdateNumberOfPlayers()
    {
        number_of_players = players.size();
    }

    void Blackjack::AddPlayer(IPlayer player)
    {
        //if (players.count(player) == 0)
        //{
        //    players.insert(player);
        //}
        //else
        //{
        //    throw runtime_error("Could not insert a player!");
        //}

        if (true)
        {
            players.push_back(player);
        }
        else
        {
            throw runtime_error("Could not insert a player!");
        }
    }
