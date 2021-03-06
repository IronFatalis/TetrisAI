#ifndef __TIMER_H
#define __TIMER_H
#include <SDL.h>

namespace SDLFramework
{
	class Timer
	{
	private:
		Timer();
		~Timer();
		static Timer* sInstance;
		unsigned int mStartTicks;
		unsigned int mElapsedTicks;
		float mDeltaTime;
		float mTimeScale;
	public:
		static Timer* Instance();
		static void Release();
		void Reset();
		float DeltaTime();
		void TimeScale(float ts);
		float TimeScale();
		void Update();

	};
}
#endif