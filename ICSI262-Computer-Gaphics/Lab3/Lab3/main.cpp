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

int sides = 0;
float red = 0, blue = 0, green = 0;
 
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
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(red, green, blue);
    
    float dist = 0.5;
    float startAngle = -M_PI * (sides - 2) / 2 / sides;
   
    
    glBegin(GL_POLYGON);
    
    for (int i = 0; i < sides; ++i)
    {
        float sideAngle = M_PI * 2.0 * i / sides + startAngle;
        float x = dist * cos(sideAngle);
        float y = dist * sin(sideAngle);
        glVertex2f(x, y);
    }
    
    glEnd();
    glFlush();
}

void special(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:
            sides++;
            break;
        case GLUT_KEY_DOWN:
            if (sides >= 2){
                sides--;
            }
            break;
        default:
            break;
    }
    
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

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    
    glutCreateWindow("Shape");
    cout << "Dursiin taliin too: ";
    cin >> sides;

    glutDisplayFunc(display);
    glutSpecialFunc(special);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(resize);

    glClearColor(1, 1, 1, 1);
    glutMainLoop();

    return EXIT_SUCCESS;
}
