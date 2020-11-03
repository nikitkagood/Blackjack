#include <iostream>
#include <stdexcept>
#include <map>
#include <vector>

using namespace std;

class Blackjack
{
public:
    Blackjack()
    {
        Dealer d;
        gameLoop();
    }

    int gameLoop()
    {
        while (true)
        {
            if (true) number_of_players++;
        }

        return -99;
    }

    void showCards()
    {

    }

    void setRules(int dealer_stops_on, int bank_per_player)
    {
        this->dealer_stops_on = dealer_stops_on;
        this->bank_per_player = bank_per_player;
    }

private:
    //The order: clubs, diamonds, hearts, spades
    //map<string, string> deck
    //{
    //    {"2C", "2 of clubs"},
    //    {"3C", "3 of clubs"},
    //    {"4C", "4 of clubs"},
    //    {"5C", "5 of clubs"},
    //    {"6C", "6 of clubs"},
    //    {"7C", "7 of clubs"},
    //    {"7C", "7 of clubs"},
    //    {"9C", "9 of clubs"},
    //    {"10C", "10 of clubs"},
    //    {"JackC", "Jack of clubs"},
    //    {"QueenC", "Queen of clubs"},
    //    {"KingC", "King of clubs"},
    //    {"AceC", "Ace of clubs"}
    //};

    map<string, int> deck_template
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

    map<string, map<string, int>> deck
    {
        { "clubs", deck_template },
        { "diamonds", deck_template },
        { "hearts", deck_template },
        { "spades", deck_template },

    };



    //default rules
    unsigned int dealer_stops_on = 17;
    unsigned int bank_per_player = 100;
    const unsigned int max_number_of_players = 7;
    unsigned int number_of_players = 0;
};

class Player : public Blackjack
{
protected:
    virtual string setName(string name)
    {
        
    }

    virtual void bet()
    {

    }
    virtual void bet_double()
    {

    }
    void takeCard()
    {

    }
    void hold()
    {

    }

    void joinGame()
    {

    }
    
    void loseGame()
    {

    }

    void leaveGame()
    {

    }

    string name;
    unsigned int player_number = 1; //номер игрока
    unsigned int bank = 0; //кол-во фишек
    vector<string> hand; //рука 

private:
};

class Dealer : public Player
{
public:
    void giveCard()
    {
        //if takeCard, then giveCard
    }
private:

};

class HumanPlayer : public Player
{
public:
    HumanPlayer()
    {
        joinGame();
        setName("Player");
    }    

    HumanPlayer(string name)
    {
        joinGame();
        setName(name);
    }

    virtual string setName(string name) override
    {
        return this->name = name;
    }

    virtual void bet() override
    {

    }
    virtual void bet_double() override
    {

    }

private:
    
};


class AI_Player : public Player
{
public:
    virtual void bet() override
    {

    }
    virtual void bet_double() override
    {

    }

private:
    
};


int main()
{
    try
    {
        Blackjack bj;
        bj.setRules(17, 100);


    }
    catch (const runtime_error& re)
    {
        cerr << re.what() << endl;
    }


    return 0;
}
