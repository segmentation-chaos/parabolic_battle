#ifndef OBJECT_H
#define OBJECT_H

class Object
{
    public:
        int ndx;
        double vel_x, vel_y;
        double pos_x, pos_y, size_x, size_y;
        int shoot(double init_vel, double init_angle, int orientation);
        int move();
};

#endif