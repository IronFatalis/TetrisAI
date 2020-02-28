#ifndef __PIECES_H
#define __PIECES_H
#include "GameEntity.h"
#include "AnimatedTexture.h"
#include "Random.h"
#include "LockGrid.h"

namespace SDLFramework
{
	class Pieces : public GameEntity
	{
	private:
		static Pieces* sInstance;
		Random* mRandom;
		

	public:
		static Pieces* Instance();

		int LocX = 0.54f;
		int LocY = 0.34f;
		int BlockSize = 22;

		Pieces();
		~Pieces();

		Texture* mCurrentPiece[5];

		void NewPiece();
		void MoveLeft();
		void MoveRight();
		void MoveDown();

		Vector2 PiecePosition;

		void Render() override;
		static void Release();
	};
}
#endif