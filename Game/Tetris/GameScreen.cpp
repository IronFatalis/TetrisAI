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
		mCurrentState=ST_CHECKPIECE::Instance(currentPiece);

		currentPiece = mRandom->GetCurrentPiece();

		//sanity test for scores
		mScores->AddHeight("10");
		mScores->AddtoHiScore("2345");

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
			if (mInput->KeyPressed(SDL_SCANCODE_SPACE))
			{
				Rotate();
			}
			CheckPos();
			MovePiece();
		}
		else
		{
			//code for cpu
			switch (mGrid->currentState)
			{
			case 0:
				mCurrentState->Enter(currentPiece);
				mGrid->currentState++;
				break;
			case 1:
				mCurrentState = ST_MOVEPIECE::Instance(currentPiece);
				mCurrentState->Enter(currentPiece);
				mGrid->currentState++;
				break;
			case 2:
				mCurrentState = ST_ROTATE::Instance(currentPiece);
				mCurrentState->Enter(currentPiece);
				mGrid->currentState++;
				break;
			case 3:
				mCurrentState = ST_DROP::Instance(currentPiece);
				mCurrentState->Enter(currentPiece);
				mGrid->currentState = 0;
				break;
			}
		}

		DropTimer();
		ClearLine();
	}

	void GameScreen::Rotate()
	{
		for (int p = 0; p < 4; p++)
		{
			mGrid->newPos[p].x = (-1 * mGrid->oldPos[p].y);
			mGrid->newPos[p].y = (1 * mGrid->oldPos[p].x);
			checkLR[p] = (mGrid->pieceRow + mGrid->newPos[p].x);
			checkUD[p] = (mGrid->pieceColumn + mGrid->newPos[p].y);
		}
		if ((mGrid->pieceRow + mGrid->newPos[0].x) < 9 && (mGrid->pieceRow + mGrid->newPos[0].x) > 0 && (mGrid->pieceRow + mGrid->newPos[1].x) < 9 && (mGrid->pieceRow + mGrid->newPos[1].x) > 0 && (mGrid->pieceRow + mGrid->newPos[2].x) < 9 && (mGrid->pieceRow + mGrid->newPos[2].x) > 0 && (mGrid->pieceRow + mGrid->newPos[3].x) < 9 && (mGrid->pieceRow + mGrid->newPos[3].x) > 0 && mGrid->pieceColumn < 23 && !mGrid->LockedPiece[checkUD[0]][checkLR[0]] && !mGrid->LockedPiece[checkUD[1]][checkLR[1]] && !mGrid->LockedPiece[checkUD[2]][checkLR[2]] && !mGrid->LockedPiece[checkUD[3]][checkLR[3]])
		{
			for (int p = 0; p < 4; p++)
			{
				mGrid->oldPos[p] = mGrid->newPos[p];
			}
		}
		else
		{
			for (int p = 0; p < 4; p++)
			{
				mGrid->newPos[p].x = mGrid->oldPos[p].x;
				mGrid->newPos[p].y = mGrid->oldPos[p].y;
			}
		}
		mGrid->CheckPosition();
	}

	void GameScreen::CheckPos()
	{
		for (int p = 0; p < 4; p++)
		{
			checkLR[p] = (mGrid->pieceRow + mGrid->oldPos[p].x);
			checkUD[p] = (mGrid->pieceColumn + mGrid->oldPos[p].y);
		}
	}

	void GameScreen::MovePiece()
	{
		for (int i = 0; i < 4; ++i)
		{
			if ((mGrid->pieceRow + mGrid->oldPos[0].x) < 9 && (mGrid->pieceRow + mGrid->oldPos[1].x) < 9 && (mGrid->pieceRow + mGrid->oldPos[2].x) < 9 && (mGrid->pieceRow + mGrid->oldPos[3].x) < 9 && !mGrid->LockedPiece[checkUD[0]][checkLR[0] + 1] && !mGrid->LockedPiece[checkUD[1]][checkLR[1] + 1] && !mGrid->LockedPiece[checkUD[2]][checkLR[2] + 1] && !mGrid->LockedPiece[checkUD[3]][checkLR[3] + 1] && mInput->KeyPressed(SDL_SCANCODE_RIGHT))
			{
				if (i == 3)
				{
					mGrid->pieceRow++;
					mGrid->CheckPosition();
					mAudio->PlaySFX("SFX/LeftRight.wav", 0, 1);
				}
				mPieces->MoveRight();
			}
			else if ((mGrid->pieceRow + mGrid->oldPos[0].x) > 0 && (mGrid->pieceRow + mGrid->oldPos[1].x) > 0 && (mGrid->pieceRow + mGrid->oldPos[2].x) > 0 && (mGrid->pieceRow + mGrid->oldPos[3].x) > 0 && !mGrid->LockedPiece[checkUD[0]][checkLR[0] - 1] && !mGrid->LockedPiece[checkUD[1]][checkLR[1] - 1] && !mGrid->LockedPiece[checkUD[2]][checkLR[2] - 1] && !mGrid->LockedPiece[checkUD[3]][checkLR[3] - 1] && mInput->KeyPressed(SDL_SCANCODE_LEFT))
			{
				if (i == 3)
				{
					mGrid->pieceRow--;
					mGrid->CheckPosition();
					mAudio->PlaySFX("SFX/LeftRight.wav", 0, 1);
				}
				mPieces->MoveLeft();
			}
			else if ((mGrid->pieceColumn + mGrid->oldPos[0].y) < 23 && (mGrid->pieceColumn + mGrid->oldPos[1].y) < 23 && (mGrid->pieceColumn + mGrid->oldPos[2].y) < 23 && (mGrid->pieceColumn + mGrid->oldPos[3].y) < 23 && !mGrid->LockedPiece[checkUD[0] + 1][checkLR[0]] && !mGrid->LockedPiece[checkUD[1] + 1][checkLR[1]] && !mGrid->LockedPiece[checkUD[2] + 1][checkLR[2]] && !mGrid->LockedPiece[checkUD[3] + 1][checkLR[3]] && mInput->KeyDown(SDL_SCANCODE_DOWN))
			{
				if (i == 3)
				{
					mGrid->pieceColumn++;
					mGrid->CheckPosition();
					PieceDrop = 0;
					mTimer->Reset();
				}
			}
		}
	}

	void GameScreen::DropTimer()
	{
		if (PieceDrop >= mScores->Speed / 4)	//speed
		{
			mTimer->Reset();
			PieceDrop = 0;
			if ((mGrid->pieceColumn + mGrid->oldPos[0].y) < 23 && (mGrid->pieceColumn + mGrid->oldPos[1].y) < 23 && (mGrid->pieceColumn + mGrid->oldPos[2].y) < 23 && (mGrid->pieceColumn + mGrid->oldPos[3].y) < 23 && !mGrid->LockedPiece[checkUD[0] + 1][checkLR[0]] && !mGrid->LockedPiece[checkUD[1] + 1][checkLR[1]] && !mGrid->LockedPiece[checkUD[2] + 1][checkLR[2]] && !mGrid->LockedPiece[checkUD[3] + 1][checkLR[3]])
			{
				mGrid->pieceColumn++;
				mGrid->CheckPosition();
			}
			else
			{
				mAudio->PlaySFX("SFX/HitFloor.wav", 0, 1);
				mGrid->LockedGrid();
				mRandom->SetCurrentPiece();
				mRandom->SetNextPiece();
				mRandom->GetCurrentPiece();
				mGrid->NewPiece();
				linesCleared = 0;
				mScores->UpdateStats();
			}
		}
		else
		{
			PieceDrop += mTimer->DeltaTime();
			mTimer->Update();
		}
	}

	void GameScreen::ClearLine()
	{
		for (int l = 23; l >= 0; l--)
		{
			if (mGrid->LockedPiece[l][0] && mGrid->LockedPiece[l][1] && mGrid->LockedPiece[l][2] && mGrid->LockedPiece[l][3] && mGrid->LockedPiece[l][4] && mGrid->LockedPiece[l][5] && mGrid->LockedPiece[l][6] && mGrid->LockedPiece[l][7] && mGrid->LockedPiece[l][8] && mGrid->LockedPiece[l][9])
			{
				for (int n = 0; n < 10; n++)
				{
					mGrid->LockedPiece[l][n] = false;
					for (int d = l; d > 0; d--)
					{
						mGrid->LockedPiece[d][n] = mGrid->LockedPiece[d - 1][n];
					}
				}
				linesCleared++;
				mScores->AddLine(1);
				mScores->AddScore(1000 * linesCleared);
				mScores->LineCounter += linesCleared;
				totalLinesCleared++;
				mScores->LineNum = totalLinesCleared;
				mScores->AddLine(totalLinesCleared);
			}
		}
	}

	void GameScreen::Render()
	{
		//render background 
		mBackground->Render();

		//render score stuff
		mScores->Render();

		//Render player's piece
		//mPieces->Render();


		
		for (int z = 0; z < 4; z++)
		{
			mGrid->GridPiece[z][mGrid->mColumns][mGrid->mRows]->Render();			//draw current piece
		}

		for (int i = 0; i < mGrid->mColumns; i++)
		{
			for (int j = 0; j < mGrid->mRows; j++)
			{
				if (mGrid->LockedPiece[i][j] == true && mGrid->DrawLockedPiece[i][j] != nullptr)
				{
					mGrid->DrawLockedPiece[i][j]->Render();
				}
			}
		}

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