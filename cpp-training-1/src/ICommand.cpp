#include "ICommand.h"

void MoveCommand::DoOperate(ExecutorImp& executor) const noexcept
{
    executor.move();
}

void TurnLeftCommand::DoOperate(ExecutorImp& executor) const noexcept
{
    executor.turnLeft();
}

void TurnRightCommand::DoOperate(ExecutorImp& executor) const noexcept
{
    executor.turnRight();
}

void FastCommand::DoOperate(ExecutorImp& executor) const noexcept
{
    executor.fastMode();
}
