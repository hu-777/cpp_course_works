#ifndef SPORTSCAREXECUTOR_H
#define SPORTSCAREXECUTOR_H

#include "ExecutorImpl.h"
#include "SportsCarCommand.h"
#include "Executor.h"

using namespace adas;

class SportsCarExecutor : public ExecutorImpl
{
    public:
        SportsCarExecutor() noexcept {}
        SportsCarExecutor(const Pose& pose) noexcept : ExecutorImpl(pose) {}
        ~SportsCarExecutor() override {}
        void Execute(const string& commands);
};

#endif