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

	void LockGrid::CheckRow()
	{
		//check the grid for any rows that player has scored
		for (int i = 0; i < mRows; i++)
		{
			mRowCounter = 0;
			for (int j = 0; i < mColumns; j++)
			{
				//if this iteratation and the next one are both true, tick up the row counter
				if (bLockGrid[i][j] == true && bLockGrid[i + 1][j + 1] == true)
				{
					mRowCounter += 1;
				}
				//when the row counter hits 5, set the row to false and add points to players score
				if (mRowCounter == 5)
				{
					bLockGrid[i][mColumns] = false;
					//add score to players score
				}
			}
		}
	}

	void LockGrid::CollisionCheck(Vector2 pos)
	{
		int k = (int)pos.x;
		int l = (int)pos.y;

		for (int i = 0; i < mRows; i++)
		{
			for (int j = 0; j < mColumns; j++)
			{
				if (bLockGrid[k][l] == true && bLockGrid[k + 10][l + 10] == true)
				{
					//collison happens, block cannot go any lower
				}
			}
		}
	}

	void LockGrid::SetBox(int x, int y)
	{
		int k = (int)x;
		int l = (int)y;
		std::printf("\r\n");
		for (int i = 0; i < mRows; i++)
		{
			for (int j = 0; j < mColumns; j++)
			{
				if (bLockGrid[i][j] == bLockGrid[x][y])
				{
					bLockGrid[k][l] = true;
					std::printf("O ");
				}
				else
				{
					std::printf("X ");
				}
				//will need some sort of switch later for different piece shapes
			}
			std::printf("\r\n");
		}
		std::printf("\r\n");
	}

	void LockGrid::MakeGrid()
	{
		std::printf("\r\n");
		for (int i = 0; i < mRows; i++)
		{
			for (int j = 0; j < mColumns; j++)
			{
				bLockGrid[i][j] = false;
				std::printf("X ");
			}
			std::printf("\r\n");
		}
		std::printf("\r\n");
		std::printf("grid made ");
	}

	LockGrid::LockGrid()
	{
		mRowCounter = 0;
		std::printf("Constructor called ");
		std::printf("\r\n");
		MakeGrid();
	}

	LockGrid::~LockGrid()
	{
		
	}
}