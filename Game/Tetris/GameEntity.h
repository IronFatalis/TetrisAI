#ifndef __GAMEENTITY_H
#define __GAMEENTITY_H
#include "MathHelper.h"
namespace SDLFramework
{
    class GameEntity
    {
    private:
        Vector2 mScale;
        bool mActive;
        GameEntity* mParent;

    public:
        enum Space { Local = 0, World = 1 };
        GameEntity(float x = 0.0f, float y = 0.0f);
        ~GameEntity();

        float mRotation;
        Vector2 mPosition;

        void SetPosition(float x, float y);
        void SetPosition(const Vector2& pos);
        Vector2 GetPosition(Space space = World);

        void SetRotation(float rot);
        float GetRotation(Space space = World);

        void SetScale(Vector2 scale);
        Vector2 GetScale(Space space = World);

        void SetActive(bool active);
        bool GetActive();

        void SetParent(GameEntity* parent);
        GameEntity* GetParent();

        void Translate(Vector2 vec, Space space = Local);
        void Rotate(float amount);

        virtual void Update() {};
        virtual void Render() {};

    };
}
#endif