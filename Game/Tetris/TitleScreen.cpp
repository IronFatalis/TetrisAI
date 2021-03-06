#include "TitleScreen.h"

namespace SDLFramework
{
	TitleScreen::TitleScreen()
	{
		//timer and input
		mTimer = Timer::Instance();
		mInput = InputManager::Instance();

		//castle
		mCastle = new Texture("TitleSheet.png", 0, 0, 360, 210);
		mCastle->SetParent(this);

		// logo entities
		mLogo = new Texture("TitleSheet.png", 255, 0, 207, 65);
		mLogo->SetParent(this);
		mLogo->SetScale(Vector2(2, 2));

		mAnimatedLogo = new AnimatedTexture("TitleSheet.png", 255, 0, 207, 65, 4, 0.9f, AnimatedTexture::Horizontal);
		mAnimatedLogo->SetParent(this);

		mLogo->SetPosition(Graphics::SCREEN_WIDTH * 0.39f, Graphics::SCREEN_HEIGHT * 0.32f);
		mAnimatedLogo->SetPosition(Graphics::SCREEN_WIDTH * 0.39f, Graphics::SCREEN_HEIGHT * 0.32f);
		mAnimatedLogo->SetScale(Vector2(2, 2));

		//push start
		mPushStart = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.55f);
		mPushLogo = new Texture("PUSH START","emulogic.ttf", 32, { 230, 230, 230 });
		mPushAnimated = new Texture("TitleSheet.png", 300, 100, 320, 65);
		mPushStart->SetParent(this);
		mPushLogo->SetPosition(Graphics::SCREEN_WIDTH * 0.36f, Graphics::SCREEN_HEIGHT * 0.7f);
		mPushAnimated->SetPosition(Graphics::SCREEN_WIDTH * 0.36f, Graphics::SCREEN_HEIGHT * 0.7f);
		mPushLogo->SetParent(mPushStart);
		mPushAnimated->SetParent(mPushStart);

		//background 
		mBackground = new Texture("TitleSheet.png", 0, 0, 255, 240);
		mBackground->SetParent(this);
		mBackground->SetPosition(Graphics::SCREEN_WIDTH * 0.174f, Graphics::SCREEN_HEIGHT * 0.174f);
		mBackground->SetScale(Vector2(2.9648f, 2.9648f));

		// screen animation variables
		mAnimationStartPos = Vector2(0.0f, Graphics::SCREEN_HEIGHT);
		mAnimationEndPos = Vec2_Zero;
		mAnimationTotalTime = 5.0f;
		mAnimationTimer = 0.0f;
		mAnimationDone = false;

		ResetAnimation();
	}

	TitleScreen::~TitleScreen()
	{
		mTimer = nullptr;
		mInput = nullptr;

		delete mCastle;
		mCastle = nullptr;

		delete mLogo;
		mLogo = nullptr;

		delete mAnimatedLogo;
		mAnimatedLogo = nullptr;

		delete mPushStart;
		mPushStart = nullptr;

		delete mPushLogo;
		mPushLogo = nullptr;

		delete mBackground;
		mBackground = nullptr;

	}

	void TitleScreen::ResetAnimation()
	{
		mAnimationStartPos = Vector2(0.0f, Graphics::SCREEN_HEIGHT);
		mAnimationEndPos = Vec2_Zero;
		mAnimationTotalTime = 5.0f;
		mAnimationTimer = 0.0f;
		mAnimationDone = false;

		SetPosition(mAnimationStartPos);
	}

	void TitleScreen::ChangeSelectedMode(int change)
	{

		mSelectedMode += change;

		if (mSelectedMode < 0) 
		{
			mSelectedMode = 1;
		}

		else if (mSelectedMode > 1)
		{
			mSelectedMode = 0;
		}

	}

	void TitleScreen::Update()
	{
		if (!mAnimationDone) {
			mAnimationTimer += mTimer->DeltaTime();
			SetPosition(Lerp(mAnimationStartPos, mAnimationEndPos, mAnimationTimer / mAnimationTotalTime));

			if (mAnimationTimer >= mAnimationTotalTime) {
				mAnimationDone = true;
			}

			if (mInput->KeyPressed(SDL_SCANCODE_SPACE)) {
				mAnimationTimer = mAnimationTotalTime;
			}
		}
		else {
			mAnimatedLogo->Update();
			if (mInput->KeyPressed(SDL_SCANCODE_RETURN))
			{
				ChangeSelectedMode(1);
			}

		}

	}

	void TitleScreen::Render()
	{
		mBackground->Render();
		mPushLogo->Render();

		if (!mAnimationDone)
		{
			mLogo->Render();
		}
		else if (mAnimationDone)
		{
			mPushTimer += 1;
			mAnimatedLogo->Render();
			if (mPushTimer >= 20 && mPushTimer <= 40)
			{
				mPushAnimated->Render();
				if (mPushTimer >= 40)
				{
					mPushTimer = 0;
				}
			}
		}
	}
}
