#ifndef _GAME_
#define _GAME_
 
#include <board.h>
#include <pieces.h>
#include <draw.h>
#include <time.h>
#include <stdlib.h>

#define FALL_TIME 700
 
class Game
{
public:
 
    Game(Board *board, Pieces *pieces, Draw *draw, int screenHeight);
 
    void drawGame();
    void makePiece();
 
    int posX, posY;               // Position of the piece that is falling down
    int current_piece, current_rotation;          // Kind and rotation the piece that is falling down
 
private:
 
    int screenHeight;              // Screen height in pixels
    int nextX, nextY;       // Position of the next piece
    int nextPiece, nextRotation;  // Kind and rotation of the next piece
 
    Board *board;
    Pieces *pieces;
    Draw *draw;
 
    int randomPiece(int a, int b);
    void startGame();
    void drawPiece(int x, int y, int piece, int rotation);
    void drawBoard();
};

#endif