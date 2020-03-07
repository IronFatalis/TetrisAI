#include "CPUStates.h"

#include <iostream>
using std::cout;
using std::endl;

namespace SDLFramework
{
	ST_CHECKPIECE* ST_CHECKPIECE::Instance(int currentPiece, int currentState)
	{
		static ST_CHECKPIECE instance;
		return &instance;
	}

	void ST_CHECKPIECE::Enter(int currentPiece, int currentState)
	{
		//when entering state
		cout << "Starting Piece ";
		//check what piece is the current piece
		switch (currentPiece)
		{
		case 0:
			cout << "T" << endl;
			break;
		case 1:
			cout << "J" << endl;
			break;
		case 2:
			cout << "Z" << endl;
			break;
		case 3:
			cout << "O" << endl;
			break;
		case 4:
			cout << "S" << endl;
			break;
		case 5:
			cout << "L" << endl;
			break;
		case 6:
			cout << "I" << endl;
			break;
		}

		ST_CHECKPIECE::Execute(currentPiece, currentState);
	}

	void ST_CHECKPIECE::Execute(int currentPiece, int currentState)
	{
		//while in state
		cout << "Checking Piece" << endl;
		ST_CHECKPIECE::Exit(currentPiece, currentState);
	}

	void ST_CHECKPIECE::Exit(int currentPiece, int currentState)
	{
		//when leaving switch to ST_MOVEPIECE
		cout << "Done Checking Piece" << endl;
	}




	ST_MOVEPIECE* ST_MOVEPIECE::Instance(int currentPiece, int currentState)
	{
		static ST_MOVEPIECE instance;
		ST_ROTATE::Instance(currentPiece, currentState);
		return &instance;
	}

	void ST_MOVEPIECE::Enter(int currentPiece, int currentState)
	{
		cout << "Checking hole" << endl;
		//check lowest open space
		//check which spaces around it are open
		//check if it's accessible by looking at blocks above it

		ST_MOVEPIECE::Execute(currentPiece, currentState);
	}

	void ST_MOVEPIECE::Execute(int currentPiece, int currentState)
	{
		//move current piece L/R depending on direction of open hole
		//rotate depending on how it fits, move to ST_ROTATE
		//check if rotate is correct and if above hole, if so move to ST_DROP

		//GameScreen::MovePiece();

		ST_MOVEPIECE::Exit(currentPiece, currentState);

	}

	void ST_MOVEPIECE::Exit(int currentPiece, int currentState)
	{
		if (rotate)
		{
			currentState++;
		}
		else if (position)
		{

		}
	}





	ST_ROTATE* ST_ROTATE::Instance(int currentPiece, int currentState)
	{
		static ST_ROTATE instance;

		return &instance;
	}

	void ST_ROTATE::Enter(int currentPiece, int currentState)
	{
		cout << "Rotate" << endl;
		//check if part needs rotated
	}

	void ST_ROTATE::Execute(int currentPiece, int currentState)
	{
		//rotate part if needed

		//Rotate();
		rotateAmount--;
		if (rotateAmount == 0)
		{
			rotate = false;
		}
	}

	void ST_ROTATE::Exit(int currentPiece, int currentState)
	{
		//move to ST_MOVEMENT
		if (rotate)
		{
			ST_ROTATE::Enter(currentPiece, currentState);
		}
		else if (position)
		{

		}
	}





	ST_DROP* ST_DROP::Instance(int currentPiece, int currentState)
	{
		static ST_DROP instance;

		return &instance;
	}

	void ST_DROP::Enter(int currentPiece, int currentState)
	{
		cout << "Drop piece" << endl;
		//Make sure piece is over hole, if not go back to ST_MOVEMENT
		ST_DROP::Execute(currentPiece, currentState);
	}

	void ST_DROP::Execute(int currentPiece, int currentState)
	{
		//Drop piece until it locks into place
		//Once locked switch state to ST_CHECKPIECE

		/*for (int i = 0; i < 4; ++i)
		{
			for (int p = 0; p < 4; p++)
			{
				checkLR[p] = (pieceRow + oldPos[p].x);
				checkUD[p] = (pieceColumn + oldPos[p].y);
			}
			if ((pieceColumn + oldPos[0].y) < 23 && (pieceColumn + oldPos[1].y) < 23 && (pieceColumn + oldPos[2].y) < 23 && (pieceColumn + oldPos[3].y) < 23 && !LockedPiece[checkUD[0] + 1][checkLR[0]] && !LockedPiece[checkUD[1] + 1][checkLR[1]] && !LockedPiece[checkUD[2] + 1][checkLR[2]] && !LockedPiece[checkUD[3] + 1][checkLR[3]])
			{
				if (i == 3)
				{
					pieceColumn++;
					CheckPosition();
					PieceDrop = 0;
					mTimer->Reset();
				}
			}
		}*/
		ST_DROP::Exit(currentPiece, currentState);
	}

	void ST_DROP::Exit(int currentPiece, int currentState)
	{
	}
}