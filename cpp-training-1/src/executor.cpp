#include "executor.h"

Executor::Executor()
{
    x = 0;
    y = 0;
    heading = N;
}
void Executor::init(int x, int y, Heading heading)
{
    this->x = x;
    this->y = y;
    this->heading = heading;
}

void Executor::move()
{
    switch (heading) {
    case N:
        y += 1;
        break;
    case S:
        y -= 1;
        break;
    case E:
        x += 1;
        break;
    case W:
        x -= 1;
        break;
    default:
        break;
    }
}

void Executor::turnLeft()
{
    switch (heading) {
    case N:
        heading = W;
        break;
    case S:
        heading = E;
        break;
    case W:
        heading = S;
        break;
    case E:
        heading = N;
        break;
    default:
        break;
    }
}
void Executor::turnRight()
{
    switch (heading) {
    case N:
        heading = E;
        break;
    case S:
        heading = W;
        break;
    case W:
        heading = N;
        break;
    case E:
        heading = S;
        break;
    default:
        break;
    }
}
void Executor::executeCommands(const string &commands)
{
    for (char command : commands) {
        switch (command) {
        case 'M':
            move();
            break;
        case 'L':
            turnLeft();
            break;
        case 'R':
            turnRight();
            break;
        default:
            break;
        }
    }
}
void Executor::getPosition(int &x, int &y, Heading &heading)
{
    x = this->x;
    y = this->y;
    heading = this->heading;
}