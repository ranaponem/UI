#include "cui.h"

int main(void){
  CUI_app* app = CUI_CreateApp(400, 2000, "test");
  if(!app) return -1;

  CUI_StartApp(app, NULL, NULL, NULL);

  return 0;
}
