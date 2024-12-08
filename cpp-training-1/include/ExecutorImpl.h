#ifndef EXECUTORIMPI_H
#define EXECUTORIMPI_H

#include "PoseHandler.h"
#include "Executor.h"
using namespace adas;

class ExecutorImpl final:public Executor
{
    private:
        PoseHandler poseHandler;
    public:
        ExecutorImpl()noexcept{}
        ExecutorImpl(const Pose& pose)noexcept:poseHandler(pose){}
        ~ExecutorImpl() override{}
        void Execute(const string& commands);
        Pose Query() const noexcept;
};

#endif