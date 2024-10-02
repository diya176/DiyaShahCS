//header guard 
#ifndef MUSIC
#define MUSIC

#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

/*
Music.h file which defines what we need for music   

Author: Diya Shah
Date: 10/1/2024
 */


class Music: public Media{
 public:
  Music();
  //will already have title and year but still need to define them 
  //for artist
  char*artist;
  char*publisher;
  char*title;
  int year;
  int duration;
  Music(char*title,char*artist,char*publisher,int year,int duration);
  ~Music();//destructor 
  char*getArtist();
  char*getPublisher();
  int getDuration();
  //unique print media for music 
  virtual void printMedia();
};

#endif
