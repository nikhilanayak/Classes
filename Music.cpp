#include "Music.h"
#include <string.h>
#include <iostream>

Music::Music(char* title, int year, char* artist, int duration, int rating): Media(title, year){
	this->artist = 	new char[strlen(artist)];
	memcpy(this->artist, artist, strlen(artist));

	std::cout << "init duration:" << duration << "\n";
	this->duration = duration;

	this->rating = rating;
	this->type = 0;
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

void Music::print(){
	std::cout << "Music: ";
	std::cout << " Duration=" << this->getDuration();
	std::cout << ", Rating=" << this->getRating();
	std::cout << ", Title=" << this->getTitle();
	std::cout << ", Year=" << this->getYear();
	std::cout << ", Artist=" << this->getArtist();
}
