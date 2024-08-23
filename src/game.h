#ifndef game_h
#define game_h

#include <raylib.h>

typedef struct {
    int Width;
    float Speed;
    Vector2 Location;
    Color Color;
} Paddle;

typedef struct {
    float Raduis;
    float Speed;
    Vector2 Location;
    Vector2 Velocity;
    Color Color;
} Ball;

typedef struct {
    Paddle Paddless[2];
    Ball Ball;
} GameState;

typedef struct {
    int ScreenWidth;
    int ScreenHeight;
    int Maring;
} Constants;

#endif