#pragma once
#ifndef FPS_HPP
#define FPS_HPP
#include <SFML/System/Clock.hpp>

namespace CRUCIBLE
{
	class FPS
	{
	public:
		FPS() : mFrame(0), mFps(0) {}

		void update();

		const unsigned int getFPS() const { return mFps; }

	private:
		unsigned int mFrame;
		unsigned int mFps;
		sf::Clock mClock;
	};

	void FPS::update()
	{
		if (mClock.getElapsedTime().asSeconds() >= 1.f)
		{
			mFps = mFrame;
			mFrame = 0;
			mClock.restart();
		}

		++mFrame;
	}

#endif
}