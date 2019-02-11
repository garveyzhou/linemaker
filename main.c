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
  while(x < 500){
  	draw_line(250,250,500-x,0,s,c);
	draw_line(250,250,500-x,500,s,c);
	x += 5;
  }
  //save_ppm(s,"Image.ppm");
  clear_screen(s);


  display(s);
  save_extension(s, "lines.png");
}
