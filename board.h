#ifndef _BOARD_
#define _BOARD_
 
#include <pieces.h>
 
#define BOARD_WIDTH 10              // Board width in blocks 
#define BOARD_HEIGHT 20             // Board height in blocks
#define NUM_BLOCKS 5                // Number of blocks in each "Stored Piece" matrix
#define PIXEL_BLOCK_SIZE 20         // Size of each block in pixels
#define BOARD_CENTER 500            // Number of pixels the center of the board is from the left side of the screen

class Board
{
public:
 
    Board(Pieces *pieces, int screenHeight);
 
    int getXPos(int pos);
    int getYPos(int pos);
    
    bool isFree(int x, int y);
    bool isLegalMove(int x, int y, int piece, int rotation);
    
    void storePiece(int x, int y, int piece, int rotation);
    void checkTetris();
    
    bool isGameOver();
 
private:
 
    enum 
    { 
        FREE, 
        TAKEN 
    };

    int boardMatrix [BOARD_WIDTH][BOARD_HEIGHT]; 
    Pieces *storedPieces;
    int screenHeight;
 
    void initBoard();
    void tetris(int y);
};
 
#endif