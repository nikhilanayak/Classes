#include "VideoGame.h"
#include <string.h>

VideoGame::VideoGame(char* title, int year, char* publisher, int rating): Media(title, year){
	this->publisher = new char[strlen(publisher)];
	memcpy(this->publisher, publisher, strlen(publisher));

	this->rating = rating;

}

VideoGame::~VideoGame(){
	delete this->publisher;
}

char* VideoGame::getPublisher(){
	return this->publisher;
}

int VideoGame::getRating(){
	return this->rating;
}
