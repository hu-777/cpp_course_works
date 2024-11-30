#ifndef _POSE_H_
#define _POSE_H_

#include "Heading.h"
#include<tuple>

class Pose
{
    public:
        int x,y;
        Heading heading;
        Pose(int x=0, int y=0, Heading heading=N):x(x),y(y),heading(heading){}

        friend bool operator==(const Pose& lhs,const Pose& rhs)
        {
            return std::tie(lhs.x,lhs.y,lhs.heading)==std::tie(rhs.x,rhs.y,rhs.heading);
        }
};

#endif