#include <gtest/gtest.h>
#include "ExecutorImp.h"

// 测试构造函数，默认（0，0，N）
TEST(ExecutorImpTest, Initialization)
{
    ExecutorImp executor;
    int x,y;
    Heading heading;
    executor.getPosition(x, y, heading);
    EXPECT_EQ(x, 0);
    EXPECT_EQ(y, 0);
    EXPECT_EQ(heading, N);
}

// 测试初始化函数
TEST(ExecutorImpTest, Init)
{
    ExecutorImp executor;
    int x,y;
    Heading heading;
    executor.init(5, 5, E);
    executor.getPosition(x, y, heading);
    EXPECT_EQ(x, 5);
    EXPECT_EQ(y, 5);
    EXPECT_EQ(heading, E);
}

//测试左转函数
TEST(ExecutorImpTest, TurnLeft)
{
    ExecutorImp executor;
    int x,y;
    Heading heading;
    executor.init(0, 0, N);
    executor.turnLeft();
    executor.getPosition(x, y, heading);
    EXPECT_EQ(x, 0);
    EXPECT_EQ(y, 0);
    EXPECT_EQ(heading, W);
}

//测试右转函数
TEST(ExecutorImpTest, TurnRight)
{
    ExecutorImp executor;
    int x,y;
    Heading heading;
    executor.init(0, 0, N);
    executor.turnRight();
    executor.getPosition(x, y, heading);
    EXPECT_EQ(x, 0);
    EXPECT_EQ(y, 0);
    EXPECT_EQ(heading, E);
}

//测试移动函数
TEST(ExecutorImpTest, Move)
{
    ExecutorImp executor;
    int x,y;
    Heading heading;
    executor.init(0, 0, N);
    executor.move();
    executor.getPosition(x, y, heading);
    EXPECT_EQ(x, 0);
    EXPECT_EQ(y, 1);
    EXPECT_EQ(heading, N);
}

//测试快速模式
TEST(ExecutorImpTest, FastMode)
{
    ExecutorImp executor;
    int x,y;
    Heading heading;
    executor.init(0, 0, N);
    executor.fastMode();
    executor.move();
    executor.getPosition(x, y, heading);
    EXPECT_EQ(x, 0);
    EXPECT_EQ(y, 2);
    EXPECT_EQ(heading, N);
}

// 测试执行函数
TEST(ExecutorImpTest, Execute)
{
    ExecutorImp executor;
    int x,y;
    Heading heading;
    executor.init(0, 0, N);
    executor.Execute("FMLMLMRFM");
    executor.getPosition(x, y, heading);
    EXPECT_EQ(x, -4);
    EXPECT_EQ(y, 0);
    EXPECT_EQ(heading, W);
}

