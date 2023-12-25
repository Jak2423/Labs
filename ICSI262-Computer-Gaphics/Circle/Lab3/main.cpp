
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
 


void resize(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}


void display(void)
{
    double rad = 0.6;
    double angle = 0.1;
//    cout << "Hoorondiin untsug: ";
//    cin >> angle;
    
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(5.0);

    
    glBegin(GL_POLYGON);
    double x, y;
    for(int i = 0; i <= 360; i++) {
        x = rad * cos(i * angle);
        y = rad * sin(i * angle);

        glVertex2f(x, y);
    }

    
    glEnd();
    glFlush();
}

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
