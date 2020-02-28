#ifndef __LOCKGRID_H
#define __LOCKGRID_H
#include "GameEntity.h"
#include "AnimatedTexture.h" //for testing where the grid is
#include "LockBlock.h"
#include <vector>

namespace SDLFramework
{
	class LockGrid : public GameEntity
	{
	private:

		//how many rows and columns the grid will be
		

		int mRowCounter;

		static LockGrid* sInstance;

	public:
		LockGrid();
		~LockGrid();

		void MakeGrid();

		int mRows = 10;
		int mColumns = 24;

		static LockGrid* Instance();
		static void Release();

		//will be used to see if a player can clear a row
		void CheckPosition();
		void CollisionCheck(Vector2 pos);
		void NewPiece();

		Texture* GridPiece[5][24][10];

		int pieceColumn = 1;
		int pieceRow = 5;

	};
}
#endif