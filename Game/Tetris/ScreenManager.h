#ifndef __SCREENMANAGER_H
#define __SCREENMANAGER_H

#include "TitleScreen.h"
#include "MenuScreen.h"
#include "GameScreen.h"

namespace SDLFramework
{
    class ScreenManager {

    private:
        ScreenManager();
        ~ScreenManager();


        //pointer to an instance of screen manager 
        static ScreenManager* sInstance;

        //enum for the screen states, allows us to easily have reference to the types of screens available in game
        enum Screens { Title, Menu, Play, CPU };
        //variable of type screens, holds the value of the screen the player needs to see
        Screens mCurrentScreen;

        InputManager* mInput;

        //here's three more pointers for screen types
        TitleScreen* mTitleScreen;
        MenuScreen* mMenuScreen;
        GameScreen* mGameScreen;
        AudioManager* mAudio;

    public:
        //methods for screen manager class, self explanatory in my opinion
        static ScreenManager* Instance();
        static void Release();

        void Update();
        void Render();

    };
}
#endif
