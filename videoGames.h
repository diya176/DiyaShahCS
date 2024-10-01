//header guard 

#ifndef VIDEOGAMES
#define VIDEOGAMES

#include <iostream>
#include <cstring>
#include "media.h"
using namespace std;

/*

videoGames.h file. Child of media parent class

Author: Diya Shah
Date: 10/1/2024
 */

class videoGames : public Media{
 public:
  videoGames();
  //inherits the title and year from Media parent class , hopefully :)
  //for publisher

  char* publisher;
  int rating;
  int year;
  char* title;
  videoGames(char*title,char*publisher,int year,int rating);
  ~videoGames();//destructor 
  char* getPublisher();
  int getRating();
  virtual void printMedia();
};

#endif
