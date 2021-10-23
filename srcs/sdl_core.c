#include <stdlib.h>
#include "sdl_core.h"

t_sdl_core	*sdl_core_init(const char *title, uint16_t width,
							uint16_t height, uint32_t flags)
{
	t_sdl_core	*sdl_core;

	sdl_core = (t_sdl_core *) malloc(sizeof(t_sdl_core));
	if (!sdl_core)
		return (NULL);
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return (NULL);
	sdl_core->width = width;
	sdl_core->height = height;
	sdl_core->title = title;
	sdl_core->font = NULL;
	sdl_core->wnd = SDL_CreateWindow("nesemu",
							SDL_WINDOWPOS_CENTERED,
							SDL_WINDOWPOS_CENTERED,
							width,
							height,
							flags);
	if (!sdl_core->wnd)
		return (NULL);
	sdl_core->renderer = SDL_CreateRenderer(sdl_core->wnd, -1,
												SDL_RENDERER_ACCELERATED
												| SDL_RENDERER_PRESENTVSYNC);
	if (!sdl_core->renderer)
		return (NULL);
	return (sdl_core);
}

t_sdl_core	*sdl_core_load_font(t_sdl_core *sdl_core, const char *path,
								int size)
{
	TTF_Font	*font;

	if (sdl_core->font != NULL)
		TTF_CloseFont(sdl_core->font);
	else
	{
		if (TTF_Init() < 0)
			return (NULL);
	}
	font = TTF_OpenFont(path, size);
	if (!font)
		return (NULL);
	sdl_core->font = font;
	return (sdl_core);	
}

void	*sdl_core_destroy(t_sdl_core *sdl_core)
{
	if (sdl_core->font != NULL)
	{
		TTF_CloseFont(sdl_core->font);
		TTF_Quit();
	}
	SDL_DestroyRenderer(sdl_core->renderer);
	SDL_DestroyWindow(sdl_core->wnd);	
	SDL_Quit();
	free(sdl_core);
}
