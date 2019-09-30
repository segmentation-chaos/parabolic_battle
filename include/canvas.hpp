#ifndef CANVAS_H
#define CANVAS_H

#include <SDL2/SDL.h>

class Canvas
{
	private:
		unsigned int width;
		unsigned int height;
		SDL_Window* display;
		SDL_Renderer* renderer;
		SDL_Event event;

	public:
		Canvas();
		Canvas(const Canvas&);
		Canvas& operator=(const Canvas&);
		~Canvas();
		int init(unsigned int, unsigned int, const char *);
		int handle_events();
		int get_mouse_position(double *, double *);
		int clear(
			unsigned short int = 255,
			unsigned short int = 255,
			unsigned short int = 255
		);
		int show();
		int draw_player(
			double,
			double,
			int,
			unsigned short int = 0,
			unsigned short int = 0,
			unsigned short int = 0
		);
		int draw_bullet(
			double,
			double,
			unsigned short int = 0,
			unsigned short int = 0,
			unsigned short int = 0
		);
		int draw_map(
			double,
			unsigned short int = 0,
			unsigned short int = 0,
			unsigned short int = 0
		);
};

#endif
