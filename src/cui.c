#include "cui.h"

CUI_app* CUI_CreateApp(int width, int height, const char* title)
{
  CUI_app* app = malloc(sizeof(CUI_app));

  if(!app) return NULL;

  SDL_Init(SDL_INIT_EVERYTHING);

  SDL_Window* window = SDL_CreateWindow(
                          title,
                          SDL_WINDOWPOS_CENTERED,
                          SDL_WINDOWPOS_CENTERED,
                          width,
                          height,
                          0
                      );

  SDL_Renderer* renderer = SDL_CreateRenderer(window, 0, 0);

  app->renderer = renderer;
  app->window = window;
  app->pages = NULL;
  app->running = false;

  return app;
}

void CUI_default_input(CUI_app* app)
{
  SDL_Event e;

  while(SDL_PollEvent(&e)){
    switch(e.type){
      case SDL_KEYDOWN:
        switch(e.key.keysym.sym){
          case SDLK_ESCAPE:
            app->running = false;
            break;
        }
        break;
      //case SDL_KEYUP:
      //  break;
      case SDL_QUIT:
        app->running = false;
        return;
      default:
        break;
    }
  }
}

void CUI_default_update(CUI_app* app)
{

}

void CUI_default_render(CUI_app* app)
{
  SDL_SetRenderDrawColor(app->renderer, CUI_BLACK);
  SDL_RenderClear(app->renderer);

  // ...

  SDL_RenderPresent(app->renderer);
}

int CUI_StartApp(CUI_app* app, CUI_func input, CUI_func update, CUI_func render)
{
  app->running = true;

  CUI_func input_func = input == NULL ? CUI_default_input : input;
  CUI_func update_func = update == NULL ? CUI_default_update : update;
  CUI_func render_func = render == NULL ? CUI_default_render : render;

  while(app->running){
    input_func(app);
    update_func(app);
    render_func(app);
  }

  SDL_DestroyRenderer(app->renderer);
  SDL_DestroyWindow(app->window);
  SDL_Quit();
  free(app);

  return 0;
}
