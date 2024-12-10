#include <gtest/gtest.h>
#include "BusExecutor.h"
using namespace adas;

TEST(BusExecutorTest,Initialization)
{
    BusExecutor busExecutor;
    Pose pose = busExecutor.Query();
    EXPECT_EQ(pose, Pose(0, 0, N));
}

TEST(BusExecutorTest,Move)
{
    BusExecutor busExecutor(Pose(0, 0, N));
    busExecutor.Execute("M");
    Pose pose = busExecutor.Query();
    EXPECT_EQ(pose.x, 0);
    EXPECT_EQ(pose.y, 1);
    EXPECT_EQ(pose.heading, N);
}

TEST(BusExecutorTest,TurnLeft)
{
    BusExecutor busExecutor(Pose(0, 0, N));
    busExecutor.Execute("L");
    Pose pose = busExecutor.Query();
    EXPECT_EQ(pose.x, 0);
    EXPECT_EQ(pose.y, 1);
    EXPECT_EQ(pose.heading, W);
}

TEST(BusExecutorTest,TurnRight)
{
    BusExecutor busExecutor(Pose(0, 0, N));
    busExecutor.Execute("R");
    Pose pose = busExecutor.Query();
    EXPECT_EQ(pose.x, 0);
    EXPECT_EQ(pose.y, 1);
    EXPECT_EQ(pose.heading, E);
}

TEST(BusExecutorTest,Fast)
{
    BusExecutor busExecutor(Pose(0, 0, N));
    busExecutor.Execute("F");
    busExecutor.Execute("M");
    Pose pose = busExecutor.Query();
    EXPECT_EQ(pose.x, 0);
    EXPECT_EQ(pose.y, 2);
    EXPECT_EQ(pose.heading, N);
}

TEST(BusExecutorTest,Back)
{
    BusExecutor busExecutor(Pose(0, 0, N));
    busExecutor.Execute("B");
    busExecutor.Execute("M");
    Pose pose = busExecutor.Query();
    EXPECT_EQ(pose.x, 0);
    EXPECT_EQ(pose.y, -1);
    EXPECT_EQ(pose.heading, N);
}

TEST(BusExecutorTest,Complex)
{
    BusExecutor busExecutor(Pose(0, 0, N));
    busExecutor.Execute("FMLBRMBM");
    Pose pose = busExecutor.Query();
    EXPECT_EQ(pose.x, 3);
    EXPECT_EQ(pose.y, 5);
    EXPECT_EQ(pose.heading, S);
}