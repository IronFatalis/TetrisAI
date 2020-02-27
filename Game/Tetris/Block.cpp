#include "Block.h"

namespace SDLFramework
{
	Block::Block()
	{
		mRow = 0;
		mColumn = 0;
		mSkin = new Texture("GameSprites.png", 38, 160, 7, 7);
		mSkin->SetParent(this);
		mSkin->SetPosition(Vector2(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f));
	}

	Block::~Block()
	{
	}

	int Block::GetRow()
	{
		return mRow;
	}

	int Block::GetColumn()
	{
		return mColumn;
	}

	void Block::SetGridLocation(int x, int y)
	{
		mRow = x;
		mColumn = y;
	}
}