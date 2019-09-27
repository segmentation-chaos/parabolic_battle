#include <ctime>

#include "system.hpp"

using namespace std;

int main(int argc, char **argv)
{
	int running = 1;
	clock_t clock_counter;
	System sys;

	while(running)
	{
		clock_counter = clock();

		running = sys.run();

		while(CLOCKS_PER_SEC / 60.0 > clock() - clock_counter)
		{
		}
	}

	return 0;
}
