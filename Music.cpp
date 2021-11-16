#include "Music.h"
#include <string.h>

Music::Music(char* title, int year, char* artist, int duration, int rating): Media(title, year){
	this->artist = 	new char[strlen(artist)];
	memcpy(this->artist, artist, strlen(artist));
	
	this->duration = duration;
	this->rating = rating;
}

Music::~Music(){
	delete this->artist;
}


char* Music::getArtist(){
	return this->artist;
}

int Music::getDuration(){
	return this->duration;
}

int Music::getRating(){
	return this->rating;
}
