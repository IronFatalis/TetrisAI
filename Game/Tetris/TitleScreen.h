#ifndef __TITLESCREEN_H
#define __TITLESCREEN_H
#include "AnimatedTexture.h"
#include "AudioManager.h"

namespace SDLFramework
{
	class TitleScreen : public GameEntity
	{
	private:

		//timer and input
		Timer* mTimer;
		InputManager* mInput;

		//castle
		Texture* mCastle;

		//logo
		Texture* mLogo;
		AnimatedTexture* mAnimatedLogo;

		//push start
		GameEntity* mPushStart;
		Texture* mPushLogo;
		Texture* mPushAnimated;

		//background
		Texture* mBackground;

		// Screen Animation Variables
		Vector2 mAnimationStartPos;
		Vector2 mAnimationEndPos;
		float mAnimationTotalTime;
		float mAnimationTimer;
		bool mAnimationDone;
		float mPushTimer;

		int mSelectedMode;

	public:
		TitleScreen();
		~TitleScreen();

		void ChangeSelectedMode(int change);
		void ResetAnimation();

		void Update() override;
		void Render() override;
	};
}

#endif