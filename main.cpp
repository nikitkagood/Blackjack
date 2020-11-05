#include <iostream>
#include <stdexcept>
#include <map>
#include <vector>

#define DEBUG

#include "Blackjack.h"
#include "Player.h"
#include "Dealer.h"
#include "HumanPlayer.h"
#include "AI_Player.h"


using namespace std;

void playerJoin()
{

}

int main()
{
    try
    {
        while (true)
        {
            Blackjack bj;
            bj.setRules(17, 100);
            HumanPlayer p1;

            break;
        }
        return -99;


    }
    catch (const runtime_error& re)
    {
        cerr << re.what() << endl;
    }


    return 0;
}
