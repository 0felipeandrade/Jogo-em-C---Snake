#ifndef SNAKE_H
#define SNAKE_H

#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define LARGURA 800
#define ALTURA 800
#define STD_SIZE_X 20
#define STD_SIZE_Y 20
#define TEMPO 0.2
#define COOLDOWN 0.2
#define SNAKE_COLOR DARKGREEN
#define FOOD_COLOR RED

#define VELOCIDADE_Y 20
#define VELOCIDADE_X 20

typedef struct Bordas{
    Rectangle pos;
}Bordas;

typedef struct Body{
    Rectangle pos;
    Color color;
    int direcao;
}Body;

typedef struct Food{
    Rectangle pos;
    Color color;
}Food;

typedef struct Jogo{
    Body body;
    Food food;
    Bordas bordas[4];
    double tempo;
    double cooldown;
    int pontuacao;
}Jogo;

//A partir de agora comecaremos a implementação das structs de listas encadeadas (Seguindo o modelo do Ziviani); ---------------------------------------------------------------------------------------

typedef struct{

    int Chave;
}TipoItem;

typedef struct TipoCelula* TipoApontador;

typedef struct TipoCelula{

    TipoItem Item;
    TipoApontador Prox;

    
}TipoCelula;

typedef struct {

    TipoApontador Primeiro,Ultimo;
}TipoLista;



//Aqui terminamos a implementação das structs-------------------------------------------------------------------------------------------------------------------------------------------------------

void IniciaBody(Jogo *j);
void IniciaBordas(Jogo *j);
void IniciaFood(Jogo *j);
void IniciaJogo(Jogo *j);
void DesenhaBody(Jogo *j);
void DesenhaFood(Jogo *j);
void DesenhaBordas(Jogo *j);
void DesenhaJogo(Jogo *j);
void AtualizaDirecao(Jogo *j);
void AtualizaPosBody(Jogo *j);
void AtualizaRodada(Jogo *j);
int ColisaoFood(Jogo *j);

//Funcoes que usaremos para fazer o encadeamento--------------------------------------------------------------------------------------------------------------------------------------------------

int Vazia(TipoLista Lista);
void Insere(Jogo *j);
void Retira(TipoApontador p, TipoLista *Lista,TipoItem *Item);
void Imprime(TipoLista Lista);

// Aqui acabaram as funções(Serão feitas provavelmente alteração de nomenclatura)--------------------------------------------------------------------------------------------------------------------


int ColisaoBordas(Jogo* j);
void DesenhaPontuacao(Jogo *j);
void AtualizaPontuacao(Jogo *j);

void FazCorpoCobra(Jogo* j);



//Precisamos agora implementar o corpo da cobra
//Seria legal tambem, colocar um score de pontuação: A cada rodada salvaria o score com o recorde e o score da rodada;

#endif
