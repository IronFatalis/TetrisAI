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
					GridPiece[mColumns][mRows] = new Texture("GameSprites.png", 38, 160, 7, 7);
					GridPiece[mColumns][mRows]->SetParent(this);
					GridPiece[mColumns][mRows]->SetScale(Vector2(3.5f, 3.5f));
					GridPiece[mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + (j * 22), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22));
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
				if (bLockGrid[k][l] == true && bLockGrid[k + 10][l + 10] == true)
				{
					//collison happens, block cannot go any lower
				}
			}
		}
	}

	void LockGrid::NewPiece()
	{
		pieceColumn = 1;
		pieceRow = 5;
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
				GridPiece[j][i]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + (j * 22), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22));*/
			}
		}
	}

	LockGrid::LockGrid()
	{
		mRowCounter = 0;
		std::printf("Constructor called ");
		std::printf("\r\n");


		for (int i = 0; i < mColumns; i++)
		{
			for (int j = 0; j < mRows; j++)
			{
				if (pieceRow == j && pieceColumn == i)
				{
					GridPiece[mColumns][mRows] = new Texture("GameSprites.png", 38, 160, 7, 7);
					GridPiece[mColumns][mRows]->SetParent(this);
					GridPiece[mColumns][mRows]->SetScale(Vector2(3.5f, 3.5f));
					GridPiece[mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + (j * 22), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22));
				}
			}
		}
	}

	LockGrid::~LockGrid()
	{
	}
}