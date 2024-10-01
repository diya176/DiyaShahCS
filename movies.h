//Header guard 
#ifndef MOVIES
#define MOVIES

#include <iostream>
#include <cstring>
#include "media.h"
using namespace std;

/*
Movies.h file that houses the functions used for movies 

Author: Diya Shah
Date: 10/1/2024
 */


class movies : public Media{
public:
  movies();
  //inherits title and year from Media parent class
  //for director
  char*director;
  int duration;
  int rating;
  char* title;
  int year;
  //all the parameters needed for this media type 
  movies(char* title,char*director, int year, int duration,int rating);
  //movies destructor 
  ~movies();
  virtual char* getDirector();
  virtual int getRating();
  virtual int getDuration();
  virtual void printMedia();
};

#endif
