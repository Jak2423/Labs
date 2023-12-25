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

float side1[3][3] = {
   0.0f, 0.8f, 0.0f ,
   -0.8f, -0.8f, 0.8f,
   0.8f, -0.8f, 0.8f,
};

float side2[3][3] = {
   0.0f, 0.8f, 0.0f,
   -0.8f, -0.8f, 0.8f,
   0.0f, -0.8f, -0.8f,
};

float side3[3][3] = {
   0.0f, 0.8f, 0.0f,
   0.0f, -0.8f, -0.8f,
   0.8f, -0.8f, 0.8f,
};

float side4[3][3] = {
   -0.8f, -0.8f, 0.8f,
   0.0f, -0.8f, -0.8f,
   0.8f, -0.8f, 0.8f,
};

void ChangeSize(int w, int h)
{
   GLfloat fAspect;
   if(h == 0)
      h = 1;
   
   glViewport(0, 0, w, h);
   fAspect = (GLfloat)w / (GLfloat)h;
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(35.0f, fAspect, 1.0, 40.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void normalize(float *v) {
   float length = sqrt(v[0]* v[0] + v[1] * v[1] + v[2] * v[2]);
   
   for(int i = 0; i < 3 ; i++) {
      v[i] = v[i] / length;
   }
}

float *cross_product(float *a, float *b) {
   float result[] = {a[1] * b[2] - a[2] * b[1], -(a[0] * b[2] - a[2] * b[0]), a[0] * b[1] - a[1] * b[0]};
   
   normalize(result);
   
   return result;
}

float *calculate_normal(float *a, float *b, float *c) {
   float x[] = {b[0] - a[0], b[1] - a[1], b[2] - a[2]};
   float y[] = {c[0] - a[0], c[1] - a[1], c[2] - a[2]};
   
   float *result = cross_product(x, y);
   
   return result;
}

void SetupMaterial()
{
   glEnable(GL_COLOR_MATERIAL);
   GLfloat  whiteLight[] = { 0.08f, 0.08f, 0.08f, 1.0f };
   GLfloat  sourceLight[] = { 0.25f, 0.25f, 0.25f, 1.0f };
   GLfloat    lightPos[] = { -10.f, -5.0f, -3.0f, 1.0f };
   
   glEnable(GL_DEPTH_TEST);
   glFrontFace(GL_CCW);
   glEnable(GL_LIGHTING);
   
   glLightModelfv(GL_LIGHT_MODEL_AMBIENT,whiteLight);
   glLightfv(GL_LIGHT0,GL_AMBIENT,sourceLight);
   glLightfv(GL_LIGHT0,GL_DIFFUSE,sourceLight);
   glLightfv(GL_LIGHT0,GL_POSITION,lightPos);
   glEnable(GL_LIGHT0);
   
   glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
   
   GLfloat mat[4];
   mat[0] =  0.24725f; mat[1] = 0.1995f; mat[2] = 0.0745f; mat[3] = 1.0f;
   glMaterialfv(GL_FRONT, GL_AMBIENT, mat);
   mat[0] = 0.75164f; mat[1] = 0.60648f; mat[2] = 0.22648f;
   glMaterialfv(GL_FRONT, GL_DIFFUSE, mat);
   mat[0] = 0.628281f; mat[1] = 0.555802f; mat[2] = 0.366065f;
   glMaterialfv(GL_FRONT, GL_SPECULAR, mat);
   glMaterialf(GL_FRONT, GL_SHININESS, 51.2f * 128.0);

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

void draw_pyramid() {
   glBegin(GL_TRIANGLES);
   glNormal3fv(calculate_normal(side1[0], side1[1], side1[2]));
   glVertex3fv( side1[0] );
   glVertex3fv( side1[1] );
   glVertex3fv( side1[2]);
   glNormal3fv(calculate_normal(side2[0], side2[1], side2[2]));
   glVertex3fv( side2[0]);
   glVertex3fv( side2[1]);
   glVertex3fv( side2[2]);
   glNormal3fv(calculate_normal(side3[0], side3[1], side3[2]));
   glVertex3fv( side3[0]);
   glVertex3fv( side3[1]);
   glVertex3fv( side3[2]);
   glNormal3fv(calculate_normal(side4[0], side4[1], side4[2]));
   glVertex3fv( side4[0]);
   glVertex3fv( side4[1]);
   glVertex3fv( side4[2]);
   glEnd();
}

void render(void)
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   
   glPushMatrix();
   glTranslatef(0.0f, 0.0f, -6.0f);
   glRotatef(xRot, 1.0f, 0.0f, 0.0f);
   glRotatef(yRot, 0.0f, 1.0f, 0.0f);
   
   //   glRotated(120, 1, 0, 0);
   //      glTranslatef(0.0f, 0.0, 0.0f);
   //      glColor3f(0.921875, 0.6171875, 0.69140625);
   //      glScaled(1.05, 1, 1.05);
   //      glutSolidTorus(0.3, 0.6, 16, 16);
   //      glColor3f(0.94140625, 0.69140625, 0.3984375);
   //      glTranslated(0, 0, 0.1);
   //      glScaled(0.95, 1, 0.95);
   //      glutSolidTorus(0.3, 0.6, 16, 16);
   
   draw_pyramid();

   
   glPopMatrix();
   glutSwapBuffers();
}


int main(int argc, char *argv[])
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize(800, 600);
   glutCreateWindow("Material");
   glutReshapeFunc(ChangeSize);
   glutSpecialFunc(SpecialKeys);
   glutDisplayFunc(render);
   SetupMaterial();
   glutMainLoop();
   
   return 0;
}



