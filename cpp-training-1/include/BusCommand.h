#ifndef BUSCOMMAND_H
#define BUSCOMMAND_H

#include "PoseHandler.h"
using namespace adas;

class BusCommand
{
public:
    virtual ~BusCommand() = default;
    virtual void DoOperate(PoseHandler& poseHandler) const noexcept = 0;
};

class BusMoveCommand : public BusCommand
{
public:
    void DoOperate(PoseHandler& poseHandler) const noexcept override;
};

class BusTurnLeftCommand : public BusCommand
{
public:
    void DoOperate(PoseHandler& poseHandler) const noexcept override;
};

class BusTurnRightCommand : public BusCommand
{
public:
    void DoOperate(PoseHandler& poseHandler) const noexcept override;
};

class BusFastCommand : public BusCommand
{
public:
    void DoOperate(PoseHandler& poseHandler) const noexcept override;
};

class BusBackCommand : public BusCommand
{
public:
    void DoOperate(PoseHandler& poseHandler) const noexcept override;
};

#endif