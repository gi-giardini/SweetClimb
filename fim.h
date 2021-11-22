//Game Over
void fim_de_jogo(){
   reseta_brigadeiros();
   //reseta variaveis de controle do jogo
   salvar = 1;
   vida = 0;
   cont = 0;
   lvl = 0;
   lvl_factor = 0;

   init_vet_escadas();

   posx = 0;
   posy = 10;
   oy = 9;
   ox = 0;
   oz = 0; 
   projecao = 1;
}

void reset_jogo(){
   //reinicia os brigadeiros
   brigadeiros();
   //reinicia variaveis de controle
   plat_num = 1;
   subir = 0;
   lateral = 1; //acho que nao precisa, mas ta aqui pra garantir

   //reinicia o personagem
   player_x = -4;
   player_y = 1;
   posiciona_personagem();
   delay(500);
}

//calculo da colisao
void colisao_brigadeiro(float *vet){
  
   //variaveis para os brigadeiros
   float yc1 = vet[1] + 0.4;
   float yc2 = vet[1] - 0.4;
   float xc1 = vet[0] + 0.3;
   float xc2 = vet[0] - 0.3;

   //variaveis para o jogador
   float ys1 = player_y + 0.2;
   float ys2 = player_y - 0.3;
   float xs1 = player_x + 0.1;
   float xs2 = player_x - 0.1;

   //comparacoes de coordenadas
   if(yc1 >= ys2 && yc1 <= ys1 || yc2 >= ys2 && yc2 <= ys1){
      if(xc1 >= xs2 && xc1 <= xs1 || xc2 >= xs2 && xc2 <= xs1){
         fim_de_jogo();
      }
      if(vet[1] + 0.5 <= player_y)
         if(lateral == 0)
            fim_de_jogo();
   }
}

//chamadas para verificar colisao
void colisao_list(){
   if(brig1[3] == 1)
      colisao_brigadeiro(brig1);
   if(brig2[3] == 1)
      colisao_brigadeiro(brig2);
   if(brig3[3] == 1)
      colisao_brigadeiro(brig3);
   if(brig4[3] == 1)
      colisao_brigadeiro(brig4);
   if(brig5[3] == 1)
   colisao_brigadeiro(brig5);
}