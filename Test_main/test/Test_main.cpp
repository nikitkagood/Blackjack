//Testing the program with googletest library
#define TESTING

#include "gtest/gtest.h"
#include "../../Blackjack.h"
#include "../../IPlayer.h"
#include "../../Dealer.h"

TEST(Blackjack, CardScoreTest)
{
    Blackjack bj;
    //bj.SetRules(17, 100);

    //Dealer d(bj);
    //IPlayer p1(bj, "TestPlayer1");

    //d.CountScore(p1);

}

//TEST(Calc, Addition)
//{
//    Calc c;
//    for (int i = 0; i < 10; i++)
//    {
//        for (int j = 0; j < 10; j++)
//        {
//            ASSERT_EQ(c.add(i, j), i + j);
//        }
//    }
//}
//
//TEST(Calc, Subtraction)
//{
//    Calc c;
//    for (int i = 0; i < 10; i++)
//    {
//        for (int j = 0; j < 10; j++)
//        {
//            ASSERT_EQ(c.subtract(i, j), i - j);
//        }
//    }
//}
//
int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}