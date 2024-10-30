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

int room::noItems(){
  int length=items.size();
  cout<<length<<endl;
  return length;
}

item* room::matchItem(char* newdescription){
  for(int i=0; i<items.size();i++){
    char outs[1000];
    strcpy(outs,items[i]->getItemDescription());
    if (strcmp(newdescription,outs)==0){
      cout<<"i have found a "<<endl;
      return items[i];
    }
    else{
      ;
    }
  }
  //cout<<"got eohaoshfsdfhsudtqourr83kehaksjfsd"<<endl;
}

void room::removeItem(char*it){
  vector<item*>::iterator i;
  for(int i=0;i<items.size();i++){
      if(strcmp(it,items[i]->getItemDescription())==0){
        items.erase(items.begin()+i);
      }
    }
}
