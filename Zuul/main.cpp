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
  //declaration of all the items Teddy,Soap, Pizza, Bike, Medicine, and Skirt
  item* teddy=new item((char*)"Teddy");
  item* soap=new item((char*)"Soap");
  item* pizza=new item((char*)"Pizza");
  item* bike=new item((char*)"Bike");
  item* bottle=new item((char*)"Medicine");
  item* skirt=new item((char*)"Skirt");

  
  //declaration of all the different rooms 
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

  //setting all the exits 
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


  //putting all the items in their respective rooms 
  kitchen->setItem(pizza);
  garage->setItem(bike);
  bathroom->setItem(soap);
  medicine->setItem(bottle);
  toy->setItem(teddy);
  closet->setItem(skirt);

  //setting the current room to the front door because that is where you start
  currentRoom=front;
  while(true){
    //winning condition - if you collect all the 6 items
    if(currentItems.size()==6){
      cout<<"You Win!";
      exit(0);
    }
    //what do you want to do
    char outs[200];
    strcpy(outs,currentRoom->getShortDescription());
    cout<<outs<<endl;
    currentRoom->printItem();
    cout<<"What would you like to do: GO,GET,DROP, INVENTORY,QUIT,HELP?"<<endl;
    cin>>player_Direction;
    cin.ignore();
    //if they say go then go to the go function
    if(strcmp(player_Direction,"GO")==0){
      goToPlace(rooms,exits,currentRoom);
    }
    //if they say get they want to pick up the objects
    else if(strcmp(player_Direction,"GET")==0){
      getItem(items,currentItems,currentRoom);
    }
    //quit means you want to stop the game- thats a bad idea :(
    else if (strcmp(player_Direction,"QUIT")==0){
      exit(0);
      cout<<"Goodbye!"<<endl;
    }
    //print inventory 
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
    //if you say something random then it just asks you again
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
  //print the possible exits of the current room
  cout<<endl;
  currentRoom->getExitString();
  map<char*,room*>::iterator i;
  cout<<"Which exit of the above would you like to go to? TYPE FULLY LOWERCASE"<<endl;
  cin>>output;
  cin.ignore();
  //if the input is the same as the input string then set the current room to the second part of the map
  //first part of map is to make sure the directions match (no directions more than 2 words)
  for (i = currentRoom->getExit().begin(); i != currentRoom->getExit().end(); ++i) {
    if (strcmp(output, i->first) == 0) {
      currentRoom = i->second;
      break;
    }
  }
}

//picking up the items 
void getItem(vector<item*>items, vector<item*>&currentItems,room*&currentRoom){
  char itemNames[1000];
  //print the items in a current room
  cout<<endl;
  cout<<endl;
  currentRoom->printItem();
  //pick the item you want to get
  cout<<"What item would you like to get"<<endl;
  cin>>itemNames;
  cin.ignore();
  //if there are no items then no point doing any search because it will just error so just stop here iteself
  if(currentRoom->noItems()==0){
    cout<<"There are no "<<itemNames<<" in the room."<<endl;
  }
  else{
    //currentRoom->matchItem(itemNames);
    //add the item to the current Items vector
    currentItems.push_back(currentRoom->matchItem(itemNames));
    //and then remove it from the current room 
    currentRoom->removeItem(itemNames);
    //items.erase(&(currentRoom->matchItem(itemNames)));
  }
  //item* tempNewItem=new item ((char*)currentRoom);currentRoom 
}

//print whatever is in current items
//MAKE SURE TO PASS IN CURRENTITEMS BY REFERENCE EVERYWHERE
void printInventory(vector<item*> &currentItems,room*&currentRoom){
  //if the size of current items is 0 just dont print anything
  if(currentItems.size()==0){
    cout<<"There are no objects in your inventory."<<endl;
  }
  cout<<"These are the items that you currently have: "<<endl;
  //iterator to go through vector currentItems
  for (std::vector<item*>:: iterator it=currentItems.begin(); it!=currentItems.end();++it){
      cout<<(*it)->getItemDescription()<<endl;;
    }
}

//drop an item
void dropItem(vector<item*>items, vector<item*>&currentItems,room*&currentRoom){
  char input[100];
  cout<<"Please enter the name of the item you want to drop"<<endl;
  cin.getline(input,101,'\n');
  item* drop;
  //segmentation fault if the item is not valid so first check if the item is valid
  if(strcmp(input, "Teddy")==0 || strcmp(input, "Soap") == 0 || strcmp(input, "Bike") == 0|| strcmp(input, "Pizza") == 0|| strcmp(input, "Medicine") == 0|| strcmp(input, "Skirt") == 0) {
    //same logic as in the room.cpp remove item but it wasn't working from there so I rewrote and changed some of it
    for (int i = 0; i < currentItems.size(); i++) {
      if (strcmp(input, currentItems[i]->getItemDescription()) == false){
      currentItems.erase(currentItems.begin() + i);
      //set the drop item to the currentItem so that it can be added to the currentRoom
      drop = currentItems[i];
      }
    }
    //add to currentRoom
    currentRoom->setItem(drop);
  }
  else{
    ;
  }

}
