#include <gtest/gtest.h>
#include "SportsCarExecutor.h"
using namespace adas;

TEST(SportsCarExecutorTest, Initialization)
{
    SportsCarExecutor sportsCarExecutor;
    Pose pose = sportsCarExecutor.Query();
    EXPECT_EQ(pose, Pose(0, 0, N));
}

TEST(SportsCarExecutorTest, Move)
{
    SportsCarExecutor sportsCarExecutor(Pose(0, 0, N));
    sportsCarExecutor.Execute("M");
    Pose pose = sportsCarExecutor.Query();
    EXPECT_EQ(pose.x, 0);
    EXPECT_EQ(pose.y, 2);
    EXPECT_EQ(pose.heading, N);
}

TEST(SportsCarExecutorTest, TurnLeft)
{
    SportsCarExecutor sportsCarExecutor(Pose(0, 0, N));
    sportsCarExecutor.Execute("L");
    Pose pose = sportsCarExecutor.Query();
    EXPECT_EQ(pose.x, -1);
    EXPECT_EQ(pose.y, 0);
    EXPECT_EQ(pose.heading, W);
}

TEST(SportsCarExecutorTest, TurnRight)
{
    SportsCarExecutor sportsCarExecutor(Pose(0, 0, N));
    sportsCarExecutor.Execute("R");
    Pose pose = sportsCarExecutor.Query();
    EXPECT_EQ(pose.x, 1);
    EXPECT_EQ(pose.y, 0);
    EXPECT_EQ(pose.heading, E);
}

TEST(SportsCarExecutorTest, Fast)
{
    SportsCarExecutor sportsCarExecutor(Pose(0, 0, N));
    sportsCarExecutor.Execute("F");
    sportsCarExecutor.Execute("M");
    Pose pose = sportsCarExecutor.Query();
    EXPECT_EQ(pose.x, 0);
    EXPECT_EQ(pose.y, 4);
    EXPECT_EQ(pose.heading, N);
}

TEST(SportsCarExecutorTest, Back)
{
    SportsCarExecutor sportsCarExecutor(Pose(0, 0, N));
    sportsCarExecutor.Execute("B");
    sportsCarExecutor.Execute("M");
    Pose pose = sportsCarExecutor.Query();
    EXPECT_EQ(pose.x, 0);
    EXPECT_EQ(pose.y, -2);
    EXPECT_EQ(pose.heading, N);
}

TEST(SportsCarExecutorTest, Complex)
{
    SportsCarExecutor sportsCarExecutor(Pose(0, 0, N));
    sportsCarExecutor.Execute("FMLMRBMBFM");
    Pose pose = sportsCarExecutor.Query();
    EXPECT_EQ(pose.x, -7);
    EXPECT_EQ(pose.y, 5);
    EXPECT_EQ(pose.heading, N);
}