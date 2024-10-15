#include <iostream>
#include <cstring>
#include "room.h"
#include <map>
#include <vector>
using namespace std;


int main(){
  vector <room*> rooms;
  map<char*, room*>exits;
  room* nowLocation;
  room* garage= new room((char*)"You are in the garage");
  room* closet=new room ((char*)"You are in the close");
  room* upstairs;=new room((char*)"You are upstairs");
  room* bedroom=new room((char*)"You are in the bedroom");
  room* medicine=new room((char*)"You are looking into the medicine cabinet");
  room* office=new room((char*)"You are in the office");
  room* washing=new room((char*)"You are in the laundry room");
  room* toy=new room((char*)"You are in the toy room");
  room* dining=new room((char*));
  room* kitchen=new room((char*)"You are in the kitchen");
  room* seconddining=new room((char*));
  room* guest=new room((char*)"You are in the guest bedroom");
  room* living=new room((char*)"You are in the living room");
  room* bathroom=new room((char*)"You are in the bathroom");
  room* patio=new room((char*)"You are on the patio");
  room* front=new room((char*)"You are at the front door");

  front->setExit((char*)"north", living);
}
