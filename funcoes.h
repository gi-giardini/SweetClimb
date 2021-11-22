void delay(int number_of_seconds){ 
    // Converting time into milli_seconds 
    int milli_seconds = 1000 * number_of_seconds; 
  
    // Stroing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not acheived 
    while (clock() < start_time + milli_seconds); 
}

void reseta_brigadeiros();

void lvl_up(){
   //aumenta o level e gera um fator aleatorio para a velocidade dos brigadeiros
   lvl++;
   pontos += 500;
   lvl_factor += (float)rand()/(float)(RAND_MAX) * 0.05;

   //reinicia variaveis de controle
   plat_num = 1;
   subir = 0;
   lateral = 1; 
   cont = 0;

   //reseta os brigadeiros
   reseta_brigadeiros();

   //reseta as escadas
   init_vet_escadas();
   

   //reinicia o personagem
   player_x = -4;
   player_y = 1;
   posiciona_personagem();
   //delay para o jogador ter tempo de ver que o jogo reiniciou
   delay(500); 
}

//quando o jogador chega ao fim do mapa, alcancando a cereja e subindo de nivel
int colisao_cereja(){
   if(player_y > plat_y[6]){
      if(player_x <= -0.8){
         lvl_up();
         return 1;
      }
   }
   return 0;
}

//verificacoes para mover a escada quando o jogador chega perto dela
void escada_fugindo(float *vet){
   if(vet[2] == 0){
      if(player_x + 0.30 >= vet[0]){
         if(vet[0] < 3){
            vet[1] += 0.15;
            vet[0] += 0.15;
         }
         else{
            vet[1] -= 0.45;
            vet[0] -= 0.45;
            vet[2] = 1;
         }
         
      }
   }
   else{
      if(player_x - 0.30 <= vet[0]){
         if(vet[0] > -3){
            vet[1] -= 0.15;
            vet[0] -= 0.15;
         }
         else{
            vet[1] += 0.45;
            vet[0] += 0.45;
            vet[2] = 0;
         }
      }
   }
}

//funcao para chamar as verificacoes de fuga das escadas que fogem
void call_fuga(){
   if(plat_num == 2)
      escada_fugindo(ef1);
   if(plat_num == 4)
      escada_fugindo(ef2);
}

void pulo(){

   //a funcao pulo usa uma contagem especifica de frames para as mudancas
   //de coodenadas do personagem, em que em uma determinada quantidade de 
   //frames ele sobe e avanca, em depois dessa quantidade de frames, ele 
   //desce, ainda avancando, mantendo controle da ultima tecla de movimento 
   //usada, direcionando o pulo naquela direcao

   if(pulou == 1){
      cont_pulo++;

      if(cont_pulo <= 30){
         if(ant == 'd')
            player_x += 0.025;
         else if(ant == 'a')
            player_x -= 0.025;
         
         player_y += 0.05;
      }
         
      
      if(cont_pulo > 30 && cont_pulo <= 60){
         if(ant == 'd')
            player_x += 0.025;
         else if(ant == 'a')
            player_x -= 0.025;
         
         player_y -= 0.05;
      }

      if(cont_pulo == 60){
         pulou = 0;
         cont_pulo = 0;
         ant = 'n';
      }
   }   
}

void RotateBrigadeiro(float x_brig, float y_brig){
   glRotatef(45,0,0,1);
   x_brig = x_brig+0.3;
}