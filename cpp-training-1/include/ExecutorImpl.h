#ifndef EXECUTORIMPI_H
#define EXECUTORIMPI_H

#include "Command.h"
#include "Executor.h"
#include "PoseHandler.h"
using namespace adas;

class ExecutorImpl :public Executor
{
    protected:
        PoseHandler poseHandler;
    public:
        ExecutorImpl()noexcept{}
        ExecutorImpl(const Pose& pose)noexcept:poseHandler(pose){}
        ~ExecutorImpl() override{}
        virtual void Execute(const string& commands);
        Pose Query() const noexcept;
};

#endif