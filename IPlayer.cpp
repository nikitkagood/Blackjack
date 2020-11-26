#include "IPlayer.h"
#include "Dealer.h"

using namespace std;

IPlayer::IPlayer()
{
    //только для Dealer
}

//IPlayer::IPlayer(Blackjack& bj)
//    {
//        //#ifdef DEBUG
//        //        cout << "IPlayer constructor" << endl;
//        //#endif // DEBUG
//
//        //JoinGame();
//        SetName("Player_" + to_string(bj.players.size() ));
//        bank = bj.GetBankPerPlayer();
//        bj.AddPlayer(*this);
//        
//
//    }

     IPlayer::IPlayer(Blackjack& bj, const string& name)
    {
        //#ifdef DEBUG
        //        cout << "IPlayer constructor" << endl;
        //#endif // DEBUG

        //JoinGame();
        SetName(name);
        bank = bj.GetBankPerPlayer();
        bj.AddPlayer(this);
    }


     IPlayer& IPlayer::operator=(const IPlayer& player)
     {
         this->name = player.name;
         this->bank = player.bank;
         this->hand = player.hand;
         //this->game_decision = player.game_decision;
         return *this;
     }

    unsigned int IPlayer::bet()
    {
        //cout << "Your bank is: " << GetBank() << endl;
        cout << GetName() << " has: " << GetBank() << " chips" << endl;
        cout << "Enter yor bet: ";
        unsigned int ammount;
        cin >> ammount;
        if (ammount == 0)
        {
            cout << "You can't bet nothing" << endl;
            cout << endl;
            return 0;
        }
        else if (bank >= ammount)
        {
            bank -= ammount;
            cout << "Your bet is " << ammount << endl;
            cout << endl;
            return ammount;
        }
        else
        {
            cout << "You don't have that much" << endl;
            cout << endl;
            return 0;
        }
    }

    void IPlayer::bet_double(Dealer d, unsigned int player_number)
    {
        unsigned int bet = d.players_current_bets[player_number];
        if (bank >= bet * 2)
        {
            //Updated player's bank
            bank -= bet;
            //Updating bets
            d.players_current_bets[player_number] *= 2;

            cout << IPlayer::GetName() << " betted double" << endl;
            cout << endl;
        }
        else
        {
            cout << "You don't have that much" << endl;
        }

    }

    void IPlayer::make_insurance()
    {
        unsigned int insurance = (current_bet * 0.5);

        if (bank >= insurance)
        {
            //обновляем банк игрока
            bank -= insurance;
            //обновляем ставки
            insurance_bet += insurance;

            cout << IPlayer::GetName() << " made insurance" << endl;
            cout << endl;
        }
        else
        {
            cout << "You don't have that much" << endl;
        }
    }

    void IPlayer::MakeGameDecision(Dealer& d, const unsigned int& player_number)
    {
        string game_decision;

        do
        {
            cin >> game_decision;
            cout << endl;
        } 
        while (!d.ReceiveGameDecision(game_decision, *this, player_number));
        //если функция возвращает true, то выход из цикла

    }

    void IPlayer::MakeInsuranceDecision()
    {
        string game_decision;

        cout << "Do you want to make isurance? " << endl;
        cout << "Y or N: ";
        cin >> game_decision;
        cout << endl;

        while (true)
        {
            if (game_decision == "Y" || game_decision == "y" || game_decision == "yes" || game_decision == "Yes")
            {
                make_insurance();
                break;
            }
            else if (game_decision == "N" || game_decision == "n" || game_decision == "no" || game_decision == "No")
            {
                //nothing
                break;
            }
            else
            {
                cout << "Wrong command" << endl;
            }
        }

    }

    void IPlayer::JoinGame()
    {

    }

    unsigned int IPlayer::GetInsuranceBet() const
    {
        return insurance_bet;
    }

    void IPlayer::ReceiveCard(const pair<string, string>& to_receive)
    {

        hand.push_back(to_receive);

    }

    void IPlayer::ShowCards() const
    {
        cout << GetName() << " has: " << endl;
        for (auto i : hand)
        {
            cout << i.first << " of " << i.second << endl;
        }
        cout << endl;
    }

    void IPlayer::ShowGameDecisions() const
    {
        for (auto i : game_decisions)
        {
            cout << i.first << ". " << i.second << "   ";
        }
        cout << endl;
    }

    const vector<pair<string, string>> IPlayer::GetHand() const
    {
        return hand;
    }

    vector<pair<string, string>>& IPlayer::GetHandLink()
    {
        return hand;
    }

    const string IPlayer::GetName() const
    {
        return name;
    }

    const unsigned int IPlayer::GetBank() const
    {
        return bank;
    }


    //void IPlayer::loseGame(Blackjack bj)
    //{
    //    if (true) LeaveGame(bj);
    //}

    void IPlayer::LeaveGame(Blackjack bj)
    {
        //удалить из контейнера игроков
        //bj.players.erase(bj.players.begin());
    }



    string IPlayer::SetName(string name)
    {
        return this->name = name;
    }

    void IPlayer::ChangeBank(const int& ammount)
    {
        bank += ammount;
    }

    void IPlayer::Reset()
    {
        hand.clear();
        current_bet = 0;
        insurance_bet = 0;
    }






