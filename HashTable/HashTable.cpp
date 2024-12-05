#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include <iomanip>
using namespace std;

/*This program includes an empty vector of structs to which youu can add,delete, or print students.
To ADD a student type ADD
To DELETE a student type DELETE and then enter the id of the student
To PRINT the current students in the vector type PRINT


Author: Diya Shah
Date: 9/17/2024
 */

//struct of Students with firstname, lastname, id, and gpa
struct Students
{
  char first_name[22];
  char last_name[22];
  int id;
  //this is the key 
  int hash;
  float gpa;
  Students* next = NULL;
};


void AddName(Students** hashtable, int &size);
Students** add(Students* student, Students** hashtable, int &size);

int main()
{
  //vector declaration
  //this is the vector that will be passed everywhere
  int size=100;
  Students** hashtable = new Students*[size];

  while (true)
  {
    char input[21];
    
   
    cout<<"Would you like to ADD, PRINT, or DELETE a student or would you like to QUIT this program?"<<endl;
    cin>>input;
    //if add is inputted go to the AddName function 
    if (strcmp(input,"ADD")==0)
    {
      AddName(hashtable,size);
    }
    /*
    //if print is inputted go to that function 
    else if (strcmp(input,"PRINT")==0)
    {
      printName(studentList);
    }
    else if(strcmp(input,"DELETE")==0)
    {
      deleteName(studentList);
    }
    //if quit is inputted quit the function and the program
    */
    else if (strcmp(input,"QUIT")==0)
    {
      exit(0);
    }
  }
 
}


void AddName(Students** hashtable, int &size)
{
  //inputting of all the variables needed to add a new person 
  char first_name[22];
  char last_name[22];
  int id;
  float gpa;
  Students* student=new Students();
  cout<<"Please enter the student's first name: ";
  cin>>student->first_name;
  cout<<"Please enter the student's last name: ";
  cin>>student->last_name;
  cout<<"Please enter the student's ID number: ";
  cin>>student->id;
  cout<<"Please enter the student's GPA: ";
  cin>>student->gpa;
  //pushing that into the vector and the struct to make a new person
  hashtable = add(student, hashtable, size);
  
}


Students** add(Students* student, Students** hashtable, int &size) {
  Students* current = hashtable[student->hash];
  int collisions = 0;

  if(current == NULL){    

    hashtable[student->hash] = student;
  }
  //if something is already there

  else{
    
    
    while(current->next!=NULL){
      current = current->next;
      
      collisions++;
      cout<<"A collision happened"<<endl;
    }
    
    current->next = student;
  }
  
  if (collisions==3){
    cout<<"3 collisions happened! Rehashing the table :)"<<endl;
    Students** newTable = new Students*[size*2]();
    for (int i=0;i<size;i++){
      Students* currenttemp= hashtable[i];
      while (currenttemp!=NULL){

	int newHash= student->id % (size*2);

        Students* studentToBeCopiedOver= new Students();
        studentToBeCopiedOver->next = NULL;
        strcpy(studentToBeCopiedOver->first_name,currenttemp->first_name);
        strcpy(studentToBeCopiedOver->last_name,currenttemp->last_name);
        studentToBeCopiedOver->id = currenttemp->id;
        studentToBeCopiedOver->gpa = currenttemp->gpa;
        studentToBeCopiedOver->hash=newHash;

	//if slot in the new table with the new hash is empty 
	if (newTable[newHash] == NULL) {
	  //add student into that slot 
          newTable[newHash] = studentToBeCopiedOver;
	}
	//if the slot is not empty - that is a problem because that means it is a collision 
	else{
	  //set a temp student to that place that is already filled up in the table
	   Students* temp = newTable[newHash];
	   //while we havent found a spot to put this student keep going here 
	   while(temp->next != NULL){
	     // keep moving to the next spot 
	     temp=temp->next;
	   }
	   //we found a place! YAY! put the student here 
	   temp->next=studentToBeCopiedOver;
	}
	//move to the next one 
	currenttemp=currenttemp->next;
      }
    }
    hashtable=newTable;
    size*=2;
  }
  return hashtable;
}
 
