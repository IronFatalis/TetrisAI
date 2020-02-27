#include "CPUStates.h"

#include <iostream>
using std::cout;
using std::endl;


CPUCheckFirstPiece* CPUCheckFirstPiece::Instance()
{
	static CPUCheckFirstPiece instance;

	return &instance;
}

void CPUCheckFirstPiece::Enter(CPU* CPU)
{
	//when entering state
	cout << "Check First Piece" << endl;
}

void CPUCheckFirstPiece::Execute(CPU* CPU)
{
	//while in state
}

void CPUCheckFirstPiece::Exit(CPU* CPU)
{
	//when leaving
}




CPUCheckHole* CPUCheckHole::Instance()
{
	static CPUCheckHole instance;

	return &instance;
}

void CPUCheckHole::Enter(CPU* CPU)
{
	cout << "Checking hole" << endl;
}

void CPUCheckHole::Execute(CPU* CPU)
{
}

void CPUCheckHole::Exit(CPU* CPU)
{
}





CPUMoveToHole* CPUMoveToHole::Instance()
{
	static CPUMoveToHole instance;

	return &instance;
}

void CPUMoveToHole::Enter(CPU* CPU)
{
	cout << "Move to hole" << endl;
}

void CPUMoveToHole::Execute(CPU* CPU)
{
	
}

void CPUMoveToHole::Exit(CPU* CPU)
{
}





CPUDropPiece* CPUDropPiece::Instance()
{
	static CPUDropPiece instance;

	return &instance;
}

void CPUDropPiece::Enter(CPU* CPU)
{
	cout << "Drop piece" << endl;
}

void CPUDropPiece::Execute(CPU* CPU)
{
}

void CPUDropPiece::Exit(CPU* CPU)
{
}





CPUNextPiece* CPUNextPiece::Instance()
{
	static CPUNextPiece instance;

	return &instance;
}

void CPUNextPiece::Enter(CPU* CPU)
{
	cout << "Finding Next Piece" << endl;
}

void CPUNextPiece::Execute(CPU* CPU)
{
}

void CPUNextPiece::Exit(CPU* CPU)
{
}
