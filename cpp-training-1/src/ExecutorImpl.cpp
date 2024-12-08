#include "ExecutorImpl.h"
#include "Command.h"
#include<memory>
#include<unordered_map>
using namespace std;

void ExecutorImpl::Execute(const string& commands)
{
    unordered_map<char, unique_ptr<ICommand>> cmderMap;
    cmderMap.emplace('M', make_unique<MoveCommand>());
    cmderMap.emplace('L', make_unique<TurnLeftCommand>());
    cmderMap.emplace('R', make_unique<TurnRightCommand>());
    cmderMap.emplace('F', make_unique<FastCommand>());
    cmderMap.emplace('B', make_unique<BackCommand>());

    for (const auto& cmd : commands) 
    {
        auto it = cmderMap.find(cmd);
        if (it != cmderMap.end()) 
        {
            it->second->DoOperate(poseHandler);
        }
    }
}

Pose ExecutorImpl::Query() const noexcept
{
    return poseHandler.Query();
}