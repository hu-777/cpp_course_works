#include <gtest/gtest.h>

#include "ExecutorImpl.h"
using namespace adas;

TEST(ExecutorImplTest, 1)
{
    PoseHandler poseHandler;
    MoveCommand moveCommand;
    moveCommand.DoOperate(poseHandler);
    Pose pose = poseHandler.Query();
    EXPECT_EQ(pose, Pose(0, 1, N));
}

TEST(ExecutorImplTest, 2)
{
    ExecutorImpl executor;
    executor.Execute("M");
    Pose pose = executor.Query();
    EXPECT_EQ(pose, Pose(0, 1, N));
}

// 测试构造函数，默认（0，0，N）
TEST(ExecutorImplTest, Initialization)
{
    ExecutorImpl executor;
    Pose pose = executor.Query();
    EXPECT_EQ(pose, Pose(0, 0, N));
}

//测试Move
TEST(ExecutorImplTest, Move)
{
    ExecutorImpl executor(Pose(0, 0, N));
    executor.Execute("M");
    Pose pose = executor.Query();
    EXPECT_EQ(pose.x, 0);
    EXPECT_EQ(pose.y, 1);
    EXPECT_EQ(pose.heading, N);
}

// 测试倒车
TEST(ExecutorImplTest, Back)
{
    ExecutorImpl executor(Pose(0, 0, N));
    executor.Execute("B");
    executor.Execute("M");
    Pose pose = executor.Query();
    EXPECT_EQ(pose.x,0);
    EXPECT_EQ(pose.y,-1);
    EXPECT_EQ(pose.heading,N);
}

//测试倒车+左转
TEST(ExecutorImplTest, BackAndLeft)
{
    ExecutorImpl executor(Pose(0, 0, N));
    executor.Execute("BL");
    executor.Execute("M");
    Pose pose = executor.Query();
    EXPECT_EQ(pose.x,-1);
    EXPECT_EQ(pose.y,0);
    EXPECT_EQ(pose.heading,E);
}

//测试倒车+右转
TEST(ExecutorImplTest, BackAndRight)
{
    ExecutorImpl executor(Pose(0, 0, N));
    executor.Execute("BR");
    executor.Execute("M");
    Pose pose = executor.Query();
    EXPECT_EQ(pose.x,1);
    EXPECT_EQ(pose.y,0);
    EXPECT_EQ(pose.heading,W);
}

// 测试倒车+快速
TEST(ExecutorImplTest, BackAndFast)
{
    ExecutorImpl executor(Pose(0, 0, N));
    executor.Execute("BF");
    executor.Execute("M");
    Pose pose = executor.Query();
    EXPECT_EQ(pose.x,0);
    EXPECT_EQ(pose.y,-2);
    EXPECT_EQ(pose.heading,N);
}

// 测试多条指令混合
TEST(ExecutorImplTest, MixCommands)
{
    ExecutorImpl executor(Pose(0, 0, N));
    executor.Execute("FMLMLRBRFMBM");
    Pose pose = executor.Query();
    EXPECT_EQ(pose.x,-2);
    EXPECT_EQ(pose.y,2);
    EXPECT_EQ(pose.heading,S);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}