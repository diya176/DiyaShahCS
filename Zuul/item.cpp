#include <iostream>
#include <cstring>
#include "item.h"

using namespace std;


item::item(){

}

item::item (char* newdescription){
  description=newdescription;
}


char* item::getItemDescription(){
  return description;
}
