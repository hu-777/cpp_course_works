#include <gtest/gtest.h>
#include "ExecutorImp.h"

// ���Թ��캯����Ĭ�ϣ�0��0��N��
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

// ���Գ�ʼ������
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

//������ת����
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

//������ת����
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

//�����ƶ�����
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

//���Կ���ģʽ
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

// ����ִ�к���
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

