#ifndef ICOMMAND_H
#define ICOMMAND_H

#include "ExecutorImp.h"

class ICommand
{
    public:
        virtual ~ICommand()=default;
        virtual void DoOperate(ExecutorImp& executor) const noexcept=0;
};

class MoveCommand:public ICommand
{
    public:
        void DoOperate(ExecutorImp& executor) const noexcept override;
};

class TurnLeftCommand:public ICommand
{
    public:
        void DoOperate(ExecutorImp& executor) const noexcept override;
};

class TurnRightCommand:public ICommand
{
    public:
        void DoOperate(ExecutorImp& executor) const noexcept override;
};

class FastCommand:public ICommand
{
    public:
        void DoOperate(ExecutorImp& executor) const noexcept override;
};

#endif