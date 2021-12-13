#include "VideoGame.h"
#include <cstring>
#include <iostream>

VideoGame::VideoGame(char* title, int year, char* publisher, int rating): Media(title, year){
	this->publisher = new char[strlen(publisher)];
	strcpy(this->publisher, publisher);

	this->rating = rating;
	this->type = 1;

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

void VideoGame::print(){
	std::cout << "Video Game: ";
	std::cout << " Rating=" << this->getRating();
	std::cout << ", Title=" << this->getTitle();
	std::cout << ", Year=" << this->getYear();
	std::cout << ", Publisher=" << this->getPublisher();

}
