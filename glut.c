#include <GL/glut.h>
#include <stdio.h>
int Tx= 0;
int Ty = 0;
int Rb = 0;
int Rba = 0;
int S = 0;
void GerenciaTeclado(unsigned char key, int x, int y){
	printf("%c\n",key );
	switch (key) {
		case  'r':
				Rb -=1;
       break;
		case 'R':
				Rb +=1;
			break;
		case 'e':
		Rba -=1;
			break;
		case 'E':
		Rba +=1;
			break;
		case 's':
			S +=1;
			break;
		case 'S':
			S -=1;
			break;
}
glutPostRedisplay();

}

void GerenciarTecladoEspecial(int key, int x, int y){
	printf("%i\n",key );
  switch (key) {
    case  GLUT_KEY_UP:
			Ty += 1;
			printf("cima\n");
				break;
    case GLUT_KEY_DOWN:
		  Ty -= 1;
			printf("Baixo\n");

      break;
    case GLUT_KEY_LEFT:
			Tx -= 1;
			printf("Esquerda\n");

      break;
    case GLUT_KEY_RIGHT:
			Tx += 1;
			printf("Direita\n");;

      break;


}
glutPostRedisplay();

}

void desenhar_qudrados(int a,int b,int c,int d,int e,int f,int g , int h){
	glBegin(GL_QUADS);
    glVertex2i(a, b);
    glVertex2i(c, d);
    glVertex2i(e, f);
    glVertex2i(g, h);
  glEnd();

}


void  executar() {
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glViewport(0, 0, 512, 512);
	glLoadIdentity();
  //Desenhando o Boneco

  glTranslatef(Tx*10, Ty*10, 0.0);
	glScalef(1+(S*0.1),1+(S*0.1),0);
  glColor3f(0.5, 0.5, 0.5);
  desenhar_qudrados(64,64,64,320,192,320,192,64);
  desenhar_qudrados(80,320,80,416,176,416,176,320);
  glColor3f(1, 0, 0);

	glPushMatrix();
	glTranslatef(208,320, 0.0);
	glRotatef(Rb*15,0,0,1);
	glTranslatef((-208),(-320), 0.0);
  desenhar_qudrados(192,178,192,320,224,320,224,178);
  glColor3f(0, 0,1);

	glPushMatrix();
	glTranslatef(208,178, 0.0);
	glRotatef(Rba*15,0,0,1);
	glTranslatef((-208),(-178), 0.0);
  desenhar_qudrados(192,64,192,178,224,178,224,64);


	glPopMatrix();
	glPopMatrix();



  glFlush();
}

int main(int argc, char const *argv[]) {
	int largura = 512;
	int altura = 512;
	glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB);
  glutInitWindowSize (altura,largura);
  glutCreateWindow("Robo Louco");
  glClearColor(1,1, 1, 1);
  glClearColor(1, 1, 1, 1);
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
	glOrtho(0, largura, 0, altura, -1 ,1);
  glutKeyboardFunc(GerenciaTeclado);
  glutSpecialFunc(GerenciarTecladoEspecial);
  glutDisplayFunc(executar);
  glutMainLoop();

  }
