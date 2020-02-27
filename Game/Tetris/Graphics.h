#ifndef __GRAPHICS_H
#define __GRAPHICS_H
#include "InputManager.h"
#include <SDL.h>
#include <iostream>
#include <SDL_image.h>
#include <SDL_ttf.h>

namespace SDLFramework
{
	class Graphics
	{
	public:
		static const short SCREEN_WIDTH = 768;
		static const short SCREEN_HEIGHT = 720;
		const char* WINDOW_TITLE = "Tetris NES by J.H, N.G and R.E";
		static Graphics* Instance();
		static void Release();
		static bool Initialized();
		SDL_Texture* LoadTexture(std::string path);
		SDL_Texture* CreateTextTexture(TTF_Font* font, std::string text, SDL_Color color);
		void DrawTexture(SDL_Texture* tex, SDL_Rect* sourceRect = nullptr, SDL_Rect* destRect = nullptr, float angle = 0.0f, SDL_RendererFlip flip = SDL_FLIP_NONE);
		void ClearBackBuffer();
		void Render();
	private:
		static Graphics* sInstance;
		static bool sInitialized;
		SDL_Window* mWindow;
		SDL_Renderer* mRenderer;
		Graphics();
		~Graphics();
		bool Init();

	};
}
#endif