#include "ScreenManager.h"

namespace SDLFramework
{
    ScreenManager* ScreenManager::sInstance = nullptr;

    ScreenManager* ScreenManager::Instance()
    {
        if (sInstance == nullptr)
        {
            sInstance = new ScreenManager();
        }

        return sInstance;
    }

    void ScreenManager::Release()
    {
        delete sInstance;
        sInstance = nullptr;
    }

    ScreenManager::ScreenManager()
    {
        mInput = InputManager::Instance();
        mTitleScreen = new TitleScreen;
        mMenuScreen = new MenuScreen;
        mGameScreen = new GameScreen;
        mAudio = AudioManager::Instance();
        mCurrentScreen = Title;
    }

    ScreenManager::~ScreenManager()
    {
        mInput = nullptr;
        delete mTitleScreen;
        mTitleScreen = nullptr;

        delete mMenuScreen;
        mMenuScreen = nullptr;

        delete mGameScreen;
        mGameScreen = nullptr;
    }

    void ScreenManager::Update()
    {
        switch (mCurrentScreen)
        {
        case Title:
            mTitleScreen->Update();

            if (mInput->KeyPressed(SDL_SCANCODE_RETURN))
            {
                //switch to menu screen
                mAudio->Playing = false;
                mAudio->CurrentMusic = 1;
                mCurrentScreen = Menu;
            }

            break;

        case Menu:
            mMenuScreen->Update();
            if (mInput->KeyPressed(SDL_SCANCODE_RETURN))
            {
                if (!mMenuScreen->CPUPlayer)
                {
                    mCurrentScreen = Play;
                    //switch to play screen
                }
                else
                {
                    mCurrentScreen = CPU;
                    //switch to computer player
                }
            }
            break;

        case Play:
            mGameScreen->Update();
            if (mInput->KeyPressed(SDL_SCANCODE_ESCAPE))
            {
                mCurrentScreen = Menu;
                //quit to menu
            }
            break;

        case CPU:
            mGameScreen->Update();
            if (mInput->KeyPressed(SDL_SCANCODE_ESCAPE))
            {
                mCurrentScreen = Title;
                //quit to menu
            }
            break;
        }

    }

    void ScreenManager::Render()
    {
        switch (mCurrentScreen)
        {
        case Title:
            mTitleScreen->Render();
            break;
        case Menu:
            mMenuScreen->Render();
            break;
        case Play:
            mGameScreen->Render();
            break;
        case CPU:
            mGameScreen->Render();
            break;
        }
    }
}