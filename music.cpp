#include <iostream>
#include<cstring>
#include "music.h"

using namespace std;

/*

Music.cpp file for all the music media types
  
Author: Diya Shah
Date: 10/1/2024
 */


//needs publisher, artist, and duration (unique to music)
Music::Music(){
  artist=new char[120];
  publisher=new char[120];
  duration=0;
}

//grabs the title and year from the parent class
Music::Music(char*title, char*newartist,char*newpublisher,int year,int newduration):Media(title,year){
  artist=new char[120];
  strcpy(artist,newartist);
  //being constructed so needs a destructor 
  publisher=new char[120];
  strcpy(publisher,newpublisher);
  duration=newduration;
}

//destroying the non primitive types
Music::~Music(){
  delete[]artist;
  delete[] publisher;
}

char*Music::getArtist(){
  return artist;
}
char*Music::getPublisher(){
  return publisher;
}
int Music::getDuration(){
  return duration;
}

//printing the various parameters of this media type 
void Music::printMedia() {
  cout << "Music: " << endl;
  Media::printMedia();
  cout<<"Artist: "<<artist<<endl;
  cout << "Publisher: " << publisher << endl;
  cout << "Duration: " << duration << endl;
}

