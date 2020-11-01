#include "gtest/gtest.h"
#include "../Calc.h"

TEST(Calc, UsageTest)
{
    Calc c;
    ASSERT_EQ(c.add(1, 2), 3);
    ASSERT_EQ(c.subtract(3, 1), 2);
}

TEST(Calc, Addition)
{
    Calc c;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            ASSERT_EQ(c.add(i, j), i+j);
        }
    }
}

TEST(Calc, Subtraction)
{
    Calc c;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            ASSERT_EQ(c.subtract(i, j), i-j);
        }
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}