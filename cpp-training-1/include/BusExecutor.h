#ifndef BUSEXECUTOR_H
#define BUSEXECUTOR_H

#include "ExecutorImpl.h"
#include "BusCommand.h"
#include "Executor.h"

using namespace adas;

class BusExecutor : public ExecutorImpl
{
public:
    BusExecutor() noexcept {}
    BusExecutor(const Pose& pose) noexcept : ExecutorImpl(pose) {}
    ~BusExecutor() override {}
    void Execute(const string& commands);
};

#endif