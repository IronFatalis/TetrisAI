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

	//for (int i = 0; i < 4; ++i)
	//{
	//	for (int p = 0; p < 4; p++)
	//	{
	//		checkLR[p] = (mGrid->pieceRow + mGrid->oldPos[p].x);
	//		checkUD[p] = (mGrid->pieceColumn + mGrid->oldPos[p].y);
	//	}
	//	if ((mGrid->pieceRow + mGrid->oldPos[0].x) < 9 && (mGrid->pieceRow + mGrid->oldPos[1].x) < 9 && (mGrid->pieceRow + mGrid->oldPos[2].x) < 9 && (mGrid->pieceRow + mGrid->oldPos[3].x) < 9 && !mGrid->LockedPiece[checkUD[0]][checkLR[0] + 1] && !mGrid->LockedPiece[checkUD[1]][checkLR[1] + 1] && !mGrid->LockedPiece[checkUD[2]][checkLR[2] + 1] && !mGrid->LockedPiece[checkUD[3]][checkLR[3] + 1])
	//	{	//move right
	//		if (i == 3)
	//		{
	//			mGrid->pieceRow++;
	//			mGrid->CheckPosition();
	//			mAudio->PlaySFX("SFX/LeftRight.wav", 0, 1);
	//		}
	//		mPieces->MoveRight();
	//	}
	//	else if ((mGrid->pieceRow + mGrid->oldPos[0].x) > 0 && (mGrid->pieceRow + mGrid->oldPos[1].x) > 0 && (mGrid->pieceRow + mGrid->oldPos[2].x) > 0 && (mGrid->pieceRow + mGrid->oldPos[3].x) > 0 && !mGrid->LockedPiece[checkUD[0]][checkLR[0] - 1] && !mGrid->LockedPiece[checkUD[1]][checkLR[1] - 1] && !mGrid->LockedPiece[checkUD[2]][checkLR[2] - 1] && !mGrid->LockedPiece[checkUD[3]][checkLR[3] - 1])
	//	{	//move left
	//		if (i == 3)
	//		{
	//			mGrid->pieceRow--;
	//			mGrid->CheckPosition();
	//			mAudio->PlaySFX("SFX/LeftRight.wav", 0, 1);
	//		}
	//		mPieces->MoveLeft();
	//	}
	//}
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

	/*for (int p = 0; p < 4; p++)
	{
		mGrid->newPos[p].x = (-1 * mGrid->oldPos[p].y);
		mGrid->newPos[p].y = (1 * mGrid->oldPos[p].x);
		GameScreen->checkLR[p] = (mGrid->pieceRow + mGrid->newPos[p].x);
		GameScreen->checkUD[p] = (mGrid->pieceColumn + mGrid->newPos[p].y);
	}
	if ((mGrid->pieceRow + mGrid->newPos[0].x) < 9 && (mGrid->pieceRow + mGrid->newPos[0].x) > 0 && (mGrid->pieceRow + mGrid->newPos[1].x) < 9 && (mGrid->pieceRow + mGrid->newPos[1].x) > 0 && (mGrid->pieceRow + mGrid->newPos[2].x) < 9 && (mGrid->pieceRow + mGrid->newPos[2].x) > 0 && (mGrid->pieceRow + mGrid->newPos[3].x) < 9 && (mGrid->pieceRow + mGrid->newPos[3].x) > 0 && mGrid->pieceColumn < 23 && !mGrid->LockedPiece[checkUD[0]][checkLR[0]] && !mGrid->LockedPiece[checkUD[1]][checkLR[1]] && !mGrid->LockedPiece[checkUD[2]][checkLR[2]] && !mGrid->LockedPiece[checkUD[3]][checkLR[3]])
	{
		for (int p = 0; p < 4; p++)
		{
			mGrid->oldPos[p] = mGrid->newPos[p];
		}
	}
	else
	{
		for (int p = 0; p < 4; p++)
		{
			mGrid->newPos[p].x = mGrid->oldPos[p].x;
			mGrid->newPos[p].y = mGrid->oldPos[p].y;
		}
	}
	mGrid->CheckPosition();*/
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

	/*for (int i = 0; i < 4; ++i)
	{
		for (int p = 0; p < 4; p++)
		{
			checkLR[p] = (mGrid->pieceRow + mGrid->oldPos[p].x);
			checkUD[p] = (mGrid->pieceColumn + mGrid->oldPos[p].y);
		}
		if ((mGrid->pieceColumn + mGrid->oldPos[0].y) < 23 && (mGrid->pieceColumn + mGrid->oldPos[1].y) < 23 && (mGrid->pieceColumn + mGrid->oldPos[2].y) < 23 && (mGrid->pieceColumn + mGrid->oldPos[3].y) < 23 && !mGrid->LockedPiece[checkUD[0] + 1][checkLR[0]] && !mGrid->LockedPiece[checkUD[1] + 1][checkLR[1]] && !mGrid->LockedPiece[checkUD[2] + 1][checkLR[2]] && !mGrid->LockedPiece[checkUD[3] + 1][checkLR[3]])
		{
			if (i == 3)
			{
				mGrid->pieceColumn++;
				mGrid->CheckPosition();
				PieceDrop = 0;
				mTimer->Reset();
			}
		}
	}*/
}

void ST_DROP::Exit(CPU* CPU)
{
}