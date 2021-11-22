//Função para cadastrar o nome do jogador

void reverso(char s[]) {
    int i, j;
    char c;

    for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void inteiro_string(int n, char s[]) {
    int i, sign;

    if ((sign = n) < 0)  
        n = -n;          
    i = 0;
    do {       
        s[i++] = n % 10 + '0';   
    } while ((n /= 10) > 0);     
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverso(s);
}

//Função que salva a pontuação final do jogador
void salvar_pontuacao(){
    FILE *novo;
    
    //Abre o arquivo para escrita
    novo = fopen("score.txt", "a");
    fprintf(novo, "%d\n", pontos);

    //Fechando arquivo
    fclose(novo);
}

/*Função responsável por mostrar os pontos do jogador
    no decorrer do mesmo*/
void mostrar_pontos(){
    unsigned char pontos_jogo[8];
    inteiro_string(pontos, pontos_jogo);

    unsigned char string[20] = "Pontos: ";

    int tam, i;

    //Mostra o texto "Pontos:"
    glPushMatrix();
        glColor3ub(102, 72, 56);
        glRasterPos3f(-5.2, 19, 0.5);
        tam = strlen(string);

        for (i = 0; i < tam; i++) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,string[i]);
        }
    glPopMatrix();

    //Mostra a pontuação atual do jogador na tela
    glPushMatrix();
        glColor3ub(102, 72, 56);
        glRasterPos3f(-4.4, 19, 0.5);
        tam = strlen(pontos_jogo);

        for (i = 0; i < tam; i++) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, pontos_jogo[i]);
        }
    glPopMatrix();

    unsigned char string2[20] = "Nivel: ";
    //Mostra o texto "Nivel:"
    glPushMatrix();
        glColor3ub(102, 72, 56);
        glRasterPos3f(-5.2, 20, 0.5);
        tam = strlen(string2);

        for (i = 0; i < tam; i++) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,string2[i]);
        }
    glPopMatrix();

    inteiro_string(lvl, pontos_jogo);
    //Mostra o nivel atual do jogador na tela
    glPushMatrix();
        glColor3ub(102, 72, 56);
        glRasterPos3f(-4.4, 20, 0.5);
        tam = strlen(pontos_jogo);

        for (i = 0; i < tam; i++) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, pontos_jogo[i]);
        }
    glPopMatrix();

    //Forma o placar na tela
    glPushMatrix();
        glTranslatef(-4.5, 19.7, 0);
        glScalef(2, 2, 0.1);
        glColor3ub(255, 255, 255);
        glutSolidCube(1);
    glPopMatrix();
}

//Função que retorna a maior pontuação do arquivo (maior score)
int maior_pontuacao(){
    FILE *novo;
    int aux;
    int maior = 0;
    
    //Abre o arquivo para leitura
    novo = fopen("score.txt", "r");

    while (!feof(novo)){
        fscanf(novo, "%d", &aux);
        if (maior == 0){
            maior = aux;
        }else{
            if (aux > maior){
                maior = aux;
            }
        }
    }
    fclose(novo);

    return maior;
}

//Função para mostrar na tela o score dos jogadores (pontos finais)
void pontos_final(){
    //Para escrever textos em português
    setlocale(LC_ALL, "Portuguese");   

    int tam;
    int i;
    int maior;
    
    maior = maior_pontuacao();

    unsigned char pontos_jogador[20];
    unsigned char maior_pontuacao[20];

    //Converte a pontuação para string, para poder ser exibido na tela
    inteiro_string(pontos, pontos_jogador);
    inteiro_string(maior, maior_pontuacao);

    unsigned char string1[20] = "Total de pontos: ";
    unsigned char string2[30] = "Primeiro colocado: ";
    unsigned char string3[20] = "Game Over";
    unsigned char string4[50] = "Pressione r para reiniciar o jogo.";
    unsigned char string5[50] = "Pressione q para sair ao jogo.";

    //Mostra o texto "Game Over:"
    glPushMatrix();
        glColor3ub(255, 0, 0);
        glRasterPos3f(-1, 9, 1.2);
        //glScalef(2, 2, 0);
        tam = strlen(string3);

        for (i = 0; i < tam; i++) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string3[i]);
        }
    glPopMatrix();

    //Mostra o texto "Pontuação final:"
    glPushMatrix();
        glColor3ub(102, 72, 56);
        glRasterPos3f(-3, 7, 1.2);
        tam = strlen(string1);

        for (i = 0; i < tam; i++) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string1[i]);
        }
    glPopMatrix();

    //Mostra o texto "Maior pontuação:"
    glPushMatrix();
        glColor3ub(102, 72, 56);
        glRasterPos3f(-3, 5, 1.2);
        tam = strlen(string1);

        for (i = 0; i < tam; i++) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string2[i]);
        }
    glPopMatrix();

    //Mostra os pontos finais do jogador
    glColor3ub(102, 72, 56);
    glRasterPos3f(3, 7, 1.2);
    tam = strlen(pontos_jogador);
    for (i = 0; i < tam; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, pontos_jogador[i]);
    }

    //Mostra a maior pontuação (score) salva no arquivo
    glColor3ub(102, 72, 56);
    glRasterPos3f(3, 5, 1.2);
    tam = strlen(maior_pontuacao);
    for (i = 0; i < tam; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, maior_pontuacao[i]);
    }

    //Mostra informações para reiniciar o jogo
    glPushMatrix();
        glColor3ub(102, 72, 56);
        glRasterPos3f(-3, 3, 1.2);
        tam = strlen(string4);

        for (i = 0; i < tam; i++) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string4[i]);
        }
    glPopMatrix();     

    //Mostra informações para sair do jogo
    glPushMatrix();
        glColor3ub(102, 72, 56);
        glRasterPos3f(-3, 2, 1.2);
        tam = strlen(string5);

        for (i = 0; i < tam; i++) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string5[i]);
        }
    glPopMatrix();

    //Cria a tabela de placar final do jogo
    glPushMatrix();
        glTranslatef(0, 6, 1);
        glScalef(8, 10, 0.1);
        glColor3ub(255, 255, 255);
        glutSolidCube(1);
    glPopMatrix();
}

void conta_pontos(float *vet){
   int aux = vet[2];
   if(plat_num - 1 == aux){
      if((plat_num-1)%2 == 0){
        if(player_x > vet[0] + 0.3){
            if(vet[3] == 1){
                pontos += 100;
                vet[3] = 0;
            }  
        }
      }
      else{
        if(player_x < vet[0] + 0.3){
            if(vet[3] == 1){
                pontos += 100;
                vet[3] = 0;
            }
        }
      }
   }
}

void pontos_lista(){
   conta_pontos(brig1);
   conta_pontos(brig2);
   conta_pontos(brig3);
   conta_pontos(brig4);
   conta_pontos(brig5);
}

//Função para mostrar a tela inicial de comandos
void tela_inicio(){
    int tam, i;

    unsigned char string1[50] = "Sweet Climb";
    unsigned char string2[50] = "Comandos: ";
    unsigned char string3[50] = "Pressione i para jogar";
    unsigned char string4[50] = "W : movimenta o personagem pra cima";
    unsigned char string5[50] = "S : movimenta o personagem pra baixo";
    unsigned char string6[50] = "D : movimenta o personagem pra direita";
    unsigned char string7[50] = "A : movimenta o personagem pra esquerda";
    unsigned char string8[50] = "L : sai do jogo";
    unsigned char string9[50] = "O : muda visao para ortogonal";
    unsigned char string10[50] = "P : muda a visao para perspectiva";
    unsigned char string11[50] = "R : reinicia o jogo";
    unsigned char string12[50] = "Setas : movimentam cenario";

    if(jogo == 0){
        glPushMatrix();
            glTranslatef(0, 8, 1);
            glColor4ub(0, 0, 0, 100);
            glScalef(30, 30, 0.5);
            glutSolidCube(1);
        glPopMatrix();

        //Mostra o texto "Sweet Climb"
        glPushMatrix();
            glColor3ub(255, 182, 193);
            glRasterPos3f(-1.5, 16, 2);
            tam = strlen(string1);

            for (i = 0; i < tam; i++) {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string1[i]);
            }
        glPopMatrix();

        //Mostra o texto "Comandos"
        glPushMatrix();
            glColor3ub(255, 255, 255);
            glRasterPos3f(-1.3, 14, 2);
            tam = strlen(string2);

            for (i = 0; i < tam; i++) {
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string2[i]);
            }
        glPopMatrix();

        //Mostra a string 4
        glPushMatrix();
            glColor3ub(255, 255, 255);
            glRasterPos3f(-2.5, 12, 2);
            tam = strlen(string4);

            for (i = 0; i < tam; i++) {
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string4[i]);
            }
        glPopMatrix();

        //Mostra a string 5
        glPushMatrix();
            glColor3ub(255, 255, 255);
            glRasterPos3f(-2.5, 11, 2);
            tam = strlen(string5);

            for (i = 0; i < tam; i++) {
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string5[i]);
            }
        glPopMatrix();

        //Mostra a string 6
        glPushMatrix();
            glColor3ub(255, 255, 255);
            glRasterPos3f(-2.5, 10, 2);
            tam = strlen(string6);

            for (i = 0; i < tam; i++) {
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string6[i]);
            }
        glPopMatrix();

        //Mostra a string 7
        glPushMatrix();
            glColor3ub(255, 255, 255);
            glRasterPos3f(-2.5, 9, 2);
            tam = strlen(string7);

            for (i = 0; i < tam; i++) {
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string7[i]);
            }
        glPopMatrix();

        //Mostra a string 8
        glPushMatrix();
            glColor3ub(255, 255, 255);
            glRasterPos3f(-2.5, 8, 2);
            tam = strlen(string8);

            for (i = 0; i < tam; i++) {
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string8[i]);
            }
        glPopMatrix();

        //Mostra a string 9
        glPushMatrix();
            glColor3ub(255, 255, 255);
            glRasterPos3f(-2.5, 7, 2);
            tam = strlen(string9);

            for (i = 0; i < tam; i++) {
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string9[i]);
            }
        glPopMatrix();

        //Mostra a string 10
        glPushMatrix();
            glColor3ub(255, 255, 255);
            glRasterPos3f(-2.5, 6, 2);
            tam = strlen(string10);

            for (i = 0; i < tam; i++) {
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string10[i]);
            }
        glPopMatrix();

        //Mostra a string 11
        glPushMatrix();
            glColor3ub(255, 255, 255);
            glRasterPos3f(-2.5, 5, 2);
            tam = strlen(string11);

            for (i = 0; i < tam; i++) {
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string11[i]);
            }
        glPopMatrix();

        //Mostra a string 12
        glPushMatrix();
            glColor3ub(255, 255, 255);
            glRasterPos3f(-2.5, 4, 2);
            tam = strlen(string12);

            for (i = 0; i < tam; i++) {
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string12[i]);
            }
        glPopMatrix();

        //Mostra a string 3
        glPushMatrix();
            glColor3ub(255, 255, 255);
            glRasterPos3f(-1.8, 2, 2);
            tam = strlen(string3);

            for (i = 0; i < tam; i++) {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string3[i]);
            }
        glPopMatrix();

    }
}