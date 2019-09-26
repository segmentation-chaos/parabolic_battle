#include "object.hpp"

#include <math.h>

int Object::shoot(double vel_init, double angle_init, int orientation)
{
    if(orientation == -1){
        angle_init = 180 - angle_init;
    }
    vel_x = vel_init * cos(M_PI * angle_init / 180.0);
    vel_y = vel_init * sin(M_PI * angle_init / 180.0);
    return 0;
}

int Object::move()
{
    double g = 9.806;
    double dt = 1e-3; 
    pos_x += vel_x * dt;
    pos_y += vel_y * dt - g * dt * dt / 2.0;
    vel_y -= g*dt; 
    return 0;
}