#include <ctime>
#include <stdio.h>
#include <iostream>

#include "system.hpp"

using namespace std;

/**
 * This main is used for testing the object.(cpp|hpp)
 * The main file has to be renamed in the makefile
 */

int main(int argc, char **argv)
{
	Object tank;
	Object bullet;

	tank.pos_x = 1.0;
	tank.pos_y = 1.0;

	bullet.pos_x = tank.pos_x;
	bullet.pos_y = tank.pos_y;

	double v0, theta0;

	cout << "Enter the value of the initial velocity:" << endl;
	cin >> v0;
	cout << "Enter the value of the initial angle:" << endl;
	cin >> theta0;

	bullet.shoot(v0, theta0, 1);

	printf("%f %f\n", bullet.vel_x, bullet.vel_y);

	FILE *out = fopen("tests/bullet_trajectory.dat", "w");
	fprintf(out, "%f %f\n", bullet.pos_x, bullet.pos_y);
	for(int i = 0; i < 150; i++)
	{
		bullet.move();
		fprintf(out, "%f %f\n", bullet.pos_x, bullet.pos_y);
	}
	fclose(out);

	return 0;
}
