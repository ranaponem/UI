#ifndef _CUI_H_
#define _CUI_H_

#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdlib.h>

#include "colors.h"

/* ALIASES */

typedef SDL_Window CUI_window;
typedef SDL_Renderer CUI_renderer;
typedef SDL_Color CUI_color;

/* STRUCTS */

typedef enum{
  NONE,
  CENTERED,
  HORIZONAL_CENTER,
  VERTICAL_CENTER,
  TO_RIGHT,
  TO_LEFT
} CUI_layout_type;

typedef struct{
  int rounded_radius;
  int padding;
  int margin;
  CUI_layout_type layout_type;
  CUI_color background;
  CUI_color foreground;
} CUI_config;

typedef struct component_t{
  int x, y, w, h;
  struct component_t** children;
  CUI_config config;
} CUI_component;

typedef struct{
  CUI_component** components;
  CUI_color background;
  CUI_layout_type layout_type;
  int id;
} CUI_page;

typedef struct{
  CUI_window* window;
  CUI_renderer* renderer;
  CUI_page** pages;
  int num_pages;
  int cur_page;
  bool running;
} CUI_app;

/* FUNCTION SIGNATURES */

typedef void (*CUI_func)(CUI_app*);

/* FUNCTIONS */

void CUI_default_input(CUI_app* app);
void CUI_default_update(CUI_app* app);
void CUI_default_render(CUI_app* app);
CUI_app* CUI_CreateApp(int width, int height, const char* title);
int CUI_StartApp(CUI_app* app, CUI_func input, CUI_func update, CUI_func render);
CUI_page* CUI_CreatePage(int id, CUI_color background_color, CUI_layout_type layout);
CUI_component* CUI_CreateComponent(CUI_config config);

#endif
