#include <iostream>
#include <cstring>
#include "room.h"
#include "item.h"
#include <map>
#include <vector>
#include <memory>

using namespace std;

/*

This is a program that simulates the game of Zuul. To play start by typing in a command (GO,GET,DROP,INVENTORY,HELP,or QUIT). From there you will be directed to either pick an exit to go to, get a specific object, or drop a specific object. If you choose INVENTORY, whatever items are currently in your possession will be printed. If you type HELP, all the possible commands and their uses will be printed. If you type QUIT, the game stops.

Author: Diya Shah
Date: 10/30/2024

 */



//method declarations
void goToPlace(vector<room*>rooms, map<char*,room*> &exits,room* &currentRoom);
void getItem(vector<item*>items, vector<item*>&currentItems,room*&currentRoom);
void printInventory(vector<item*>&currentItems,room*&currentRoom);
void dropItem(vector<item*>items, vector<item*>&currentItems,room*&currentRoom);


int main(){
  vector <room*> rooms;
  vector<item*> items;
  vector<item*> currentItems;
  map<char*, room*>exits;
  room* currentRoom;
  char go[3]="GO";
  char player_Direction[100];
  item* teddy=new item((char*)"Teddy");
  item* soap=new item((char*)"Soap");
  item* pizza=new item((char*)"Pizza");
  item* bike=new item((char*)"Bike");
  item* bottle=new item((char*)"Medicine");
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
    cin.ignore();
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
    else if (strcmp(player_Direction,"INVENTORY")==0){
      printInventory(currentItems,currentRoom);
    }
    else if (strcmp(player_Direction,"HELP")==0){
      cout<<endl;
      cout<<"GO: In order to move to another room"<<endl;
      cout<<"GET: To pick up the different items in a room"<<endl;
      cout<<"DROP: To drop an item into a room"<<endl;
      cout<<"QUIT: To stop the game"<<endl;
      cout<<"INVENTORY: Prints out all the current Items that you have"<<endl;
      cout<<"HELP: For a list of the different commands and what they do"<<endl;
      cout<<"Make sure that you always type commands in with all CAPS"<<endl;
      cout<<endl;
    }
    else if (strcmp(player_Direction,"DROP")==0){
      dropItem(items,currentItems,currentRoom);
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
  cin.ignore();
  for (i = currentRoom->getExit().begin(); i != currentRoom->getExit().end(); ++i) {
    if (strcmp(output, i->first) == 0) {
      currentRoom = i->second;
      break;
    }
  }
}

void getItem(vector<item*>items, vector<item*>&currentItems,room*&currentRoom){
  char itemNames[1000];
  currentRoom->printItem();
  cout<<"What item would you like to get"<<endl;
  cin>>itemNames;
  cin.ignore();
  if(currentRoom->noItems()==0){
    cout<<"There are no "<<itemNames<<" in the room."<<endl;
  }
  else{
    //currentRoom->matchItem(itemNames);
    currentItems.push_back(currentRoom->matchItem(itemNames));
    currentRoom->removeItem(itemNames);
    //items.erase(&(currentRoom->matchItem(itemNames)));
  }
  //item* tempNewItem=new item ((char*)currentRoom);currentRoom 
}

void printInventory(vector<item*> &currentItems,room*&currentRoom){
  if(currentItems.size()==0){
    cout<<"There are no objects in your inventory."<<endl;
  }
  cout<<"These are the items that you currently have: "<<endl;
  for (std::vector<item*>:: iterator it=currentItems.begin(); it!=currentItems.end();++it){
      cout<<(*it)->getItemDescription()<<endl;;
    }
}

void dropItem(vector<item*>items, vector<item*>&currentItems,room*&currentRoom){
  char input[100];
  cout<<"Please enter the name of the item you want to drop"<<endl;
  cin.getline(input,101,'\n');
  item* drop;
  
  if(strcmp(input, "Teddy")==0 || strcmp(input, "Soap") == 0 || strcmp(input, "Bike") == 0|| strcmp(input, "Pizza") == 0|| strcmp(input, "Medicine") == 0|| strcmp(input, "Skirt") == 0) {
    for (int i = 0; i < currentItems.size(); i++) {
      if (strcmp(input, currentItems[i]->getItemDescription()) == false){
      currentItems.erase(currentItems.begin() + i);
      drop = currentItems[i];
      }
    }
    currentRoom->setItem(drop);
  }
  else{
    ;
  }

}
