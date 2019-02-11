#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  int x,y;
  if(x0 > x1){
    int temp = x0;
    x0 = x1;
    x1 = temp;
    temp = y0;
    y0 = y1;
    y1 = temp;
  }
  x = x0;
  y = y0;
  int rise = y1 - y0;
  int run = x1 - x0;
  int a = run * 2;
  int b = -rise * 2;
  if(abs(rise) <= abs(run)){
    int d = 2*a +b;
    //OCT1
    if(rise > 0){
      while(x <= x1){
	plot(s,c,x,y);
	if( d > 0){
	  y++;
	  d+= 2* b;
	}
	x++;
	d+=2*a;
      }
    }
    //OCT8
    if(rise < 0){
      while(x <= x1){
	plot(s,c,x,y);
	if(d < 0){
	  y--;
	  d-= 2*b;
	}
	x++;
	d+= 2*a;
      }
    }
  }
  else{
    //OCT2
    if(rise > 0){
      int d = a +2*b;
      while(y <= y1){
	plot(s,c,x,y);
	if(d < 0){
	  x++;
	  d+= 2*a;
	}
	y++;
	d += 2*b;
      }
    }
    //OCT7
    if(rise < 0){
      int d= a-2*b;
      while( y >= y1){
	plot(s,c,x,y);
	if(d > 0){
	  x++;
	  d+= 2*a;
	}
	y--;
	d -= 2*b;
      }
    }
  } 
}
