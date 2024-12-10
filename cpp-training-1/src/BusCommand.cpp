/*Bus����ϳ�������ռ2�����������ǳ�ͷ�����ꡣΪ���г���ȫ��ָ�������Ϊ��ѭ����������
+ M��ǰ����1���ƶ�1��
+ L����ǰ��1������ת90��
+ R����ǰ��1������ת90��*/

#include "BusCommand.h"

void BusMoveCommand::DoOperate(PoseHandler& poseHandler) const noexcept
{
    poseHandler.Move();
}

void BusTurnLeftCommand::DoOperate(PoseHandler& poseHandler) const noexcept
{
    poseHandler.Move();
    poseHandler.TurnLeft();
}

void BusTurnRightCommand::DoOperate(PoseHandler& poseHandler) const noexcept
{
    poseHandler.Move();
    poseHandler.TurnRight();
}

void BusFastCommand::DoOperate(PoseHandler& poseHandler) const noexcept
{
    poseHandler.Fast();
}

void BusBackCommand::DoOperate(PoseHandler& poseHandler) const noexcept
{
    poseHandler.Back();
}

