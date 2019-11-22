//colisao com a maçã e aumento de nivel (para todas as outras funcoes)
//FUNCIONA?

void posiciona_personagem(){
   glPushMatrix();  
      glTranslatef(player_x, player_y, 0);
      personagem();
   glPopMatrix();
}

void lvl_up(){
   //aumenta o level
   lvl++;
   // //gera o fator para reposicionamento das escadas
   // lvl_factor = (float)rand()/(float)(RAND_MAX) * 0.5;
   // int sinal = rand()%20;
   // if(sinal >= 1 && sinal <= 10) lvl_factor = -lvl_factor;
   // printf("%.2f\t", lvl_factor);
   // criar_escadas();
   // criar_plataformas();
   
   //reinicia vetor das escadas
   init_vet_escadas();

   //reinicia variaveis de controle
   plat_num = 1;
   subir = 0;
   descer = 0;
   lateral = 1; //acho que nao precisa, mas ta aqui pra garantir

   //reinicia o personagem
   player_x = -4;
   player_y = 1;
   posiciona_personagem();
}

void collision_apple(){
   if(player_y > plat_y[6]){
      if(player_x <= -0.8){
         lvl_up();
         
      }
   }
}

//Função para imprimir no terminal as posicoes do chao de cada plataforma
void imprime(){
    for(int i = 0; i < 6; i++){
        printf("%2.f\t", plat_y[i]);
    }
}

//Função responsável por resetar as variáveis da câmera
void resetar_visao(){
      posx = 0;
      posy = 0;
      posz = 0;
      ox   = 0;
      oy   = 0;
      oz   = 0;
}