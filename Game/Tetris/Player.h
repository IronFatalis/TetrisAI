#ifndef __PLAYER_H
#define __PLAYER_H
#include "AnimatedTexture.h"
#include "AudioManager.h"
#include "InputManager.h"

using namespace SDLFramework;

class Player : public GameEntity
{
private:

	InputManager* mInput;
	AudioManager* mAudio;

	Texture* mPiece;

public:
	Player();
	~Player();

	void MovePiece();
	Texture GetNextPiece();
	
};
#endif