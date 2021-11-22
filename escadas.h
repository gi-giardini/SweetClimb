//Função de criacao das escadas
void escadas(float tx, float ty, float tz){

   glColor3ub(255, 253, 208);
   //escada
   glPushMatrix();
   //degrais
      glPushMatrix();

         glTranslatef(tx+0.25, ty-0.5, tz);
         //glRotatef(90, 0, 0, 1);
         glScalef(0.7, 0.1, 0.1);
         glutSolidCube(1);

      glPopMatrix();

      glPushMatrix();

         glTranslatef(tx+0.25, ty, tz);
         //glRotatef(90, 0, 0, 1);
         glScalef(0.7, 0.1, 0.1);
         glutSolidCube(1);

      glPopMatrix();

      glPushMatrix();

         glTranslatef(tx+0.25, ty+0.5, tz);
         //glRotatef(90, 0, 0, 1);
         glScalef(0.7, 0.1, 0.1);
         glutSolidCube(1);

      glPopMatrix();

      glPushMatrix();

         glTranslatef(tx+0.25, ty+1, tz);
         //glRotatef(90, 0, 0, 1);
         glScalef(0.7, 0.1, 0.1);
         glutSolidCube(1);

      glPopMatrix();

      glPushMatrix();

         glTranslatef(tx+0.25, ty-1, tz);
         //glRotatef(90, 0, 0, 1);
         glScalef(0.7, 0.1, 0.1);
         glutSolidCube(1);

      glPopMatrix();
      //fim degrais

      //laterais
      glPushMatrix();
         //lateral direita
         glTranslatef(tx+0.5, ty, tz);
         glRotatef(90, 0, 0, 1);
         glScalef(2.8, 0.1, 0.1);
         glutSolidCube(1);

      glPopMatrix();

      //lateral esquerda
      glTranslatef(tx, ty, tz);
      glRotatef(90, 0, 0, 1);
      glScalef(2.8, 0.1, 0.1);
      glutSolidCube(1);
      //fim laterais

   glPopMatrix();

   glutPostRedisplay();
}//fim escadas

//Cria os vetores com as posicoes de x das escadas em que será possível subí-las
void init_vet_escadas(){
   //escadas da direita
   e1[0] = 4.75;
   e1[1] = 4.95;

   //escadas da esquerda
   e2[0] = -4.25;
   e2[1] = -4.40;

   //escada da ultima plataforma
   e3[0] = 1;
   e3[1] = 1.15;

   //escada que foge
   ef1[0] = 1;
   ef1[1] = 0.4;
   ef1[2] = 1;

   ef2[0] = 1;
   ef2[1] = 0.4;
   ef2[2] = 1;
}

//gera todos os dados necessarios para as criacoes das escadas e das escadas quebradas
void criar_escadas(){
   float tx = 4.6, ty = 1.2, tz = -0.65;
   float txf = 1;

   //cria todas as escadas em suas devidas posicoes
   for(int i = 0; i < 5; i++){
      escadas(tx, ty, tz);
      tx = -tx;
      txf = -txf;
      ty += 3;
      
   }
   //escada da ultima plataforma
   escadas(0.8, 16.5, tz);
}