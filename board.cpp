#include <board.h>

void Board::initBoard()
{
    for (int i = 0; i < BOARD_WIDTH; i++)
    {
        for (int j = 0; j < BOARD_HEIGHT; j++)
        {
            boardMatrix[i][j] = FREE;
        }
    }
}

void Board::storePiece(int x, int y, int piece, int rotation)
{
    for (int i = x, j = 0; i < x + NUM_BLOCKS; i++, j++)
    {
        for (int n = y, m = 0; n < y + NUM_BLOCKS; n++, m++)
        {   
            if (storedPieces->getPostionType (piece, rotation, m, j) != 0)      
                boardMatrix[i][n] = TAKEN;    
        }
    }
}

bool Board::isGameOver()
{
    for (int i = 0; i < BOARD_WIDTH; i++)
    {
        if (boardMatrix[i][0] == TAKEN) 
        {
            return true;
        }
    }
 
    return false;
}

void Board::tetris(int y)
{
    for (int j = y; j > 0; j--)
    {
        for (int i = 0; i < BOARD_WIDTH; i++)
        {
            boardMatrix[i][j] = boardMatrix[i][j-1];
        }
    }   
}

void Board::checkTetris()
{
    for (int j = 0; j < BOARD_HEIGHT; j++)
    {
        int i = 0;
        
        while (i < BOARD_WIDTH)
        {
            if (boardMatrix[i][j] != TAKEN) 
            {
                break;
            }

            i++;
        }
 
        if (i == BOARD_WIDTH) 
        {
            tetris(j);
        }
    }
}

bool Board::isFree(int x, int y)
{
    if (boardMatrix[x][y] == TAKEN) 
    {
        return true; 
    }
    else 
    {
        return false;
    }
}

int Board::getXPos(int pos)
{
    return  ( ( BOARD_CENTER - (PIXEL_BLOCK_SIZE * (BOARD_WIDTH / 2)) ) + (pos * PIXEL_BLOCK_SIZE) );
}
 

int Board::getYPos(int pos)
{
    return ( (screenHeight - (PIXEL_BLOCK_SIZE * BOARD_HEIGHT)) + (pos * PIXEL_BLOCK_SIZE) );
}

bool Board::isLegalMove(int x, int y, int piece, int rotation)
{
    for (int i = x, j = 0; i < x + NUM_BLOCKS; i++, j++)
    {
        for (int n = y, m = 0; n < y + NUM_BLOCKS; n++, m++)
        {   
            if (i < 0 || i > BOARD_WIDTH  - 1 || n > BOARD_HEIGHT - 1)
            {
                if (storedPieces->getPostionType(piece, rotation, m, j) != 0)
                    return 0;       
            }
 
            if (n >= 0) 
            {
                if ((storedPieces->getPostionType(piece, rotation, m, j) != 0) && (!isFree(i, n)))
                {
                    return false;
                }
            }
        }
    }
 
    return true;
}