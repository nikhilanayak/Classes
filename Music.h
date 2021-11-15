#ifndef MUSIC_H
#define MUSIC_H
#include "Media.h"

class Music: Media{
public:
	char* artist;
	int duration;
	int rating;
	Music(char* title, int year, char* artist, int duration, int rating);
	~Music();
};

#endif
