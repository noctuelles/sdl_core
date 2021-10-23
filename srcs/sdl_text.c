#include "sdl_core.h"

t_sdl_core	*sdl_draw_text(t_sdl_core *sdl_core, const char *strtext,
							 t_pos pos, SDL_Color color)
{
	SDL_Surface	*text;
	SDL_Texture	*text_texture;
	SDL_Rect	rect;

	text = TTF_RenderText_Solid(sdl_core->font, strtext, color);
	if (!text)
		return (NULL);
	text_texture = SDL_CreateTextureFromSurface(sdl_core->renderer, text);
	rect.x = pos.x;
	rect.y = pos.y;
	rect.w = text->w;
	rect.h = text->h;
	SDL_RenderCopy(sdl_core->renderer, text_texture, NULL, &rect);
	SDL_DestroyTexture(text_texture);
	SDL_FreeSurface(text);
	return (sdl_core);
}
