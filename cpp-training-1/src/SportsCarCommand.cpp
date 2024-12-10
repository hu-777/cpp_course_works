/*�ٶȺܿ죬ָ�������Ϊ��ѭ����������
+ M��ǰ����1���ƶ�2��(��ǰ��1����ǰ��1��)
+ L������ת90�ȣ���ǰ��1��
+ R������ת90�ȣ���ǰ��1��*/

#include "SportsCarCommand.h"

void SportsCarMoveCommand::DoOperate(PoseHandler& poseHandler) const noexcept
{
    int step=2;
    for(int i=0;i<step;i++)
    {
        poseHandler.Move();
    }
}

void SportsCarTurnLeftCommand::DoOperate(PoseHandler& poseHandler) const noexcept
{
    poseHandler.TurnLeft();
    poseHandler.Move();
}

void SportsCarTurnRightCommand::DoOperate(PoseHandler& poseHandler) const noexcept
{
    poseHandler.TurnRight();
    poseHandler.Move();
}

void SportsCarFastCommand::DoOperate(PoseHandler& poseHandler) const noexcept
{
    poseHandler.Fast();
}

void SportsCarBackCommand::DoOperate(PoseHandler& poseHandler) const noexcept
{
    poseHandler.Back();
}

