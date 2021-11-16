#ifndef MUSIC_H
#define MUSIC_H
#include "Media.h"

class Music: public Media{
public:
	char* artist;
	int duration;
	int rating;
	Music(char* title, int year, char* artist, int duration, int rating);
	~Music();


	char* getArtist();
	int getDuration();
	int getRating();
};

#endif
