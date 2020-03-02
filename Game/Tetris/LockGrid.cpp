#include "LockGrid.h"

namespace SDLFramework
{
	LockGrid* LockGrid::sInstance = nullptr;

	LockGrid* LockGrid::Instance()
	{
		if (sInstance == nullptr)
		{
			sInstance = new LockGrid();
		}
		return sInstance;
	}

	void LockGrid::Release()
	{
		sInstance = nullptr;
		delete sInstance;
	}

	void LockGrid::CheckPosition()
	{
		for (int i = 0; i < mColumns; i++)
		{
			for (int j = 0; j < mRows; j++)
			{
				if (pieceRow == j && pieceColumn == i)
				{
					for (int z = 0; z < 4; z++)
					{
						GridPiece[z][mColumns][mRows] = new Texture("GameSprites.png", 38, 160, 7, 7);
						GridPiece[z][mColumns][mRows]->SetParent(this);
						GridPiece[z][mColumns][mRows]->SetScale(Vector2(3.5f, 3.5f));
					}
					PieceMovement(j, i);
				}
			}
		}
	}

	void LockGrid::CollisionCheck(Vector2 pos)
	{
		int k = (int)pos.x;
		int l = (int)pos.y;

		for (int i = 0; i < mColumns; i++)
		{
			for (int j = 0; j < mRows; j++)
			{

			}
		}
	}

	void LockGrid::NewPiece()
	{
		pieceColumn = 1;
		pieceRow = 5;
		PieceShape();
		CheckPosition();
	}

	void LockGrid::MakeGrid()
	{
		for (int i = 0; i < mColumns; i++)
		{
			for (int j = 0; j < mRows; j++)
			{
				/*GridPiece[j][i] = new Texture("GameSprites.png", 38, 160, 7, 7);
				GridPiece[j][i]->SetParent(this);
				GridPiece[j][i]->SetScale(Vector2(3.5f, 3.5f));
				GridPiece[j][i]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + (j * slotSize), Graphics::SCREEN_HEIGHT * 0.185f + (i * slotSize));*/
			}
		}
	}

	void LockGrid::PieceShape()
	{		
		oldPos[0] = Vector2(0, 0);
		switch (mRandom->GetCurrentPiece())
		{																							//+right												+down
		case 0:	//T		//center
			oldPos[1] = Vector2(1, 0);
			oldPos[2] = Vector2(-1, 0);
			oldPos[3] = Vector2(0, 1);
			break;

		case 1:	//J		//center line
			oldPos[1] = Vector2(0, -1);
			oldPos[2] = Vector2(0, 1);
			oldPos[3] = Vector2(-1, 1);
			break;

		case 2:	//Z		//bottom right
			oldPos[1] = Vector2(1, 0);
			oldPos[2] = Vector2(0, -1);
			oldPos[3] = Vector2(-1, -1);
			break;
			
		case 3:	//O		//none
			oldPos[1] = Vector2(1, 0);
			oldPos[2] = Vector2(0, 1);
			oldPos[3] = Vector2(1, 1);
			break;

		case 4:	//S		//top left
			oldPos[1] = Vector2(1, 0);
			oldPos[2] = Vector2(0, 1);
			oldPos[3] = Vector2(-1, 1);
			break;
			
		case 5:	//L		//center line
			oldPos[1] = Vector2(0, -1);
			oldPos[2] = Vector2(0, 1);
			oldPos[3] = Vector2(1, 1);
			break;

		case 6:	//I		//second in
			oldPos[1] = Vector2(0, -1);
			oldPos[2] = Vector2(0, 1);
			oldPos[3] = Vector2(0, 2);
			break;
		}
	}

	void LockGrid::PieceMovement(int j, int i)
	{
		for (int p = 0; p < 4; p++)
		{
			GridPiece[p][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + ((j * slotSize) + (slotSize * oldPos[p].x)), Graphics::SCREEN_HEIGHT * 0.185f + (i * slotSize) + (slotSize * oldPos[p].y));
		}
	}

	LockGrid::LockGrid()
	{
		mRandom = Random::Instance();
		mRandom->SetNextPiece();
		mRandom->GetCurrentPiece();
		mRandom->SetCurrentPiece();
		mRandom->SetNextPiece();
		mRandom->GetCurrentPiece();

		for (int i = 0; i < mColumns; i++)
		{
			for (int j = 0; j < mRows; j++)
			{
				if (pieceRow == j && pieceColumn == i)
				{
					for (int z = 0; z < 4; z++)
					{
						GridPiece[z][mColumns][mRows] = new Texture("GameSprites.png", 38, 160, 7, 7);
						GridPiece[z][mColumns][mRows]->SetParent(this);
						GridPiece[z][mColumns][mRows]->SetScale(Vector2(3.5f, 3.5f));
					}
					PieceShape();
					PieceMovement(j, i);
				}
			}
		}
	}

	LockGrid::~LockGrid()
	{
	}
}