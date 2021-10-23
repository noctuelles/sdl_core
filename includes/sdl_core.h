#ifndef SDL_CORE_H
#define SDL_CORE_H

#include <stdint.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

typedef struct s_sdl_core
{
	SDL_Window		*wnd;
	SDL_Renderer	*renderer;
	TTF_Font		*font;
	uint16_t		width;
	uint16_t		height;
	const char		*title;
}				t_sdl_core;

typedef struct s_pos
{
	int				x;
	int				y;
}				t_pos;

t_sdl_core	*sdl_core_init(const char *title, uint16_t width,
							uint16_t height, uint32_t flags);
t_sdl_core	*sdl_core_load_font(t_sdl_core *sdl_core, const char *path, int size);
t_sdl_core	*sdl_draw_text(t_sdl_core *sdl_core, const char *text, t_pos pos,
							SDL_Color color);
void		*sdl_core_destroy(t_sdl_core *sdl_core);

#endif
