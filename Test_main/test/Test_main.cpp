//Testing the program with googletest library

#include "gtest/gtest.h"
#include "../../Blackjack.h"
#include "../../IPlayer.h" 
#include "../../Dealer.h"


TEST(Blackjack, AceScoreTest)
{
    Blackjack bj;
    bj.SetRules(17, 100);

    Dealer d(bj);

    IPlayer p1(bj, "TestPlayer1");

    bj.CountRound();

    p1.GetHandLink().push_back({ "Ace", "spades" });
    p1.GetHandLink().push_back({ "Queen", "hearts" });

    p1.ShowCards();

    int score = d.CountScore(p1);
    int expected_score = 21;

    cout << "Score: " << score << "   Expected score: " << expected_score << endl;
    ASSERT_EQ(score, expected_score);
}

TEST(Blackjack, AceScoreTest2)
{
    Blackjack bj;
    bj.SetRules(17, 100);

    Dealer d(bj);

    IPlayer p1(bj, "TestPlayer1");

    bj.CountRound();

    p1.GetHandLink().push_back({ "Ace", "spades" });
    p1.GetHandLink().push_back({ "Ace", "spades" });
    p1.GetHandLink().push_back({ "Queen", "hearts" });

    p1.ShowCards();

    int score = d.CountScore(p1);
    int expected_score = 12;

    cout << "Score: " << score << "   Expected score: " << expected_score << endl;
    ASSERT_EQ(score, expected_score);
}

TEST(Blackjack, AceScoreTest3)
{
    Blackjack bj;
    bj.SetRules(17, 100);

    Dealer d(bj);

    IPlayer p1(bj, "TestPlayer1");

    bj.CountRound();

    p1.GetHandLink().push_back({ "Ace", "spades" });
    p1.GetHandLink().push_back({ "Ace", "spades" });
    p1.GetHandLink().push_back({ "8", "hearts" });

    p1.ShowCards();

    int score = d.CountScore(p1);
    int expected_score = 20;

    cout << "Score: " << score << "   Expected score: " << expected_score << endl;
    ASSERT_EQ(score, expected_score);
}

TEST(Blackjack, AceScoreTest4)
{
    Blackjack bj;
    bj.SetRules(17, 100);

    Dealer d(bj);

    IPlayer p1(bj, "TestPlayer1");

    bj.CountRound();

    p1.GetHandLink().push_back({ "King", "spades" });
    p1.GetHandLink().push_back({ "2", "spades" });
    p1.GetHandLink().push_back({ "Queen", "hearts" });

    p1.ShowCards();

    int score = d.CountScore(p1);
    int expected_score = 22;

    cout << "Score: " << score << "   Expected score: " << expected_score << endl;
    ASSERT_EQ(score, expected_score);
}

//Examples of tests
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