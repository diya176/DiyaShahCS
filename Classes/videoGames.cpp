#include <iostream>
#include <cstring>
#include "videoGames.h"

using namespace std;

/*

  Videogames.cpp file, defines the functions from videoGames.h

  Author: Diya Shah
  Date: 10/1/2024

 */


//only needs publisher and rating
videoGames::videoGames(){
  publisher=new char[120];
  rating=0;
}

//takes title and year from parent function 
videoGames::videoGames(char* title,char* newpublisher,int year, int newrating):Media(title,year){
  publisher=new char[120];
  strcpy(publisher,newpublisher);
  rating=newrating;
}

//destructor for the things created with a constructor 
videoGames::~videoGames(){
  delete[] publisher;
}

char*videoGames::getPublisher(){
  return publisher;
}

int videoGames::getRating(){
  return rating;
}

//unique/overriden print function 
void videoGames::printMedia() {
  cout << "Videogame: " << endl;
  Media::printMedia();
  cout << "Publisher: " << publisher << endl;
  cout << "Rating: " << rating << endl;
}
