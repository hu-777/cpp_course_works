#include "PoseHandler.h"

namespace adas
{
    PoseHandler::PoseHandler() noexcept
    {
        pose=Pose(0,0,N);
        fast=false;
        back=false;
    }

    PoseHandler::PoseHandler(const Pose& pose) noexcept
    {
        this->pose=pose;
        fast=false;
        back=false;
    }

    void PoseHandler::MoveOneStep() noexcept
    {
        if (back) 
        {
            switch (pose.heading) 
            {
            case N:
                pose.y -= 1;
                break;
            case S:
                pose.y += 1;
                break;
            case E:
                pose.x -= 1;
                break;
            case W:
                pose.x += 1;
                break;
            default:
                break;
            }
        } 
        else 
        {
            switch (pose.heading) 
            {
            case N:
                pose.y += 1;
                break;
            case S:
                pose.y -= 1;
                break;
            case E:
                pose.x += 1;
                break;
            case W:
                pose.x -= 1;
                break;
            default:
                break;
            }
        }
    }

    void PoseHandler::Move() noexcept
    {
        int step=fast?2:1;
        for(int i=0;i<step;i++)
        {
            MoveOneStep();
        }
    }

    void PoseHandler::TurnLeft() noexcept
    {
        if(fast)
        {
            if(back)
            {
                MoveOneStep();
                pose.heading=static_cast<Heading>((pose.heading+1)%4);
            }
            else
            {
                MoveOneStep();
                pose.heading=static_cast<Heading>((pose.heading+3)%4);
            }
        }
        else if(back)
        {
            pose.heading=static_cast<Heading>((pose.heading+1)%4);
        }
        else
        {
            pose.heading=static_cast<Heading>((pose.heading+3)%4);
        }
    }

    void PoseHandler::TurnRight() noexcept
    {
        if(fast)
        {
            if(back)
            {
                MoveOneStep();
                pose.heading=static_cast<Heading>((pose.heading+3)%4);
            }
            else
            {
                MoveOneStep();
                pose.heading=static_cast<Heading>((pose.heading+1)%4);
            }
        }
        else if(back)
        {
            pose.heading=static_cast<Heading>((pose.heading+3)%4);
        }
        else
        {
            pose.heading=static_cast<Heading>((pose.heading+1)%4);
        }
    }

    void PoseHandler::Fast() noexcept
    {
        fast=!fast;
    }

    bool PoseHandler::isFast() const noexcept
    {
        return fast;
    }

    Pose PoseHandler::Query() const noexcept
    {
        return pose;
    }

    void PoseHandler::Back() noexcept
    {
        back=!back;
    }

    bool PoseHandler::isBack() const noexcept
    {
        return back;
    }
}