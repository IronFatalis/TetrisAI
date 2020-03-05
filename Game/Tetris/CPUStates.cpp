#include "CPUStates.h"

#include <iostream>
using std::cout;
using std::endl;


ST_CHECKPIECE* ST_CHECKPIECE::Instance()
{
	static ST_CHECKPIECE instance;

	return &instance;
}

void ST_CHECKPIECE::Enter(CPU* CPU)
{
	//when entering state
	cout << "Check Piece" << endl;
	//mRandom->GetCurrentPiece();
	//check what piece is the current piece
}

void ST_CHECKPIECE::Execute(CPU* CPU)
{
	//while in state
}

void ST_CHECKPIECE::Exit(CPU* CPU)
{
	//when leaving switch to ST_MOVEPIECE
}




ST_MOVEPIECE* ST_MOVEPIECE::Instance()
{
	static ST_MOVEPIECE instance;

	return &instance;
}

void ST_MOVEPIECE::Enter(CPU* CPU)
{
	cout << "Checking hole" << endl;
	//check lowest open space
	//check which spaces around it are open
	//check if it's accessible by looking at blocks above it
}

void ST_MOVEPIECE::Execute(CPU* CPU)
{
	//move current piece L/R depending on direction of open hole
	//rotate depending on how it fits, move to ST_ROTATE
	//check if rotate is correct and if above hole, if so move to ST_DROP
}

void ST_MOVEPIECE::Exit(CPU* CPU)
{
}





ST_ROTATE* ST_ROTATE::Instance()
{
	static ST_ROTATE instance;

	return &instance;
}

void ST_ROTATE::Enter(CPU* CPU)
{
	cout << "Rotate" << endl;
	//check if part needs rotated
}

void ST_ROTATE::Execute(CPU* CPU)
{
	//rotate part if needed
}

void ST_ROTATE::Exit(CPU* CPU)
{
	//move to ST_MOVEMENT
}





ST_DROP* ST_DROP::Instance()
{
	static ST_DROP instance;

	return &instance;
}

void ST_DROP::Enter(CPU* CPU)
{
	cout << "Drop piece" << endl;
	//Make sure piece is over hole, if not go back to ST_MOVEMENT
}

void ST_DROP::Execute(CPU* CPU)
{
	//Drop piece until it locks into place
	//Once locked switch state to ST_CHECKPIECE
}

void ST_DROP::Exit(CPU* CPU)
{
}