// 智能车控制系统
#ifndef _CAR_H_
#define _CAR_H_

#include "Heading.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 执行器类Executor
class Executor
{
    private:
        int x, y;
        Heading heading;

    public:
        Executor();
        virtual ~Executor(){}
        virtual void init(int x, int y, Heading heading);
        virtual void move();
        virtual void turnLeft();
        virtual void turnRight();
        virtual void executeCommands(const string &commands);
        virtual void getPosition(int &x, int &y, Heading &heading);
};

#endif
