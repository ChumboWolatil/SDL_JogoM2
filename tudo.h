//
// Created by ernani on 05/05/2020.
//

#ifndef JOGO_SDL_M2_TUDO_H
#define JOGO_SDL_M2_TUDO_H
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
const int NUMERO_FASES = 3;
const int NUMERO_PERSONAGENS = 3;
const int NUMERO_INIMIGOS = 3;
const int ACAO = 2;

enum Dano{
    ERRO = 0,NORMAL = 1,CRITICO = 2
};
enum Acao{
    PERSONAGEM, ATAQUE
};
enum Ataque{
    FISICO, MAGICO
};
enum SubFase{
    COMUM, MINI, BOSS
};
enum Terreno{
    FLORESTA, DESERTO, CALABOUCO
};

enum Classe{
    MAGO,GUERREIRO,RANGER
};


struct Personagens {
    int vida = 1000;
    int FORCA;
    int INTELIGENCIA;
    SDL_Texture *texture = nullptr;
};

struct Inimigo{
    int vida;
    int ATTACK_BASE;
    SDL_Texture *texture;
};

struct Fase{
    Inimigo inimigo[NUMERO_INIMIGOS];
    int terreno;
    Personagens personagens[NUMERO_PERSONAGENS];
    int subfase;
};

void mostraAlvo(Fase jogo[NUMERO_PERSONAGENS], SDL_Renderer *renderer, SDL_Rect destino, int fase);

void mostraPersonagemEscolido(Personagens personagens[NUMERO_PERSONAGENS], int escolido, SDL_Renderer *renderer, SDL_Rect destino, SDL_Rect origem);

void mostraTipoAtaque(SDL_Renderer *renderer, SDL_Texture *espada,SDL_Texture *staff, SDL_Rect destino, int escolido);

void inicializaFLoresta(Fase &floresta, SDL_Renderer *renderer);

void inicializaDeserto(Fase &deserto, SDL_Renderer *renderer);

void ataqueAmigo(int &vidaAlheia, Personagens personagens[NUMERO_PERSONAGENS],int tipoAtaque, int quem);

void ataqueInimigo(Personagens personagens[NUMERO_PERSONAGENS], int atack);

SDL_Texture *inicializaBG(SDL_Renderer *renderer);

void personagensJogo(Fase jogo);

void mostraBoss(SDL_Texture *texture ,SDL_Rect destino, SDL_Renderer *renderer);

void mostraPersonagens(Personagens personagens[NUMERO_PERSONAGENS], SDL_Rect destino, SDL_Rect origem, SDL_Renderer *renderer);

void mostraMenu(SDL_Rect destino, SDL_Rect origem, SDL_Texture *back, SDL_Renderer *renderer);

void consomeEvento(SDL_Event *evento, bool &game, int acao[ACAO], bool &meuTurno);

void mostraCampo(SDL_Rect destino, SDL_Rect origem, int fase, SDL_Renderer *renderer, SDL_Texture *bg);

void inicializaMAGO(Personagens &mago);

void inicializaGuerreiro(Personagens &guerreiro);

void inicializaRanger(Personagens &ranger);

void inicializaPersonagens(Fase &jogo, SDL_Renderer *renderer);

SDL_Texture * loadTexture(SDL_Renderer *renderer, const char *file);

#endif //JOGO_SDL_M2_TUDO_H
