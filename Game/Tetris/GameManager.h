#ifndef __GAMEMANAGER_H
#define __GAMEMANAGER_H
#include <SDL.h>

#include "ScreenManager.h"
#include "AnimatedTexture.h"
#include "TypeManager.h"

namespace SDLFramework
{
	class GameManager
	{
	public:
        static GameManager* Instance();

        static void Release();

        void Run();
        void Update();
        void LateUpdate();
        void Render();

        GameManager();
        ~GameManager();

	private:
        static GameManager* sInstance;

        const int FRAME_RATE = 60;

        bool mQuit;

        Graphics* mGraphics;
        Timer* mTimer;

        AssetManager* mAssetManager;
        InputManager* mInputManager;
        AudioManager* mAudioManager;
        ScreenManager* mScreenManager;
        TypeManager* mTypeManager;

        GameEntity* mParent;
        GameEntity* mChild;

        SDL_Event mEvent;
	};
}


#endif