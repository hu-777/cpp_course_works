// ���ܳ�����ϵͳ
#ifndef _CAR_H_
#define _CAR_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// headingö������
enum Heading { N, S, E, W };

// ִ������Executor
class Executor
{
    private:
        int x, y;
        Heading heading;

    public:
        Executor();
        void init(int x, int y, Heading heading);
        void move();
        void turnLeft();
        void turnRight();
        void executeCommands(const string &commands);
        void getPosition(int &x, int &y, Heading &heading);
};

#endif
