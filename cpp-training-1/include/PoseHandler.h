//解耦循环依赖，封装抽离ExecutorImp状态数据
#pragma once
#include "Executor.h"
#include "Pose.h"

namespace adas
{
    class PoseHandler
    {
        private:
            Pose pose;
            bool fast;
            bool back;

        public:
            PoseHandler() noexcept;
            PoseHandler(const Pose& pose) noexcept;

            void Move(void) noexcept;
            void MoveOneStep(void) noexcept;
            void TurnLeft(void) noexcept;
            void TurnRight(void) noexcept;
            void Fast(void) noexcept;
            bool isFast(void) const noexcept;
            void Back(void) noexcept;
            bool isBack(void) const noexcept;
            Pose Query(void) const noexcept;
    };
} // namespace adas