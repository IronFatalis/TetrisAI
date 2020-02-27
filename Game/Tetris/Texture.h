#ifndef __TEXTURE_H
#define __TEXTURE_H
#include "GameEntity.h"
#include "AssetManager.h"


namespace SDLFramework {

    class Texture : public GameEntity {

    private:
        SDL_Texture* mTex;
        Graphics* mGraphics;

        bool mClipped;

    public:
        Texture(std::string filename);
        Texture(std::string text, std::string fontPath, int size, SDL_Color color);
        Texture(std::string filename, int x, int y, int w, int h);
        ~Texture();

        SDL_Rect mSourceRect;
        SDL_Rect mDestinationRect;

        int mWidth;
        int mHeight;

        Vector2 ScaledDimensions();

        void Render() override;
    };
}
#endif