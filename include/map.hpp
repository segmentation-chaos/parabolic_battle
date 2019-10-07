#ifndef MAP_H
#define MAP_H

#include <cstdlib>
#include <ctime>

#include "object.hpp"

class Map
{
	public:
		int **grid; 
		int height;
		int width;
		Map();
		Map(int, int);
		int collision(double, double);
		int set(Object);
		int unset();
		int gridfy_y(double);
		int gridfy_x(double);
};

#endif
