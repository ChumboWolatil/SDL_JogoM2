//
// Created by ernani on 16/05/2020.
//
#include "tudo.h"

void mostraTipoAtaque(SDL_Renderer *renderer, SDL_Texture *espada,SDL_Texture *staff, SDL_Rect destino, int escolido){
    destino.y = 600/ 2 + 33;
    destino.h = 120;
    destino.w = 120;
    if (escolido % 2 == FISICO) {
        destino.x = 600;
        SDL_RenderCopy(renderer, staff, nullptr, &destino);
        destino.x = 480;
        destino.h = destino.h * 1.5;
        destino.w = destino.w * 1.5;
        SDL_RenderCopy(renderer, espada, nullptr, &destino);
    } else {
        destino.x = 480;
        SDL_RenderCopy(renderer, espada, nullptr, &destino);
        destino.x = 600;
        destino.h = destino.h * 1.5;
        destino.w = destino.w * 1.5;
        SDL_RenderCopy(renderer, staff, nullptr, &destino);
    }
}

void mostraBoss(SDL_Texture *texture, SDL_Rect destino, SDL_Renderer *renderer){
    destino.y = 0;
    destino.x = 20;
    destino.w = 98 * 2.7;
    destino.h = 115 * 2.7;
    SDL_RenderCopy(renderer, texture, nullptr, &destino);
}

void mostraAlvo(Fase jogo[NUMERO_PERSONAGENS], SDL_Renderer *renderer, SDL_Rect destino, int fase){
    destino.h = 115 * 2;
    destino.x = 0;
    destino.y = 600/ 2 + 25;
    destino.w = 98 * 2;
    SDL_RenderCopy(renderer, jogo[fase].inimigo[jogo[fase].subfase].texture, nullptr, &destino);
}

void mostraPersonagemEscolido(Personagens personagens[NUMERO_PERSONAGENS], int escolido, SDL_Renderer *renderer, SDL_Rect destino, SDL_Rect origem){
    origem.h = 26;
    origem.x = 0;
    origem.y = 0;
    origem.w = 280 / 12 - 1;
    destino.h = 800 /4;
    destino.x = 800 - 170;
    destino.y = 70;
    destino.w = 800 / 4;
    if (escolido < 0)
        escolido = escolido * -1;
    int personagem = escolido % 3;
    switch (personagem) {
        case GUERREIRO:
            SDL_RenderCopy(renderer, personagens[GUERREIRO].texture, &origem, &destino);
            break;
        case RANGER:
            SDL_RenderCopy(renderer, personagens[RANGER].texture, &origem, &destino);
            break;
        case MAGO:
            origem.w = 266 / 11;
            SDL_RenderCopy(renderer, personagens[MAGO].texture, &origem, &destino);
            break;

    }
}

void mostraPersonagens(Personagens personagens[NUMERO_PERSONAGENS], SDL_Rect destino, SDL_Rect origem, SDL_Renderer *renderer){
    origem.h = 26;
    destino.x = 500;
    destino.h = 26 * 2;
    if (personagens[MAGO].vida > 0) {
        origem.x = 0;
        origem.y = 0;
        origem.w = 266 / 11;
        destino.w = 266/11 * 2;
        destino.y = 200;
        SDL_RenderCopy(renderer, personagens[MAGO].texture, &origem, &destino);
    } else {
        destino.w = 266/11 * 2;
        destino.y = 200;
        origem.x = (266 / 11) * 8 + 5;
        origem.y = 0;
        origem.w = 266 / 11;
        SDL_RenderCopy(renderer, personagens[MAGO].texture, &origem, &destino);
    }
    if (personagens[GUERREIRO].vida > 0) {
        destino.y = 130;
        origem.x = 0;
        origem.w = 280 / 12 - 1;
        destino.w = (280 / 12 - 1) * 2;
        SDL_RenderCopy(renderer, personagens[GUERREIRO].texture, &origem, &destino);
    } else {
        destino.y = 130;
        origem.x = (280 / 12 - 1) * 8 + 12;
        origem.y = 0;
        origem.w = 280 / 12 + 3;
        destino.w = (280 / 12 - 1) * 2;
        SDL_RenderCopy(renderer, personagens[GUERREIRO].texture, &origem, &destino);
    }
    if (personagens[RANGER].vida > 0) {
        destino.y = 270;
        origem.x = 0;
        origem.y = 0;
        origem.w = 280 / 12 - 1;
        destino.w = (280 / 12 - 1) * 2;
        SDL_RenderCopy(renderer, personagens[RANGER].texture, &origem, &destino);
    } else {
        destino.y = 270;
        origem.x = (280 / 12 - 1) * 8 + 7;
        origem.y = 0;
        origem.w = 280 / 12 + 3;
        destino.w = (280 / 12 - 1) * 2;
        SDL_RenderCopy(renderer, personagens[RANGER].texture, &origem, &destino);
    }
}

void mostraMenu(SDL_Rect destino, SDL_Rect origem, SDL_Texture *back, SDL_Renderer *renderer){
    origem.x = 0;
    origem.y = 316/2;
    origem.h = 316/2;
    origem.w = 234;
    SDL_RenderCopy(renderer, back, &origem, nullptr);
    destino.h = 800 /2;
    destino.x = 800 - 190;
    destino.y = 0;
    destino.w = 800;
    SDL_RenderCopy(renderer, back, &origem, &destino);
    destino.h = 800 / 2;
    destino.x = 0;
    destino.y = 600/ 2 + 25;
    destino.w = 800;
    SDL_RenderCopy(renderer, back, &origem, &destino);
}

void mostraCampo(SDL_Rect destino, SDL_Rect origem, int fase, SDL_Renderer *renderer, SDL_Texture *bg){

    switch (fase) {
        case FLORESTA:
            origem.h = 1070 / 8;
            origem.w = 1230/ 5;
            origem.x = 1230/ 5;
            origem.y = 0;
            break;
        case DESERTO:
            origem.h = 1070 / 8;
            origem.w = 1230 / 5;
            origem.x = 0;
            origem.y = 1070 / 8;
            break;
        case CALABOUCO:
            origem.h = 1070 / 8;
            origem.w = 1230 / 5;
            origem.x = 1230 / 5 * 3;
            origem.y = 0;
            break;
    }
    destino.x = 0;
    destino.y = 0;
    destino.w = 1230 / 5 * 2.5;
    destino.h = 1070 / 8 * 2.5;
    SDL_RenderCopy(renderer, bg, &origem, &destino);
}
