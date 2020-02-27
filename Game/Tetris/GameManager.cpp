#include "GameManager.h"

namespace SDLFramework
{
	GameManager* GameManager::sInstance = nullptr;

	GameManager* GameManager::Instance()
	{
		if (sInstance == nullptr)
		{
			sInstance = new GameManager();
		}
		return sInstance;
	}

	void GameManager::Release()
	{
		delete sInstance;
		sInstance = nullptr;
	}

	void GameManager::Run()
	{
		while (!mQuit)
		{
			mTimer->Update();

			while (SDL_PollEvent(&mEvent))
			{
				switch (mEvent.type)
				{
				case SDL_QUIT:
					mQuit = true;
					break;
				}
			}
			if (mTimer->DeltaTime() >= 1.0f / FRAME_RATE)
			{
				Update();
				LateUpdate();
				Render();
				mTimer->Reset();
			}

			if (mInputManager->KeyPressed(SDL_SCANCODE_ESCAPE) && mInputManager->KeyPressed(SDL_SCANCODE_SPACE))
			{
				mQuit = true;
			}
		}
	}

	void GameManager::Update()
	{
		mInputManager->Update();
		mScreenManager->Update();
		mAudioManager->Update();
	}

	void GameManager::LateUpdate()
	{
		mInputManager->UpdatePrevInput();
	}

	void GameManager::Render()
	{
		mGraphics->ClearBackBuffer();
		mScreenManager->Render();
		mGraphics->Render();
	}

	GameManager::GameManager() : mQuit(false)
	{  
		mGraphics = Graphics::Instance();
		
		if (!Graphics::Initialized())
		{
			mQuit = true;
		}

		mAssetManager = AssetManager::Instance();
		mTimer = Timer::Instance();

		mParent = new GameEntity(100.0f, 400.0f);
		mChild = new GameEntity(100.0f, 500.0f);

		mInputManager = InputManager::Instance();
		mScreenManager = ScreenManager::Instance();

		//mChild->Parent(mParent);

		mInputManager = InputManager::Instance();
		mAudioManager = AudioManager::Instance();

		//mMenuScreen = new MenuScreen();
	}

	GameManager::~GameManager()
	{
		//delete mMenuScreen;
		//mMenuScreen = nullptr;

		Timer::Release();
		mTimer = nullptr;

		//AssetManager::Release();
		//mAssetManager = nullptr;

		AudioManager::Release();
		mAudioManager = nullptr;

		InputManager::Release();
		mInputManager = nullptr;

		Graphics::Release();
		mGraphics = nullptr;

		SDL_Quit();
	}
}