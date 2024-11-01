#include <iostream>
#include <cstring>
#include "item.h"

using namespace std;



/*

  Deals with the items. Sets the items and returns their description. 

Author: Diya Shah
Date: 11/1/2024

 */

item::item(){

}

//in order to set an item we need a desceription which is just the objects name :)
item::item (char* newdescription){
  description=newdescription;
}


//returns the description or title of the object
char* item::getItemDescription(){
  return description;
}
