#include <game.h>

int Game::randomPiece(int x, int y)
{
    return rand() % (x - y + 1) + x;
}

void Game::startGame()
{
    srand((unsigned int) time(NULL));
 
    current_piece = randomPiece (0, 6);
    current_rotation = randomPiece (0, 3);
    posX = (BOARD_WIDTH / 2) + pieces->getInitialX(current_piece, current_rotation);
    posY = pieces->getInitialY(current_piece, current_rotation);
 
    nextPiece = randomPiece(0, 6);
    nextRotation = randomPiece(0, 3);
    nextX = BOARD_WIDTH + 5;
    nextY = 5;    
}

void Game::makePiece()
{
    current_piece = nextPiece;
    current_rotation = nextRotation;
    posX = (BOARD_WIDTH / 2) + pieces->getInitialX (current_piece, current_rotation);
    posY = pieces->getInitialY(current_piece, current_rotation);
 
    nextPiece = randomPiece(0, 6);
    nextRotation = randomPiece(0, 3);
}

void Game::drawPiece (int x, int y, int piece, int rotation)
{ 
    int pixelsX = board->getXPos (x);
    int pixelsY = board->getYPos (y);
 
    for (int i = 0; i < NUM_BLOCKS; i++)
    {
        for (int j = 0; j < NUM_BLOCKS; j++)
        {
            if (pieces->getPostionType(piece, rotation, j, i) != 0) 
            {
                Draw->DrawRectangle(pixelsX + i * PIXEL_BLOCK_SIZE, pixelsY + j * PIXEL_BLOCK_SIZE, (pixelsX + i * PIXEL_BLOCK_SIZE) + PIXEL_BLOCK_SIZE - 1, (pixelsY + j * PIXEL_BLOCK_SIZE) + PIXEL_BLOCK_SIZE - 1);
            }
        }
    }
}

void Game::drawBoard ()
{
    int boardLeft = BOARD_CENTER - (PIXEL_BLOCK_SIZE * (BOARD_WIDTH / 2)) - 1;
    int boardRight = BOARD_CENTER + (PIXEL_BLOCK_SIZE * (BOARD_WIDTH / 2));
    int boardHeight = screenHeight - (PIXEL_BLOCK_SIZE * BOARD_HEIGHT);
     
    Draw->DrawRectangle(boardLeft - BOARD_WIDTH, boardHeight, boardLeft, screenHeight - 1);
 
    Draw->DrawRectangle(boardRight, boardHeight, boardRight + BOARD_WIDTH, screenHeight - 1);
     
    boardLeft += 1;
    for (int i = 0; i < BOARD_WIDTH; i++)
    {
        for (int j = 0; j < BOARD_HEIGHT; j++)
        {   
            if (!board->isFree(i, j))  
            {
                Draw->DrawRectangle( boardLeft + i * PIXEL_BLOCK_SIZE, boardHeight + j * PIXEL_BLOCK_SIZE, (boardLeft + i * PIXEL_BLOCK_SIZE) + PIXEL_BLOCK_SIZE - 1, (boardHeight + j * PIXEL_BLOCK_SIZE) + PIXEL_BLOCK_SIZE - 1);
            }
        }
    }   
}

void Game::drawGame ()
{
    drawBoard ();                                                   
    drawPiece (posX, posY, current_piece, current_rotation);                    
    drawPiece (nextX, nextY, nextPiece, nextRotation);    
}