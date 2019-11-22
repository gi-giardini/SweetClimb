#define atoa(x) #x

//Função para cadastrar o nome do jogador
/*int cadastrar(){
    FILE *novo;
    char nome[20];    

    printf("\nDigite seu nome: ");
    scanf("%[^\n]", nome);
    getchar();
    
    //Abre o arquivo para escrita
    novo = fopen("score.txt", "a");
    fprintf(novo, "%s\n", nome);

    //Fechando arquivo
    fclose(novo);
}*/

//Função que salva a pontuação final do jogador
void pontuacao(){
    FILE *novo;
    
    //Abre o arquivo para escrita
    novo = fopen("score.txt", "a");
    fprintf(novo, "%d\n", pontos);

    //Fechando arquivo
    fclose(novo);
}

void mostrar_pontos(){
    // char p[5] = (char*) malloc(sizeof(char));
    // p = atoa(pontos);
    //unsigned char pontos_jogo[] = {pontos};
    unsigned char pontos_jogo[] = "Pontos";
    int tam, i;

    glPushMatrix();
        //glTranslatef(0, 1, 0);
        //glScalef(50, 50, 50);
        glColor3ub(102, 72, 56);
        glRasterPos3f(-5, 21, 0.5);
        tam = strlen(pontos_jogo);

        for (i = 0; i < tam; i++) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, pontos_jogo[i]);
        }
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-4.5, 21, 0);
        glScalef(2, 1, 0.1);
        glColor3ub(255, 255, 255);
        glutSolidCube(1);
    glPopMatrix();
}

int maior_pontuacao(){
    FILE *novo;
    int aux;
    int maior = 0;
    
    //Abre o arquivo para leitura
    novo = fopen("score.txt", "r");

    while (!feof(novo)){
        fscanf(novo, "%d", &pontos);
        if (maior == 0){
            maior = pontos;
        }else{
            if (pontos > maior){
                maior = pontos;
            }
        }
    }

    fclose(novo);

    return maior;
}

//Função para mostrar na tela o score dos jogadores
int pontos_final(){
    //char nome[20];
    int tam1, tam2;
    int i;
    int maior;
    
    maior = maior_pontuacao();

    unsigned char pontos_jogador[] = {"20"};
    unsigned char maior_pontuacao[] = {"maior"};
        
    glColor3ub(0, 0, 0);
    glRasterPos3f(0, 1, 0);
    tam1 = strlen(pontos_jogador);
    for (i = 0; i < tam1; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, pontos_jogador[i]);
    }

    glColor3ub(0, 0, 0);
    glRasterPos3f(6, 1, 0);
    tam2 = strlen(maior_pontuacao);
    for (i = 0; i < tam2; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, maior_pontuacao[i]);
    }

    /*glPushMatrix();
        glColor3ub(100, 255, 40);
        glRasterPos2f(5, -4);
        tam = strlen(nome);
        for (i = 0; i < tam; i++) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, nome[i]);
        }
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, pontos);
    glPopMatrix();*/
}

/*void menu(){
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutAddMenuEntry("Digite seu nome:\n", 1);
    int aux = 1;
    char teste[20] = "teste";

    switch (aux)
    {
    case 1:
        glPushMatrix();
            glTranslatef(0, 1, 0);
            glLineWidth(20);
            // Define a espessura da linha
            glColor3f(1,.5,0);
            for(int i = 0; i < strlen(teste); i++){
                glutStrokeCharacter( GLUT_STROKE_ROMAN, teste[i]);
            }
        glPopMatrix();        
        break;
    
    default:
        break;
    }

}*/