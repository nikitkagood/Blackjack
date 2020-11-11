#include "IPlayer.h"
#include "Dealer.h"

using namespace std;

     IPlayer::IPlayer()
    {
        //#ifdef DEBUG
        //        cout << "IPlayer constructor" << endl;
        //#endif // DEBUG

        JoinGame();
        SetName("Player " + player_number);
    }

     IPlayer::IPlayer(string name)
    {
        //#ifdef DEBUG
        //        cout << "IPlayer constructor" << endl;
        //#endif // DEBUG
        JoinGame();
        SetName(name);
    }

    unsigned int IPlayer::bet(unsigned int ammount)
    {
        if (bank > ammount)
        {
            bank -= ammount;
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

    void IPlayer::MakeGameDecision(const Dealer& d)
    {
        cin >> game_decision;
        if (game_decision == "Hit" || game_decision == "hit")
        {
            
        }
        else if (game_decision == "Stand" || game_decision == "stand")
        {

        }
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



