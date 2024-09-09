#ifndef game_h
#define game_h

#include <raylib.h>

#define GridSize 1024

typedef enum { MAINMENU, GAMEPLAY, GAMEOVER } GameMode;

typedef struct {
  Vector2 Pieces[GridSize];
  Vector2 MovementDirection;
  int Size;
} Snake;

typedef struct {
  Music Audio[2];
  Texture2D FoodTexture;
  Vector2 FoodPosition;
  Snake Snake;
  GameMode Mode;
  int Score;
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
