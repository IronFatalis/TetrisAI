#ifndef __LOCKGRID_H
#define __LOCKGRID_H
#include "GameEntity.h"
#include "AnimatedTexture.h" //for testing where the grid is
#include "Random.h"
#include <vector>

namespace SDLFramework
{
	class LockGrid : public GameEntity
	{
	private:
		Random* mRandom;

		int mRowCounter;
		int slotSize = 22;

		static LockGrid* sInstance;

	public:
		LockGrid();
		~LockGrid();

		void LockedGrid();
		void PieceShape();
		void PieceMovement(int j, int i);

		int mRows = 10;
		int mColumns = 24;

		Vector2 newPos [4];
		Vector2 oldPos [4];

		static LockGrid* Instance();
		static void Release();

		//will be used to see if a player can clear a row
		void CheckPosition();
		void CollisionCheck(Vector2 pos);
		void NewPiece();

		Texture* GridPiece[5][24][10];
		Texture* DrawLockedPiece[24][10];
		bool LockedPiece[24][10];
		int currentState;

		int pieceColumn = 1;
		int pieceRow = 5;

	};
}
#endif