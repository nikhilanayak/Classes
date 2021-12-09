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
	std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
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
        	std::cout << "Enter A Command (ADD, DELETE, PRINT, STOP, SEARCH): ";
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
				std::cin.getline(title, 256, '\n');

				std::cout << "Year: ";
				int year = get_type<int>();

				std::cout << "Artist: ";
				char* artist = new char[256];
				std::cin.getline(artist, 256, '\n');

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
				std::cin.getline(title, 256, '\n');

				std::cout << "Year: ";
				int year = get_type<int>();

				std::cout << "Publisher: ";
				char* publisher = new char[256];
				std::cin.getline(publisher, 256, '\n');

				std::cout << "Rating: ";
				int rating = get_type<int>();
				
				VideoGame* v = new VideoGame(title, year, publisher, rating);
				database.push_back(v);
			}
			else if(num == 2){// movie
				// Movie(char* title, int year, char* director, int duration, int rating);
				std::cout << "Title: ";
				char* title = new char[256];
				std::cin.getline(title, 256, '\n');

				std::cout << "Year: ";
				int year = get_type<int>();
				
				std::cout << "Director: ";
				char* director = new char[256];
				std::cin.getline(director, 256, '\n');

				std::cout << "Duration: ";
				int duration = get_type<int>();

				std::cout << "Rating: ";
				int rating = get_type<int>();

				Movie* m = new Movie(title, year, director, duration, rating);
				database.push_back(m);

			}
		}

		else if(strcmp(input, "SEARCH") == 0){
			int by = -1;
			while(by != 0 && by != 1){
				std::cout << "By title (0) or year(1)? : ";
				by = get_type<int>();
			}


			if(by == 0){ // title
				std::cout << "Title: ";
				char title[256];
				std::cin.getline(title, 256, '\n');
				for(int i = 0; i < database.size(); i++){
					Media* m = database[i];
					if(strcmp(m->getTitle(), title) == 0){
						Music* song = static_cast<Music*>(m);
						VideoGame* game = static_cast<VideoGame*>(m);
						Movie* movie = static_cast<Movie*>(m);

						if(m->type == 0) song->print();
						if(m->type == 1) game->print();
						if(m->type == 2) movie->print();
						std::cout << "\n";
					}
				}
			}
			else if(by == 1){ // year
				std::cout << "Year: ";
				int year = get_type<int>();
				for(int i = 0; i < database.size(); i++){
					Media* m = database[i];
					if(m->getYear() == year){
						Music* song = static_cast<Music*>(m);
						VideoGame* game = static_cast<VideoGame*>(m);
						Movie* movie = static_cast<Movie*>(m);

						if(m->type == 0) song->print();
						if(m->type == 1) game->print();
						if(m->type == 2) movie->print();
						std::cout  << "\n";
					}
				}
			}
		}

		else if(strcmp(input, "DELETE") == 0){
			int by = -1;
			while(by != 0 && by != 1){
				std::cout << "By title (0) or year(1)? : ";
				by = get_type<int>();
			}


			if(by == 0){ // title
				std::cout << "Title: ";
				char title[256];
				std::cin.getline(title, 256, '\n');
				for(int i = 0; i < database.size(); i++){
					Media* m = database[i];
					if(strcmp(m->getTitle(), title) == 0){
						database.erase(database.begin() + i - 1);
						break;
					}
				}
			}
			else if(by == 1){ // year
				std::cout << "Year: ";
				int year = get_type<int>();
				for(int i = 0; i < database.size(); i++){
					Media* m = database[i];
					if(m->getYear() == year){
						database.erase(database.begin() + i - 1);
						break;
					}
				}
			}
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
