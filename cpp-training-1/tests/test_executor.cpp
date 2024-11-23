#include <gtest/gtest.h>
#include "executor.h"

//���Թ��캯����Ĭ�ϣ�0��0��N��
TEST(ExecutorTest, Initialization) {
    Executor executor;
    int x, y;
    Heading heading;
    executor.getPosition(x, y, heading);
    EXPECT_EQ(x, 0);
    EXPECT_EQ(y, 0);
    EXPECT_EQ(heading, N);
}

//���Գ�ʼ������
TEST(ExecutorTest, InitFunction) {
    Executor executor;
    executor.init(5, 5, E);
    int x, y;
    Heading heading;
    executor.getPosition(x, y, heading);
    EXPECT_EQ(x, 5);
    EXPECT_EQ(y, 5);
    EXPECT_EQ(heading, E);
}

//�����ƶ�����
TEST(ExecutorTest, MoveFunction) {
    Executor executor;
    executor.init(0, 0, N);
    executor.move();
    int x, y;
    Heading heading;
    executor.getPosition(x, y, heading);
    EXPECT_EQ(x, 0);
    EXPECT_EQ(y, 1);
    EXPECT_EQ(heading, N);
}

//������ת����
TEST(ExecutorTest, TurnLeftFunction) {
    Executor executor;
    executor.init(0, 0, N);
    executor.turnLeft();
    int x, y;
    Heading heading;
    executor.getPosition(x, y, heading);
    EXPECT_EQ(heading, W);
}

//������ת����
TEST(ExecutorTest, TurnRightFunction) {
    Executor executor;
    executor.init(0, 0, N);
    executor.turnRight();
    int x, y;
    Heading heading;
    executor.getPosition(x, y, heading);
    EXPECT_EQ(heading, E);
}

//��������ָ��ִ��
TEST(ExecutorTest, ExecuteCommandsFunction) {
    Executor executor;
    executor.init(0, 0, N);
    executor.executeCommands("MRMLM");
    int x, y;
    Heading heading;
    executor.getPosition(x, y, heading);
    EXPECT_EQ(x, 1);
    EXPECT_EQ(y, 2);
    EXPECT_EQ(heading, N);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}