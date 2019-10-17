#include "object.hpp"

int Object::shoot(double vel_init, double angle_init)
{
    vel_x = vel_init * cos(angle_init);
    vel_y = vel_init * sin(angle_init);
    return 0;
}

int Object::move()
{
    double g = 9.806;
    double dt = 1e-1/60.;
    pos_x += vel_x * dt;
    pos_y += vel_y * dt - g * dt * dt / 2.0;
    vel_y -= g*dt; 
    return 0;
}
