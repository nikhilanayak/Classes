#ifndef VIDEOGAME_H
#define VIDEOGAME_H
#include "Media.h"

class VideoGame: public Media{
public:
	char* publisher;
	int rating;
	VideoGame(char* title, int year, char* publisher, int rating);
	~VideoGame();

	char* getPublisher();
	int getRating();
	void print();
};

#endif
