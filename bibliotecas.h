//Bibliotecas do C
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <locale.h>

//Bibliotecas do OpenGL
#include <GL/freeglut.h>
#include <GL/glut.h>
#include <GL/gl.h>

//Biblioteca com a declaração das variáveis globais
#include "variaveis.h"

//Biblioteca para formar os personagens
#include "personagens.h"

//Biblioteca para formar as plataformas
#include "plataformas.h"

//Biblioteca para formar as escadas
#include "escadas.h"

//biblioteca para criacao e movimentacao dos brigadeiros
#include "brigadeiros.h"

//Biblioteca que possui funções auxiliares para o jogo
#include "funcoes.h"

//Biblioteca de definição do céu (fundo)
#include "ceu.h"

//Biblioteca com os valores de pontuação do jogo
#include "pontuacao.h"

//biblioteca para colisao com o brigadeiro e tela de fim de jogo
#include "fim.h"

//Definição do radiano
#define incr_radia 0.017453293

