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
    heading = static_cast<Heading>((heading +3) % 4);
}
void Executor::turnRight()
{
    heading = static_cast<Heading>((heading + 1) % 4);
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