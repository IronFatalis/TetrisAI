#include "TypeManager.h"
namespace SDLFramework 
{
	TypeManager* TypeManager::sInstance = nullptr;
	bool TypeManager::mGameType = false;

	TypeManager::TypeManager()
	{

	}

	TypeManager::~TypeManager()
	{
		sInstance = nullptr;
		delete sInstance;
	}

	void TypeManager::SetGameType(int type)
	{
		if (type == 0)
		{
			mGameType = 0;
		}

		else if (type == 1)
		{
			mGameType = 1;
		}
		else if (type == 2)
		{
			mGameType = 2;
		}
	}

	bool TypeManager::GetGameType()
	{
		return mGameType;
	}

	TypeManager* TypeManager::GetInstance()
	{
		if (sInstance == nullptr)
		{
			sInstance = new TypeManager();
		}
		return sInstance;
	}
}

