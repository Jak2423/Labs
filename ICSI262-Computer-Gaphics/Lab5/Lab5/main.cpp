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

float timeChange = -0.1;
int globalBoolean = 0;

typedef struct{
   float x;
   float y;
} point;

point startPoints[] = {
   {0, -2},
   {-2, -2},
   {-2, 2},
   {2, 2},
   {2, -2},
   
};

point endPoints[] = {
   {0, -1},
   {-2, 1},
   {-1, 2},
   {1, 2},
   {2, 1},
};

void reshape(int width, int height) {
   glViewport(0, 0, width, height);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(-3, 3, -3, 3);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity() ;
}


void display() {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glColor3f(1.0, 0.0, 0.0);
   glPointSize(1.0);
   glLineWidth(1.0);
   glBegin(GL_LINE_LOOP);
   
   if (timeChange > 1)
   {
      globalBoolean = 1;
   }
   else if (timeChange < 0.1)
   {
      globalBoolean = 0;
   }
   if (globalBoolean)
   {
      timeChange -= 0.01;
   }
   else
   {
      timeChange += 0.01;
   }
   
   point a, b, c, d, e;
   a.x = (1 - timeChange) * startPoints[0].x + timeChange * endPoints[0].x;
   a.y = (1 - timeChange) * startPoints[0].y + timeChange * endPoints[0].y;
   b.x = (1 - timeChange) * startPoints[1].x + timeChange * endPoints[1].x;
   b.y = (1 - timeChange) * startPoints[1].y + timeChange * endPoints[1].y;
   c.x = (1 - timeChange) * startPoints[2].x + timeChange * endPoints[2].x;
   c.y = (1 - timeChange) * startPoints[2].y + timeChange * endPoints[2].y;
   d.x = (1 - timeChange) * startPoints[3].x + timeChange * endPoints[3].x;
   d.y = (1 - timeChange) * startPoints[3].y + timeChange * endPoints[3].y;
   e.x = (1 - timeChange) * startPoints[4].x + timeChange * endPoints[4].x;
   e.y = (1 - timeChange) * startPoints[4].y + timeChange * endPoints[4].y;
   glVertex2f(a.x, a.y);
   glVertex2f(b.x, b.y);
   glVertex2f(c.x, c.y);
   glVertex2f(d.x, d.y);
   glVertex2f(e.x, e.y);
   glEnd();
   
   glutSwapBuffers();
   
}

void timer(int state)
{
   glutPostRedisplay();
   glutTimerFunc(40, timer, 0);
}

int main(int argc, char *argv[]) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize(400, 400);
   glutCreateWindow("Animation");
   glutReshapeFunc(reshape);
   glutDisplayFunc(display);
   glutTimerFunc(1, timer, 0);
   
   glClearColor(0, 0, 0, 1);
   glutMainLoop();
   
   return EXIT_SUCCESS;
}
