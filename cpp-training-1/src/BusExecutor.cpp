#include "BusExecutor.h"
#include "BusCommand.h"
#include <memory>
#include <unordered_map>
using namespace std;

void BusExecutor::Execute(const string& commands)
{
    unordered_map<char, unique_ptr<BusCommand>> cmderMap;
    cmderMap.emplace('M', make_unique<BusMoveCommand>());
    cmderMap.emplace('L', make_unique<BusTurnLeftCommand>());
    cmderMap.emplace('R', make_unique<BusTurnRightCommand>());
    cmderMap.emplace('F', make_unique<BusFastCommand>());
    cmderMap.emplace('B', make_unique<BusBackCommand>());

    for (const auto& cmd : commands)
    {
        auto it = cmderMap.find(cmd);
        if (it != cmderMap.end())
        {
            it->second->DoOperate(poseHandler);
        }
    }
}