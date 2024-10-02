//header guard - must be capital 
#ifndef MEDIA
#define MEDIA

#include <iostream>
#include <cstring>

using namespace std;

/*
This is the media.h file which defines all the functions that will be used. It also defines the variables. This is the parent class. 
Author: Diya Shah
Date: 10/1/2024
 */


class Media{
 public:
  Media();
  char* title;
  int year;
  //title and year
  Media (char*title,int year);
  virtual char* getTitle();
  virtual int getYear();
  //needs to be virtual 
  virtual void printMedia();
};

#endif
