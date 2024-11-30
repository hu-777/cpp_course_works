#include "ExecutorImp.h"
#include "ICommand.h"
#include<memory>
using namespace std;

ExecutorImp::ExecutorImp()
{
    pose.x = 0;
    pose.y = 0;
    pose.heading = N;
    fast = false;
}

void ExecutorImp::init(int x, int y, Heading heading)
{
    pose.x = x;
    pose.y = y;
    pose.heading = heading;
    fast = false;
}

void ExecutorImp::getPosition(int& x, int& y, Heading& heading)
{
    x = pose.x;
    y = pose.y;
    heading = pose.heading;
}

void ExecutorImp::moveOneStep()
{
    switch (pose.heading) {
    case N:
        pose.y += 1;
        break;
    case S:
        pose.y -= 1;
        break;
    case E:
        pose.x += 1;
        break;
    case W:
        pose.x -= 1;
        break;
    default:
        break;
    }
}

void ExecutorImp::move()
{
    int step = fast ? 2 : 1;
    for (int i = 0; i < step; ++i) 
    {
        moveOneStep();
    }
}

void ExecutorImp::turnLeft()
{
    if (fast) 
    {
        moveOneStep();
    }
    pose.heading = static_cast<Heading>((pose.heading + 3) % 4);
}
void ExecutorImp::turnRight()
{
    if (fast) 
    {
        moveOneStep();
    }
    pose.heading = static_cast<Heading>((pose.heading + 1) % 4);
}

void ExecutorImp::fastMode()
{
    fast = !fast;
}

bool ExecutorImp::isFast()
{
    return fast;
}

void ExecutorImp::Execute(const string& commands)
{
    for(const auto& cmd:commands)
    {
        unique_ptr<ICommand> pcmd=nullptr;
        switch(cmd)
        {
            case 'M':
                pcmd=make_unique<MoveCommand>();
                break;
            case 'L':
                pcmd=make_unique<TurnLeftCommand>();
                break;
            case 'R':
                pcmd=make_unique<TurnRightCommand>();
                break;
            case 'F':
                pcmd=make_unique<FastCommand>();
                break;
            default:
                break;
        }
        if(pcmd)
        {
            pcmd->DoOperate(*this);
        }
    }
}