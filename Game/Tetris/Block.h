#ifndef __BLOCK_H
#define __BLOCK_H
#include "GameEntity.h"
#include "AnimatedTexture.h"
#include "Random.h"

namespace SDLFramework
{
	class Block : public GameEntity
	{
	private:
		Texture* mSkin;
		int mRow;
		int mColumn;
		int mWidth;
		int mHeight;
		
		//void SetTexture();

	public:
		int GetRow();
		int GetColumn();
		void SetGridLocation(int x, int y);

		Block();
		~Block();
	};
}
#endif