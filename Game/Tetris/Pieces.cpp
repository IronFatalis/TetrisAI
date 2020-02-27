#include "Pieces.h"

namespace SDLFramework
{
	Pieces* Pieces::sInstance = nullptr;

	Pieces::Pieces()
	{
		mRandom = Random::Instance();
		mRandom->SetNextPiece();
		mRandom->GetCurrentPiece();
		mRandom->SetCurrentPiece();
		mRandom->SetNextPiece();
		mRandom->GetCurrentPiece();

		for (int i = 1; i < 5; ++i)
		{
			mCurrentPiece[i] = new Texture("GameSprites.png", 38, 160, 7, 7);
			mCurrentPiece[i]->SetParent(this);
			mCurrentPiece[i]->SetScale(Vector2(3.5f, 3.5f));
		}

		mCurrentPiece[1]->SetPosition(Graphics::SCREEN_WIDTH * 0.54f, Graphics::SCREEN_HEIGHT * 0.18f);

		Vector2(mCurrentPiece[1]->GetPosition());

		switch (mRandom->GetCurrentPiece())
		{
		case 0:
			mCurrentPiece[2]->SetPosition(mCurrentPiece[1]->mPosition + Vector2(0, BlockSize));
			mCurrentPiece[3]->SetPosition(mCurrentPiece[1]->mPosition + Vector2(BlockSize, 0));
			mCurrentPiece[4]->SetPosition(mCurrentPiece[1]->mPosition - Vector2(BlockSize, 0));
			break;
		case 1:
			mCurrentPiece[2]->SetPosition(mCurrentPiece[1]->mPosition + Vector2(0, BlockSize));
			mCurrentPiece[3]->SetPosition(mCurrentPiece[1]->mPosition + Vector2(0, (BlockSize * 2)));
			mCurrentPiece[4]->SetPosition(mCurrentPiece[1]->mPosition - Vector2(BlockSize, 0));
			break;
		case 2:
			mCurrentPiece[2]->SetPosition(mCurrentPiece[1]->mPosition - Vector2(0, BlockSize));
			mCurrentPiece[3]->SetPosition(mCurrentPiece[1]->mPosition + Vector2(BlockSize, 0));
			mCurrentPiece[4]->SetPosition(mCurrentPiece[1]->mPosition - Vector2(BlockSize, BlockSize));
			break;
		case 3:
			mCurrentPiece[2]->SetPosition(mCurrentPiece[1]->mPosition + Vector2(0, BlockSize));
			mCurrentPiece[3]->SetPosition(mCurrentPiece[1]->mPosition + Vector2(BlockSize, 0));
			mCurrentPiece[4]->SetPosition(mCurrentPiece[1]->mPosition + Vector2(BlockSize, BlockSize));
			break;
		case 4:
			mCurrentPiece[2]->SetPosition(mCurrentPiece[1]->mPosition - Vector2(0, BlockSize));
			mCurrentPiece[3]->SetPosition(mCurrentPiece[1]->mPosition - Vector2(BlockSize, 0));
			mCurrentPiece[4]->SetPosition(mCurrentPiece[1]->mPosition + Vector2(BlockSize, -BlockSize));
			break;
		case 5:
			mCurrentPiece[2]->SetPosition(mCurrentPiece[1]->mPosition + Vector2(0, BlockSize));
			mCurrentPiece[3]->SetPosition(mCurrentPiece[1]->mPosition + Vector2(0, (BlockSize * 2)));
			mCurrentPiece[4]->SetPosition(mCurrentPiece[1]->mPosition + Vector2(BlockSize, 0));
			break;
		case 6:
			mCurrentPiece[2]->SetPosition(mCurrentPiece[1]->mPosition + Vector2(0, BlockSize));
			mCurrentPiece[3]->SetPosition(mCurrentPiece[1]->mPosition + Vector2(0, (BlockSize * 2)));
			mCurrentPiece[4]->SetPosition(mCurrentPiece[1]->mPosition + Vector2(0, (BlockSize * 3)));
			break;
		}
	}

	Pieces::~Pieces()
	{
		Release();
	}

	void Pieces::NewPiece()
	{
		for (int i = 1; i < 5; ++i)
		{
			mCurrentPiece[i] = new Texture("GameSprites.png", 38, 160, 7, 7);
			mCurrentPiece[i]->SetParent(this);
			mCurrentPiece[i]->SetScale(Vector2(3.5f, 3.5f));
		}

		mCurrentPiece[1]->SetPosition(Graphics::SCREEN_WIDTH * 0.54f, Graphics::SCREEN_HEIGHT * 0.18f);

		Vector2(mCurrentPiece[1]->GetPosition());

		switch (mRandom->GetCurrentPiece())
		{
		case 0:
			mCurrentPiece[2]->SetPosition(mCurrentPiece[1]->mPosition + Vector2(0, BlockSize));
			mCurrentPiece[3]->SetPosition(mCurrentPiece[1]->mPosition + Vector2(BlockSize, 0));
			mCurrentPiece[4]->SetPosition(mCurrentPiece[1]->mPosition - Vector2(BlockSize, 0));
			break;
		case 1:
			mCurrentPiece[2]->SetPosition(mCurrentPiece[1]->mPosition + Vector2(0, BlockSize));
			mCurrentPiece[3]->SetPosition(mCurrentPiece[1]->mPosition + Vector2(0,(BlockSize*2)));
			mCurrentPiece[4]->SetPosition(mCurrentPiece[1]->mPosition - Vector2(BlockSize, 0));
			break;
		case 2:
			mCurrentPiece[2]->SetPosition(mCurrentPiece[1]->mPosition - Vector2(0, BlockSize));
			mCurrentPiece[3]->SetPosition(mCurrentPiece[1]->mPosition + Vector2(BlockSize, 0));
			mCurrentPiece[4]->SetPosition(mCurrentPiece[1]->mPosition - Vector2(BlockSize, BlockSize));
			break;
		case 3:
			mCurrentPiece[2]->SetPosition(mCurrentPiece[1]->mPosition + Vector2(0, BlockSize));
			mCurrentPiece[3]->SetPosition(mCurrentPiece[1]->mPosition + Vector2(BlockSize, 0));
			mCurrentPiece[4]->SetPosition(mCurrentPiece[1]->mPosition + Vector2(BlockSize, BlockSize));
			break;
		case 4:
			mCurrentPiece[2]->SetPosition(mCurrentPiece[1]->mPosition - Vector2(0, BlockSize));
			mCurrentPiece[3]->SetPosition(mCurrentPiece[1]->mPosition - Vector2(BlockSize, 0));
			mCurrentPiece[4]->SetPosition(mCurrentPiece[1]->mPosition + Vector2(BlockSize, -BlockSize));
			break;
		case 5:
			mCurrentPiece[2]->SetPosition(mCurrentPiece[1]->mPosition + Vector2(0, BlockSize));
			mCurrentPiece[3]->SetPosition(mCurrentPiece[1]->mPosition + Vector2(0, (BlockSize * 2)));
			mCurrentPiece[4]->SetPosition(mCurrentPiece[1]->mPosition + Vector2(BlockSize, 0));
			break;
		case 6:
			mCurrentPiece[2]->SetPosition(mCurrentPiece[1]->mPosition + Vector2(0, BlockSize));
			mCurrentPiece[3]->SetPosition(mCurrentPiece[1]->mPosition + Vector2(0, (BlockSize * 2)));
			mCurrentPiece[4]->SetPosition(mCurrentPiece[1]->mPosition + Vector2(0,(BlockSize*3)));
			break;
		}
	}

	void Pieces::MoveLeft()
	{
		Vector2(mCurrentPiece[1]->GetPosition());
		for (int i = 1; i < 5; ++i)
		{			
			mCurrentPiece[i]->SetParent(this);
			mCurrentPiece[i]->SetScale(Vector2(3.5f, 3.5f));
			mCurrentPiece[i]->Translate(Vector2(-8, 0));
		}
	}

	void Pieces::MoveRight()
	{
		Vector2(mCurrentPiece[1]->GetPosition());
		for (int i = 1; i < 5; ++i)
		{
			mCurrentPiece[i]->SetParent(this);
			mCurrentPiece[i]->SetScale(Vector2(3.5f, 3.5f));
			mCurrentPiece[i]->Translate(Vector2(8, 0));
		}
	}

	void Pieces::MoveDown()
	{
		Vector2(mCurrentPiece[1]->GetPosition());
		for (int i = 1; i < 5; ++i)
		{
			mCurrentPiece[i]->SetParent(this);
			mCurrentPiece[i]->SetScale(Vector2(3.5f, 3.5f));
			mCurrentPiece[i]->Translate(Vector2(0,8));
		}
	}

	void Pieces::Render()
	{
		for (int i = 1; i < 5; ++i)
		{
			mCurrentPiece[i]->Render();
		}
	}

	Pieces* Pieces::Instance()
	{
		sInstance = new Pieces();
		return sInstance;
	}

	void Pieces::Release()
	{
		sInstance = nullptr;
		delete sInstance;
	}
}