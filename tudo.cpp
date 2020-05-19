//
// Created by ernani on 09/05/2020.
//
#include "tudo.h"


void consomeEvento(SDL_Event *evento, bool &game,int acao[ACAO], bool &meuTurno){
    while (SDL_PollEvent(evento)){
        switch (evento->type) {
            case SDL_QUIT:
                SDL_Quit();
                break;
            case SDL_KEYDOWN:
                switch (evento->key.keysym.sym) {
                    case SDLK_LEFT:
                    case SDLK_a:
                        acao[ATAQUE]++;
                        std::cout << "Magico"<< std::endl;
                        break;
                    case SDLK_RIGHT:
                    case SDLK_d:
                        acao[ATAQUE]--;
                        std::cout << "Fisico"<< std::endl;
                        break;
                    case SDLK_UP:
                    case SDLK_w:
                        acao[PERSONAGEM]++;
                        std::cout << "Personagem++"<< std::endl;
                        break;
                    case SDLK_DOWN:
                    case SDLK_s:
                        acao[PERSONAGEM]--;
                        std::cout << "Personagem--"<< std::endl;
                        break;
                    case SDLK_SPACE:
                        meuTurno = false;
                        break;
                }
                break;
        }
    }
}

void ataqueAmigo(int &vidaAlheia, Personagens personagens[NUMERO_PERSONAGENS],int tipoAtaque, int classe){
    classe = classe % 3;
    int dado;
    dado = (rand() % 20) + 1;
    int dano;
    if (dado == 20){
        if (tipoAtaque % 2 == FISICO){
            dano = personagens[classe].FORCA * CRITICO;
        }
        else {
            dano = personagens[classe].INTELIGENCIA * CRITICO;
        }
    }else if (dado > 5 && dado < 20){
        if (tipoAtaque % 2 == FISICO){
            dano = personagens[classe].FORCA * NORMAL;
        }
        else {
            dano = personagens[classe].INTELIGENCIA * NORMAL;
        }
    } else if (dado < 5 && dado >= 0){
        dano = 0;
    }

    vidaAlheia -= dano;
}

void ataqueInimigo(Personagens personagens[NUMERO_PERSONAGENS], int atack){
    int alvo = rand() % NUMERO_PERSONAGENS;
    int dado = (rand() % 20) + 1;
    int dano;
    bool ataqueCompleto = false;
    while (!ataqueCompleto) {
        if (personagens[alvo].vida > 0) {
            if (dado == 20)
                dano = atack * 2;
            else if (dado > 10 && dado < 20)
                dano = atack * 1;
            else
                dano = 0;
            ataqueCompleto = true;
        } else{
            alvo = (alvo + 1) % 3;
        }

    }
    personagens[alvo].vida =  personagens[alvo].vida - dano;

}


void inicializaMAGO(Personagens  &mago, SDL_Renderer* renderer) {
    mago.FORCA = 40;
    mago.INTELIGENCIA = 100;
    mago.texture = loadTexture(renderer,"../Mage.png");
}

void inicializaGuerreiro(Personagens &guerreiro,SDL_Renderer *renderer){
    guerreiro.FORCA = 100;
    guerreiro.INTELIGENCIA = 40;
    guerreiro.texture = loadTexture(renderer, "../Warrior.png");
}

void inicializaRanger(Personagens &ranger, SDL_Renderer* renderer){
    ranger.FORCA = 40;
    ranger.INTELIGENCIA = 100;
    ranger.texture = loadTexture(renderer, "../Ranger.png");
}

void inicializaPersonagens(Fase &jogo, SDL_Renderer *renderer){
    inicializaGuerreiro(jogo.personagens[GUERREIRO], renderer);
    inicializaMAGO(jogo.personagens[MAGO], renderer);
    inicializaRanger(jogo.personagens[RANGER], renderer);
}
void inicializaFLoresta(Fase &floresta, SDL_Renderer *renderer){
    inicializaPersonagens(floresta, renderer);
    floresta.terreno = FLORESTA;
    floresta.subfase = COMUM;
    floresta.inimigo[COMUM].vida = 400;
    floresta.inimigo[COMUM].ATTACK_BASE = 20;
    floresta.inimigo[COMUM].texture = loadTexture(renderer, "../Lobos.png");
    floresta.inimigo[MINI].vida = 600;
    floresta.inimigo[MINI].ATTACK_BASE = 70;
    floresta.inimigo[MINI].texture = loadTexture(renderer, "../MiniFloresta.png");
    floresta.inimigo[BOSS].vida = 1000;
    floresta.inimigo[BOSS].texture = loadTexture(renderer, "../BossDragao.png");
    floresta.inimigo[BOSS].ATTACK_BASE = 100;
}

void inicializaDeserto(Fase &deserto, SDL_Renderer *renderer){
    inicializaPersonagens(deserto, renderer);
    deserto.terreno = DESERTO;
    deserto.subfase = COMUM;
    deserto.inimigo[COMUM].vida = 400;
    deserto.inimigo[COMUM].ATTACK_BASE = 20;
    deserto.inimigo[COMUM].texture = loadTexture(renderer, "../DesertoComum.png");
    deserto.inimigo[MINI].vida = 600;
    deserto.inimigo[MINI].ATTACK_BASE = 70;
    deserto.inimigo[MINI].texture = loadTexture(renderer, "../DesrtoMini.png");
    deserto.inimigo[BOSS].vida = 1000;
    deserto.inimigo[BOSS].texture = loadTexture(renderer, "../BossDeserto.png");
    deserto.inimigo[BOSS].ATTACK_BASE = 100;
}

SDL_Texture *inicializaBG(SDL_Renderer *renderer){
    SDL_Texture *bg = loadTexture(renderer, "../Battlegrounds.png");
    return bg;
}

SDL_Texture *loadTexture(SDL_Renderer *renderer, const char *file){
    SDL_Surface *surface = IMG_Load(file);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}
