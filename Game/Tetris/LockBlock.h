#ifndef __LOCKBLOCK_H
#define __LOCKBLOCK_H
#include "Block.h"

namespace SDLFramework
{
	class LockBlock
	{
	private:


	public:
		LockBlock();
		~LockBlock();

		int GetLockLocation();
		void SetLockLocation();
	};
}
#endif