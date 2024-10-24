#include <iostream>
#include <cstring>
#include "room.h"
#include "item.h"
#include <map>
#include <vector>
using namespace std;

void goToPlace(vector<room*>rooms, map<char*,room*> &exits,room* &currentRoom);
void getItem(vector<item*>items, vector<item*>currentItems,room*&currentRoom);

int main(){
  vector <room*> rooms;
  vector<item*> items;
  vector<item*> currentItems;
  map<char*, room*>exits;
  room* currentRoom;
  char go[3]="GO";
  char player_Direction[100];
  item* teddy=new item((char*)"Teddy Bear");
  item* soap=new item((char*)"Soap");
  item* pizza=new item((char*)"Slice of pizza");
  item* bike=new item((char*)"Bike");
  item* bottle=new item((char*)"Medicine Bottle");
  item* skirt=new item((char*)"Skirt");
  
  
  room* garage= new room((char*)"You are in the garage");
  room* closet=new room ((char*)"You are in the close");
  room* upstairs=new room((char*)"You are upstairs");
  room* bedroom=new room((char*)"You are in the bedroom");
  room* medicine=new room((char*)"You are looking into the medicine cabinet");
  room* office=new room((char*)"You are in the office");
  room* washing=new room((char*)"You are in the laundry room");
  room* toy=new room((char*)"You are in the toy room");
  room* dining=new room((char*)"You are in the dining room");
  room* kitchen=new room((char*)"You are in the kitchen");
  room* seconddining=new room((char*)"You are in the second dining room");
  room* guest=new room((char*)"You are in the guest bedroom");
  room* living=new room((char*)"You are in the living room");
  room* bathroom=new room((char*)"You are in the bathroom");
  room* patio=new room((char*)"You are on the patio");
  room* front=new room((char*)"You are at the front door");

  front->setExit((char*)"north", living);
  front->setExit((char*)"west",garage);

  garage->setExit((char*)"east",front);
  
  living->setExit((char*)"south",front);

  living->setExit((char*)"east",dining);
  dining->setExit((char*)"west",living);

  dining->setExit((char*)"north",kitchen);
  kitchen->setExit((char*)"south",dining);

  kitchen->setExit((char*)"north",seconddining);
  seconddining->setExit((char*)"south",kitchen);

  seconddining->setExit((char*)"north",patio);
  patio->setExit((char*)"south",seconddining);

  

  living->setExit((char*)"west",upstairs);
  upstairs->setExit((char*)"east",living);


  upstairs->setExit((char*)"south",washing);
  washing->setExit((char*)"north",upstairs);

  washing->setExit((char*)"west",office);
  office->setExit((char*)"east",washing);

  washing->setExit((char*)"south",toy);
  toy->setExit((char*)"north",washing);

  upstairs->setExit((char*)"north",medicine);
  medicine->setExit((char*)"south",upstairs);

  medicine->setExit((char*)"west",bedroom);
  bedroom->setExit((char*)"east",medicine);

  bedroom->setExit((char*)"north",closet);
  closet->setExit((char*)"south",bedroom);


  
  

  living->setExit((char*)"north",guest);
  guest->setExit((char*)"south",living);

  guest->setExit((char*)"west",bathroom);
  bathroom->setExit((char*)"east",guest);


  kitchen->setItem(pizza);
  garage->setItem(bike);
  bathroom->setItem(soap);
  medicine->setItem(bottle);
  toy->setItem(teddy);


  
  currentRoom=front;
  while(true){
    char outs[200];
    strcpy(outs,currentRoom->getShortDescription());
    cout<<outs<<endl;
    currentRoom->printItem();
    cout<<"What would you like to do"<<endl;
    cin>>player_Direction;
    if(strcmp(player_Direction,"GO")==0){
      cout<<"got here"<<endl;
      goToPlace(rooms,exits,currentRoom);
    }
    else if(strcmp(player_Direction,"GET")==0){
      getItem(items,currentItems,currentRoom);
    }
    else if (strcmp(player_Direction,"QUIT")==0){
      exit(0);
      cout<<"Goodbye!"<<endl;
    }
    else{
      ;
    }

  }  
}

void goToPlace(vector<room*>rooms, map<char*,room*> &exits,room* &currentRoom){
  //char outs[200];
  //strcpy(outs,currentRoom->getShortDescription());
  //cout<<outs<<endl;

  char output[200];
  currentRoom->getExitString();
  map<char*,room*>::iterator i;
  cout<<"Which exit of the above would you like to go to?"<<endl;
  cin>>output;
  for (i = currentRoom->getExit().begin(); i != currentRoom->getExit().end(); ++i) {
    if (strcmp(output, i->first) == 0) {
      currentRoom = i->second;
      break;
    }
  }
}

void getItem(vector<item*>items, vector<item*>currentItems,room*&currentRoom){
  char itemNames[1000];
  currentRoom->printItem();
  cout<<"What item would you like to get"<<endl;
  cin>>itemNames;
  if(currentRoom->noItems()==0){
    cout<<"There are no "<<itemNames<<" in the room."<<endl;
  }
  else{
    //currentRoom->matchItem(itemNames);
    currentItems.push_back(currentRoom->matchItem(itemNames));
    for (std::vector<item*>:: iterator it=currentItems.begin(); it!=currentItems.end();++it){
      cout<<"inside this thing"<<endl;
      cout<<(*it)->getItemDescription()<<endl;;
    }
    //items.erase(currentRoom->matchItem(itemNames));
  }
  //item* tempNewItem=new item ((char*)currentRoom);currentRoom 
}
