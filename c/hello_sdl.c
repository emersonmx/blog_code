#include <stdio.h>
#include <SDL.h>

int main() {
    SDL_Window* janela = NULL;
    SDL_Surface* tela = NULL;
    SDL_Event evento;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Cagou Tudo Porra! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    janela = SDL_CreateWindow("Hello SDL", SDL_WINDOWPOS_UNDEFINED, 
            SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    if (janela == NULL) {
        printf("Cagou Tudo Porra! SDL_Error: %s\n", SDL_GetError());
    }
    tela = SDL_GetWindowSurface(janela);

    int executando = 1;
    while (executando) {
        while (SDL_PollEvent(&evento)) {
            if (evento.type == SDL_QUIT) {
                executando = 0;
            }
        }

        SDL_FillRect(tela, NULL, 0xffffffff);
        SDL_UpdateWindowSurface(janela);
    }

    SDL_DestroyWindow(janela);
    SDL_Quit();

    return 0;
}
