#include <iostream>
#include <cstring>
#include "movies.h"

using namespace std;

/*

This is the .cpp file for movies. It uses the title and year from the media.cpp file and is therefore a child class of media. 

Author: Diya Shah
Date: 10/1/2024

 */

movies::movies(){
  director=new char[120];
  duration=0;
  rating=0;
}

//uses the title and year from the media class
//needs a new director, duration, and rating 
movies::movies(char*title, char *newdirector,int year, int newduration,int newrating):Media(title,year){
  director=new char[120];
  strcpy(director,newdirector);
  duration=newduration;
  rating=newrating;
}

//only delete non primitive types (or anything with new)
movies::~movies(){
  delete[] director;
}

char*movies::getDirector(){
  return director;
}
int movies::getRating(){
  return rating;
}
int movies::getDuration(){
  return duration;
}
//overrides the print media of the original media
void movies::printMedia() {
  cout << "Movies: " << endl;
  Media::printMedia();
  cout << "Director: " << director << endl;
  cout<<"Duration: "<<duration<<endl;
  cout << "Rating: " << rating << endl;
}



