#ifndef MEDIA_H
#define MEDIA_H

/*
Video games must have the fields: publisher, rating.
Music must have the fields: artist, duration, publisher.
Movies must have the fields: director, duration, rating.

Common: title, year, 
 */


class Media{
public:
	char* title;
	int year;
	Media(char* title, int year);
	~Media();
	char* getTitle();
	int getYear();

};

#endif
