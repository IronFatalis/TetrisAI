#ifndef __GAMESCREEN_H
#define __GAMESCREEN_H
#include "AnimatedTexture.h"
#include "AudioManager.h"
#include "MenuScreen.h"
#include "Pieces.h"
#include "Score.h"
#include "TypeManager.h"
#include "LockGrid.h"

namespace SDLFramework
{
	class GameScreen : public GameEntity
	{
	private:
		//timer and input
		Timer* mTimer;
		InputManager* mInput;
		AudioManager* mAudio;
		TypeManager* mTypeManager;
		Pieces* mPieces;
		LockGrid* mLockGrid;

		//background
		Texture* mBackground;

		Texture* grid[10][24];

		//Next Block
		Texture* mNextBlockT;
		Texture* mNextBlockJ;
		Texture* mNextBlockZ;
		Texture* mNextBlockSquare;
		Texture* mNextBlockS;
		Texture* mNextBlockL;
		Texture* mNextBlockI;

		// Screen Animation Variables
		Vector2 mAnimationStartPos;
		Vector2 mAnimationEndPos;
		float mAnimationTotalTime;
		float mAnimationTimer;
		bool mAnimationDone;
		
		//collision grid
		LockGrid* mGrid;

		Texture* mLockedPieces;
		bool bLockedPieces = false;
		bool NewPiece = true;
		float PieceDrop = 0;

		//MenuScreen* mMenuScreen;
		Random* mRandom;
		Score* mScores;

		int checkLR[4];
		int checkUD[4];
		int linesCleared;

	public:
		
		GameScreen();
		~GameScreen();

		void Update() override;
		void Render() override;

	};
}

#endif