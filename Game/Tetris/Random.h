#ifndef __RANDOM_H
#define __RANDOM_H
#include <cstdlib>
#include <ctime>
#include <iostream>

namespace SDLFramework {

	class Random {
	private:

		Random();
		~Random();

		static int mRandomPieceCurrent;
		static int mRandomPieceNext;

		static Random* sInstance;
		
	public:
		static Random* Instance();
		static void Release();

		int GetNextPiece();
		void SetNextPiece();
		int GetCurrentPiece();

		void SetCurrentPiece();

	};
}
#endif

