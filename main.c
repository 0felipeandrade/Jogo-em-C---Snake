#include <stdio.h>
#include "snake.h"
#include "raylib.h"

int main(){
    Jogo jogo;
    int gameOver = 1;

    //Cria a janela;
    InitWindow(LARGURA, ALTURA, "Snake Game");
    SetTargetFPS(60);
    srand(time(NULL));
    
    IniciaJogo(&jogo);


    while (!WindowShouldClose()){

        //cria bordas
        BeginDrawing();
        ClearBackground(BLACK);
        if (gameOver){
            DesenhaJogo(&jogo);
            AtualizaRodada(&jogo);
            if (ColisaoBordas(&jogo)){
                gameOver = 0;
            }
           
           if(ColisaoFood(&jogo)){

            AtualizaPontuacao(&jogo);
            IniciaFood(&jogo);
            Insere(&jogo);

           }
        } else {
            DrawText("Perdeu Otario!", 150, 200, 40, WHITE);
            DrawText("Continue", 265, 400, 30, WHITE);
            jogo.pontuacao = 0;
            if (IsKeyPressed(KEY_ENTER)){
                IniciaJogo(&jogo);
                gameOver = 1;
            }
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
