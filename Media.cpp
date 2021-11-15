#include "Media.h"
#include <string.h>


Media::Media(char* title, int year){
	this->title = new char[strlen(title)];
	memcpy(this->title, title, strlen(title));
	this->year = year;
}

Media::~Media(){
	delete title;	
}
