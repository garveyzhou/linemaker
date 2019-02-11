#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {

  screen s;
  color c;

  c.red = 0;
  c.green = MAX_COLOR;
  c.blue = 0;
  int x = 0;
  while(x <= 500){
	  draw_line(x,0,500-x,500,s,c);
	  x+= 5;
  }

  clear_screen(s);


  display(s);
  save_extension(s, "lines.png");
}
