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
					PieceShape(j, i);
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

	void LockGrid::PieceShape(int j, int i)
	{
		GridPiece[0][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + ((j * 22) + (22 * 0)), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22 * 0));
		
		switch (mRandom->GetCurrentPiece())
		{																							//+right												+down
		case 0:	//T		//center

			// 1  0  1  0			0  1  0  1
			//-1  0 -1  0			0 -1  0 -1
			// 0  1  0 -1			1  0 -1  0

			if (rotate == 0)
			{
				GridPiece[1][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + ((j * 22) + (22 * 1)), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22 * 0));
				GridPiece[2][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + ((j * 22) + (22 * -1)), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22 * 0));
				GridPiece[3][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + ((j * 22) + (22 * 0)), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22 * 1));
			}
			else if (rotate == 1)
			{
				GridPiece[1][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + ((j * 22) + (22 * 0)), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22 * 1));
				GridPiece[2][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + ((j * 22) + (22 * 0)), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22 * -1));
				GridPiece[3][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + ((j * 22) + (22 * -1)), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22 * 0));
			}
			else if (rotate == 2)
			{
				GridPiece[1][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + ((j * 22) + (22 * 1)), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22 * 0));
				GridPiece[2][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + ((j * 22) + (22 * -1)), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22 * 0));
				GridPiece[3][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + ((j * 22) + (22 * 0)), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22 * -1));
			}
			else if (rotate == 3)
			{
				GridPiece[1][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + ((j * 22) + (22 * 0)), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22 * 1));
				GridPiece[2][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + ((j * 22) + (22 * 0)), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22 * -1));
				GridPiece[3][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + ((j * 22) + (22 * 1)), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22 * 0));
			}
			break;
		case 1:	//J		//center line

			// 0  1  0 -1		-1  0  1  0
			// 0 -1  0  1		 1  0 -1  0
			//-1 -1  1  1		 1 -1 -1  1

			if (rotate == 0)
			{
				GridPiece[1][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + ((j * 22) + (22 * 0)), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22 * -1));
				GridPiece[2][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + ((j * 22) + (22 * 0)), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22 * 1));
				GridPiece[3][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + ((j * 22) + (22 * -1)), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22 * 1));
			}
			else if (rotate == 1)
			{
				GridPiece[1][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + ((j * 22) + (22 * 1)), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22 * 0));
				GridPiece[2][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + ((j * 22) + (22 * -1)), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22 * 0));
				GridPiece[3][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + ((j * 22) + (22 * -1)), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22 * -1));
			}
			else if (rotate == 2)
			{
				GridPiece[1][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + ((j * 22) + (22 * 0)), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22 * 1));
				GridPiece[2][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + ((j * 22) + (22 * 0)), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22 * -1));
				GridPiece[3][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + ((j * 22) + (22 * 1)), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22 * -1));
			}
			else if (rotate == 3)
			{
				GridPiece[1][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + ((j * 22) + (22 * -1)), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22 * 0));
				GridPiece[2][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + ((j * 22) + (22 * 1)), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22 * 0));
				GridPiece[3][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + ((j * 22) + (22 * 1)), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22 * 1));
			}
			break;

		case 2:	//Z		//bottom right
			if (rotate == 0 || rotate == 2)
			{
				GridPiece[1][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + ((j * 22) + (22 * 1)), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22 * 0));
				GridPiece[2][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + ((j * 22) + (22 * 0)), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22 * -1));
				GridPiece[3][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + ((j * 22) + (22 * -1)), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22 * -1));
			}
			else if (rotate == 1 || rotate == 3)
			{
				GridPiece[1][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + ((j * 22) + (22 * 0)), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22 * 1));
				GridPiece[2][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + ((j * 22) + (22 * 1)), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22 * 0));
				GridPiece[3][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + ((j * 22) + (22 * 1)), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22 * -1));
			}
			break;

		case 3:	//O		//none
			GridPiece[1][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + ((j * 22) + (22 * 1)), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22 * 0));
			GridPiece[2][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + ((j * 22) + (22 * 0)), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22 * 1));
			GridPiece[3][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + ((j * 22) + (22 * 1)), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22 * 1));
			break;

		case 4:	//S		//top left
			if (rotate == 0 || rotate == 2)
			{
			GridPiece[1][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + ((j * 22) + (22 * 1)), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22 * 0));
			GridPiece[2][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + ((j * 22) + (22 * 0)), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22 * 1));
			GridPiece[3][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + ((j * 22) + (22 * -1)), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22 * 1));
			}
			else if (rotate == 1 || rotate == 3)
			{
			}
			break;

		case 5:	//L		//center line
			if (rotate == 0)
			{
			GridPiece[1][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + ((j * 22) + (22 * 0)), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22 * 1));
			GridPiece[2][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + ((j * 22) + (22 * 0)), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22 * 2));
			GridPiece[3][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + ((j * 22) + (22 * 1)), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22 * 2));
			}
			else if (rotate == 1)
			{
			}
			else if (rotate == 2)
			{
			}
			else if (rotate == 3)
			{
			}
			break;

		case 6:	//I		//second in
			if (rotate == 0 || rotate == 2)
			{
			GridPiece[1][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + ((j * 22) + (22 * 1)), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22 * 0));
			GridPiece[2][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + ((j * 22) + (22 * 2)), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22 * 0));
			GridPiece[3][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + ((j * 22) + (22 * 3)), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22 * 0));
			}
			else if (rotate == 1 || rotate == 3)
			{
			}
			break;
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
					}																						//+right												+down

					GridPiece[0][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + (j * 22) + (22 * 0), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22 * 0));
					GridPiece[1][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + (j * 22) + (22 * 0), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22 * -1));
					GridPiece[2][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + (j * 22) + (22 * 1), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22 * 0));
					GridPiece[3][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + (j * 22) + (22 * 2), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22 * 0));

					/*GridPiece[0][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + (j * 22) + (22*0), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22)+ (22*0));
					GridPiece[1][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + (j * 22) + (22*-1), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22*0));
					GridPiece[2][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + (j * 22) + (22*0), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22*-1));
					GridPiece[3][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + (j * 22) + (22*0), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22*-2));*/

					/*GridPiece[0][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + (j * 22) + (22 * 0), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22 * 0));
					GridPiece[1][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + (j * 22) + (22 * 1), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22 * 0));
					GridPiece[2][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + (j * 22) + (22 * 0), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22 * 1));
					GridPiece[3][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + (j * 22) + (22 * 0), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22 * 2));*/
			
					/*GridPiece[0][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + (j * 22) + (22 * 0), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22 * 0));
					GridPiece[1][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + (j * 22) + (22 * 0), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22 * 1));
					GridPiece[2][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + (j * 22) + (22 * -1), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22 * 0));
					GridPiece[3][mColumns][mRows]->SetPosition(Graphics::SCREEN_WIDTH * 0.395f + (j * 22) + (22 * -2), Graphics::SCREEN_HEIGHT * 0.185f + (i * 22) + (22 * 0));*/
				}
			}
		}
	}

	LockGrid::~LockGrid()
	{
	}
}