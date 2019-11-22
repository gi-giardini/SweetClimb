//Programa exemplo para representa��es de elementos bidimensionais e tridimensionais. A estrutura permite manipular diferentes proje��es.

#include <stdlib.h>
#include <stdio.h>
#include <GL/freeglut.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>
#include <string.h>

//Declara��o de Vari�veis Globais
int angulo1 = 0, angulo2 = 0, angulo3 = 0;
int set_x = 0, set_y = 0, set_z = 1;
int set_x2 = 0, set_y2 = 0, set_z2 = 1;
int set_x3 = 0, set_y3 = 0, set_z3 = 1;
int projecao = 0; //Vari�vel L�gica para Definir o Tipo de Proje��o (Perspectiva ou Ortogonal)
int posx = 1, posy = 10, posz = 35; //Vari�veis que definem a posi��o da c�mera
int oy = 0,ox = 0,oz = 0;           //Vari�veis que definem para onde a c�mera olha
int lx = 0, ly = 1,  lz = 0;        //Vari�veis que definem qual eixo estar� na vertical do monitor.

//Prot�tipos das Funcoes
void Inicializa();
void Display();
void Mouse(int botao, int estado, int x, int y);
void keyboard (unsigned char key, int x, int y);
void TeclasEspeciais (int key, int x, int y);
void instructions();

void Display()
{
   
   glEnable(GL_DEPTH_TEST);
   
   glEnable(GL_LINE_SMOOTH);
   glEnable(GL_POLYGON_SMOOTH); 

   glEnable(GL_SMOOTH);
   glEnable(GL_BLEND);
   
   // Inicializa par�metros de rendering
    // Define a cor de fundo da janela de visualiza��o como preta
   glClearColor(0.0, 0.0, 0.0, 0.0); 
   
   
   glMatrixMode(GL_PROJECTION);/*glMatrixMode()- define qual matriz ser� alterada. SEMPRE defina o tipo de apresenta��o 
                              (Ortogonal ou Perspectiva) na matriz PROJECTION.*/
   glLoadIdentity();//"Limpa" ou "transforma" a matriz em identidade, reduzindo poss�veis erros.

   if (projecao==1)
      glOrtho(-250, 250, -250, 250, -250, 250); //Define a proje��o como ortogonal
   else
      gluPerspective(45,1,1,50); //Define a proje��o como perspectiva
   
   glMatrixMode(GL_MODELVIEW);/*glMatrixMode()- define qual matriz ser� alterada. SEMPRE defina a c�mera 
                              (Ortogonal ou Perspectiva) na matriz MODELVIEW (onde o desenho ocorrer�).*/
   glLoadIdentity(); ////"Limpa" ou "transforma" a matriz em identidade, reduzindo poss�veis erros.

   gluLookAt(posx,posy,posz,ox,oy,oz,lx,ly,lz); //Define a pos da c�mera, para onde olha e qual eixo est� na vertical.
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); /* "limpa" um buffer particular ou combina��es de buffers, 
                                                         onde buffer � uma �rea de armazenamento para informa��es da imagem. 
                                                        Nesse caso, est� "limpando os buffers para suportarem anima��es */
   //Chamada para Fun��o  ou fun��es para desenhar o objeto/cena...
   //----------------------------------------------------------------
   //glPushMatrix(); //Salva o estado atual da cena. O que for desenhado ap�s o Push n�o influenciar� o j� representado   
   
   instructions();

   glColor3ub(100, 255, 40);
   glutWireSphere(1.0, 50, 50);

   glRotatef(angulo1, set_x, set_y, set_z);
   glTranslatef(3.0, 0, 0);
    glPushMatrix();
      glScalef(4, 1, 1);
      glColor3ub(255, 0, 0);
      glutSolidCube(1.5);
    glPopMatrix();
    
   glTranslatef(3.0, 0, 0);
   glColor3ub(100, 255, 40);
   glutWireSphere(1.0, 50, 50);

   glRotatef(angulo2, set_x2, set_y2, set_z2);
   glTranslatef(3.0, 0, 0);
    glPushMatrix();
      glScalef(4, 1, 1);
      glColor3ub(0, 200, 0);
      glutSolidCube(1.5);
    glPopMatrix();
    
     
   glColor3ub(100, 255, 40);
   glTranslatef(3.0, 0, 0);
   glutWireSphere(1.0, 50, 50);

   glRotatef(angulo3, set_x3, set_y3, set_z3);     
   glRotatef(180, 1, 0, 0);
   glTranslatef(2.0, 0, 0);
   glPushMatrix();
      glScalef(3,1,1);
      glColor3ub(0,0,255);
      glutSolidCube(1.5);
   glPopMatrix();

       


  // glPopMatrix();  //Retorna ao estado anterior da cena. O que for desenhado ap�s o Push n�o influenciou o j� representado
   //----------------------------------------------------------------   
   
   glutSwapBuffers(); //Executa a Cena. SwapBuffers d� suporte para mais de um buffer, permitindo execu��o de anima��es sem cintila��es. 
}

void Mouse(int botao, int estado, int x, int y)
{  //bot�o - recebe o c�digo do bot�o pressionado
   //estado - recebe se est� pressionado ou n�o
   //x, y - recebem respectivamente as posi��es do mouse na tela
   switch (botao)
   {
      case GLUT_LEFT_BUTTON:

      break;

      case GLUT_RIGHT_BUTTON:
      if(estado == GLUT_DOWN)
      {
         projecao=0;
         posx=0; posy=10; posz=20;
         oy=0; ox=0;  oz=0;
         lx=0, ly=1, lz=0;
         glutPostRedisplay();
      }
      break;
   }
}

void keyboard (unsigned char key, int x, int y){//Key - recebe o c�digo ASCII da tecla
 //x, y - recebem as posi��es do mouse na tela (permite tratar os dois dispositivos)
   
   //para o primeiro eixo
   //muda as rotações para o eixo x
   if(key == 'b'){
      set_x = 1;
      set_y = 0;
      set_z = 0;
   }

   //muda as rotações para o eixo y
   if(key == 'n'){
      set_x = 0;
      set_y = 1;
      set_z = 0;
   }

   //muda as rotações para o eixo z
   if(key == 'm'){
      set_x = 0;
      set_y = 0;
      set_z = 1;
   }

///////////////////////////////////////////////////////////
   //para o segundo eixo
   //muda as rotações para o eixo x
   if(key == 'j'){
      set_x2 = 1;
      set_y2 = 0;
      set_z2 = 0;
   }

   //muda as rotações para o eixo y
   if(key == 'k'){
      set_x2 = 0;
      set_y2 = 1;
      set_z2 = 0;
   }

   //muda as rotações para o eixo z
   if(key == 'l'){
      set_x2 = 0;
      set_y2 = 0;
      set_z2 = 1;
   }

/////////////////////////////////////////////////////////////////////////
   //para o primeiro eixo
   //muda as rotações para o eixo x
   if(key == 'i'){
      set_x3 = 1;
      set_y3 = 0;
      set_z3 = 0;
   }

   //muda as rotações para o eixo y
   if(key == 'o'){
      set_x3 = 0;
      set_y3 = 1;
      set_z3 = 0;
   }

   //muda as rotações para o eixo z
   if(key == 'p'){
      set_x3 = 0;
      set_y3 = 0;
      set_z3 = 1;
   }

    if(key == 'w')
        angulo1 = (angulo1 - 5)%360; 
    else if(key == 'q')
        angulo1 = (angulo1 + 5)%360;
    else if(key == 's')
        angulo2 = (angulo2 - 5)%360;
    else if(key == 'a')
        angulo2 = (angulo2 + 5)%360;
    else if(key == 'z')
         angulo3 = (angulo3 + 5)%360;
    else if(key == 'x')
         angulo3 = (angulo3 - 5)%360;

   glutPostRedisplay();
}

void TeclasEspeciais (int key, int x, int y)
{//Key - recebe o c�digo ASCII da tecla
 //x, y - recebem respectivamente as posi��es mouse na tela (permite tratar os dois dispositivos)
      if (key==GLUT_KEY_RIGHT)
      {
         posx+=5; ox+=5;
      }
      else if (key==GLUT_KEY_PAGE_UP)
      {
         posy+=5; oy+=5;
      }
      else if (key==GLUT_KEY_UP)
      {
         posz-=5; oz-=5;
      }
      else if (key==GLUT_KEY_LEFT)    
      { 
         posx-=5; ox-=5;
      }
      else if (key==GLUT_KEY_PAGE_DOWN)
      {
         posy-=5; oy-=5;
      }
      else if (key==GLUT_KEY_DOWN)
      {      
         posz+=5; oz+=5;
      }
      glutPostRedisplay();
}

void instructions(){
   int i;
   unsigned char info_x[] = {"Para rotacionar o primeiro retangulo sobre o eixo x, pressione 'b'"};
   unsigned char info_y[] = {"Para rotacionar o primeiro retangulo sobre o eixo y, pressione 'n'"};
   unsigned char info_z[] = {"Para rotacionar o primeiro retangulo sobre o eixo z, pressione 'm'"};

   unsigned char info_x2[] = {"Para rotacionar o segundo retangulo sobre o eixo x, pressione 'j'"};
   unsigned char info_y2[] = {"Para rotacionar o segundo retangulo sobre o eixo y, pressione 'k'"};
   unsigned char info_z2[] = {"Para rotacionar o segundo retangulo sobre o eixo z, pressione 'l'"};

   unsigned char info_x3[] = {"Para rotacionar o terceiro retangulo sobre o eixo x, pressione 'i'"};
   unsigned char info_y3[] = {"Para rotacionar o terceiro retangulo sobre o eixo y, pressione 'o'"};
   unsigned char info_z3[] = {"Para rotacionar o terceiro retangulo sobre o eixo z, pressione 'p'"};

   unsigned char instruct1[] = {"Para mover o primeiro retangulo, pressione 'q' ou 'w'"};
   unsigned char instruct2[] = {"Para mover o segundo retangulo, pressione 'a' ou 's'"};
   unsigned char instruct3[] = {"Para mover o terceiro retangulo, pressione 'z' ou 'x'"};

//////////////////////////////////////////////////////////////////
   //instrucoes de movimentacao

   glColor3ub(100, 255, 40);
   glRasterPos2f(5, -4);
   int tam = strlen(instruct1);
   for (i = 0; i < tam; i++) {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, instruct1[i]);
   }

   glColor3ub(100, 255, 40);
   glRasterPos2f(5, -6);
   int tam2 = strlen(instruct2);
   for (i = 0; i < tam2; i++) {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, instruct2[i]);
   }

   glColor3ub(100, 255, 40);
   glRasterPos2f(5, -8);
   int tam3 = strlen(instruct3);
   for (i = 0; i < tam3; i++) {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, instruct3[i]);
   }

///////////////////////////////////////////////////////////////////////////////////////
   //primeiro retângulo
   glColor3ub(100, 255, 40);
   glRasterPos2f(-5, 8);
   int len = strlen(info_x);
   for (i = 0; i < len; i++) {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, info_x[i]);
   }

   glColor3ub(100, 255, 40);
   glRasterPos2f(-5, 6);
   int len2 = strlen(info_y);
   for (i = 0; i < len2; i++) {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, info_y[i]);
   }
   
   glColor3ub(100, 255, 40);
   glRasterPos2f(-5, 4);
   int len3 = strlen(info_z);
   for (i = 0; i < len3; i++) {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, info_z[i]);
   }

///////////////////////////////////////////////////////////////////////////////////////
   //segundo retângulo
   glColor3ub(100, 255, 40);
   glRasterPos2f(5, 8);
   int len4 = strlen(info_x2);
   for (i = 0; i < len4; i++) {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, info_x2[i]);
   }

   glColor3ub(100, 255, 40);
   glRasterPos2f(5, 6);
   int len5 = strlen(info_y2);
   for (i = 0; i < len5; i++) {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, info_y2[i]);
   }
   
   glColor3ub(100, 255, 40);
   glRasterPos2f(5, 4);
   int len6 = strlen(info_z2);
   for (i = 0; i < len6; i++) {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, info_z2[i]);
   }

///////////////////////////////////////////////////////////////////////////////////////
   //terceiro retângulo
   glColor3ub(100, 255, 40);
   glRasterPos2f(15, 8);
   int len7 = strlen(info_x3);
   for (i = 0; i < len7; i++) {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, info_x3[i]);
   }

   glColor3ub(100, 255, 40);
   glRasterPos2f(15, 6);
   int len8 = strlen(info_y3);
   for (i = 0; i < len8; i++) {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, info_y3[i]);
   }
   
   glColor3ub(100, 255, 40);
   glRasterPos2f(15, 4);
   int len9 = strlen(info_z3);
   for (i = 0; i < len9; i++) {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, info_z3[i]);
   }
}

int main(int argc,char **argv)
{
   glutInit(&argc, argv); // Initializes glut
    
   
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); /*Define as caracter�sticas do espa�o vetorial. 
                                                                           //  Nesse caso, permite anima��es (sem cintila��es), cores compostas por Verm. Verde e Azul,
                                                                           //  Buffer que permite trablhar com profundidade e elimina faces escondidas.*/           
  
   // glutInitWindowSize(800, 800);
   // glutInitWindowPosition(100, 100);
   glutCreateWindow("Estrutura para uma Aplicacao 3D");
   glutFullScreen();
   glutDisplayFunc(Display);
   glutMouseFunc(Mouse);
   glutKeyboardFunc(keyboard);
   glutSpecialFunc(TeclasEspeciais);
   glutMainLoop();
   return 0; 
}
