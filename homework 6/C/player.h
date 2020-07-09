#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include "adapter.h"

class Player{
	std::vector<Adapter*> playlist;
public:
	void add(Audio* aud){
		Adapter *audpt = new AudioAdapter(aud);
		playlist.push_back(audpt);
	}
	void add(Video* vid){
		Adapter *vidpt = new VideoAdapter(vid);
		playlist.push_back(vidpt);
	}
	void play(){
		if (playlist.empty())
			std::cout << "Nothing to play" << std::endl;
		for (Adapter* file: playlist)
			file->play();
	}
	void pause(){
		if (playlist.empty())
			std::cout << "Nothing to pause" << std::endl;
		for (Adapter* file: playlist)
			file->pause();
	}
	void doubleSpeed(){
		if (playlist.empty())
			std::cout << "Nothing to double speed" << std::endl;
		for (Adapter* file: playlist)
			file->doubleSpeed();
	}
};

#endif