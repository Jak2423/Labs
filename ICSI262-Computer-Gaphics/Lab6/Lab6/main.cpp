#define GL_SILENCE_DEPRECATION
#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <iostream>
using namespace std;

#define WIDTH 500
#define HEIGHT 500
#define MAX_ITEMS 2000

typedef struct{
   double x;
   double y;
} point;

point points[MAX_ITEMS];
int pointCount = 0;

float red = 0, blue = 0, green = 0;
bool dragging = false;

void reshape(int width, int height) {
   glViewport(0, 0, width, height);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(0, WIDTH, 0, HEIGHT);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity() ;
}

void display() {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glColor3f(red, green, blue);
   glPointSize(3.0);

   for(int i = 0;  i < pointCount; i++) {
      glBegin(GL_POINTS);
      glVertex2f(points[i].x, points[i].y);
   
      glEnd();
   }
   
   glutSwapBuffers();
   glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'r':
            red = 1;
            green = 0;
            blue = 0;
            break;
        case 'b':
            red = 0;
            green = 0;
            blue = 1;
            break;
        case 'g':
            red = 0;
            green = 1;
            blue = 0;
            break;
        default:
            break;
    }
    
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {
   if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
      
      if (pointCount == MAX_ITEMS) {
         return;
      }
      
      dragging = true;
      points[pointCount].x = (double) x;
      points[pointCount].y = (double) HEIGHT - y;
      pointCount++;

   } else {
      dragging = false;
   }
   
   glutPostRedisplay();
}

void motion(int x, int y) {
   if(dragging && pointCount != MAX_ITEMS) {
      points[pointCount].x = (double) x;
      points[pointCount].y = (double) HEIGHT - y;
      pointCount++;
   }
}

int main(int argc, char *argv[]) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize(WIDTH, HEIGHT);
   glutInitWindowPosition(400, 100);
   glutCreateWindow("Shape");
   glutReshapeFunc(reshape);
   glutDisplayFunc(display);
   glutKeyboardFunc(keyboard);
   glutMouseFunc(mouse);
   glutMotionFunc(motion);
   
   glClearColor(1, 1, 1, 1);
   glutMainLoop();
   
   return EXIT_SUCCESS;
}


