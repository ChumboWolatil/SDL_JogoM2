#include "tudo.h"
#include <iostream>
#include <SDL_ttf.h>



int main() {
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    SDL_Window *window = SDL_CreateWindow("Window Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Texture *bg = inicializaBG(renderer);
    SDL_Texture *fisico = loadTexture(renderer, "../Sword.png");
    SDL_Texture *magico = loadTexture(renderer , "../MagicStaff.png");
    SDL_Texture *back = loadTexture(renderer, "../Menu.png");
    Fase jogo[NUMERO_FASES];
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    inicializaFLoresta(jogo[FLORESTA], renderer);
    inicializaDeserto(jogo[DESERTO], renderer);
    bool game = true;
    bool meuTurno = true;
    SDL_Rect origem;
    SDL_Rect destino;
    SDL_Event evento;
    int fase = FLORESTA;
    int acao[ACAO] = {MAGO, FISICO};
    while (game){

        while ((jogo[fase].terreno <= CALABOUCO)&& game) {

            while (jogo[fase].inimigo[jogo[fase].subfase].vida > 0 && (jogo[fase].personagens[MAGO].vida > 0 ||
                    jogo[fase].personagens[GUERREIRO].vida > 0 || jogo[fase].personagens[RANGER].vida > 0) && game) {

                while (meuTurno) {
                    consomeEvento(&evento, game, acao, meuTurno);
                    SDL_RenderClear(renderer);
                    mostraMenu(destino, origem, back, renderer);
                    mostraCampo(destino, origem, jogo[fase].terreno, renderer, bg);
                    mostraPersonagens(jogo[fase].personagens, destino, origem, renderer);
                    mostraBoss(jogo[fase].inimigo[jogo[fase].subfase].texture, destino, renderer);
                    mostraPersonagemEscolido(jogo[fase].personagens, acao[PERSONAGEM], renderer, destino, origem);
                    mostraAlvo(jogo, renderer, destino, fase);
                    mostraTipoAtaque(renderer, fisico, magico ,destino, acao[ATAQUE]);
                    SDL_RenderPresent(renderer);
                    SDL_Delay(1000 / 60);
                }
                std::cout << "Antes: " << jogo[fase].inimigo[jogo[fase].subfase].vida << std::endl;
                ataqueAmigo(jogo[fase].inimigo[jogo[fase].subfase].vida, jogo[fase].personagens, acao[ATAQUE], acao[PERSONAGEM]);
                std::cout << "Depois: " << jogo[fase].inimigo[jogo[fase].subfase].vida << std::endl;
                SDL_RenderClear(renderer);
                mostraMenu(destino, origem, back, renderer);
                mostraCampo(destino, origem, jogo[fase].terreno, renderer, bg);
                mostraPersonagens(jogo[fase].personagens, destino, origem, renderer);
                mostraBoss(jogo[fase].inimigo[jogo[fase].subfase].texture, destino, renderer);
                if (jogo[fase].inimigo[jogo[fase].subfase].vida > 0)
                    ataqueInimigo(jogo[fase].personagens, jogo[fase].inimigo[jogo[fase].subfase].ATTACK_BASE);
                meuTurno = true;
            }
            jogo[fase].subfase++;
            if (jogo[fase].subfase > BOSS){
                fase++;
            }
            if (fase > CALABOUCO){
                game = false;
            }
        }

    }
    SDL_Quit();
    return 0;
}
