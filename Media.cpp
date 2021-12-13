#include "Media.h"
#include <cstring>
#include <iostream>


Media::Media(char* title, int year){
	this->title = new char[strlen(title)];
	strcpy(this->title, title);
	this->year = year;
}

char* Media::getTitle(){
	return this->title;
}
int Media::getYear(){
	return this->year;
}

Media::~Media(){
	delete title;	
}

