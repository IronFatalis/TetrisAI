#ifndef __ASSETMANAGER_H
#define __ASSETMANAGER_H

#include "Graphics.h"
#include <sstream>
#include <SDL_Mixer.h>
#include <map>

namespace SDLFramework
{
	class AssetManager
	{
	private:
		static void Release();

		std::map<std::string, SDL_Texture*> mText;
		std::map<std::string, SDL_Texture*> mTextures;
		std::map<std::string, Mix_Music*> mMusic;
		std::map<std::string, TTF_Font*> mFonts;
		std::map<std::string, Mix_Chunk*> mSFX;

		std::map<SDL_Texture*, unsigned> mTextureRefCount;
		std::map<Mix_Music*, unsigned> mMusicRefCount;
		std::map<Mix_Chunk*, unsigned*> mSFXRefCount;

		TTF_Font* GetFont(std::string filename, int size);

	public:
		static AssetManager* Instance();

		static AssetManager* sInstance;

		void DestroyTexture(SDL_Texture* texture);
		void DestroyMusic(Mix_Music* music);
		void DestroySFX(Mix_Chunk* sfx);

		SDL_Texture* GetText(std::string text, std::string filename, int size, SDL_Color color);
		SDL_Texture* GetTexture(std::string filename);

		Mix_Music* GetMusic(std::string filename, bool managed);
		Mix_Chunk* GetSFX(std::string filename, bool managed);
		
		AssetManager();
		~AssetManager();


	};
}

#endif