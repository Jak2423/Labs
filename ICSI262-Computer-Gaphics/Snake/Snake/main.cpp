#define GL_SILENCE_DEPRECATION
#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>

#define COLUMNS 40
#define ROWS 40
#define FPS 10
#define UP 1
#define DOWN -1
#define RIGHT 2
#define LEFT -2
#define MAX 60
bool gameOver = false, food = true;
int foodX, foodY;
int snake_len = 5, score = 0;

void DisplayCallback();
void ReshapeCallback(int, int);
void initGrid(int, int);
void drawGrid();
void TimerCallback(int);
void KeyboardCallback(int, int, int);
void randomm (int &x, int &y);

int gridX, gridY;
short sDirection = RIGHT;
int posX[60] = {20, 20, 20, 20, 20}, posY[60] = {20, 19, 18, 17, 16};

void initGrid(int x, int y)
{
  gridX = x;
  gridY = y;
}
void unit(int, int);
void drawGrid()
{
  for(int x = 0; x <= gridX; x++)
  {
    for (int y = 0; y <= gridY; y++)
    {
      unit(x, y);
    }
  }
}

void unit(int x, int y)
{
  if(x == 0 || y == 0 || x == gridX - 1 || y == gridY - 1)
  {
    glLineWidth(3.0);
    glColor3f(1.0, 0.0, 0.0);
  }
  else
  {
    glLineWidth(1.0);
    glColor3f(0.0, 0.0, 0.0);
  }
  
  glBegin(GL_LINE_LOOP);
    glVertex2f(x, y);
    glVertex2f(x + 1, y);
    glVertex2f(x + 1, y + 1);
    glVertex2f(x, y + 1);
  glEnd();
}

void init() {
   
  glClearColor(0.0, 0.0, 0.0, 1.0);
  initGrid(COLUMNS, ROWS);
}

void DrawSnake()
{
  for (int i = snake_len - 1; i > 0; i--)
  {
    posX[i] = posX[i - 1];
    posY[i] = posY[i - 1];
  }
  
  if (sDirection == UP)
  {
    posY[0]++;
  }
  else if(sDirection == DOWN)
  {
    posY[0]--;
  }
  else if(sDirection == RIGHT)
  {
    posX[0]++;
  }
  else if(sDirection == LEFT)
  {
    posX[0]--;
  }
  for (int i = 0; i < snake_len; i++)
  {
    if(i == 0)
    {
      glColor3f(1.0, 0.0, 0.0);
    }
    else
    {
      glColor3f(0.0, 1.0, 0.0);
    }
    glRectd(posX[i], posY[i], posX[i] + 1, posY[i] + 1);
  }
  if(posX[0] == 0 || posX[0] == gridX - 1 || posY[0] == 0 || posY[0] == gridY - 1)
  {
    gameOver = true;
  }
  if(posX[0] == foodX && posY[0] == foodY)
  {
    score++;
    snake_len++;
    if(snake_len > MAX)
    {
      snake_len = MAX;
    }
    food = true;
  }
  for(int j = 1; j < snake_len; j++)
  {
    if(posX[j] == posX[0] && posY[j] == posY[0])
    {
      gameOver = true;
    }
  }
}

void DrawFood()
{
  if(food)
  {
    randomm(foodX, foodY);
  }
  food = false;
  glColor3f(1.0, 0.0, 0.0);
  glRectf(foodX, foodY, foodX + 1, foodY + 1);
}

void randomm (int &x, int &y)
{
  int maxX = gridX - 2, maxY = gridY - 2;
  int minn = 1;
  x = minn + rand() % (maxX - minn);
  y = minn + rand() % (maxY - minn);
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
  glutInitWindowPosition(500, 150);
  glutInitWindowSize(1024, 600);
  glutCreateWindow("Snake");
  glutDisplayFunc(DisplayCallback);
  glutReshapeFunc(ReshapeCallback);
  glutTimerFunc(0, TimerCallback, 0);
  glutSpecialFunc(KeyboardCallback);
  init();
  glutMainLoop();
  return 0;
}

void DisplayCallback()
{
  glClear(GL_COLOR_BUFFER_BIT);
  drawGrid();
  DrawSnake();
  DrawFood();
  glutSwapBuffers();
  if(gameOver)
  {
    exit(0);
  }
}

void ReshapeCallback(int weight, int hight){
  glViewport(0, 0, (GLsizei)weight, (GLsizei)hight);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0, COLUMNS, 0.0, ROWS, -1.0, 1.0);
  glMatrixMode(GL_MODELVIEW);

}

void TimerCallback(int)
{
  glutPostRedisplay();
  glutTimerFunc(3000 / FPS, TimerCallback, 0);
   
}
void KeyboardCallback(int key, int, int)
{
  if(key == GLUT_KEY_UP && key != DOWN)
  {
    sDirection = UP;
  }
  else if(key == GLUT_KEY_DOWN && key != UP)
  {
    sDirection = DOWN;
  }
  else if (key == GLUT_KEY_RIGHT && key != LEFT)
  {
    sDirection = RIGHT;
  }
  else if(key == GLUT_KEY_LEFT && key != RIGHT)
  {
    sDirection = LEFT;
  }
}
