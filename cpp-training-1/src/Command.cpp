#include "Command.h"
#include "PoseHandler.h"

void MoveCommand::DoOperate(PoseHandler& poseHandler) const noexcept
{
    poseHandler.Move();
}

void TurnLeftCommand::DoOperate(PoseHandler& poseHandler) const noexcept
{
    poseHandler.TurnLeft();
}

void TurnRightCommand::DoOperate(PoseHandler& poseHandler) const noexcept
{
    poseHandler.TurnRight();
}

void FastCommand::DoOperate(PoseHandler& poseHandler) const noexcept
{
    poseHandler.Fast();
}

void BackCommand::DoOperate(PoseHandler& poseHandler) const noexcept
{
    poseHandler.Back();
}