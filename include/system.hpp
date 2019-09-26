#ifndef SYSTEM_H
#define SYSTEM_H

#include "map.hpp"
#include "object.hpp"
#include "canvas.hpp"

class System
{
	private:
		Canvas canvas;
		Map map;

	public:
		System();

		int run();
};

#endif
