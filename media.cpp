#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

/*
This is the media.cpp file which defines the functions in media.h. This is the parent class.

Author: Diya Shah
Date: 10/1/2024
 */

//setting up the title and year
Media::Media(){
  title=new char [80];
  year=0;
}
//asking for the title and year because those are shared between all the different media types 
Media::Media(char* newtitle, int newyear){
  title=new char[80];
  strcpy(title,newtitle);
  year=newyear;
}

//returning title 
char*Media::getTitle(){
  return title;
}
//returning year
int Media::getYear(){
  return year;
}

//printing the title and year (this is a function that we need to make virtual because it differs between the child classes)
void Media::printMedia() {
  cout << "Title: " << title << endl;
  cout << "Year: " << year << endl;
}
