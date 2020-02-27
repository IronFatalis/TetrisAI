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
		static const int mRows = 24;
		static const int mColumns = 10;

		int mRowCounter;

		static LockGrid* sInstance;

	public:
		LockGrid();
		~LockGrid();

		void MakeGrid();

		bool bLockGrid[mRows][mColumns];
		int mGrid[mRows][mColumns];

		static LockGrid* Instance();
		static void Release();

		//will be used to see if a player can clear a row
		void CheckRow();
		void CollisionCheck(Vector2 pos);
		void SetBox(int x, int y);
	};
}
#endif