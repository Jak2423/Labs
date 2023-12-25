
#define GL_SILENCE_DEPRECATION
#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
 


void resize(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-2.0, 2.0, -2.0, 2.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}


void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(10.0);
    glBegin(GL_POINT);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef(1, 0, 0);
   glRotatef(90, 1, 0, 0);
   glRotatef(90, 0, 1, 0);
   glBegin(GL_POINTS);
   glVertex3f(1, 0, 0);
    glEnd();
    glFlush();
}
 
/* Program entry point */
 

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

    glutCreateWindow("Shape");
    glutDisplayFunc(display);
    glutReshapeFunc(resize);

    glClearColor(1, 1, 1, 1);
    glutMainLoop();

 

    return EXIT_SUCCESS;
}
