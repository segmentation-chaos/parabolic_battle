#include "map.hpp"

Map::Map()
{
	srand(time(NULL));

	height = (double) rand() / RAND_MAX / 2. + 0.5;
}
