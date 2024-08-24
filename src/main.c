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

    snake->Size = 3;
    snake->Pieces[0] = (Vector2){5, 5};
    snake->Pieces[1] = (Vector2){4, 5};
    snake->Pieces[2] = (Vector2){3, 5};
    snake->MovementDirection = (Vector2){1, 0};

    game_state.FoodPosition = (Vector2){25, 25};

    unsigned long frameCounter = 0;

    while (!WindowShouldClose()) {
        // Update
        frameCounter++;

        if (IsKeyDown(KEY_W) && snake->MovementDirection.y != 1) {
            snake->MovementDirection = (Vector2){0, -1};
        }

        if (IsKeyDown(KEY_S) && snake->MovementDirection.y != -1) {
            snake->MovementDirection = (Vector2){0, 1};
        }

        if (IsKeyDown(KEY_A) && snake->MovementDirection.x != 1) {
            snake->MovementDirection = (Vector2){-1, 0};
        }

        if (IsKeyDown(KEY_D) && snake->MovementDirection.x != -1) {
            snake->MovementDirection = (Vector2){1, 0};
        }

        if (frameCounter % 20 == 0) {
            // Move snake every 20 frame?
            for (int i = snake->Size - 1; i >= 1; i--) {
                snake->Pieces[i].x = snake->Pieces[i - 1].x;
                snake->Pieces[i].y = snake->Pieces[i - 1].y;
            }

            snake->Pieces[0].x += snake->MovementDirection.x;
            snake->Pieces[0].y += snake->MovementDirection.y;
        }

        if (snake->Pieces[0].x == game_state.FoodPosition.x && snake->Pieces[0].y == game_state.FoodPosition.y) {
            snake->Pieces[snake->Size + 1].x = snake->Pieces[snake->Size].x;
            snake->Pieces[snake->Size + 1].y = snake->Pieces[snake->Size].y;
            snake->Size++;

            int new_valid_position = 1;

            Vector2 new_position = (Vector2){0, 0};

            do {
                new_valid_position = 1;

                new_position.x = GetRandomValue(1, constants.GridWidth);
                new_position.y = GetRandomValue(1, constants.GridWidth);

                for (int i = snake->Size - 1; i >= 1; i--) {
                    if (snake->Pieces[i].x == new_position.x && snake->Pieces[i].y == new_position.y) {
                        new_valid_position = 0;
                    }
                }
            } while (!new_valid_position);

            game_state.FoodPosition = new_position;
        }

        // Draw
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawRectangle(0, 0, constants.ScreenWidth, constants.ScreenHeight, DARKGRAY);

        DrawRectangle(snake->Pieces[0].x * constants.TileWidth, snake->Pieces[0].y * constants.TileHeight,
                      constants.SnakeBlockSize, constants.SnakeBlockSize, DARKGREEN);

        for (int i = 1; i < snake->Size; i++) {
            DrawRectangle(snake->Pieces[i].x * constants.TileWidth, snake->Pieces[i].y * constants.TileHeight,
                          constants.SnakeBlockSize, constants.SnakeBlockSize, GREEN);
        }

        DrawTexture(game_state.FoodTexture,
                    game_state.FoodPosition.x  * constants.TileWidth,
                    game_state.FoodPosition.y  * constants.TileHeight, WHITE);

        EndDrawing();
    }

    // De-Initialization
    CloseWindow();

    return 0;
}