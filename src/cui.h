#ifndef _CUI_H_
#define _CUI_H_

#include "input.h"
#include "SDL2/SDL.h"

typedef SDL_Window CUI_window;
typedef SDL_Renderer CUI_renderer;

typedef enum{
  NONE,
  CENTERED,
  HORIZONAL_CENTER,
  VERTICAL_CENTER,
  TO_RIGHT,
  TO_LEFT
} CUI_layout_type;

typedef struct component_t{
  int x, y, w, h;
  component_t** children;
  CUI_layout_type layout_type;
} CUI_component;

typedef struct{
  CUI_window* window;
  CUI_renderer* renderer;
} CUI_app;

CUI_app* CUI_CreateApp(int width, int height);
int CUI_StartApp(CUI_app* app);

#endif
