#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector>

#include "canvas.hpp"
#include "map.hpp"
#include "object.hpp"

class System
{
	private:
		double vel_gauge;
		bool charging;
		Canvas canvas;
		Map map;
		Object player_1;
		Object player_2;
		std::vector<Object> bullets;

	public:
		System();

		int run();
};

#endif
