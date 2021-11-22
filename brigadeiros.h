//Bibliotecas do OpenGL
#include <GL/freeglut.h>
#include <GL/glut.h>
#include <GL/gl.h>

//da os valores iniciais para as posicoes x e y dos brigadeiros
void inicializa_brigadeiros(float *vet){
   
   vet[0] = -4;   //x do brigadeiro
   vet[1] = 15.5; //y do brigadeiro
   vet[2] = 5;    //numero da plataforma que o brigadeiro esta
   vet[3] = 1;    //brigadeiro ainda nao passou pelo jogador
   vet[4] = 0;    //angulo do brigadeiro

}

//gera os dados de todos os brigadeiros que rolam 
void brigadeiros(){
   inicializa_brigadeiros(brig1);
   inicializa_brigadeiros(brig2);
   inicializa_brigadeiros(brig3);
   inicializa_brigadeiros(brig4);
   inicializa_brigadeiros(brig5);
}

//gera a aparencia do brigadeiro e o posiciona
void posiciona_brigadeiro(float *vet){
   int aux = vet[3];
   float x = vet[0];
   float y = vet[1];

   glPushMatrix();
      
      glColor3ub(123,63,0);
      glTranslatef(x, y, 0);
      glRotatef(vet[4], 0, 0, 1);
      //brigadeiro
      glPushMatrix();
         glRotatef(1, 0, 0, 1);
         glColor3ub(123,63,0);
         //glTranslatef(x, y, 0);
         glutSolidSphere(0.3, 20,20); //Corpinho

         glRotatef(0, 0, 0, 0);
         glColor3ub(255,255,255);
         glTranslatef(0.1, 0.05, 0.3);
         glutSolidSphere(0.08, 20,20);//Zóio esquerdo
         
         glRotatef(0, 0, 0, 0);
         glColor3ub(255,255,255);
         glTranslatef(-0.2, 0, 0);
         glutSolidSphere(0.08, 20,20);//Zóio direito

         glRotatef(0, 0, 0, 0);
         glColor3ub(0,0,0);
         glTranslatef(0.02, -0.04, 0.08);
         glutSolidSphere(0.03, 20,20);//Pupila esquerda

         glRotatef(0, 0, 0, 0);
         glColor3ub(0,0,0);
         glTranslatef(0.16, 0, 0);
         glutSolidSphere(0.03, 20,20);//Pupila direita
      glPopMatrix();

   glPopMatrix();
   
   //rotacao dos brigadeiros
   if(aux%2 == 0){
      vet[4] += 5;  
   }
   else{
      vet[4] -= 5;
   }
   
}

//movimentacao geral do brigadeiro
void move_brigadeiro(float *vet){
   //para executar a funcao mod, deve-se usar variaveis inteiras, entao usamos uma auxiliar int
   int aux = vet[2];
   //plataformas com escadas na esquerda
   if(aux%2 == 0){
      //se um brigadeiro estiver na primeira plataforma , sua movimentação sera diferente
      if(aux == 0){
         //se movera horizontalmente
         vet[0] -= 0.05 + lvl_factor;
         //passando da borda, comeca a mover-se tambem verticalmente 
         if(vet[0] < -5.5)
            vet[1] -= 0.10 + lvl_factor;
      }
      else{
         //enquanto nao chegar na escada, move horizontalmente
         if(vet[0] >= e2[0])
            vet[0] -= 0.05 + lvl_factor;
         //chegando na escada, move verticalmente para baixo
         if(vet[0] <= e2[0]){
            vet[1] -= 0.05 + lvl_factor;
         }
         //se chegou na plataforma de baixo, decrementa o indice de plataforma daquele brigadeiro
         if(vet[1] <= plat_y[aux-1] - 0.3)
            aux--;
      }
   }
   //plataformas com escadas na direita
   else{
      //enquanto nao chegar na escada, move horizontalmente
      if(vet[0] <= e1[1])
         vet[0] += 0.05 + lvl_factor;
      //chegando na escada, move verticalmente para baixo
      if(vet[0] >= e1[1]){
         vet[1] -= 0.05 + lvl_factor;
      }
      //se chegou na plataforma de baixo, decrementa o indice de plataforma daquele brigadeiro
      if(vet[1] <= plat_y[aux-1] - 0.3)
         aux--;
   }
   vet[2] = aux;

   posiciona_brigadeiro(vet);
}

//reinicia as posicoese e contadora para gerar os brigadeiros do zero
void reseta_brigadeiros(){
   cont = 0;
   en2 = 0;
   en3 = 0;
   en4 = 0;
   en5 = 0;
   brigadeiros();
   
}

//verifica se o brigadeiro saiu da tela e o reposiciona no topo
int colisao_cereja(); // prototipos
void colisao_list();
void verifica_fim(float *vet){
   if(vet[1] < -4){
      inicializa_brigadeiros(vet);
   }
   //reinicia a geracao de brigadeiros
   if(colisao_cereja() == 1){
      reseta_brigadeiros();
   }
   //verifica se houve colisao com algum brigadeiro
   colisao_list();
}

//faz a criacao de varios brigadeiros a partir de um determinado numero de frames 
void cria_brigadeiro(int cont){

   //fator aleatorio para espaco de criacao dos brigadeiros
   int fator = rand()%100+1;

   //variaveis "enable" para permitir a criacao dos outros brigadeiros
   if(cont >= 300+fator-lvl_factor){
      en2 = 1;
   }
   if(cont >= 600+fator-lvl_factor){
      en3 = 1;
   }
   if(cont >= 750+fator-lvl_factor){
      en4 = 1;
   }
   if(cont >= 1050+fator-lvl_factor){
      en5 = 1;
   }

   move_brigadeiro(brig1);

   if(en2 == 1){
      move_brigadeiro(brig2);
   }
   if(en3 == 1){

      move_brigadeiro(brig3);
   }
   if(en4){

      move_brigadeiro(brig4);
   }
   if(en5){

      move_brigadeiro(brig5);
   }

   //chamadas para verificar se o brigadeiro saiu da tela
   verifica_fim(brig1);
   verifica_fim(brig2);
   verifica_fim(brig3);
   verifica_fim(brig4);
   verifica_fim(brig5);
}