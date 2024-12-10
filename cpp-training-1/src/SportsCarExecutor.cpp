#include "SportsCarExecutor.h"
#include "SportsCarCommand.h"
#include <memory>
#include <unordered_map>
using namespace std;

void SportsCarExecutor::Execute(const string& commands)
{
    unordered_map<char, unique_ptr<SportsCarCommand>> cmderMap;
    cmderMap.emplace('M', make_unique<SportsCarMoveCommand>());
    cmderMap.emplace('L', make_unique<SportsCarTurnLeftCommand>());
    cmderMap.emplace('R', make_unique<SportsCarTurnRightCommand>());
    cmderMap.emplace('F', make_unique<SportsCarFastCommand>());
    cmderMap.emplace('B', make_unique<SportsCarBackCommand>());

    for (const auto& cmd : commands) 
    {
        auto it = cmderMap.find(cmd);
        if (it != cmderMap.end()) 
        {
            it->second->DoOperate(poseHandler);
        }
    }
}