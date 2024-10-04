#ifndef __INPUT_H__
#define __INPUT_H__

#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <stdbool.h>

typedef struct{
  SDL_Window* w;
  SDL_Renderer* r;
  bool running;
}state_t;

void keydown(state_t *state, SDL_Event e);
void keyup(state_t *state, SDL_Event e);
void process_input(state_t *state);
#endif
