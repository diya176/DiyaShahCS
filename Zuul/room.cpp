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

map<char*,room*> room::getExit(){
  return exits;
}

void room::setItem(item* newItem){
  items.push_back(newItem);
}

void room::printItem(){
  cout<<"Items: "<<endl;
  for(int i=0; i<items.size();i++){
    char outs[1000];
    strcpy(outs,items[i]->getItemDescription());
    cout<<outs<<endl;
  }
}
