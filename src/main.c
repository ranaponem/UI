#include <SDL2/SDL_image.h>
#include <SDL2/SDL_keycode.h>
#include <stdio.h>
#include <stdbool.h>
#include "input.h"
#include "window.h"

void init(state_t *s){
  if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    fprintf(stderr, "E: Couldn't initialize SDL\n");

  IMG_Init(IMG_INIT_PNG);

  s->w = SDL_CreateWindow(
      TITLE,
      SDL_WINDOWPOS_CENTERED,
      SDL_WINDOWPOS_CENTERED,
      SCR_W, SCR_H,
      SDL_WINDOW_SHOWN
      );

  if(s->w == 0)
    fprintf(stderr, "E: Couldn't initialize SDL window\n");

  s->r = SDL_CreateRenderer(s->w, -1, 0);
  SDL_SetRenderDrawBlendMode(s->r, SDL_BLENDMODE_BLEND);

  s->running = true;
}

void update(state_t *s){
}

void render(state_t *s){
  SDL_SetRenderDrawColor(s->r, 255, 255, 255, 255);
  SDL_RenderClear(s->r);

  SDL_RenderPresent(s->r);
}

void quit(state_t *s){
  SDL_DestroyRenderer(s->r);
  SDL_DestroyWindow(s->w);
  SDL_Quit();
  IMG_Quit();
}

int main(void){
  // variable init
  
  state_t s;
  // window and renderer init
  init(&s);

  while(s.running){
    process_input(&s);
    update(&s);
    render(&s);
  }

  quit(&s);

  return 0;
}
