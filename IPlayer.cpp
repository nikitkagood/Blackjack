#include "IPlayer.h"
#include "Dealer.h"

using namespace std;

IPlayer::IPlayer()
{
    //только для Dealer
}

IPlayer::IPlayer(Blackjack& bj)
    {
        //#ifdef DEBUG
        //        cout << "IPlayer constructor" << endl;
        //#endif // DEBUG

        //JoinGame();
        SetName("Player " + to_string(player_number));
        bank = bj.GetBankPerPlayer();

    }

     IPlayer::IPlayer(Blackjack& bj, string name)
    {
        //#ifdef DEBUG
        //        cout << "IPlayer constructor" << endl;
        //#endif // DEBUG

        //JoinGame();
        SetName(name);
        bank = bj.GetBankPerPlayer();
    }

    unsigned int IPlayer::bet()
    {
        cout << "Enter yor bet: ";
        unsigned int ammount;
        cin >> ammount;
        if (bank > ammount)
        {
            bank -= ammount;
            cout << "Your bet is " << ammount << endl;
            return ammount;
        }
        else
        {
            cout << "You don't have that much" << endl;
            return 0;
        }
    }
    void IPlayer::bet_double()
    {

    }

    void IPlayer::Hold()
    {

    }

    void IPlayer::Hit()
    {

    }

    string IPlayer::MakeGameDecision(Dealer& d, IPlayer& player_himself)
    {
        cin >> game_decision;
        d.ReceiveGameDecision(game_decision, player_himself);

        return game_decision;
    }

    //string IPlayer::GameDecision(string decision) const
    //{
    //    for (auto i : game_decisions)
    //    {
    //        if (decision == i.second) return i.second;
    //    }
    //    //else
    //    return "-99";
    //}
    //int IPlayer::GameDecision(int decision) const
    //{
    //    for (auto i : game_decisions)
    //    {
    //        if (decision == i.first) return i.first;
    //    }
    //    //else
    //    return -99;
    //}

    void IPlayer::JoinGame()
    {

    }

    void IPlayer::ReceiveCard(const pair<string, string>& to_receive)
    {

        hand.push_back(to_receive);

    }

    void IPlayer::ShowCards() const
    {
        for (auto i : hand)
        {
            cout << i.first << " of " << i.second << endl;
        }
    }

    void IPlayer::ShowGameDecisions() const
    {
        for (auto i : game_decisions)
        {
            cout << i.first << ". " << i.second << ' ';
        }
    }

    const vector<pair<string, string>> IPlayer::GetHand() const
    {
        return hand;
    }

    //void TakeCard()
    //{

    //}

    void IPlayer::loseGame(Blackjack bj)
    {
        if (true) LeaveGame(bj);
    }

    void IPlayer::LeaveGame(Blackjack bj)
    {
        //удалить из контейнера игроков
    }



    string IPlayer::SetName(string name)
    {
        return this->name = name;
    }



