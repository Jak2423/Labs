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

static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;

void ChangeSize(int w, int h)
{
   GLfloat fAspect;
   if(h == 0)
      h = 1;
   
   glViewport(0, 0, w, h);
   fAspect = (GLfloat)w/(GLfloat)h;
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(35.0f, fAspect, 1.0, 40.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void SetupRC()
{
   GLfloat  whiteLight[] = { 0.05f, 0.05f, 0.05f, 1.0f };
   GLfloat  sourceLight[] = { 0.25f, 0.25f, 0.25f, 1.0f };
   GLfloat    lightPos[] = { -10.f, 5.0f, 5.0f, 1.0f };
   
   glEnable(GL_DEPTH_TEST);
   glFrontFace(GL_CCW);
   glEnable(GL_CULL_FACE);
   glEnable(GL_LIGHTING);
   
   glLightModelfv(GL_LIGHT_MODEL_AMBIENT,whiteLight);
   glLightfv(GL_LIGHT0,GL_AMBIENT,sourceLight);
   glLightfv(GL_LIGHT0,GL_DIFFUSE,sourceLight);
   glLightfv(GL_LIGHT0,GL_POSITION,lightPos);
   glEnable(GL_LIGHT0);
   
   glEnable(GL_COLOR_MATERIAL);
   
   glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
   glClearColor(0.0f, 0.0f, 0.0f, 0.0f );
}

void SpecialKeys(int key, int x, int y)
{
   if(key == GLUT_KEY_UP)
      xRot-= 5.0f;
   
   if(key == GLUT_KEY_DOWN)
      xRot += 5.0f;
   
   if(key == GLUT_KEY_LEFT)
      yRot -= 5.0f;
   
   if(key == GLUT_KEY_RIGHT)
      yRot += 5.0f;
   
   xRot = (GLfloat)((const int)xRot % 360);
   yRot = (GLfloat)((const int)yRot % 360);
   
   glutPostRedisplay();
}

void RenderRobot(void)
{
   GLUquadricObj *pObj;
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   
   glPushMatrix();
   glTranslatef(0.0f, 1.0f, -5.0f);
   glRotatef(xRot, 1.0f, 0.0f, 0.0f);
   glRotatef(yRot, 0.0f, 1.0f, 0.0f);
   pObj = gluNewQuadric();
   gluQuadricNormals(pObj, GLU_SMOOTH);
   
   //Head
   glPushMatrix();
   glColor3f(0.51f, 0.55f, 0.62f);
   glScaled(0.6, 0.3, 0.6);
   glutSolidSphere(0.2, 16, 16);
   
   glTranslatef(0.0f, -0.6, 0.0f);
   glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
   gluCylinder(pObj, 0.2, 0.2, 0.6f, 26, 13);
   glTranslatef(0, 0, 0);
   glTranslatef(0, 0, 0);
   glutSolidSphere(0.2, 16, 16);
   glPopMatrix();
   
   // Body
   glPushMatrix();
   glTranslatef(0.0f, -0.3, 0.0f);
   glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
   gluCylinder(pObj, 0.07, 0.07, 0.15, 26, 13);
   
   glTranslatef(0, 0, -0.25);
   glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
   glScaled(1, 0.7, 0.7);
   glutSolidSphere(0.4, 16, 16);
   
   glTranslatef(0, -0.25, 0);
   glScaled(1.2, 1, 1);
   glutSolidSphere(0.3, 5, 5);
   glPopMatrix();
   
   glColor3f(1, 1, 1);

   // Left eye
   glPushMatrix();
   glTranslatef(-0.04, -0.08, 0.11);
   glScaled(0.3, 0.3, 0.1);
   glutSolidSphere(0.1, 16, 16);
   glPopMatrix();
   
   // Right eye
   glPushMatrix();
   glColor3f(1, 1, 1);
   glTranslatef(0.04, -0.08, 0.11);
   glScaled(0.3, 0.3, 0.1);
   glutSolidSphere(0.1, 16, 16);
   glPopMatrix();
   
   // Jaw
   glColor3f(0.51f, 0.55f, 0.62f);
   glPushMatrix();
   glTranslatef(0, -0.2, 0.05);
   glScaled(1.2, 0.5, 0.8);
   glutSolidCube(0.2);
   glPopMatrix();
   
   // Left arm
   glPushMatrix();
   glTranslated(-0.4, -0.5, 0);
   glScaled(0.8, 1, 1);
   glutSolidSphere(0.1, 16, 16);
   glRotated(-45, 1, 0, 0);
   glTranslated(0, -0.2, 0);
   glScaled(0.6, 1.5, 0.6);
   glutSolidCube(0.2);
   glTranslated(0, -0.1, 0);
   glScaled(0.8, 0.2, 0.8);
   glutSolidSphere(0.2, 16, 16);
   glScaled(1, 0.9, 1);
   glTranslated(0, -0.6, 0);
   glScaled(0.8, 3, 1);
   glutSolidCube(0.4);
   glTranslated(0, -0.2, 0);
   glScaled(0.2, 1, 1);
   glutSolidCube(0.3);
   glPopMatrix();
   
   // Right arm
   glPushMatrix();
   glTranslated(0.4, -0.5, 0);
   glScaled(0.8, 1, 1);
   glutSolidSphere(0.1, 16, 16);
   glRotated(-25, 1, 0, 0);
   glTranslated(0, -0.2, 0);
   glScaled(0.6, 1.5, 0.6);
   glutSolidCube(0.2);
   glTranslated(0, -0.1, 0);
   glScaled(0.8, 0.2, 0.8);
   glutSolidSphere(0.2, 16, 16);
   glScaled(1, 0.9, 1);
   glTranslated(0, -0.6, 0);
   glScaled(0.8, 3, 1);
   glutSolidCube(0.4);
   glTranslated(0, -0.2, 0);
   glScaled(0.2, 1, 1);
   glutSolidCube(0.3);
   glPopMatrix();
   
   
   // Pelvis
   glPushMatrix();
   glTranslated(0, -0.9, 0);
   glScaled(1, 1.5, 0.7);
   glutSolidCube(0.2);
   
   glTranslated(0, -0.07, 0);
   glScaled(1.1, 0.1, 0.2);
   glutSolidCube(0.5);
   glPopMatrix();
   
   // Right leg
   glPushMatrix();
   glTranslated(0.25, -1.02, 0);
   glScaled(0.7, 1, 1);
   glutSolidSphere(0.1, 16, 16);
   
   glTranslated(0, -0.2, 0);
   glScaled(0.6, 1.5, 0.6);
   glutSolidCube(0.2);
   glTranslated(0, -0.1, 0);
   glScaled(1, 0.2, 0.8);
   glutSolidSphere(0.2, 16, 16);
   glScaled(1, 0.9, 1);
   glTranslated(0, -0.8, 0);
   glScaled(1, 4, 1);
   glutSolidCube(0.4);
   glTranslated(0, -0.2, 0.2);
   glScaled(1.5, 0.1, 2.5);
   glutSolidCube(0.3);
   glPopMatrix();
   
   // Left leg
   glPushMatrix();
   glTranslated(-0.25, -1.02, 0);
   glScaled(0.7, 1, 1);
   glutSolidSphere(0.1, 16, 16);
   glTranslated(0, -0.2, 0);
   glScaled(0.6, 1.5, 0.6);
   glutSolidCube(0.2);
   glTranslated(0, -0.1, 0);
   glScaled(1, 0.2, 0.8);
   glutSolidSphere(0.2, 16, 16);
   glScaled(1, 0.9, 1);
   glTranslated(0, -0.8, 0);
   glScaled(1, 4, 1);
   glutSolidCube(0.4);
   glTranslated(0, -0.2, 0.2);
   glScaled(1.5, 0.1, 2.5);
   glutSolidCube(0.3);
   glPopMatrix();
   
   glPopMatrix();
   glutSwapBuffers();
}


int main(int argc, char *argv[])
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize(800, 600);
   glutCreateWindow("Iron Giant");
   glutReshapeFunc(ChangeSize);
   glutSpecialFunc(SpecialKeys);
   glutDisplayFunc(RenderRobot);
   SetupRC();
   glutMainLoop();
   
   return 0;
}



