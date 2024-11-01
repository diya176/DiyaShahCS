#include <iostream>
#include <cstring>
#include "room.h"

using namespace std;


/*

This file defines all the functions that will be used. Matching items, setting exits, printing the different items, etc. 

Author: Diya Shah
Date: 11/1/2024
  
 */


room::room(){
  
}

//sets a new room with a description of the room
room::room (char* newdescription){
  description=newdescription;
}

//sets the various exits 
void room:: setExit(char* newdirection, room* newneighbor){
  exits.insert(pair<char*,room*>(newdirection,newneighbor));
}

//no idea why this is called short description but it basically just returns the description
char*room::getShortDescription(){
  return description;
}

//prints the different exits available 
void room::getExitString(){
  cout << "EXITS: ";
  map<char*, room*>::iterator i;
  for (i = exits.begin(); i != exits.end(); ++i) {
    //prints all the exits with a comma in between
    cout << i->first << ", ";
  }
  cout << endl;
}

//returns the exits that are possible 
map<char*,room*> room::getExit(){
  return exits;
}

//setting item into a particular room
void room::setItem(item* newItem){
  //adding that room into the vector os available items 
  items.push_back(newItem);
}

//printing all the items in a room
void room::printItem(){
  cout<<"ITEMS: "<<endl;
  for(int i=0; i<items.size();i++){
    char outs[1000];
    //using get description from the other item.cpp
    strcpy(outs,items[i]->getItemDescription());
    cout<<outs<<endl;
  }
}

//if there are no items return 0
int room::noItems(){
  int length=items.size();

  return length;
}

//trying to find the item that is the same
item* room::matchItem(char* newdescription){
  for(int i=0; i<items.size();i++){
    char outs[1000];
    //copying the description to outs to compare easily
    strcpy(outs,items[i]->getItemDescription());
    if (strcmp(newdescription,outs)==0){
      return items[i];
    }
    else{
      ;
    }
  }
  //cout<<"got eohaoshfsdfhsudtqourr83kehaksjfsd"<<endl;
}

//to remove item iterate through the vector until you find the one that matches and then delete that one
void room::removeItem(char*it){
  vector<item*>::iterator i;
  for(int i=0;i<items.size();i++){
      if(strcmp(it,items[i]->getItemDescription())==0){
        items.erase(items.begin()+i);
      }
    }
}
