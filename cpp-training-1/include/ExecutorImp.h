#ifndef _EXECUTORIMP_H_
#define _EXECUTORIMP_H_

#include "executor.h"
#include "Pose.h"

class ExecutorImp final:public Executor
{
    private:
        Pose pose;
        bool fast;
        void moveOneStep();

    public:
        ExecutorImp();
        ~ExecutorImp() override {}
        void init(int x, int y, Heading heading) override;
        void getPosition(int &x, int &y, Heading &heading);
        void move() override;
        void turnLeft() override;
        void turnRight() override;
        void fastMode();
        bool isFast();
        void Execute(const string& commands);
};

#endif