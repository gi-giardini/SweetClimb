//Programa exemplo para representacoes de elementos bidimensionais e tridimensionais.
//A estrutura permite manipular diferentes projecoes.
#include "bibliotecas.h"

/****************************************************
Valores Importantes

Valores de x para as plataformas:
   -5.5 a 5.5 (plataformas grandes)

Valores de y para as plataformas:
   *os valores de y em plat_y sao os valores do chao de cada plataforma (y + 0.9)
   valores de plat_y:
      1, 4, 7, 10, 13, 16

Valores Iniciais do Jogador:
   x: -4
   y:  1

Valores de x para as escadas normais
   4.6  (escadas da direita)
   -3.5 (escadas da esquerda)

*Todos os valores foram testados empiricamente e foram os melhores encontrados
*Cuidado ao fazer qualquer alteracao, pode baguncar tudo
****************************************************/

//Prototipos das Funcoes
void Display();
void Mouse(int botao, int estado, int x, int y);
void keyboard (unsigned char key, int x, int y);
void TeclasEspeciais (int key, int x, int y);

//Função responsáel por mostrar as informações e objetos na tela
void Display(){   
   glEnable(GL_DEPTH_TEST);
   glEnable(GL_LINE_SMOOTH);
   glEnable(GL_POLYGON_SMOOTH);
   glEnable(GL_SMOOTH);
   glEnable(GL_BLEND);

   glClearColor(0.1, 0.65, 0.65, 0);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();

   if (projecao == 1)
      glOrtho(-12, 12, -12, 12, -30, 50); //Define a projecao como ortogonal
   else
      gluPerspective(45,1,1,50); //Define a projecao como perspectiva

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity(); 

   gluLookAt(posx,posy,posz,ox,oy,oz,lx,ly,lz); //Define a posicao da camera, para onde olha e qual eixo esta na vertical.
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 

   //gera o mapa e inicializa informacoes
   criar_plataformas();
   criar_escadas(); 
   criar_nuvens();

   //cria e controla as escadas que fogem
   escadas((ef1[1] + ef1[0]) / 2, 4.5, -0.65);
   escadas((ef2[1] + ef2[0]) / 2, 10.5, -0.65);
   call_fuga();   

   //posiciona o personagem
   glPushMatrix();  
      glTranslatef(player_x, player_y, 0);
      personagem();
   glPopMatrix();

   //posiciona a cereja
   glPushMatrix();
      glTranslatef(-4, 18.5, 0);
      cereja();
   glPopMatrix();

   //posiciona o vilao brigadeirao
   glPushMatrix();
      glTranslatef(-4, 16, 0);
      cria_vilao();
   glPopMatrix();

   //limite para nao precisar incrementar muito alem do necessario
   if(cont < 5000)
      cont++;

   //os brigadeiros so se movem se o jogador estiver vivo
   if(vida == 1 && jogo == 1)
      cria_brigadeiro(cont);

   pontos_lista();
   mostrar_pontos();

   //quando o jogador morre, tela de pontos sera apresentada
   if(vida == 0){
      //Game Over
      if(salvar == 1){
         //Salva os pontos do jogador no arquivo score.txt
         salvar_pontuacao();
         salvar = 0;
      }
      //Mostra placar final, com pontos do jogador e melhor pontuação
      pontos_final();
      
   }

   //executa o pulo quando ativado
   pulo();

   //verifica condicao de lvl-up
   colisao_cereja();

   tela_inicio();   
   
   glutSwapBuffers(); //Executa a Cena. SwapBuffers da suporte para mais de um buffer, permitindo execu��o de anima��es sem cintila��es. 
}//fim display

//Função responsável pela iteração com o teclado
void keyboard(unsigned char key, int x, int y){
   //Key - recebe o codigo ASCII da tecla

   //entradas de movimento so serao permitidas se o jogador ainda estiver vivo
   if(vida == 1){
      //posicoes da camera
      //visao diagonal
      if(key == 'p'){
         projecao = 0;
         //ajustando variaveis para visao diagonal
         posz = 20;
         posx = 0;
         posy = 10;
         oy   = 0;
      }

      //visao frontal
      if(key == 'o'){
         projecao = 1;
         //ajustando variaveis para visao frontal
         posz = 28;
         posx = 0;
         posy = 10;
         oy   = 9;
      }

      //Movimentacao horizontal à esquerda ao pressionar 'a'
      if(key == 'a'){
         if(lateral == 1){
            //se estiver na ultima plataforma, o limite da movimentacao e diferente
            if(plat_num > 6){
               if(player_x > plat_fim[0]){
                  player_x -= 0.15;; 
               }  
            }
            else{
               if(player_x > -5.35){
                  player_x -= 0.15;
               }
            }
         }
         ant = 'a';
      }
      //Movimentacao horizontal à direita ao pressionar 'd'
      if(key == 'd'){
         if(lateral == 1){
            //se estiver na ultima plataforma, o limite da movimentacao e diferente
            if(plat_num > 6){
               if(player_x < plat_fim[1])
                  player_x += 0.15;
            }
            else{
               if(player_x < 5.35){
                  player_x += 0.15;
               }
            }
         }
         ant = 'd';
      }

      //Movimentacao vertical para cima ao pressionar 'w'
      if(key == 'w'){
         //se nao estiver na ultima plataforma
         if(player_y <= plat_y[6]){
            //se estiver em uma plataforma com escada a direita
            if(subir == 0){
               if(player_x >= e1[0] && player_x <= e1[1]){
                  player_y += 0.15; 
                  lateral = 0;
               }
               //subiu de plataforma
               if(player_y >= plat_y[plat_num]){
                  subir = 1;
                  lateral = 1;
                  plat_num++;
                  pontos += 50;
               }
            //se estiver em uma plataforma com escada a esquerda
            }else{
               if(player_x <= e2[0] && player_x >= e2[1]){
                  player_y += 0.15; 
                  lateral = 0;         
               }
               //ultima escada
               if(player_x >= e3[0] && player_x<= e3[1]){
                  player_y += 0.15; 
                  lateral = 0; 
               }
               //subiu de plataforma
               if(player_y >= plat_y[plat_num]){
                  subir = 0;
                  lateral = 1;
                  plat_num++;
                  pontos += 50;
               }
            }
         }
      }

      //Movimentacao vertical para baixo ao pressionar 's'
      if(key == 's'){
         if(subir == 0){
            if(player_x >= e1[0] && player_x<= e1[1]){
               if(player_y - 0.15 >= plat_y[plat_num-1]){
                  player_y -= 0.15; 
                  lateral = 0;
               }      
            }
            if(player_y <= plat_y[plat_num]){
               lateral = 1;
            } 
         }else{
            if(player_x <= e2[0] && player_x >= e2[1]){
               if(player_y - 0.15 >= plat_y[plat_num-1]){
                  player_y -= 0.15; 
                  lateral = 0;   
               }
               //alcançou a base da plataforma anterior
               if(player_y <= plat_y[plat_num-1]+1.1){
                  lateral = 1;
               }         
            }
            //ultima escada
            if(player_x >= e3[0] && player_x<= e3[1]){
               if(player_y - 0.15 >= plat_y[plat_num-1]){
                  player_y -= 0.15; 
                  lateral = 0;
               }
               if(player_y <= plat_y[plat_num-1]+1){
                  lateral = 1;
               }  
            }
         }
      }
      
      if(key == ' '){
         pulou = 1;
         //player_y += 1.5;
      }
   }

   //Sai da tela de placar e reinicia o jogo
   if(key == 'r'){
      vida = 1;
      pontos = 0;
      reset_jogo();
      jogo = 0;
   }

   //Sai do jogo
   if(key == 'l'){
      salvar_pontuacao();
      glutExit();
      exit(0);
   }

   if(key == 'i'){
      jogo = 1;
   }
   glutPostRedisplay();
}

//Função responsável pela iteração com o mouse
void Mouse(int botao, int estado, int x, int y){ 
   //botao  - recebe o codigo do botao pressionado
   //estado - recebe se esta pressionado ou nao
   //x, y   - recebem respectivamente as posicoes do mouse na tela
   switch (botao){
      case GLUT_LEFT_BUTTON:
         if(estado == GLUT_DOWN){
         }
      break;

      case GLUT_RIGHT_BUTTON:
         if(estado == GLUT_DOWN){
         }
      break;
   }
}

//Função responsável pela iteraçãgio com as setas do teclado
void TeclasEspeciais (int key, int x, int y){
   //x, y - recebem respectivamente as posi��es mouse na tela (permite tratar os dois dispositivos)
      
   if (key==GLUT_KEY_RIGHT){
   }
   else if (key==GLUT_KEY_PAGE_UP){
      
   }
   else if (key==GLUT_KEY_UP){
      if(posy < 25){
         posy++;
         oy++;
      }  
   }
   else if (key==GLUT_KEY_LEFT){ 
      
   }
   else if (key==GLUT_KEY_PAGE_DOWN){
      
   }
   else if (key==GLUT_KEY_DOWN){      
      if(posy > 0){
         posy--;
         oy--;
      }
   }
   glutPostRedisplay();
}

//Função main do programa, responsável por chamar as outras funções
int main(int argc,char **argv){

   glutInit(&argc, argv); // Initializes glut
   
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); 
   //Define as caracteristicas do espaco vetorial. 
   // Nesse caso, permite animacoes (sem cintilacoes), cores compostas por Verm. Verde e Azul,
   // Buffer que permite trablhar com profundidade e elimina faces escondidas.          

   glutCreateWindow("Sweet Climb 0.8");
   glutFullScreen();
   init_vet_escadas();
   brigadeiros();
   glutDisplayFunc(Display);
   glutMouseFunc(Mouse);
   glutKeyboardFunc(keyboard);
   glutSpecialFunc(TeclasEspeciais);
   glutMainLoop();
   return 0; 
}