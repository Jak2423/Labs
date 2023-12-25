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

#define WIDTH 1000
#define HEIGHT 660

bool dragging = false;
double dim = 4.0;
int th = 0;
int ph = 0;
float currentX,  currentY, prevX, prevY;

void reshape(int width, int height) {
   glViewport(0,0, width, height);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-dim, +dim, -dim, +dim, -dim, +dim);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void drawObjects() {
   glPushMatrix();
   glColor3f(0.0, 0.0, 0.0);
   glRotated(60, 1, 1, 0);
   glTranslated(0, 1.5, 1);
   glutWireSphere(0.5, 16, 16);
   glPopMatrix();
   
   glPushMatrix();
   glColor3f(0.046, 0.339, 0.742);
   glTranslated(2, 0.5, 1);
   glutWireCube(1);
   glPopMatrix();
   
   glPushMatrix();
   glColor3f(0.68, 0.57, 0.41);
   glRotated(90, 1, 0, 0);
   glTranslated(2.5, 2.5, -0.3);
   glScaled(1, 1, 2);
   glutWireTorus(0.2, 0.4, 16, 16);
   glPopMatrix();
}

void drawTable() {
   glColor3f(0.42, 0.37, 0.355);
   glViewport(-200  , 0, WIDTH + 500, HEIGHT);
   glBegin(GL_QUADS);
   glVertex3d(0, 0, 0);
   glVertex3d(0, 0, 4);
   glVertex3d(4, 0, 4);
   glVertex3d(4, 0, 0);
   glEnd();
}

void display() {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glEnable(GL_DEPTH_TEST);
   glLoadIdentity();
   
   glTranslated(-2, 0, -2);
   glRotated(ph, 1, 0, 0);
   glRotated(th, 0, 1, 0);
   drawTable();
   drawObjects();
   
   glFlush();
   glutSwapBuffers();
}

void mouse(int button, int state, int x, int y) {
   if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
      dragging = true;
      prevX = x;
      prevY = y;
   } else {
      dragging = false;
   }
   
   glutPostRedisplay();
}

void motion(int x, int y) {
   if(dragging) {
      currentX = (double) x;
      currentY = (double) HEIGHT - y;
      
      if(currentX > prevX  ) {
         th += 2;
      }
      if(currentX < prevX ) {
         th -= 2;
      }
      if(currentY > prevY ) {
         ph -= 2;
      }
      if(currentY < prevY) {
         ph += 2;
      }
      th %= 360;
      ph %= 360;
      
      prevX = currentX;
      prevY = currentY;
      glutPostRedisplay();
   }
}

int main(int argc, char *argv[]) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize(WIDTH, HEIGHT);
   glutCreateWindow("Shape");
   glutReshapeFunc(reshape);
   glutDisplayFunc(display);
   glutMouseFunc(mouse);
   glutMotionFunc(motion);
   glClearColor(1, 1, 1, 1);
   glutMainLoop();
   
   return EXIT_SUCCESS;
}


