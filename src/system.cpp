#include "system.hpp"

System::System()
{
	canvas.init(800, 600, "Parabolic Battle");

	player_1.pos_x = 0.2;
	player_1.pos_y = map.height;
	player_2.pos_x = 0.8;
	player_2.pos_y = map.height;

	vel_gauge = 2.;
	charging = false;
}

int System::run()
{
	int handle_code = -1;
	double x = 0, y = 0;

	handle_code = canvas.handle_events();

	if(0 < bullets.size())
	{
		for(unsigned i = 0; i < bullets.size(); i++)
		{
			bullets[i].move();
			if(
				1 < bullets[i].pos_x ||
				0 > bullets[i].pos_x ||
				map.height > bullets[i].pos_y
			)
			{
				bullets.erase(bullets.begin() + i);
			}
		}
	}

	if(1 == handle_code)
	{
		charging = true;
	}
	else if(2 == handle_code)
	{
		charging = false;
		canvas.get_mouse_position(&x, &y);
		bullets.push_back(Object());
		bullets.back().pos_x = player_1.pos_x;
		bullets.back().pos_y = player_1.pos_y;
		bullets.back().shoot(
			vel_gauge,
			atan2((y - player_1.pos_y), (x - player_1.pos_x))
		);
		vel_gauge = 2.;
	}

	if(charging && 3. > vel_gauge)
	{
		vel_gauge += 0.015;
	}

	canvas.clear();

	canvas.draw_map(map.height);

	canvas.draw_player(player_1.pos_x, player_1.pos_y, 1);
	canvas.draw_player(player_2.pos_x, player_2.pos_y, -1);

	for(unsigned i = 0; i < bullets.size(); i++)
	{
		canvas.draw_bullet(bullets[i].pos_x, bullets[i].pos_y);
	}

	canvas.show();

	return handle_code;
}
