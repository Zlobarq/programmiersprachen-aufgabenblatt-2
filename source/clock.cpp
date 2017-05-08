#include "window.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>
#include "circle.hpp"

int main(int argc, char* argv[])
{
  Window win{std::make_pair(600,600)};

  while (!win.should_close()) {
    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }
    Vec2 ctr{300,300};
    Circle clock{ctr, 250, Color{25,25,25}};
    clock.draw(win); 
    float passedTime = win.get_time(); 
    Vec2 s{sin((passedTime*6*M_PI)/180)*230,-cos((passedTime*6*M_PI)/180)*230};
    Vec2 m{sin((0.1*passedTime*M_PI)/180)*210,-cos((0.1*passedTime*M_PI)/180)*210};
    Vec2 h{sin((0.0075*passedTime*M_PI)/180)*160,-cos((0.0075*passedTime*M_PI)/180)*160};




    s += ctr;
    m += ctr;
    h += ctr;
    //Zeitstriche
    for (float a=0.0;a<360.0;a++)
    {
    Vec2 ha{sin((a*1*M_PI)/180)*235,-cos((a*1*M_PI)/180)*235};
    Vec2 hb{sin((a*1*M_PI)/180)*245,-cos((a*1*M_PI)/180)*245};
    ha+= ctr;
    hb+= ctr;
    win.draw_line(ha.x_,ha.y_,hb.x_,hb
    	.y_,25.0f,25.0f,25.0f);	
    }
    for (float a=0.0;a<60.0;a++)
    {
    Vec2 ha{sin((a*6*M_PI)/180)*230,-cos((a*6*M_PI)/180)*230};
    Vec2 hb{sin((a*6*M_PI)/180)*245,-cos((a*6*M_PI)/180)*245};
    ha+= ctr;
    hb+= ctr;
    win.draw_line(ha.x_,ha.y_,hb.x_,hb
    	.y_,25.0f,25.0f,25.0f);	
    }
    for (float a=0.0;a<12.0;a++)
    {
    Vec2 ha{sin((a*30*M_PI)/180)*220,-cos((a*30*M_PI)/180)*220};
    Vec2 hb{sin((a*30*M_PI)/180)*265,-cos((a*30*M_PI)/180)*265};
    ha+= ctr;
    hb+= ctr;
    win.draw_line(ha.x_,ha.y_,hb.x_,hb
    	.y_,25.0f,25.0f,25.0f);	
    }
    //Uhrzeiger
    win.draw_line(ctr.x_,ctr.y_,s.x_,s.y_,25.0f,25.0f,25.0f);
    win.draw_line(ctr.x_,ctr.y_,m.x_,m.y_,25.8f,25.8f,25.8f);
    win.draw_line(ctr.x_,ctr.y_,h.x_,h.y_,25.0f,25.0f,25.0f);
    //Zeitanzeige
    std::string zeit =std::to_string((int)passedTime/3600 %24) + ":" 
    + std::to_string((int)passedTime/60 %60) + ":" + std::to_string((int)passedTime%60);
    win.draw_text(10, 5, 35.0f, zeit);
  	win.draw_text(ctr.x_-15,ctr.y_-300, 35.0f, "12");
  	win.draw_text(ctr.x_-7.5,ctr.y_+265, 35.0f, "6");
  	win.draw_text(ctr.x_+270,ctr.y_-17, 35.0f, "3");
  	win.draw_text(ctr.x_-285,ctr.y_-17, 35.0f, "9");
  	win.draw_text(ctr.x_-7.5,ctr.y_+265, 35.0f, "6");
    win.update();
  }

  return 0;
}