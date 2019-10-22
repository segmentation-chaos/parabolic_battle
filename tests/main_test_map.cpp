#include <iostream>
#include <ctime>

using namespace std;

#include "system.hpp"

/**
 * This main is used for testing the map.(cpp|hpp)
 * The main file has to be renamed in the makefile
 * !!The current stage IS NOT compatible with the system.(cpp|hpp) given that 
 * the variable 'height' from map changed type from (double) to (int)!!
 * !!This test is only for the map functions alone, without connection to 
 * System and Canvas!!
 * !!The current state DOES NOT check for boundaries when constructing the map!!
 */

int main(int argc, char **argv)
{

    int width = 20;
    int height = 20;
    Map map(width, height);
    
    // Test matrix construction
	for (int i = map.width - 1; i >= 0; i--)
	{
		for (int j = map.height - 1; j >= 0 ; j--)
		{
			cout << map.grid[i][j];
		}
		cout << endl;
	}

    // Test colision
	double hit_posx = 0.5;
	double hit_posy = 0.5;
	int ix = (int) wdth * hit_posx;
	int iy = (int) hght * hit_posy;

	cout << map.collision(hit_posx, hit_posy) << endl;
    cout << map.grid[ix][iy] << endl;
	
	// Test set
	Object obj;
	obj.ndx = 9;
	obj.pos_x = hit_posx;
	obj.pos_y = hit_posy;
	map.set(obj);

	for (int i = map.width - 1; i >= 0; i--)
	{
		for (int j = map.height - 1; j >= 0 ; j--)
		{
			cout << map.grid[i][j];
		}
		cout << endl;
	}

	cout << map.collision(hit_posx, hit_posy) << endl;
    cout << map.grid[ix][iy] << endl;

	return 0;
}
