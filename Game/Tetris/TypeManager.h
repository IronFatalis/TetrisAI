#ifndef __TYPEMANAGER_H
#define __TYPEMANAGER_H

namespace SDLFramework
{
	class TypeManager
	{
	private:
		TypeManager();
		~TypeManager();

	public:
		void SetGameType(int type);
		bool GetGameType();

		static bool mGameType;
		
		static TypeManager* GetInstance();
		static TypeManager* sInstance;
	};

}
#endif