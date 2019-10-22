#include "map.hpp"

Map::Map()
{
	Map(1000, 1000);
}

/**
* Creates the matrix grid
* 	Elements index:
* 	 > empty: 0
* 	 > terrain: 1
* 	 > player: obj.ndx
* 	 > bullet: obj.ndx 
*/ 
Map::Map(int h, int w)
{	
	srand(time(NULL));
	
	height = h;
	width = w; 

	// Memory allocation
	grid = new int *[width];
	for(int i = 0; i < width; i++)
	{
		grid[i] = new int [height];
	}

	// Set grid to zero
	for(int i = 0; i < width; i++)
	{
		for(int j = 0; j < height; j++)
		{
			grid[i][j] = 0;
		}
	}

	// Set map terrain: flat line
	int map_lvl = gridfy_y((double) rand() / RAND_MAX / 2.0);
	for(int i = 0; i < map_lvl; i++)
	{
		for(int j = 0; j < height; j++)
		{
			grid[i][j] = 1;
		}
	}

	/** Future features: 
	*	>> Check map_lvl for boundaries hit
	*   >> Terrain generator
	*	>> Different terrain types (sand, dirt, water ...)
	*/
}

Map::~Map()
{
	for(int i = 0; i < width; i++)
	{
		delete [] grid[i];	
	}
	delete [] grid;
}

int Map::collision(double x, double y)
{
	return grid[gridfy_x(x)][gridfy_y(y)];
}

/** Sets an object (obj) index to the grid
*  >> For now, it only sets the type index (obj.ndx), not ID
*  >> It does not consider objects dimensions (size_x, size_y)
*/ 
int Map::set(Object obj)
{
	grid[gridfy_x(obj.pos_x)][gridfy_y(obj.pos_y)] = obj.ndx;
	
	/** Future feature:
	* 	>> Distinguish player/bullet ID
	*/ 

	return 0;
}

// Sets grid to empty space (index 0)
int Map::unset()
{
	return 0; 
}

// Converts a double [0,1] height position to grid index
int Map::gridfy_y(double y)
{
	return (int) height * y;
}

// Converts a double [0,1] width position to grid index
int Map::gridfy_x(double x)
{
	return (int) width * x;
}
