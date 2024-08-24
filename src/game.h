#ifndef game_h
#define game_h

#include <raylib.h>

#define GridSize 1024

typedef struct {
    Vector2 Pieces[GridSize];
    Vector2 MovementDirection;
    int Size;
} Snake;

typedef struct {
    AudioStream Audio[2];
    Texture2D FoodTexture;
    Vector2 FoodPosition;
    Snake Snake;
    Vector2 Grid;
} GameState;

typedef struct {
    int ScreenWidth;
    int ScreenHeight;
    int Margin;
    int SnakeBlockSize;
    int TileWidth;
    int TileHeight;
    int GridWidth;
    int GridHeight;
} Constants;

#endif