#include <iostream>
#include <cstring>
#include "room.h"

using namespace std;


room::room(){
  
}

room::room (char* newdescription){
  description=newdescription;
}

void room:: setExit(char* newdirection, room* newneighbor){
  exits.insert(pair<char*,room*>(newdirection,newneighbor));
}

char*room::getShortDescription(){
  return description;
}

void room::getExitString(){
  cout << "Exits: ";
  map<char*, room*>::iterator i;
  for (i = exits.begin(); i != exits.end(); ++i) {
    cout << i->first << ", ";
  }
  cout << endl;
}
