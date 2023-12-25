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
bool isChange = false;

struct Vertex {
   GLfloat x, y, z;
};

struct Face {
   GLuint v1, v2, v3;
};

vector<Vertex> vertices;
vector<Face> faces;

void init(void) {
   float ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
   float diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
   float specular[] ={ 1.0f, 1.0f, 1.0f, 1.0f };
   float position[] = { 200.0f, 300.0f, 100.0f, 0.0f };
   
   float mat_ambient[] ={ 0.19225f, 0.19225f, 0.19225f, 1.0f };
   float mat_diffuse[] ={ 0.50754f, 0.50754f, 0.50754f, 1.0f};
   float mat_specular[] ={0.508273f, 0.508273f, 0.508273f, 1.0f };
   float shine = 51.2f;
   
   glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
   glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
   glLightfv(GL_LIGHT0, GL_POSITION, position);
   glEnable(GL_LIGHT0);
   
   glEnable(GL_DEPTH_TEST);
   glFrontFace(GL_CCW);
   glEnable(GL_CULL_FACE);
   glEnable(GL_LIGHTING);
   
   glEnable(GL_COLOR_MATERIAL);
   glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

   
   glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
   glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
   glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
   glMaterialf(GL_FRONT, GL_SHININESS, shine * 128.0);
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f );
}

void ChangeSize(int w, int h)
{
   GLfloat fAspect;
   if(h == 0)
      h = 1;
   
   glViewport(0, 0, w, h);
   fAspect = (GLfloat) w / (GLfloat) h;
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void loadObj(const char *fname){
   FILE *fp;
   int read;
   GLfloat x, y, z;
   GLuint v1, v2, v3;
   char ch;
   
   vertices.clear();
   faces.clear();
   fp = fopen(fname, "r");
   
   if (fp == NULL)
   {
      printf("can't open file %s\n", fname);
      exit(1);
   }
   
   while(!(feof(fp)))
   {
      read = fscanf(fp,"%c", &ch);
      if (read == EOF) break;
      
      switch(ch) {
         case 'v':
            fscanf(fp, "%f %f %f", &x, &y, &z);
            vertices.push_back({x, y, z});
            break;
         case 'f':
            fscanf(fp, "%u %u %u", &v1, &v2, &v3);
            faces.push_back({v1, v2, v3});
            break;
         default:
            break;
      }
   }
   fclose(fp);
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

void keyboard(unsigned char key, int x, int y) {
   if(key == 't') {
      isChange = !isChange;
   }
   
   glutPostRedisplay();
}


void drawObj()
{
   glPushMatrix();
   glColor3f(1.0, 1.0, 1.0);
   glTranslated(0, 0, 0);
   glRotated(-90, 1, 0, 0);
   glRotatef(xRot, 1.0f, 0.0f, 0.0f);
   glRotatef(yRot, 0.0f, 0.0f, 1.0f);
   glBegin(GL_TRIANGLES);
   glColor3f(0.45, 0.45, 0.45);
   
   for(Face face : faces) {
      Vertex v1  = vertices[face.v1 - 1];
      Vertex v2 = vertices[face.v2 - 1];
      Vertex v3 = vertices[face.v3 - 1];
      
      GLfloat nx = (v2.y - v1.y) * (v3.z - v1.z) - (v2.z - v1.z) * (v3.y - v1.y);
      GLfloat ny = (v2.z - v1.z) * (v3.x - v1.x) - (v2.x - v1.x) * (v3.z - v1.z);
      GLfloat nz = (v2.x - v1.x) * (v3.y - v1.y) - (v2.y - v1.y) * (v3.x - v1.x);
      
      GLfloat length = sqrt(nx * nx + ny * ny + nz * nz);
      nx /= length;
      ny /= length;
      nz /= length;
      
      glNormal3f(nx, ny, nz);
      glVertex3f(v1.x, v1.y, v1.z);
      glVertex3f(v2.x, v2.y, v2.z);
      glVertex3f(v3.x, v3.y, v3.z);
   }
   glEnd();
   glPopMatrix();
}

void display(void)
{
   glClearColor (0.0 ,0.0, 0.0, 1.0);
   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glLoadIdentity();
   if(isChange)
   {
      glLoadIdentity();
      glOrtho(-25, +25, -25, +25, -25, +25);
      loadObj("bunny.obj");
   }
   else
   {
      glLoadIdentity();
      glOrtho(-1, +1, -1, +1, -1, +1);
      loadObj("dragon.obj");
   }
   
   drawObj();
   glutSwapBuffers();
}


int main(int argc, char *argv[])
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize(800, 600);
   glutCreateWindow("Read Obj");
   glutReshapeFunc(ChangeSize);
   glutSpecialFunc(SpecialKeys);
   glutKeyboardFunc(keyboard);
   glutDisplayFunc(display);
   init();
   glutMainLoop();
   
   return 0;
}



