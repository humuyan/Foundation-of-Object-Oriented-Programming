#pragma once
#include <bits/stdc++.h>
#include "audio.h"
#include "video.h"

class Adapter {
	public:
		virtual void play() = 0;
		virtual void pause() = 0;
		virtual void doubleSpeed() = 0;
};

class AudioAdapter: public Adapter {
	private:
		Audio *aud;
	public:
		AudioAdapter(Audio *aud) : aud(aud) {}
		virtual void play() {
			aud->play();
		}
		virtual void pause() {
			aud->pause();
		}
		virtual void doubleSpeed() {
			std::cout << "audio cannot be double speed" << std::endl;
		}
};

class VideoAdapter: public Adapter{
	private:
		Video *vid;
	public:
		VideoAdapter(Video *vid) : vid(vid) {}
		virtual void play() {
			vid->playVideo();
		}
		virtual void pause() {
			vid->pauseVideo();
		}
		virtual void doubleSpeed() {
			vid->doubleSpeed();
		}
};