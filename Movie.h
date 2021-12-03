#ifndef MOVIE_H
#define MOVIE_H
#include "Media.h"

class Movie: public Media{
	char* director;
	int duration;
	int rating;
public:
	Movie(char* title, int year, char* director, int duration, int rating);
	~Movie();

	char* getDirector();
	int getDuration();
	int getRating();
	virtual void print();
};

#endif
