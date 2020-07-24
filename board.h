#ifndef _BOARD_
#define _BOARD_
 
#include <pieces.h>
 
#define BOARD_WIDTH 10              // Board width in blocks 
#define BOARD_HEIGHT 20             // Board height in blocks

class Board
{
public:
 
    Board(Pieces *pPieces, int pScreenHeight);
 
    int getXPos(int pPos);
    int getYPos(int pPos);
    
    bool isFreeBlock(int pX, int pY);
    bool isLegalMove(int pX, int pY, int pPiece, int pRotation);
    
    void storePiece(int pX, int pY, int pPiece, int pRotation);
    void deletePossibleLines();
    
    bool isGameOver();
 
private:
 
    enum 
    { 
        FREE, 
        TAKEN 
    };

    int mBoard [BOARD_WIDTH][BOARD_HEIGHT]; 
    Pieces *mPieces;
    int screenHeight;
 
    void initBoard();
    void deleteLine(int pY);
};
 
#endif