#include "input.h"

void keydown(state_t *state, SDL_Event e){
  switch(e.key.keysym.sym){
    case SDLK_ESCAPE:
      state->running = false;
      break;
  }
}

void keyup(state_t *state, SDL_Event e){
  switch(e.key.keysym.sym){
  }
}

void process_input(state_t *state){
  SDL_Event e;

  while(SDL_PollEvent(&e)){
    switch(e.type){
      case SDL_KEYDOWN:
        keydown(state, e);
        break;
      case SDL_KEYUP:
        keyup(state, e);
        break;
      case SDL_QUIT:
        state->running = false;
        return;
      default:
        break;
    }
  }
}
