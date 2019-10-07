#include "map.hpp"

Map::Map()
{
	srand(time(NULL)); // Temporary

//	Map(1000, 1000);

	height = (double) rand() / RAND_MAX / 2. + 0.5;
}

/**
* Creates a matrix grid indexed with elements
* 	Index:
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

	// Set map to zero
	for(int i = 0; i < width; i++)
	{
		for(int j = 0; j < height; j++)
		{
			grid[i][j] = 0;
		}
	}

	// Set map terrain: flat line (index 1 for terrain)
	int map_lvl = gridfy_y((double) rand() / RAND_MAX / 2.0);
	for(int i = 0; i < map_lvl; i++)
	{
		for(int j = 0; j < height; j++)
		{
			grid[i][j] = 1;
		}
	}

	/**
	*  Future features: 
	*	>> Terrain generator
	*	>> Different terrain types (sand, dirt, water ...)
	*/
}

int Map::collision(double x, double y)
{
	return grid[gridfy_x(x)][gridfy_y(y)];
}

// Sets obj index to grid
/**
*  >> For now, it only sets the type index (obj.ndx), not ID
*  >> It does not consider objects dimensions (size_x, size_y)
*/ 
int Map::set(Object obj)
{
	grid[gridfy_x(obj.pos_x)][gridfy_y(obj.pos_y)] = obj.ndx;
	/**
	*  Future feature:
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

// Converts a double [0,1 width position to grid index
int Map::gridfy_x(double x)
{
	return (int) width * x;
}