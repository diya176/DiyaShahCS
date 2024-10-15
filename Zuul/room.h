//Header guard
#ifndef ROOM
#define ROOM

#include <iostream>
#include <cstring>
#include <map>

using namespace std;


class room{
 public:
  room();
  room(char*description);
  void setExit(char* direction, room* neighbor);
  char* getShortDescription();
  char* getLongDescription();
  room getExit(char* direction);
  int index;
  char* direction;
  room* neighbor;
  //char* itemName;
  //item getItem(char* itemName);
  //void removeItem(char* itemName);
  //item newitem;
  //void setItem(item newitem);
  //char* getRoomItems();
  //list<char> items;
  map<char*, room*>exits;
 private:
  char* description;
  void getExitString();
};

#endif
