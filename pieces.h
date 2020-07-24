#ifndef _PIECES_
#define _PIECES_

#define PIECE_TYPES 7
#define NUM_ROTATIONS 4
#define NUM_X_BLOCKS 5
#define NUM_Y_BLOCKS 5
#define POSITION 2

class Pieces
{
public:

	int getPostionType(int pPiece, int pRotation, int pX, int pY);
	int getInitialY(int pPiece, int pRotation);
	int getInitialX(int pPiece, int pRotation);

};

#endif