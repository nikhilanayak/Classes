#include "Movie.h"
#include <string.h>
#include <iostream>

Movie::Movie(char* title, int year, char* director, int duration, int rating): Media(title, year){
	this->director = new char[strlen(director)];
	memcpy(this->director, director, strlen(director));

	this->duration = duration;
	this->rating = rating;
}

char* Movie::getDirector(){
	return this->director;
}

int Movie::getDuration(){
	return this->duration;
}

int Movie::getRating(){
	return this->rating;
}


Movie::~Movie(){
	delete this->director;
}

void Movie::print(){
	std::cout << "Movie: ";
	std::cout << "Director=" << this->getDirector();
	std::cout << ", Duration=" << this->getDuration();
	std::cout << ", Rating=" << this->getRating();
	std::cout << ", Title=" << this->getTitle();
	std::cout << ", Year=" << this->getYear();
}
