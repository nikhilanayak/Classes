#include <vector>
#include <iostream>

#include "Music.h"
#include "VideoGame.h"
#include "Movie.h"

template<typename T>
T get_type(){ // gets input of a type, ignoring all other types
        T input;
        while(!(std::cin >> input)){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear the whole buffer
                std::cout << "Invalid input, please try again: ";
        }
        return input;
}

int main(){
	std::vector<Media> database;

	
	char input[10];
	while(true){
        	std::cout << "Enter A Command (ADD, DELETE, PRINT, STOP): ";
        	std::cin >> input;

		// parse input
		if(strcmp(input, "ADD") == 0){
			std::cout << "Would you like to add a song(0), video game(1), or movie(2): ";
			int num = get_type<int>();
			std::cout << num << "\n";
			while(num > 2 || num < 0){
				std::cout << "Would you like to add a song(0), video game(1), or movie(2): ";
				num = get_type<int>();	
			}
			if(num == 0){ // song
				std::cout << "Title: ";
				char title[256];
				std::cin >> title;

				std::cout << "Year: ";
				int year = get_type<int>();

				std::cout << "Artist: ";
				char artist[256];
				std::cin >> artist;

				std::cout << "Duration: ";
				int duration = get_type<int>();

				std::cout << "Rating: ";
				int rating = get_type<int>();

				Music m = Music(title, year, artist, duration, rating);
				database.push_back(m);

			}
			else if(num == 1){ // video game
				std::cout << "Title: ";
				char title[256];
				std::cin >> title;

				std::cout << "Year: ";
				int year = get_type<int>();

				std::cout << "Publisher: ";
				char publisher[256];
				std::cin >> publisher;

				std::cout << "Rating: ";
				int rating = get_type<int>();
				
				VideoGame v = VideoGame(title, year, publisher, rating);
				database.push_back(v);
			}
			else if(num == 2){// movie
				// Movie(char* title, int year, char* director, int duration, int rating);
				std::cout << "Title: ";
				char title[256];
				std::cin >> title;

				std::cout << "Year: ";
				int year = get_type<int>();
				
				std::cout << "Director: ";
				char director[256];
				std::cin >> director;

				std::cout << "Duration: ";
				int duration = get_type<int>();

				std::cout << "Rating: ";
				int rating = get_type<int>();

				Movie m = Movie(title, year, director, duration, rating);
				database.push_back(m);
			}
		}
		else if(strcmp(input, "DELETE") == 0){

		}
		else if(strcmp(input, "PRINT") == 0){
			for(int i = 0; i < database.size(); i++){
				Media* m = &database[i];
				m->print();
				//std::cout << i << "\n";
			}
		}
		else if(strcmp(input, "STOP") == 0){
		    return 0;
		}

    }

}
