void cria_vilao(){
    
    glPushMatrix();
        glColor3ub(101, 67, 33);
        glutSolidSphere(0.7, 20, 20); //Corpo do brigadeiro
        
        glColor3ub(255, 255, 255);
        glTranslatef(0.25,0.15,0.7);  
        glutSolidSphere(0.1, 20, 20); // Olho direito

        glColor3ub(0, 0, 0);
        glTranslatef(0,0,0.1);  
        glutSolidSphere(0.05, 20, 20); //íris/Pupila direita

        glColor3ub(255, 255, 255);
        glTranslatef(-0.50,0,0);  
        glutSolidSphere(0.1, 20, 20); //Olho esquerdo

        glColor3ub(0, 0, 0);
        glTranslatef(0,0,0.1);  
        glutSolidSphere(0.05, 20, 20);//Íris/Pupila esquerda

        glColor3ub(255, 215, 0);
        glRotatef(90,1,0,0);
        glTranslatef(0.25,-0.6,-0.4);  
        glutSolidTorus(0.1,0.5,50,10); //Base da coroa

        glColor3ub(255, 215, 0);
        glRotatef(180,0,1,0);
        glTranslatef(0.25,0,0.1);  
        glutSolidCone(0.15,0.35,2,3);//Triângulo da esquerda da coroa

        glColor3ub(255, 215, 0);
        glRotatef(0,0,0,0);
        glTranslatef(-0.25,0,0);  
        glutSolidCone(0.15,0.5,2,3); //Triângulo central da coroa

        glColor3ub(255, 0, 0);
        glTranslatef(0,0.1,0.15);  
        glutSolidSphere(0.05, 20, 20); //Pedrinha vermelha da coroa

        glColor3ub(255, 215, 0);
        glRotatef(0,0,0,0);
        glTranslatef(-0.25,-0.1,-0.15);   
        glutSolidCone(0.15,0.35,2,3); //Triangulo da direita da coroa

        glColor3ub(140, 67, 33);
        glRotatef(70,0,1,0);
        glTranslatef(0.57,0.7,0.20); 
        glutSolidCylinder(0.05,0.3,20,10); //Sobrancelha esquerda

        glColor3ub(140, 67, 33);
        glRotatef(37,0,1,0);
        glTranslatef(0.08,0,-0.53); 
        glutSolidCylinder(0.05,0.3,20,10); //Sobrancelha direita

        glColor3ub(255, 255, 255);
        glRotatef(-17,0,1,0);
        glTranslatef(0.5,0,0.1); 
        glutSolidCylinder(0.05,0.3,20,10); //Base da boca

        glColor3ub(0,0,0);
        glRotatef(0,0,0,0);
        glTranslatef(0,0.05,0); 
        glutSolidCylinder(0.008,0.3,20,10); //Linha divisória da boca

    glPopMatrix();
}

//Função para criação da maçã
void cereja(){
    glPushMatrix();
        glTranslatef(3, 0, 0.3); //A origem da esfera foi transladada para a posição (transx, transy, ftransz).
        glColor3ub(250, 50, 30); //Define a cor
        glutSolidSphere(0.3, 50, 50); //Definição (criação) da esfera
    glPopMatrix();
    glPushMatrix();
        glRotatef(45, 1, 0, 0);
        glTranslatef(3, 1, 0.3); //A origem do cubo foi transladada para a posição (transx, transy, transz).
        glScalef(0.1, 0.6, 0.1);
        glColor3ub(127, 255, 14);
        glutSolidCube(0.6);
    glPopMatrix();
}

//Função para criação da personagem principal (sorvete)
void personagem(){
    
    glScalef(0.5, 0.5, 0.5);
    glPushMatrix();
   
    glColor3ub(255, 204, 102);
    glTranslatef(0,0,0); 
    glRotatef(90,1,0,0);
    glutSolidCone(0.5,1.5,20,10);

    glColor3ub(255, 0, 102);
    glTranslatef(-0.2,0,-0.2); 
    glutSolidSphere(0.35,20,20);

    glColor3ub(255, 255, 204);
    glTranslatef(0.4,0,0); 
    glutSolidSphere(0.35,20,20);

    glColor3ub(153, 0, 0);
    glTranslatef(-0.2,0,-0.3); 
    glutSolidSphere(0.35,20,20);

    glColor3ub(255,255,255);
    glTranslatef(-0.2,0.5,0.8); 
    glutSolidSphere(0.15,20,20);

    glColor3ub(0,255,0);
    glTranslatef(0,0.15,0); 
    glutSolidSphere(0.1,20,20);

    glColor3ub(0,0,0);
    glTranslatef(0,0.1,0); 
    glutSolidSphere(0.05,20,20);

    glColor3ub(255,255,255);
    glTranslatef(0.4,-0.25,0); 
    glutSolidSphere(0.15,20,20);

    glColor3ub(0,255,0);
    glTranslatef(0,0.15,0); 
    glutSolidSphere(0.1,20,20);

    glColor3ub(0,0,0);
    glTranslatef(0,0.1,0); 
    glutSolidSphere(0.05,20,20);

    glColor3ub(165,42,10);
    glTranslatef(-0.1,0.05,-0.2); 
    glRotatef(90,0,1,0);
    glutSolidCylinder(0.02,0.25,20,10);

    glColor3ub(165,42,10);
    glTranslatef(0,0,-0.4); 
    glutSolidCylinder(0.02,0.25,20,10);

   glPopMatrix();
}

void posiciona_personagem(){
   glPushMatrix();  
      glTranslatef(player_x, player_y, 0);
      personagem();
   glPopMatrix();
}