//Header guard
#ifndef ROOM
#define ROOM

#include <iostream>
#include <cstring>
#include <map>
#include"item.h"
#include <vector>
using namespace std;


class room{
 public:
  room();
  room(char*description);
  void setExit(char* direction, room* neighbor);
  char* getShortDescription();
  char* getLongDescription();
  map<char*,room*> getExit();
  int index;
  char* direction;
  room* neighbor;
  char* itemName;
  //item getItem(char* itemName);
  void removeItem(char* itemName);
  item* newitem;
  void setItem(item* newitem);
  void printItem();
  //char* getRoomItems();
  vector<item*> items;
  map<char*, room*>exits;
  char* description;
  void getExitString();
  int noItems();
  char* itemDescription;
  item* matchItem(char*itemDescription);
  
};

#endif
