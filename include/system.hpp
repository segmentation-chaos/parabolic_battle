#ifndef SYSTEM_H
#define SYSTEM_H

#include "canvas.hpp"
#include "map.hpp"
#include "object.hpp"

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
