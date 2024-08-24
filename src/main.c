#include <raylib.h>

#include "game.h"

int main(void) {
    // Initialization
    Constants constants = {};
    constants.ScreenWidth = 800;
    constants.ScreenHeight = 450;
    constants.Margin = 10;
    constants.SnakeBlockSize = 20;

    constants.GridWidth = 50;
    constants.GridHeight = 50;

    constants.TileWidth = constants.ScreenWidth / constants.GridWidth;
    constants.TileHeight = constants.ScreenHeight / constants.GridHeight;

    GameState game_state = {};

    InitWindow(constants.ScreenWidth, constants.ScreenHeight, "Snakrray");

    SetTargetFPS(60);

    Image foodImage = LoadImage("assets/food.png");

    game_state.FoodTexture = LoadTextureFromImage(foodImage);  // Image converted to texture, GPU memory (VRAM);

    Snake* snake = &game_state.Snake;

    snake->Size = 1;
    snake->Pieces[0] = (Vector2){5, 5};

    game_state.FoodPosition = (Vector2){25, 25};

    while (!WindowShouldClose()) {
        // Update

        // Draw
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawRectangle(0, 0, constants.ScreenWidth, constants.ScreenHeight, DARKGRAY);

        DrawTexture(game_state.FoodTexture,
                    (game_state.FoodPosition.x - game_state.FoodTexture.width / 2) * constants.TileWidth,
                    (game_state.FoodPosition.y - game_state.FoodTexture.height / 2) * constants.TileHeight, WHITE);

        for (int i = 0; i < snake->Size; i++) {
            DrawRectangle(snake->Pieces[i].x * constants.TileWidth, snake->Pieces[i].y * constants.TileHeight,
                          constants.SnakeBlockSize, constants.SnakeBlockSize, GREEN);
        }

        EndDrawing();
    }

    // De-Initialization
    CloseWindow();

    return 0;
}