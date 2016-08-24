#include <GL/glut.h>
#include <stdio.h>
#define uni 64
#define largura 512
#define altura  512
float Cx = 0;
float Cy = 0;
void desenhar_qudrados(int a,int b,int c,int d,int e,int f,int g , int h){
	glBegin(GL_QUADS);
    glVertex2i(a, b);
    glVertex2i(c, d);
    glVertex2i(e, f);
    glVertex2i(g, h);
  glEnd();

}

void executar() {
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glViewport(0, 0, 512, 512);
  glLoadIdentity();
  glColor3f(0.5, 0.5, 0.5);
  glTranslatef(Cx,Cy,0);
  desenhar_qudrados(uni+Cx,uni+Cy,uni+Cx,(uni*4)+Cy ,(uni*4)+Cx,(uni*4)+Cy,(uni*4)+Cx,uni+Cy);
  glFlush();

}
void animacao(int i) {
  Cx++;
  Cy++;
  Cy++;
  printf("Cx:%f Cy:%f\n",Cx,Cy);
  glutPostRedisplay();
  glutTimerFunc(50, animacao, i);

}
int main(int argc, char const *argv[]) {
	glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB);
  glutInitWindowSize (altura,largura);
  glutCreateWindow("Project Benio");
  glClearColor(1, 1, 1, 1);
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
	glOrtho(0, largura, 0, altura, -1 ,1);
  glutDisplayFunc(executar);
  glutTimerFunc(50,animacao,1);
  glutMainLoop();
  return 0;
}
