//Header guard
#ifndef ITEM
#define ITEM

#include <iostream>
#include <cstring>
#include <map>

using namespace std;


/*
Declaration of all the functions that will be used in item.h.

Author: Diya Shah
Date: 11/1/2024


 */

class item{
 public:
  item();
  //need functions to get description and to set an item initially - everything else goes in room.cpp
  char* description;
  item(char*description);
  char* getItemDescription();
};

#endif
