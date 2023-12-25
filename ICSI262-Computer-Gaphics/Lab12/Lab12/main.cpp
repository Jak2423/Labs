#define GL_SILENCE_DEPRECATION
#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
using namespace std;

typedef struct {
   unsigned char rgbtBlue;
   unsigned char rgbtGreen;
   unsigned char rgbtRed;
} RGBTriple;


static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;
GLuint texture_num;

struct Vertex {
   GLfloat x, y, z;
};

struct Face {
   GLuint v1, vt1, vn1, v2, vt2, vn2, v3, vt3, vn3, v4, vt4, vn4;
};

struct Normal {
   GLfloat x, y, z;
};

struct Texture {
   GLfloat u, v;
};

vector<Vertex> vertices;
vector<Face> faces;
vector<Normal> normals;
vector<Texture> textures;

GLuint loadTexture(const char *filename) {
   GLuint textureID;
   int i, j = 0;
   FILE *l_file;
   unsigned char header[54];
   unsigned int dataPos;
   unsigned int width, height;
   unsigned int imageSize;
   unsigned char *l_texture;
   
   RGBTriple rgb;
   
   if( (l_file = fopen(filename, "rb"))==NULL) return (-1);
   
   fread(header, 1, sizeof(header), l_file);
   
   dataPos = *(int *)&(header[0x0A]);
   imageSize = *(int *)&(header[0x22]);
   width = *(int *)&(header[0x12]);
   height = *(int *)&(header[0x16]);
   l_texture = (unsigned char *) malloc(width * height * 4);
   memset(l_texture, 0, width * height * 4);
   
   
   for (i = 0; i < width * height; i++)
   {
      fread(&rgb, sizeof(rgb), 1, l_file);
      
      l_texture[j+0] = rgb.rgbtRed;
      l_texture[j+1] = rgb.rgbtGreen;
      l_texture[j+2] = rgb.rgbtBlue;
      l_texture[j+3] = 255;
      j += 4;
   }
   
   fclose(l_file);
   
   glGenTextures(1, &textureID);
   glBindTexture(GL_TEXTURE_2D, textureID);
   
   glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
   glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
   glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
   glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
//   glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, l_texture);
   gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, width, height, GL_RGBA, GL_UNSIGNED_BYTE, l_texture);
   free(l_texture);
   
   return textureID;
}


void init(void) {
   glEnable(GL_COLOR_MATERIAL);
   glShadeModel(GL_SMOOTH);
   GLfloat  whiteLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
   GLfloat  sourceLight[] = { 0.25f, 0.25f, 0.25f, 1.0f };
   GLfloat    lightPos[] = { -80.f, -80.0f, -80.0f, 1.0f };
   
   glEnable(GL_DEPTH_TEST);
   glFrontFace(GL_CCW);
   glEnable(GL_LIGHTING);
   glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
   
   glLightModelfv(GL_LIGHT_MODEL_AMBIENT,whiteLight);
   glLightfv(GL_LIGHT0,GL_AMBIENT,sourceLight);
   glLightfv(GL_LIGHT0,GL_DIFFUSE,sourceLight);
   glLightfv(GL_LIGHT0,GL_POSITION,lightPos);
   glEnable(GL_LIGHT0);
   glEnable(GL_LIGHTING);
   
   glEnable(GL_TEXTURE_2D);
   texture_num = loadTexture("Texture.bmp");
   if (texture_num == -1)
   {
      printf("can't open texture file\n");
      exit(1);
   }
   
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
   gluPerspective(45.0, fAspect, -1, 10);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void loadObj(const char *fname){
   FILE *fp;
   int read;
   GLfloat x, y, z;
   GLuint v1, vt1, vn1, v2, vt2, vn2, v3, vt3, vn3, v4, vt4, vn4;
   char ch[128];
   
   vertices.clear();
   faces.clear();
   textures.clear();
   fp = fopen(fname, "r");
   
   if (fp == NULL)
   {
      printf("can't open file: %s\n", fname);
      exit(1);
   }
   
   while(!(feof(fp)))
   {
      read = fscanf(fp,"%s", ch);
      if (read == EOF) break;
      
      if(strcmp(ch, "v") == 0) {
         fscanf(fp, "%f %f %f", &x, &y, &z);
         vertices.push_back({x, y, z});
      }
      else if(strcmp(ch, "vt") == 0){
         fscanf(fp, "%f %f", &x, &y);
         textures.push_back({x, y});
      }
      else if(strcmp(ch, "vn") == 0){
         fscanf(fp, "%f %f %f", &x, &y, &z);
         normals.push_back({x, y, z});
      }
      else if(strcmp(ch, "f") == 0){
         fscanf(fp, "%u/%u/%u %u/%u/%u %u/%u/%u %u/%u/%u", &v1, &vt1, &vn1, &v2, &vt2, &vn2, &v3, &vt3, &vn3, &v4, &vt4, &vn4);
         faces.push_back({ v1, vt1, vn1, v2, vt2, vn2, v3, vt3, vn3, v4, vt4, vn4});
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

void drawObj()
{
   glPushMatrix();
   glColor3f(1.0, 1.0, 1.0);
   glRotatef(xRot, 1.0f, 0.0f, 0.0f);
   glRotatef(yRot, 0.0f, 1.0f, 0.0f);
   glBindTexture(GL_TEXTURE_2D, texture_num);
   for(Face face : faces) {
      glBegin(GL_QUADS);
      Vertex v1 = vertices[face.v1 - 1];
      Vertex v2 = vertices[face.v2 - 1];
      Vertex v3 = vertices[face.v3 - 1];
      Vertex v4 = vertices[face.v4 - 1];
      
      Texture t1 = textures[face.vt1 - 1];
      Texture t2 = textures[face.vt2 - 1];
      Texture t3 = textures[face.vt3 - 1];
      Texture t4 = textures[face.vt4 - 1];
      
      Normal n1 = normals[face.vn1 - 1];
      Normal n2 = normals[face.vn2 - 1];
      Normal n3 = normals[face.vn3 - 1];
      Normal n4 = normals[face.vn4 - 1];
      
      glTexCoord2f(t1.u, t1.v);
      glNormal3f(n1.x, n1.y, n1.z);
      glVertex3f(v1.x, v1.y, v1.z);
      
      
      glTexCoord2f(t2.u, t2.v);
      glNormal3f(n2.x, n2.y, n2.z);
      glVertex3f(v2.x, v2.y, v2.z);
      
      glTexCoord2f(t3.u, t3.v);
      glNormal3f(n3.x, n3.y, n3.z);
      glVertex3f(v3.x, v3.y, v3.z);
      
      glTexCoord2f(t4.u, t4.v);
      glNormal3f(n4.x, n4.y, n4.z);
      glVertex3f(v4.x, v4.y, v4.z);
      
      glEnd();
   }
   glPopMatrix();
}

void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glLoadIdentity();
   glScaled(0.1, 0.1, 0.1);
   glTranslated(0, -5, 0);
   glRotated(180, 0, 1, 0);
   loadObj("Character.obj");
   drawObj();
   glutSwapBuffers();
}


int main(int argc, char *argv[])
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize(800, 600);
   glutCreateWindow("Load Obj");
   glutReshapeFunc(ChangeSize);
   glutSpecialFunc(SpecialKeys);
   glutDisplayFunc(display);
   init();
   glutMainLoop();
   
   return 0;
}




