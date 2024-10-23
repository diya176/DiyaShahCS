//Header guard
#ifndef ITEM
#define ITEM

#include <iostream>
#include <cstring>
#include <map>

using namespace std;


class item{
 public:
  item();
  char* description;
  item(char*description);
  char* getItemDescription();
};

#endif
