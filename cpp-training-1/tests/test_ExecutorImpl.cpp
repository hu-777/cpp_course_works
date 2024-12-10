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

// ���Թ��캯����Ĭ�ϣ�0��0��N��
TEST(ExecutorImplTest, Initialization)
{
    ExecutorImpl executor;
    Pose pose = executor.Query();
    EXPECT_EQ(pose, Pose(0, 0, N));
}

//����Move
TEST(ExecutorImplTest, Move)
{
    ExecutorImpl executor(Pose(0, 0, N));
    executor.Execute("M");
    Pose pose = executor.Query();
    EXPECT_EQ(pose.x, 0);
    EXPECT_EQ(pose.y, 1);
    EXPECT_EQ(pose.heading, N);
}

// ���Ե���
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

//���Ե���+��ת
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

//���Ե���+��ת
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

// ���Ե���+����
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

// ���Զ���ָ����
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