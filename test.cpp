#include "pch.h"
#include "../fortesting1/classes.cpp"

class fortesting1Test : public ::testing::Test
{};

matA* A;
matB* B;
int h;

TEST(fortesting1Test, CheckPar)
{
    int u = 3, y = 2;
    Par rect;
    rect.init(u, y);
    ASSERT_TRUE(rect.a == 3);
    ASSERT_TRUE(rect.b == 2);
}

TEST(fortesting1Test, CheckInitA)
{
    EXPECT_TRUE(A->AAA == 5);
}

TEST(fortesting1Test, CheckInitB)
{
    B->init(&h);
    ASSERT_NO_THROW(B);
}

TEST(fortesting1Test, CheckRrasA)
{
    A->Rras(h);
    EXPECT_LE(A->j, 1);
}

TEST(fortesting1Test, CheckRrasB)
{
    int t = B->Rras(h);
    EXPECT_GE(t, 21);
}



int main(int argc, char** argv)
{
    A = new matA;
    B = new matB;
    h = 0;
    A->init(&h);
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}