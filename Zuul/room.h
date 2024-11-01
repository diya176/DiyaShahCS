//Header guard
#ifndef ROOM
#define ROOM

#include <iostream>
#include <cstring>
#include <map>
#include"item.h"
#include <vector>
using namespace std;

/*

  Room.h has all the functions that room.cpp will need. Deals with everything room related (moving between rooms, adding items to rooms, dropping items in different rooms.

  Author: Diya Shah
  Date: 11/1/2024


 */


class room{
 public:
  room();
  room(char*description);
  void setExit(char* direction, room* neighbor);
  //returning the description 
  char* getShortDescription();

  map<char*,room*> getExit();
  int index;
  char* direction;
  room* neighbor;
  char* itemName;

  void removeItem(char* itemName);
  item* newitem;
  void setItem(item* newitem);
  void printItem();
  //items vector that has all the items in order to manipulate them (add delete etc)
  vector<item*> items;
  map<char*, room*>exits;
  char* description;
  //prints all the different exits 
  void getExitString();
  int noItems();
  //matching the items
  char* itemDescription;
  item* matchItem(char*itemDescription);
  
};

#endif
