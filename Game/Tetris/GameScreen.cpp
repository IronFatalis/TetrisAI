#include "GameScreen.h"

namespace SDLFramework
{
	GameScreen::GameScreen()
	{
		mTimer = Timer::Instance();
		mInput = InputManager::Instance();
		mAudio = AudioManager::Instance();
		mRandom = Random::Instance();
		mTypeManager = TypeManager::GetInstance();
		mGrid = LockGrid::Instance();
		mPieces = Pieces::Instance();
		mScores = Score::Instance();

		//sanity test for scores
		mScores->AddScore(100);
		mScores->AddHeight("10");
		mScores->AddLine(2);
		mScores->AddLevel("13");
		mScores->AddtoHiScore("2345");

		if (mGrid->Instance())
		{
			std::printf("instance made on game screen ");
		}

		mGrid->MakeGrid();

		/*mRandom->SetNextPiece();
		mRandom->GetCurrentPiece();
		mRandom->SetCurrentPiece();
		mRandom->SetNextPiece();
		mRandom->GetCurrentPiece();*/

		//background
		mBackground = new Texture("GameSprites.png", 0, 0, 260, 243);
		mBackground->SetParent(this);
		mBackground->SetPosition(Graphics::SCREEN_WIDTH * 0.146f, Graphics::SCREEN_HEIGHT * 0.146f);
		mBackground->SetScale(Vector2(3.0f, 3.25f));


		// screen animation variables
		mAnimationStartPos = Vector2(0.0f, Graphics::SCREEN_HEIGHT);
		mAnimationEndPos = Vec2_Zero;
		mAnimationTotalTime = 5.0f;
		mAnimationTimer = 0.0f;
		mAnimationDone = false;

		//Next Block
		mNextBlockT = new Texture("GameSprites.png", 33, 90, 17, 16);
		mNextBlockT->SetParent(this);
		mNextBlockT->SetPosition(Graphics::SCREEN_WIDTH * 0.77f, Graphics::SCREEN_HEIGHT * 0.51f);
		mNextBlockT->SetScale(Vector2(5.0f, 5.25f));

		mNextBlockJ = new Texture("GameSprites.png", 33, 105, 17, 16);
		mNextBlockJ->SetParent(this);
		mNextBlockJ->SetPosition(Graphics::SCREEN_WIDTH * 0.77f, Graphics::SCREEN_HEIGHT * 0.51f);
		mNextBlockJ->SetScale(Vector2(5.0f, 5.25f));

		mNextBlockZ = new Texture("GameSprites.png", 33, 120, 17, 16);
		mNextBlockZ->SetParent(this);
		mNextBlockZ->SetPosition(Graphics::SCREEN_WIDTH * 0.77f, Graphics::SCREEN_HEIGHT * 0.5f);
		mNextBlockZ->SetScale(Vector2(5.0f, 5.25f));

		mNextBlockSquare = new Texture("GameSprites.png", 33, 136, 17, 16);
		mNextBlockSquare->SetParent(this);
		mNextBlockSquare->SetPosition(Graphics::SCREEN_WIDTH * 0.77f, Graphics::SCREEN_HEIGHT * 0.5f);
		mNextBlockSquare->SetScale(Vector2(5.0f, 5.25f));

		mNextBlockS = new Texture("GameSprites.png", 33, 150, 17, 16);
		mNextBlockS->SetParent(this);
		mNextBlockS->SetPosition(Graphics::SCREEN_WIDTH * 0.77f, Graphics::SCREEN_HEIGHT * 0.49f);
		mNextBlockS->SetScale(Vector2(5.0f, 5.25f));

		mNextBlockL = new Texture("GameSprites.png", 33, 168, 17, 16);
		mNextBlockL->SetParent(this);
		mNextBlockL->SetPosition(Graphics::SCREEN_WIDTH * 0.77f, Graphics::SCREEN_HEIGHT * 0.5f);
		mNextBlockL->SetScale(Vector2(5.0f, 5.25f));

		mNextBlockI = new Texture("GameSprites.png", 30, 188, 24, 8);
		mNextBlockI->SetParent(this);
		mNextBlockI->SetPosition(Graphics::SCREEN_WIDTH * 0.77f, Graphics::SCREEN_HEIGHT * 0.51f);
		mNextBlockI->SetScale(Vector2(3.9f, 5.25f));

		mGrid->MakeGrid();
		mGrid->SetParent(this);
	}

	GameScreen::~GameScreen()
	{
		mTimer = nullptr;
		mInput = nullptr;
		mTypeManager = nullptr;

		delete mBackground;
		mBackground = nullptr;

		//Next Block
		mNextBlockSquare = nullptr;

		mGrid = nullptr;
		delete mGrid;
	}

	void GameScreen::Update()
	{
		if (!mTypeManager->GetGameType())
		{
			for (int i = 1; i < 5; ++i)
			{
				if (mGrid->pieceRow < 9 && mGrid->pieceColumn < 23 && mInput->KeyPressed(SDL_SCANCODE_RIGHT))
				{
					if (i == 4)
					{
						mGrid->pieceRow++;
						mGrid->CheckPosition();
						mAudio->PlaySFX("SFX/LeftRight.wav", 0, 1);
					}
					mPieces->MoveRight();
				}
				else if (mGrid->pieceRow > 0 && mGrid->pieceColumn < 23 && mInput->KeyPressed(SDL_SCANCODE_LEFT))
				{
					if (i == 4)
					{
						mGrid->pieceRow--;
						mGrid->CheckPosition();
						mAudio->PlaySFX("SFX/LeftRight.wav", 0, 1);
					}
					mPieces->MoveLeft();
				}
				else if (mGrid->pieceColumn < 23 && mInput->KeyDown(SDL_SCANCODE_DOWN))
				{
					if (i == 4)
					{
						mGrid->pieceColumn++;
						mGrid->CheckPosition();
						PieceDrop = 0;
						mTimer->Reset();
					}
				}
				else if (mGrid->pieceColumn > 22)
				{
					mAudio->PlaySFX("SFX/HitFloor.wav", 0, 1);
					mRandom->SetCurrentPiece();
					mRandom->SetNextPiece();
					mRandom->GetCurrentPiece();
					mScores->AddScore(100);
					mScores->AddLine(1);
					mGrid->NewPiece();
					bLockedPieces = true;
					mPieces->NewPiece();
				}

				if (PieceDrop >= 10)	//speed
				{
					mTimer->Reset();
					PieceDrop = 0;
					if (mGrid->pieceColumn < 23)
					{
							mGrid->pieceColumn++;
							mGrid->CheckPosition();
					}
					else
					{
						mAudio->PlaySFX("SFX/HitFloor.wav", 0, 1);
						mGrid->NewPiece();

						mRandom->GetCurrentPiece();

						mScores->AddLine(1);

						CurrentLocationY = 0;
						CurrentLocationX = 0;
						bLockedPieces = true;
						mPieces->NewPiece();
					}
				}
				else
				{
					PieceDrop += mTimer->DeltaTime();
					mTimer->Update();
					mScores->AddLine(1);
				}
			}
		}
		//code for cpu
	}

	void GameScreen::Render()
	{
		//render background 
		mBackground->Render();

		//render score stuff
		mScores->Render();

		//Render player's piece
		//mPieces->Render();


		for (int i = 0; i < mGrid->mColumns; i++)
		{
			for (int j = 0; j < mGrid->mRows; j++)
			{
				if (mGrid->pieceRow == j && mGrid->pieceColumn == i)
				{
					mGrid->GridPiece[mGrid->mColumns][mGrid->mRows]->Render();			//draw grid
				}
			}
		}
		//mGrid->GridPiece[5][1]->Render();		//main spawn piece

		//Next Block
		switch (mRandom->GetNextPiece())
		{
		case 0:
			mNextBlockT->Render();
			break;
		case 1:
			mNextBlockJ->Render();
			break;
		case 2:
			mNextBlockZ->Render();
			break;
		case 3:
			mNextBlockSquare->Render();
			break;
		case 4:
			mNextBlockS->Render();
			break;
		case 5:
			mNextBlockL->Render();
			break;
		case 6:
			mNextBlockI->Render();
			break;
		}
	}
}