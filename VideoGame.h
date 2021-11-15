#ifndef VIDEOGAME_H
#define VIDEOGAME_H
#include "Media.h"

class VideoGame: public Media{
public:
	char* publisher;
	float rating;
	VideoGame(char* title, int year, char* publisher, float rating);
	~VideoGame();
};

#endif
