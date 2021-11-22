//Declaracao de Variaveis Globais
int projecao = 1;                      //Variavel Logica para Definir o Tipo de Projecao (Perspectiva ou Ortogonal)
int posx = 0, posy = 10, posz = 28;    //Variaveis que definem a posicao da camera
int oy = 9,ox = 0,oz = 0;              //Variaveis que definem para onde a camera olha
int lx = 0, ly = 1,  lz = 0;           //Variaveis que definem qual eixo estara na vertical do monitor. //NAO MUDAR

//variaveis para movimentacao do personagem
float player_x = -4, player_y = 1;
int lateral = 1;

//controla qual lado a escada esta para comparacao durante a subida
int subir = 0;

//variaveis para movimentacao do brigadeiro
float ang = 0;
int plat_brig = 5;
int cont_brig = 0;
float brig1[5];
float brig2[5];
float brig3[5];
float brig4[5];
float brig5[5];

//variaveis para permitir a existencia de mais brigadeiros (enables)
int en2 = 0;
int en3 = 0;
int en4 = 0;
int en5 = 0;

//contadora de frames, usada para o intervalo de criacao dos brigadeiros
int cont = 0;

//posicao das plataformas
float plat_y[10];
int plat_num = 1;
int plat_fim[2];

//posições das escadas
float e1[2];
float e2[2];
float e3[2];
float ef1[3];
float ef2[3];

//variaveis para controlar o level do jogo
int lvl = 1;
float lvl_factor = 0; //modifica a velocidade dos brigadeiros conforme o level do jogo
int jogo = 0;

//pontuacao
int pontos = 0;

//variável que indica a vida do personagem
int vida = 1;

//variavel para controlar salvamento de pontuacao no arquivo
int salvar = 0;

//variavel para controlar o pulo
int pulou = 0;
int up = 0;
int cont_pulo = 0;
char ant;