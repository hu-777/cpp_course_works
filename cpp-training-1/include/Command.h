#ifndef COMMAND_H
#define COMMAND_H

#include "PoseHandler.h"
using namespace adas;

class ICommand
{
public:
    virtual ~ICommand() = default;
    virtual void DoOperate(PoseHandler& poseHandler) const noexcept = 0;
};

class MoveCommand : public ICommand
{
public:
    void DoOperate(PoseHandler& poseHandler) const noexcept override;
};

class TurnLeftCommand : public ICommand
{
public:
    void DoOperate(PoseHandler& poseHandler) const noexcept override;
};

class TurnRightCommand : public ICommand
{
public:
    void DoOperate(PoseHandler& poseHandler) const noexcept override;
};

class FastCommand : public ICommand
{
public:
    void DoOperate(PoseHandler& poseHandler) const noexcept override;
};

class BackCommand : public ICommand
{
public:
    void DoOperate(PoseHandler& poseHandler) const noexcept override;
};

#endif