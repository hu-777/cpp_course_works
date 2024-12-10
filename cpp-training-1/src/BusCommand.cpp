/*Bus车体较长，长度占2格，它的坐标是车头的坐标。为了行车安全，指令控制行为遵循下述描述：
+ M：前进，1次移动1格
+ L：先前进1格，再左转90度
+ R：先前进1格，再右转90度*/

#include "BusCommand.h"

void BusMoveCommand::DoOperate(PoseHandler& poseHandler) const noexcept
{
    poseHandler.Move();
}

void BusTurnLeftCommand::DoOperate(PoseHandler& poseHandler) const noexcept
{
    poseHandler.Move();
    poseHandler.TurnLeft();
}

void BusTurnRightCommand::DoOperate(PoseHandler& poseHandler) const noexcept
{
    poseHandler.Move();
    poseHandler.TurnRight();
}

void BusFastCommand::DoOperate(PoseHandler& poseHandler) const noexcept
{
    poseHandler.Fast();
}

void BusBackCommand::DoOperate(PoseHandler& poseHandler) const noexcept
{
    poseHandler.Back();
}

