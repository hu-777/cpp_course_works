#ifndef SPORTSCARCOMMAND_H
#define SPORTSCARCOMMAND_H

#include "PoseHandler.h"
using namespace adas;

class SportsCarCommand
{
public:
    virtual ~SportsCarCommand() = default;
    virtual void DoOperate(PoseHandler& poseHandler) const noexcept = 0;
};

class SportsCarMoveCommand : public SportsCarCommand
{
public:
    void DoOperate(PoseHandler& poseHandler) const noexcept override;
};

class SportsCarTurnLeftCommand : public SportsCarCommand
{
public:
    void DoOperate(PoseHandler& poseHandler) const noexcept override;
};

class SportsCarTurnRightCommand : public SportsCarCommand
{
public:
    void DoOperate(PoseHandler& poseHandler) const noexcept override;
};

class SportsCarFastCommand : public SportsCarCommand
{
public:
    void DoOperate(PoseHandler& poseHandler) const noexcept override;
};

class SportsCarBackCommand : public SportsCarCommand
{
public:
    void DoOperate(PoseHandler& poseHandler) const noexcept override;
};

#endif