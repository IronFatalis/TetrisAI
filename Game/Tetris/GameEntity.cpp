#include "GameEntity.h"

namespace SDLFramework
{
    GameEntity::GameEntity(float x, float y) : mPosition(x, y), mRotation(0.0f), mScale(Vec2_One), mActive(true), mParent(nullptr)
    {
    }

    //The destructor doesn't have anything major to do. We will, however, set the **mPa rent** pointer to `null` just for good measure.
    GameEntity::~GameEntity()
    {
        mParent = nullptr;
    }

    void GameEntity::SetPosition(float x, float y)
    {
        mPosition = Vector2(x, y);
    }

    void GameEntity::SetPosition(const Vector2& pos)
    {
        mPosition = pos;
    }

    Vector2 GameEntity::GetPosition(Space space)
    {
        if (space == Local || mParent == nullptr)
        {
            return mPosition;
        }
        Vector2 parentScale = mParent->GetScale(World);
        Vector2 rotPosition = RotateVector(mPosition, mParent->GetRotation(Local));
        return mParent->GetPosition(World) + Vector2(rotPosition.x * parentScale.x, rotPosition.y * parentScale.y);
    }

    void GameEntity::SetRotation(float rot)
    {
        mRotation = rot;
        while (mRotation > 360.0f) { mRotation -= 360.0f; }
        while (mRotation < 0.0f) { mRotation += 360.0f; }
    }

    float GameEntity::GetRotation(Space space)
    {
        if (space == Local || mParent == nullptr) 
        {
            return mRotation;
        }
        return mParent->GetRotation(World) + mRotation;
    }

    void GameEntity::SetScale(Vector2 scale)
    {
        mScale = scale;
    }

    Vector2 GameEntity::GetScale(Space space)
    {
        if (space == Local || mParent == nullptr) { return mScale; }
        Vector2 scale = mParent->GetScale(World);
        scale.x *= mScale.x;
        scale.y *= mScale.y;
        return scale;
    }

    void GameEntity::SetActive(bool active)
    {
        mActive = active;
    }

    bool GameEntity::GetActive() 
    { 
        return mActive;
    }

    void GameEntity::SetParent(GameEntity* parent)
    {
        if (parent == nullptr)
        {
            mPosition = GetPosition(World);
            mRotation = GetRotation(World);
            mScale = GetScale(World);
        }
        else
        {
            if (mParent != nullptr)
            {
                SetParent(nullptr);
            }
            Vector2 parentScale = parent->GetScale(World);
            mPosition = RotateVector(GetPosition(World) - parent->GetPosition(World), -parent->GetRotation(World));
            mPosition.x /= parentScale.x;
            mPosition.y /= parentScale.y;
            mRotation -= parent->GetRotation(World);
            mScale = Vector2(mScale.x / parentScale.x, mScale.y / parentScale.y);
        }
        mParent = parent;
    }

    GameEntity* GameEntity::GetParent()
    {
        return mParent;
    }

    void GameEntity::Translate(Vector2 vec, Space space)
    {
        if (space == World)
        {
            mPosition += vec;
        }
        else
        {
            mPosition += RotateVector(vec, GetRotation());
        }
    }

    void GameEntity::Rotate(float amount)
    {
        mRotation += amount;
    }

}