#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <iostream>
#include<iostream>
#include "cars.h"
#include "power_up.h"
using namespace std;


void InitGraphics(int argc, char* argv[]);
void SetTransformations();
void Display();
float tile1_movement = -140;
float tile2_movement = -40;
float tile3_movement = 80;
float speed_move = 7.0f;
float speed_tiles = 1;
int score = 0;

float intpart;
float scoref = 0;
float double_score_up_timef = 0;
float invincible_up_timef = 0;
int invincible_up_time = 0;
int double_score_up_time = 0;

bool crashed = false;
bool invincible_nottaken = true;
bool doublescore = false;
bool untouchable=false;
bool inmenu = true;
bool selected;
bool start=true;

cars car_m(0, -195, 0.7, 0, 0);
cars car_m2(0, -160, 0.7, 0.4, 0);
cars car_m3(0, -160, 0.7, 0.3, 0.2);
cars car_o(0, 300, 1, 0.5, 0);
cars car_o1(40, 750, 1, 0, 1);
cars car_o2(-40, 500, 0.36, 0.25, 0.14);
power_up invincible(0, 300);
power_up double_score(0,300);

void timer(int value)
{
   const int fps = 60;
   glutTimerFunc(1000 / fps, timer, 0);
   glutPostRedisplay();
}

void restart() {
   if (car_m.selected) {
      car_m.x = 0;
      car_m.y = -195;
   }
   else if (car_m2.selected) {
      car_m2.x = 0;
      car_m2.y = -160;
   }
   else if (car_m3.selected) {
      car_m3.x = 0;
      car_m3.y = -160;
   }
   car_o.x = 0;
   car_o.y = 300 ;
   car_o1.x = 40;
   car_o1.y = 700;
   car_o2.x = -40;
   car_o2.y = 600;
   speed_tiles = 1;
   car_o.speed = 1.5f;
   car_o1.speed = 1.5f;
   car_o2.speed = 1.5f;
   invincible.speed = 1;
   invincible.y = 400;
   double_score.speed = 1;
   double_score.y = 400;
   speed_move = 7.0f;
   score = 0;
   crashed = false;
   invincible.draw = false;
   double_score.draw = false;
   invincible_nottaken = true;
   doublescore = false;
   
   glutDisplayFunc(Display);
}

void OnSpecKeyPress(int key, int x, int y) {
   if (inmenu) {
      if (key == GLUT_KEY_RIGHT) {
         if (car_m.selected && !car_m2.selected) {
            car_m2.selected = true;
            car_m.selected = false;
         }
         else if (!car_m.selected && car_m2.selected) {
            car_m3.selected = true;
            car_m2.selected = false;
         }
         else if (car_m3.selected && !car_m.selected) {
            car_m.selected = true;
            car_m3.selected = false;
         }
         
      }
      
      if (key == GLUT_KEY_LEFT) {
         if (!car_m.selected && car_m2.selected) {
            car_m2.selected = false;
            car_m.selected = true;
         }
         else if (car_m3.selected && !car_m2.selected) {
            car_m2.selected = true;
            car_m3.selected = false;
         }
         else if (!car_m3.selected && car_m.selected) {
            car_m3.selected = true;
            car_m.selected = false;
         }
      }
   }
}

void OnKeyPress(unsigned char key, int x, int y) {
   switch (key) {
      case 'a':
      case 'A':
         if (!inmenu) {
            if (!crashed) {
               if (car_m.selected) {
                  if (car_m.x - speed_move > -55) {
                     car_m.x -= speed_move;
                     break;
                  }
               }
               if (car_m2.selected) {
                  if (car_m2.x - speed_move > -55) {
                     car_m2.x -= speed_move;
                     break;
                  }
               }
               if (car_m3.selected) {
                  if (car_m3.x - speed_move > -55) {
                     car_m3.x -= speed_move;
                     break;
                  }
               }
               
            }
         }
         break;
      case 'd':
      case 'D':
         if (!inmenu) {
            if (!crashed) {
               if (car_m.selected) {
                  if (car_m.x + speed_move < 55) {
                     car_m.x += speed_move;
                     break;
                  }
               }
               if (car_m2.selected) {
                  if (car_m2.x + speed_move < 55) {
                     car_m2.x += speed_move;
                     break;
                  }
               }
               if (car_m3.selected) {
                  if (car_m3.x + speed_move < 55) {
                     car_m3.x += speed_move;
                     break;
                  }
               }
            }
         }
         break;
         
      case 'r':
      case 'R':
         if (!inmenu) {
            if (crashed) {
               restart();
            }
         }
         break;
         
         
      case 13:
         if (inmenu) {
            inmenu = false;
         }
         break;
         
      case 27:// Esc
         if (!inmenu) {
            if (crashed) {
               glutDestroyWindow(1);
               exit(0);
            }
         }
         break;
         
      case 'm':
      case 'M':
         if (!inmenu) {
            if (crashed) {
               inmenu = true;
               restart();
            }
         }
         break;
   }
}


void power_up_check() {
   if (car_m.selected) {
      if ((abs(car_m.x - invincible.x) < 30) && abs( invincible.y + 100) < 10)  {
         invincible.draw = false;
         invincible_nottaken = false;
         invincible.y = 400;
         invincible_up_time = 10;
         untouchable = true;
         invincible_up_timef = invincible_up_time;
      }
   }
   if (car_m2.selected) {
      if ((abs(car_m2.x - invincible.x) < 30) && abs(invincible.y + 100) < 10) {
         invincible.draw = false;
         invincible_nottaken = false;
         invincible.y = 400;
         invincible_up_time = 10;
         untouchable = true;
         invincible_up_timef = invincible_up_time;
      }
   }
   if (car_m3.selected) {
      if ((abs(car_m3.x - invincible.x) < 30) && abs(invincible.y + 100) < 10) {
         invincible.draw = false;
         invincible_nottaken = false;
         invincible.y = 400;
         invincible_up_time = 10;
         untouchable = true;
         invincible_up_timef = invincible_up_time;
      }
   }
   if (car_m.selected) {
      if ((abs(car_m.x - double_score.x) < 30) && abs(double_score.y + 100) < 10) {
         double_score.draw = false;
         doublescore = true;
         double_score.y = 400;
         double_score_up_time = 7;
         double_score_up_timef = double_score_up_time;
      }
   }
   if (car_m2.selected) {
      if ((abs(car_m2.x - double_score.x) < 30) && abs(double_score.y + 100) < 10) {
         double_score.draw = false;
         doublescore = true;
         double_score.y = 400;
         double_score_up_time = 7;
         double_score_up_timef = double_score_up_time;
      }
   }
   if (car_m3.selected) {
      if ((abs(car_m3.x - double_score.x) < 30) && abs(double_score.y + 100) < 10) {
         double_score.draw = false;
         doublescore = true;
         double_score.y = 400;
         double_score_up_time = 7;
         double_score_up_timef = double_score_up_time;
      }
   }
   
   if (invincible_up_time == 0) {
      untouchable = false;
      invincible_nottaken = true;
      
   }
   if (double_score_up_time == 0) {
      doublescore = false;
   }
}


void SetTransformations() {
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(-200, 200, -200, 200);
}

void Drawscore(int score, float x, float y, float z)
{
   glColor3f(1, 1, 1);
   glRasterPos3f(x, y, z);
   string s = "score : " + to_string(score);
   
   for (int i = 0; i < s.length(); i++)
   {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s.at(i));
   }
   
}

void stop(){
   speed_tiles = 0;
   car_o.speed = 0;
   car_o1.speed = 0;
   car_o2.speed = 0;
   invincible.speed = 0;
   double_score.speed = 0;
   doublescore = false;
   crashed = true;
   
   if (crashed) {
      glColor3f(0.3, 0.3, 0.3);
      glBegin(GL_QUADS);
      glVertex2f(-40, 30);
      glVertex2f(40, 30);
      glVertex2f(40, -30);
      glVertex2f(-40, -30);
      glEnd();
      
      string info = "Your score: " + to_string(score);
      glColor3f(0.99609375f, 0.99609375f, 0);
      glRasterPos3f(-28, 40, 0);
      for (int i = 0; i < info.length(); i++)
      {
         glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, info.at(i));
      }

      string s = "You crashed";
      string s2 = "Esc: Exit";
      string s3 = "R: Restart";
      string s4 = "M: Menu";
      glColor3f(1, 1, 1);
      glRasterPos3f(-28, 20, 0);
      for (int i = 0; i < s.length(); i++)
      {
         glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s.at(i));
      }
      glRasterPos3f(-28, 0, 0);
      for (int i = 0; i < s2.length(); i++)
      {
         glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s2.at(i));
      }
      
      glRasterPos3f(-28, -10, 0);
      for (int i = 0; i < s3.length(); i++)
      {
         glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s3.at(i));
      }
      glRasterPos3f(-28, -20, 0);
      for (int i = 0; i < s4.length(); i++)
      {
         glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s4.at(i));
      }
   }
}

void crash_check() {
   if (car_m.selected) {
      if ((((abs(car_m.x - car_o.x) < 25) & (abs(car_o.y + 100) < 15)) |
           ((abs(car_m.x - car_o1.x) < 25) & (abs(car_o1.y + 100) < 15)) |
           ((abs(car_m.x - car_o2.x) < 25) & (abs(car_o2.y + 100) < 15)))) {
         stop();
      }
   }
   if (car_m2.selected) {
      if ((((abs(car_m2.x - car_o.x) < 25) & (abs(car_o.y + 100) < 30)) |
           ((abs(car_m2.x - car_o1.x) < 25) & (abs(car_o1.y + 100) < 30)) |
           ((abs(car_m2.x - car_o2.x) < 25) & (abs(car_o2.y + 100) < 30)))) {
         stop();
      }
   }
   if (car_m3.selected) {
      if ((((abs(car_m3.x - car_o.x) < 25) & (abs(car_o.y + 100) < 15)) |
           ((abs(car_m3.x - car_o1.x) < 25) & (abs(car_o1.y + 100) < 15)) |
           ((abs(car_m3.x - car_o2.x) < 25) & (abs(car_o2.y + 100) < 15)))) {
         stop();
      }
   }
}

void draw_street() {
   glBegin(GL_QUADS);
   glColor3f(0.159412, 0.159412, 0.159412);
   glVertex2i(-75, 200);
   glVertex2i(75, 200);
   glVertex2i(75, -200);
   glVertex2i(-75, -200);
   glEnd();
}

void draw_tiles() {
   glPushMatrix();
   glTranslatef(0, tile1_movement, 0);
   glBegin(GL_QUADS);
   glColor3f(0.85, 0.85, 0.85);
   glVertex2i(-25, -200);
   glVertex2i(-30, -200);
   glVertex2i(-30, -120);
   glVertex2i(-25, -120);
   
   glVertex2i(25, -200);
   glVertex2i(30, -200);
   glVertex2i(30, -120);
   glVertex2i(25, -120);
   glEnd();
   
   tile1_movement -= speed_tiles;
   if (tile1_movement <= -280) {
      glLoadIdentity();
      tile1_movement = 400;
      glTranslatef(0, tile1_movement, 0);
   }
   glPopMatrix();
  
   glPushMatrix();
   glTranslatef(0, tile2_movement, 0);
   glBegin(GL_QUADS);
   
   glColor3f(0.85, 0.85, 0.85);
   glVertex2i(-25, -100);
   glVertex2i(-30, -100);
   glVertex2i(-30, -20);
   glVertex2i(-25, -20);
   
   glVertex2i(25, -100);
   glVertex2i(30, -100);
   glVertex2i(30, -20);
   glVertex2i(25, -20);
   
   glEnd();
   tile2_movement -= speed_tiles;
   if (tile2_movement <= -280) {
      glLoadIdentity();
      tile2_movement = 400;
      glTranslatef(0, tile2_movement, 0);
   }
   glPopMatrix();
   
   glPushMatrix();
   glTranslatef(0, tile3_movement, 0);
   glBegin(GL_QUADS);
   glColor3f(0.85, 0.85, 0.85);
   glVertex2i(-25, 0);
   glVertex2i(-30, 0);
   glVertex2i(-30, 80);
   glVertex2i(-25, 80);
   
   glVertex2i(25, 0);
   glVertex2i(30, 0);
   glVertex2i(30, 80);
   glVertex2i(25, 80);
   glEnd();
   tile3_movement -= speed_tiles;
   if (tile3_movement <= -280) {
      glLoadIdentity();
      tile3_movement = 400;
      glTranslatef(0, tile3_movement, 0);
   }
   
   glPopMatrix();
}

void game() {
   draw_street();
   draw_tiles();
   if (car_m.selected) {
      car_m.draw_car_m();
   }
   else if (car_m2.selected) {
      car_m2.draw_car_mohab();
   }
   else if (car_m3.selected) {
      car_m3.draw_car_badr();
   }
   if (untouchable) {
      glPushMatrix();
      
      if (car_m.selected) {
         glColor3f(car_m.r, car_m.g, car_m.b);
         glTranslatef(car_m.x, car_m.y + 190, 0);
      }
      if (car_m2.selected) {
         glColor3f(car_m2.r, car_m2.g, car_m2.b);
         glTranslatef(car_m2.x, car_m2.y + 190, 0);
      }
      if (car_m3.selected) {
         glColor3f(car_m3.r, car_m3.g, car_m3.b);
         glTranslatef(car_m3.x, car_m3.y + 190, 0);
      }
      glBegin(GL_LINE_LOOP);
      glVertex2d(-15, -120);
      glVertex2d(-12, -117);
      glVertex2d(0, -115);
      glVertex2d(12, -117);
      glVertex2d(15, -120);
      glEnd();
      glPopMatrix();
      
      glColor3f(1, 1, 1);
      glRasterPos3f(150, -110, 0);
      string s = "invincible";
      for (int i = 0; i < s.length(); i++)
      {
         glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s.at(i));
      }
      
      glRasterPos3f(150, -120, 0);
      invincible_up_timef -= 0.02;
      if (modf(invincible_up_timef, &intpart) < 0.02)
      {
         invincible_up_time--;
      }
      string number = to_string (invincible_up_time);
      for (int i = 0; i < number.length(); i++)
      {
         glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, number.at(i));
      }
   }
   
   if (doublescore) {
      glColor3f(1, 1, 1);
      glRasterPos3f(150, -160, 0);
      string s = "Double points";
      
      for (int i = 0; i < s.length(); i++)
      {
         glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s.at(i));
      }
      glRasterPos3f(150, -170, 0);
      
      double_score_up_timef -= 0.02;
      if (modf(double_score_up_timef, &intpart) < 0.02)
      {
         double_score_up_time--;
      }
      
      string number = to_string(double_score_up_time);
      
      for (int i = 0; i < number.length(); i++)
      {
         glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, number.at(i));
      }
      
   }
   
   car_o.draw_car_o();
   car_o1.draw_car_o();
   car_o2.draw_car_o();
   
//   if (score % 10 == 0 & score !=0) {
//      speed_tiles  += 0.006;
//      car_o.speed  += 0.006;
//      car_o1.speed += 0.006;
//      car_o2.speed += 0.006;
//      speed_move += 0.009;
//   }
   Drawscore(score, 150, -190, 0);
   if (!crashed) {
      scoref += 0.02;
      if (modf(scoref, &intpart) < 0.02)
      {
         if (!doublescore) {
            score += 1;
         }
         else {
            score += 2;
         }
         
      }
   }
   
   invincible.draw_power_up_invincible(score);
   double_score.draw_power_up_double_score(score);
   
   power_up_check();
   if (invincible_nottaken) {
      crash_check();
   }
}

void menu() {
   glClearColor(0, 0, 0, 1);
   glClear(GL_COLOR_BUFFER_BIT);
   draw_street();
   draw_tiles();
   if (car_m.selected) {
      car_m.draw_car_m();
   }
   else if (car_m2.selected) {
      car_m2.draw_car_mohab();
   }
   else if (car_m3.selected) {
      car_m3.draw_car_badr();
   }
   
   glColor3f(0.2, 0.2, 0.2);
   glBegin(GL_QUADS);
   glVertex2f(-50,100);
   glVertex2f(50, 100);
   glVertex2f(50, 50);
   glVertex2f(-50, 50);
   glEnd();
   glColor3f(0.2, 0.2, 0.2);
   glBegin(GL_QUADS);
   glVertex2f(-40, -60);
   glVertex2f(40, -60);
   glVertex2f(40, -100);
   glVertex2f(-40, -100);
   glEnd();
   glColor3f(1, 1, 1);
   
   glRasterPos3f(-20, 70, 0);
   string s1 = "Car Crash";
   string s2 = "Press Enter to play";
   string s3 = "Press Esc to exit";
   string s4 = "Press Left or Right to change the car";
   
   
   for (int i = 0; i < s1.length(); i++)
   {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s1.at(i));
   }
    
   glRasterPos3f(-35, -75, 0);
   for (int i = 0; i < s2.length(); i++)
   {
      glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s2.at(i));
   }
   
   glRasterPos3f(-35, -90, 0);
   for (int i = 0; i < s3.length(); i++)
   {
      glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s3.at(i));
   }
   
   glRasterPos3f(-60, 20, 0);
   for (int i = 0; i < s4.length(); i++)
   {
      glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s4.at(i));
   }
   
}

void Display() {
   
   if (!inmenu) {
      glClearColor(0, 0, 0, 1);
      glClear(GL_COLOR_BUFFER_BIT);
      game();
   }
   else {
      menu();
   }
   
   glutSwapBuffers();
}


int main(int argc, char* argv[]) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_RGBA | GL_DOUBLE);
   glutInitWindowPosition(100, 100);
   glutInitWindowSize(1020, 720);
   glutCreateWindow("Car Crash");
   glutTimerFunc(0, timer, 0);
   glutDisplayFunc(Display);
   glutKeyboardFunc(OnKeyPress);
   glutSpecialFunc(OnSpecKeyPress);
   
   SetTransformations();
   car_m.selected = true;
   glutMainLoop();
   
   return 0;
}
