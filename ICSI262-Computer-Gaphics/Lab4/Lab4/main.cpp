#define GL_SILENCE_DEPRECATION
#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <iostream>
#include <math.h>
using namespace std;

void setOrtho(float l, float r, float b, float t) {
   glLoadIdentity();
   glOrtho(l, r, b, t, 1, -1);
   
}
void displaySinex ( void ) {
      glClear(GL_COLOR_BUFFER_BIT);
      glMatrixMode( GL_PROJECTION );
      glLoadIdentity();
      glPointSize(0.5);
      glColor3f(0.0, 0.0, 0.0);
   
      int j = 1, k = 1;
      for(int i = 1; i <= 15; i++) {
         float  yView = 100 - (j - 1) * 100;
         if(i % 5 == 0) {
            j++;
         }
         
         for(float x = 40.0; x <= 360.0; x += 1.0)
         {
            float y = 30 * sin(x * ( M_PI / 180.0));
            setOrtho(-360.0, 360.0, -120.0, 120.0);
            glViewport(-120 + (k - 1) * 120, yView, 300, 300);
            glBegin(GL_LINE_STRIP);
            glVertex2f(x, y);
         }
         
         if(i % 5 == 0) {
            k = 0;
         }
         
         k++;
         glEnd();
      }
   
      j = 1;
      k = 1;

      for(int i = 1; i <= 15; i++) {
         float  yView = 100 - (j - 1) * 100;
         if(i % 5 == 0) {
            j++;
         }
         
         for(float x = 40.0; x <= 360.0; x += 1.0)
         {
            float y = 30 * sin(x * ( M_PI / 180.0));
            if(i % 2 != 0) {
               setOrtho(-360.0, 360.0, 120.0, -120.0);
            }
            else {
               setOrtho(-360.0, 360.0, -120.0, 120.0);
            }
            glViewport(580 + (k - 1) * 120, yView, 300, 300);
            glBegin(GL_LINE_STRIP);
            glVertex2f(x, y);
         }
         
         if(i % 5 == 0) {
            k = 0;
         }
         k++;
         glEnd();
      }

   glFlush();
}
   
int main(int argc, char *argv[]) {
       glutInit(&argc, argv);
       glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
       glutInitWindowSize(1400, 300.0);
       glutCreateWindow("Shape");
       glutDisplayFunc(displaySinex);
       glClearColor(1, 1, 1, 1);
       glutMainLoop();

       return EXIT_SUCCESS;
}

