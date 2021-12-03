#include "Media.h"
#include <string.h>
#include <iostream>


Media::Media(char* title, int year){
	this->title = new char[strlen(title)];
	memcpy(this->title, title, strlen(title));
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

