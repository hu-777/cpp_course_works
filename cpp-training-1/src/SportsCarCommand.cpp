/*速度很快，指令控制行为遵循下述描述：
+ M：前进，1次移动2格(先前进1格再前进1格)
+ L：先左转90度，再前进1格
+ R：先右转90度，再前进1格*/

#include "SportsCarCommand.h"

void SportsCarMoveCommand::DoOperate(PoseHandler& poseHandler) const noexcept
{
    int step=2;
    for(int i=0;i<step;i++)
    {
        poseHandler.Move();
    }
}

void SportsCarTurnLeftCommand::DoOperate(PoseHandler& poseHandler) const noexcept
{
    poseHandler.TurnLeft();
    poseHandler.Move();
}

void SportsCarTurnRightCommand::DoOperate(PoseHandler& poseHandler) const noexcept
{
    poseHandler.TurnRight();
    poseHandler.Move();
}

void SportsCarFastCommand::DoOperate(PoseHandler& poseHandler) const noexcept
{
    poseHandler.Fast();
}

void SportsCarBackCommand::DoOperate(PoseHandler& poseHandler) const noexcept
{
    poseHandler.Back();
}

