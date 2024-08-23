#include <raylib.h>

#include "game.h"

int main(void) {
    // Initialization
    Constants constants = {};
    constants.ScreenWidth = 800;
    constants.ScreenHeight = 450;
    constants.Maring = 10;

    GameState game_state = {};

    game_state.Paddless[0].Color = GREEN;
    game_state.Paddless[0].Width = 20;
    game_state.Paddless[0].Location.x = constants.Maring + game_state.Paddless[1].Width;
    game_state.Paddless[0].Location.y = (constants.ScreenHeight / 2) - 30;

    game_state.Paddless[1].Color = GREEN;
    game_state.Paddless[1].Width = 20;
    game_state.Paddless[1].Location.x = constants.ScreenWidth - (constants.Maring + game_state.Paddless[1].Width);
    game_state.Paddless[1].Location.y = (constants.ScreenHeight / 2) - 30;

    game_state.Ball.Color = GREEN;
    game_state.Ball.Speed = 10.0f;
    game_state.Ball.Raduis = 20.0f;
    game_state.Ball.Location.x = constants.ScreenWidth / 2;
    game_state.Ball.Location.y = constants.ScreenHeight / 2;
    game_state.Ball.Velocity.x = 0.0f;
    game_state.Ball.Velocity.y = 1.0f;

    InitWindow(constants.ScreenWidth, constants.ScreenHeight, "Snakrray");

    SetTargetFPS(60);

    Vector2 ball_new_location;

    while (!WindowShouldClose()) {
        // Update
        ball_new_location.x = game_state.Ball.Location.x + (game_state.Ball.Speed * game_state.Ball.Velocity.x);
        ball_new_location.y = game_state.Ball.Location.y + (game_state.Ball.Speed * game_state.Ball.Velocity.y);

        // Player 1 score
        if (ball_new_location.x < 0) {
        }

        // Player 2 score
        if (ball_new_location.x > constants.ScreenWidth) {
        }

        // Player 2 score
        if (ball_new_location.y > constants.ScreenHeight || ball_new_location.y < 0) {
            game_state.Ball.Velocity.y *= -1;
        }

        game_state.Ball.Location.x = ball_new_location.x;
        game_state.Ball.Location.y = ball_new_location.y;

        // Draw
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawRectangle(0, 0, constants.ScreenWidth, constants.ScreenHeight, DARKGRAY);

        for (int i = 0; i < 2; i++) {
            DrawRectangle(game_state.Paddless[i].Location.x, game_state.Paddless[i].Location.y,
                          game_state.Paddless[i].Width, 60, game_state.Paddless[i].Color);
        }

        DrawCircle(game_state.Ball.Location.x, game_state.Ball.Location.y, game_state.Ball.Raduis,
                   game_state.Ball.Color);

        EndDrawing();
    }

    // De-Initialization
    CloseWindow();

    return 0;
}