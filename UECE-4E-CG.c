#include <GL/glut.h>
#include <stdio.h>
#define uni 64
#define largura 512
#define altura  512
float Cx = 0;
float Cy = 0;
int Vx   = 1;
int Vy   = 1;
float qua [16];

 void vetorizar(){
   qua[0] = (uni*2)+Cx;
   qua[1] = (uni*2)+Cy+10;
   qua[2] = (uni*2)+Cx;
   qua[3] = (uni*3)+Cy+10;
   qua[4] = (uni*3)+Cx;
   qua[5] = (uni*3)+Cy+10;
   qua[6] = (uni*3)+Cx;
   qua[7] = (uni*2)+Cy+10;
   //Pontos medios
   qua[8] = (qua[0]+ qua[2])/2;
   qua[9] = (qua[1]+ qua[3])/2;
   qua[10] = (qua[1]+ qua[7])/2;
   qua[11] = (qua[0]+ qua[6])/2;
   qua[12] = (qua[2]+ qua[4])/2;
   qua[13] = (qua[3]+ qua[5])/2;
   qua[14] = (qua[4]+ qua[6])/2;
   qua[15] = (qua[5]+ qua[7])/2;
  }
 void VerificarColisao() {
   for (size_t i = 8; i < 16; i++) {

     if ((qua[i] > 500 || qua[i] < 10)) {
       printf("%f : %i\n",qua[i],i );
       switch (i) {
         case 8:
         case 9:
          Vy = 1;
          Vx = 1;
          break;
        case 10:
        case 11:
          Vy = 1;
          Vx = 0;
          break;
        case 12:
        case 13:
          Vy = 0;
          Vx = 1;
          break;
        case 14:
        case 15:
          Vy=0;
          Vx=0;
          break;
       }
       break;
     }
 }
  }
void desenhar_qudrados(int a,int b,int c,int d,int e,int f,int g , int h){
	glBegin(GL_QUADS);
    glVertex2i(a, b);
    glVertex2i(c, d);
    glVertex2i(e, f);
    glVertex2i(g, h);
  glEnd();

}

void executar() {
  vetorizar();
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glViewport(0, 0, 512, 512);
  glLoadIdentity();
  glColor3f(1, 0, 0);
  desenhar_qudrados(10,10,10,500,500,500,500,10);
  glColor3f(0, 1, 0);
  desenhar_qudrados(qua[0],qua[1],qua[2],qua[3],qua[4],qua[5],qua[6],qua[7]);
  VerificarColisao();
  glFlush();

}
void animacao(int i) {
  if (Vx == 1) Cx++;
  else Cx--;
  if (Vy == 1) Cy++;
  else Cy--;
  glutPostRedisplay();
  glutTimerFunc(5, animacao, i);

}
int main(int argc, char const **argv) {
	glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB);
  glutInitWindowSize (altura,largura);
  glutCreateWindow("Project Benio");
  glClearColor(1, 1, 1, 1);
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
	glOrtho(0, largura, 0, altura, -1 ,1);
  glutDisplayFunc(executar);
  glutTimerFunc(10,animacao,1);
  glutMainLoop();
  return 0;
}
