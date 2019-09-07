#include "system.hpp"

System::System()
{
	canvas.init(800, 600, "Parabolic Battle");
}

int System::run()
{
	int handle_code = -1;

	handle_code = canvas.handle_events();

	canvas.clear();

	canvas.draw_map(map.height);

	canvas.draw_player(0.2, map.height, 1);
	canvas.draw_player(0.8, map.height, -1);

	canvas.show();

	return handle_code;
}
