#include "canvas.hpp"

using namespace std;

Canvas::Canvas()
{
}

Canvas::Canvas(const Canvas &other)
{
	*this = other;
}

Canvas& Canvas::operator=(const Canvas &other)
{
	if(this != &other)
	{
		width = other.width;
		height = other.height;
		display = other.display;
		renderer = other.renderer;
	}

	return *this;
}

Canvas::~Canvas()
{
	SDL_DestroyWindow(display);
	SDL_Quit();
}

int Canvas::init(
	unsigned int w,
	unsigned int h,
	const char *window_name
)
{
	width = w;
	height = h;

	if(0 > SDL_Init(SDL_INIT_VIDEO))
	{
		return 1;
	}

	display = SDL_CreateWindow(
		window_name,
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		width,
		height,
		0
	);
	if(NULL == display)
	{
		return 2;
	}

	renderer = SDL_CreateRenderer(display, -1, 0);
	if(NULL == renderer)
	{
		return 3;
	}

	return 0;
}

int Canvas::handle_events()
{
	while(SDL_PollEvent(&event))
	{
		if(SDL_QUIT == event.type)
		{
			return 0;
		}
		else if(SDL_KEYUP == event.type)
		{
			if(SDLK_ESCAPE == event.key.keysym.sym)
			{
				return 0;
			}
		}
		else if(SDL_MOUSEBUTTONDOWN == event.type)
		{
			if(SDL_BUTTON_LEFT == event.button.button)
			{
				return 1;
			}
		}
		else if(SDL_MOUSEBUTTONUP == event.type)
		{
			if(SDL_BUTTON_LEFT == event.button.button)
			{
				return 2;
			}
		}
	}
	return -1;
}

int Canvas::get_mouse_position(double *x, double *y)
{
	int x_raw, y_raw;

	SDL_GetMouseState(&x_raw, &y_raw);

	*x = (double) x_raw / width;
	*y = 1. - (double) y_raw / height;

	return 0;
}

int Canvas::clear(
	unsigned short int r,
	unsigned short int g,
	unsigned short int b
)
{
	SDL_SetRenderDrawColor(renderer, r, g, b, 255);
	SDL_RenderClear(renderer);

	return 0;
}

int Canvas::show()
{
	SDL_RenderPresent(renderer);

	return 0;
}

int Canvas::draw_player(
	double x,
	double y,
	int face,
	unsigned short int r,
	unsigned short int g,
	unsigned short int b
)
{
	SDL_Rect body;
	SDL_Rect gun;

	body.w = 12;
	body.h = 10;
	body.x = (int) (x * width) - body.w / 2;
	body.y = (int) ((1 - y) * height) - body.h;

	gun.w = 4;
	gun.h = 3;
	if(0 <= face)
	{
		gun.x = body.x + body.w;
	}
	else
	{
		gun.x = body.x - gun.w;
	}
	gun.y = body.y + body.h / 2 - gun.h;

	SDL_SetRenderDrawColor(renderer, r, g, b, 255);
	SDL_RenderFillRect(renderer, &body);
	SDL_RenderFillRect(renderer, &gun);

	return 0;
}

int Canvas::draw_bullet(
	double x,
	double y,
	unsigned short int r,
	unsigned short int g,
	unsigned short int b
)
{
	SDL_Rect body;

	body.w = 3;
	body.h = 3;
	body.x = (int) (x * width) - body.w / 2;
	body.y = (int) ((1 - y) * height) - body.h;

	SDL_SetRenderDrawColor(renderer, r, g, b, 255);
	SDL_RenderFillRect(renderer, &body);

	return 0;
}

int Canvas::draw_map(
	double h,
	unsigned short int r,
	unsigned short int g,
	unsigned short int b
)
{
	SDL_SetRenderDrawColor(renderer, r, g, b, 255);
	SDL_RenderDrawLine(renderer, 0, (1 - h) * height, width, (1 - h) * height);

	return 0;
}
