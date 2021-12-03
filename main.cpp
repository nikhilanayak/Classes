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
	std::vector<Media*> database;
	//Movie test_movie = Movie("title", 2020, "me", 10, 10);
	//Movie another = Movie("title2", 1020, "you", 10, 10);
	//database.push_back(&test_movie);
	//database.push_back(&another);


	//Media* m = database[0];
	//std::cout << m << "\n";
	//Music* song = static_cast<Music*>(m);
	//song->duration = 100;
	//std::cout << song->getDuration() << "\n";
	//song->print();

	//exit(0);

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
				char* title = new char[256];
				std::cin >> title;

				std::cout << "Year: ";
				int year = get_type<int>();

				std::cout << "Artist: ";
				char* artist = new char[256];
				std::cin >> artist;

				std::cout << "Duration: ";
				int duration = get_type<int>();

				std::cout << "Rating: ";
				int rating = get_type<int>();

				Music* m = new Music(title, year, artist, duration, rating);
				database.push_back(m);

			}
			else if(num == 1){ // video game
				std::cout << "Title: ";
				char* title = new char[256];
				std::cin >> title;

				std::cout << "Year: ";
				int year = get_type<int>();

				std::cout << "Publisher: ";
				char* publisher = new char[256];
				std::cin >> publisher;

				std::cout << "Rating: ";
				int rating = get_type<int>();
				
				VideoGame* v = new VideoGame(title, year, publisher, rating);
				database.push_back(v);
			}
			else if(num == 2){// movie
				// Movie(char* title, int year, char* director, int duration, int rating);
				std::cout << "Title: ";
				char* title = new char[256];
				std::cin >> title;

				std::cout << "Year: ";
				int year = get_type<int>();
				
				std::cout << "Director: ";
				char* director = new char[256];
				std::cin >> director;

				std::cout << "Duration: ";
				int duration = get_type<int>();

				std::cout << "Rating: ";
				int rating = get_type<int>();

				Movie* m = new Movie(title, year, director, duration, rating);
				database.push_back(m);
			}
		}
		else if(strcmp(input, "DELETE") == 0){

		}
		else if(strcmp(input, "PRINT") == 0){
			for(int i = 0; i < database.size(); i++){
				Media* m = database[i];
				std::cout << m << "\n";
				Music* song = static_cast<Music*>(m);
				VideoGame* game = static_cast<VideoGame*>(m);
				Movie* movie = static_cast<Movie*>(m);

				if(m->type == 0) song->print();
				if(m->type == 1) game->print();
				if(m->type == 2) movie->print();
				//song->print();
				std::cout << "\n";
				//std::cout << i << "\n";
			}
		}
		else if(strcmp(input, "STOP") == 0){
		    return 0;
		}

    }

}
