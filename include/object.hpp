#ifndef OBJECT_H
#define OBJECT_H

#include <math.h>

class Object
{
    public:
        double vel_x, vel_y;
        double pos_x, pos_y, size_x, size_y;
        int shoot(double, double);
        int move();
};

#endif
