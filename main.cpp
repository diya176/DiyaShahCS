#include <iostream>
#include<cstring>
#include "media.h"
#include "movies.h"
#include "videoGames.h"
#include "music.h"
#include <vector>
#include <bits/stdc++.h>

using namespace std;
/*
This program uses different classes to add, search, and delete media types. The different media types are videogames, music, and movies. When the user calls the add function they will be prompted to give the title, year, etc for the media type. This is then added to the mediaTypes list. The search function looks through the mediaTypes list to find the media type with the same title or year as what is inputted by the user. The delete function asks for a title or year and then deletes the media types with those titles or years.     

Author: Diya Shah
Date: 10/1/2024


 */



//declaration of different functions that will be used in this program

//enters the different functions for Movies, VideoGames, and Music and then asks whether the user wants to add, delete, search, or quit 
void doMovie(vector<Media*>&mediaTypes);
void doVideoGames(vector<Media*>&mediaTypes);
void doMusic(vector<Media*>&mediaTypes);

//adding the various different media types into the mediaTypes vector - need seperate functions for all of these because of the different parameters 
void addMovie(vector<Media*>& mediaTypes);
void addVideoGames(vector<Media*>&mediaTypes);
void addMusic(vector<Media*>&mediaTypes);

//one search function because we are searching the whole media database not individual media types 
void searchMediaTypes(vector<Media*>&mediaTypes);
//searching by year
void searchYear(vector<Media*>&mediaTypes);
//searching by titles
void searchTitles(vector<Media*>&mediaTypes);
//deleting media from the media database
void deleteMediaTypes(vector<Media*>&mediaTypes);
//deleting by year
void deleteYear(vector<Media*>&mediaTypes);
//deleting by title 
void deleteTitle(vector<Media*>&mediaTypes);

//main method - starts the code by asking what type of media the user wants to manipulate; based on the answer it calls a different function for movies, videogames, and music 
int main(){

  vector<Media*> mediaTypes;
  while (true){
      char typeofmedia[120];
      cout<<"What type of media would you like to manipulate: MOVIES, VIDEOGAMES, or MUSIC? Or would you like to QUIT?"<<endl;
      cin>>typeofmedia;
      //movies
      if(strcmp(typeofmedia,"MOVIES")==0){
	doMovie(mediaTypes);
      }
      //videogames
      else if(strcmp(typeofmedia,"VIDEOGAMES")==0){
	doVideoGames(mediaTypes);
      }
      //music 
      else if(strcmp(typeofmedia,"MUSIC")==0){
	doMusic(mediaTypes);
      }
      //quit - stop the program 
      else if(strcmp(typeofmedia,"QUIT")==0){
	exit(0);
      }
  }
}
//movies method 
void doMovie(vector <Media*>& mediaTypes){
  char function [120]; // creating char array that allows 120 characters
  cout<<"Do you want to ADD, DELETE, SEARCH, OR QUIT"<<endl;
  cin>>function;
  //adds movie
  if (strcmp(function,"ADD")==0){
    addMovie(mediaTypes);
  }
  //same function for all the different media types
  //searching through the database 
  else if (strcmp(function,"SEARCH")==0){
    searchMediaTypes(mediaTypes);
  }
  //same function for all the different media types
  //deletes the media with the same title or year
  else if(strcmp(function,"DELETE")==0){
    deleteMediaTypes(mediaTypes);
  }
  //quits the program
  else if (strcmp(function,"QUIT")==0){
    exit(0);
  }
}

//videoGames 
void doVideoGames(vector <Media*>& mediaTypes){
  char function [120];
  cout<<"Do you want to ADD, DELETE, SEARCH, OR QUIT"<<endl;
  cin>>function;
  //adds videogame
  if (strcmp(function,"ADD")==0){
    addVideoGames(mediaTypes);
  }
  //searches (same function)
  else if(strcmp(function,"SEARCH")==0){
    searchMediaTypes(mediaTypes);
  }
  //deletes (same function)
  else if(strcmp(function,"DELETE")==0){
    deleteMediaTypes(mediaTypes);
  }
  //quits
  else if (strcmp(function,"QUIT")==0){
    exit(0);
  }
}
//music method
void doMusic(vector <Media*>& mediaTypes){
  char function [120];
  cout<<"Do you want to ADD, DELETE, SEARCH, OR QUIT"<<endl;
  cin>>function;
  //adds a music media type
  if (strcmp(function,"ADD")==0){
    addMusic(mediaTypes);
  }
  //searches through the entire media database
  else if(strcmp(function,"SEARCH")==0){
    searchMediaTypes(mediaTypes);
  }
  //deletes from the media database
  else if(strcmp(function,"DELETE")==0){
    deleteMediaTypes(mediaTypes);
  }
  //quits the program
  else if (strcmp(function,"QUIT")==0){
    exit(0);
  }
}


//adds a new video game by asking for all the required parameters 
void addVideoGames(vector<Media*>&mediaTypes){
  Media* videoGamesMedia=new Media();
  char*title=new char[120];
  char*publisher=new char[120];
  int year;
  int rating;
  cout<<"Please enter the title of this video game: "<<endl;
  cin.ignore();
  cin.getline(title, 120,'\n');
  cout<<"Please enter the publisher of this video game: "<<endl;
  cin.getline(publisher,120,'\n');
  cout<<"Please enter the year this video game was produced: "<<endl;
  cin>>year;
  cout<<"Please enter the rating of this video game: "<<endl;
  cin>>rating;
  // order: title, publisher, year, rating
  videoGames* newVideoGame=new videoGames(title,publisher,year,rating);
  mediaTypes.push_back(newVideoGame);
  
}


//adds a new movie by asking for all the required parameters 
void addMovie(vector<Media*>& mediaTypes){
  Media* movieMedia=new Media();
  char* title= new char[120];
  char* director=new char [120];
  int year;
  int duration;
  int rating;
  cout<<"Please enter the title of this movie: "<<endl;
  cin.ignore();
  cin.getline(title, 120,'\n');
  cout<<"Please enter the director of this movie: "<<endl;
  cin.getline(director,120,'\n');
  cout<<"Please enter the year this movie was produced: "<<endl;
  cin>>year;
  cout<<"Please enter the duration of this movie: "<<endl;
  cin>>duration;
  cout<<"Please enter the rating of this movie: "<<endl;
  cin>>rating;
  //order: title, director, year, duration, rating
  movies* newMovie=new movies(title,director,year,duration,rating);
  mediaTypes.push_back(newMovie);
  
}


//adds a new song by asking for all the required parameters 
void addMusic(vector<Media*>& mediaTypes){
  cout<<"here"<<endl;
  Media* musicMedia=new Media();
  char* title= new char[120];
  char* artist=new char [120];
  char* publisher=new char[120];
  int year;
  int duration;
  cout<<"Please enter the title of this song : "<<endl;
  cin.ignore();
  cin.getline(title, 120,'\n');
  cout<<"Please enter the artist of this song : "<<endl;
  cin.getline(artist,120,'\n');
  cout<<"Please enter the publisher of this song: "<<endl;
  cin.getline(publisher,120,'\n');
  cout<<"Please enter the year this song was produced: "<<endl;
  cin>>year;
  cout<<"Please enter the duration of this song: "<<endl;
  cin>>duration;
  //orde: title, artist, publisher, year, duration 
  Music* newMusic=new Music(title,artist,publisher,year,duration);
  mediaTypes.push_back(newMusic);

}

//searches media - starts by asking whether user wants to search using title or year
void searchMediaTypes(vector<Media*>& mediaTypes){
  cout<<"got here"<<endl;
  char*searchParameters=new char[120];
  cin.ignore();
  cout<<"Would you like to search the database using TITLE or YEAR"<<endl;
  cin.getline(searchParameters,120,'\n');
  //if they want to search by title
  if(strcmp(searchParameters,"TITLE")==0){
    searchTitles(mediaTypes);
  }
  //if they want to search by year
  else if(strcmp(searchParameters,"YEAR")==0){
    searchYear(mediaTypes);
  }
}


//searching by title 
void searchTitles(vector<Media*>&mediaTypes){
  char*inputTitle=new char[120];
  cout<<"Please enter the title of the media"<<endl;
  cin.getline(inputTitle,120,'\n');
  //for every entry in list mediaTypes
  for (int i = 0; i < mediaTypes.size(); i++) {
    //if the inputted title = the title of that media type
      if(strcmp(inputTitle, mediaTypes[i]->getTitle())== 0) {
	cout << endl;
	//print that media type with all the corresponding information 
	mediaTypes[i]->printMedia();
	cout << endl;
      }
  }
}

//searching by year 
void searchYear(vector<Media*>&mediaTypes){
  int inputYear;
  cout<<"Please enter the year the media was produced"<<endl;
  cin>>inputYear;
  //same logic as the previous method just with year instead of title 
  for (int i = 0; i < mediaTypes.size(); i++) {
      if(mediaTypes[i]->getYear()== inputYear) {
        cout << endl;
        mediaTypes[i]->printMedia();
        cout << endl;
      }
  }


}

//deleting media 
void deleteMediaTypes(vector<Media*>&mediaTypes){
  cout<<"got here"<<endl;
  char*searchParameters=new char[120];
  cin.ignore();
  cout<<"Would you like to delete from the database using TITLE or YEAR"<<endl;
  cin.getline(searchParameters,120,'\n');
  //deleting by title 
  if(strcmp(searchParameters,"TITLE")==0){
    deleteTitle(mediaTypes);
  }
  //deleting by year
  else if(strcmp(searchParameters,"YEAR")==0){
    deleteYear(mediaTypes);
  }

}

//deleting by title
void deleteTitle(vector<Media*>&mediaTypes){
  char*inputTitle=new char[120];
  int indexNumber;
  cout<<"Please enter the title of the media"<<endl;
  cin.getline(inputTitle,120,'\n');

  for (int i = 0; i < mediaTypes.size(); i++) {
      if(strcmp(inputTitle, mediaTypes[i]->getTitle())== 0) {
        cout << endl;
        mediaTypes[i]->printMedia();
	//indexNumber=i;
	//making sure that the user wants to delete 
	char*wantToDelete=new char[10];
	cout<<"Are you sure you want to delete this media YES or NO?"<<endl;
	cin.ignore();
	cin.getline(wantToDelete,10,'\n');
	if(strcmp(wantToDelete,"YES")==0){
	  cout<<endl;
	  cout<<"You deleted: "<<mediaTypes[i]->getTitle()<<endl;
	  //deleting that media type 
	  mediaTypes.erase(mediaTypes.begin() + i);
	}
	else if (strcmp(wantToDelete,"NO")==0){
	  //passing if they say they don't want to delete because there might be more than 1 title 
	  ;
	}
        cout <<endl;
      }
  }

}

//deleting by year 
void deleteYear(vector<Media*>&mediaTypes){
  int inputYear;
  int indexNumber;
  cout<<"Please enter the year the media was produced"<<endl;
  cin>>inputYear;
  //same method as deleting title just with year 
  for (int i = 0; i < mediaTypes.size(); i++) {
      if(mediaTypes[i]->getYear()== inputYear) {
        cout << endl;
        mediaTypes[i]->printMedia();
        indexNumber=i;
        char*wantToDelete=new char[10];
        cout<<"Are you sure you want to delete this media YES or NO?"<<endl;
	cin.ignore();
	cin.getline(wantToDelete,10,'\n');
        if(strcmp(wantToDelete,"YES")==0){
          cout<<endl;
          cout<<"You deleted: "<<mediaTypes[indexNumber]->getTitle()<<endl;
          mediaTypes.erase(mediaTypes.begin() + indexNumber);
        }
        else if (strcmp(wantToDelete,"NO")==0){
          ;
        }
        cout <<endl;

      }
  }

}
