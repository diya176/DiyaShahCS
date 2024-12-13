#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include <iomanip>
#include <fstream>
#include <string>
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


void AddName(Students** &hashtable, int &size);
void GenerateName(Students** &hashtable, int &size);
Students** add(Students* student, Students** &hashtable, int &size);
void printName(Students** &hashtable, int &size);
Students** deleteName(Students** &hashtable, int &size);


int main()
{
  //vector declaration
  //this is the vector that will be passed everywhere
  int size=100;
  Students** hashtable = new Students*[size];
  srand(time(NULL));
  while (true)
  {
    char input[21];
    
   
    cout<<"Would you like to ADD, GENERATE, PRINT, or DELETE a student or would you like to QUIT this program?"<<endl;
    cin>>input;
    //if add is inputted go to the AddName function 
    if (strcmp(input,"ADD")==0)
    {
      AddName(hashtable,size);
    }
    else if (strcmp(input, "GENERATE")==0){
      GenerateName(hashtable,size);
    }
    //if print is inputted go to that function 
    else if (strcmp(input,"PRINT")==0)
    {
      printName(hashtable,size);
    }
    
    else if(strcmp(input,"DELETE")==0)
    {
      deleteName(hashtable,size);
    }
    //if quit is inputted quit the function and the program
    
    else if (strcmp(input,"QUIT")==0)
    {
      exit(0);
    }
  }
 
}


void AddName(Students** &hashtable, int &size)
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

void GenerateName(Students** &hashtable, int &size){
  cout<<"How many students would you like to add?"<<endl;
  int students;
  cin>>students;
  for (int i=0; i<students; i++){
    //ifstream myfile;
    //myfile.open("FirstName.txt");
    ifstream f("FirstName.txt");
    int num=rand()% 427;
    char firstname[100];
    for (int i = 1; i <= num; i++){
      f.getline(firstname,sizeof(firstname));
    }
    f.close();

    ifstream l("LastName.txt");
    int num2=rand()% 441;
    char lastname[100];
    for (int i = 1; i <= num2; i++){
      l.getline(lastname,sizeof(lastname));
    }
    l.close();


    
    //cout<<firstName;
    Students* student= new Students();
    strcpy(student->first_name,firstname);
    cout<<student->first_name;
    strcpy(student->last_name,lastname);
    cout<<student->last_name;
    int id= rand()% 100001;
    student->id=id;
    float gpa = (double)(rand()%50)/10;
    student->gpa = gpa;
    hashtable = add(student, hashtable, size);
  }
}


Students** add(Students* student, Students** &hashtable, int &size) {
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
    //delete [] hashtable;  
    hashtable=newTable;
    size*=2;
    collisions=0;
  }
  return hashtable;
}
 



Students** deleteName(Students** &hashtable, int &size)
{
  cout<<"Please enter the ID of the student you want to delete"<<endl;
  int input;
  cin>>input;
  for (int i=0; i<size; i++){
    if(hashtable[i]!=NULL){
      //cout<<i<<"here"<<endl;
      Students* current= hashtable[i];
      Students* prev=NULL;
      while (current!=NULL){
	if(current->id==input){
	  //hashtable[i]=NULL;
	  if (prev==NULL){
	    hashtable[i]=current->next;
	  }
	  else{
	    prev->next=current->next;
	  }
	  //current=NULL;
	  //current=current->next;
	  //cout<<current->first_name<<endl;
	  //cout<<current->last_name<<endl;
	  return hashtable; 
	  //main();
	}
	prev=current;
	current=current->next;
      }
    }
    else{
      ;
    }
  }
  return hashtable;
}


void printName(Students** &hashtable, int &size)
{
  for (int i=0; i<size; i++){
    if(hashtable[i]!=NULL){
      //cout<<i<<"here"<<endl;
      cout<<hashtable[i]->first_name<<" "<<hashtable[i]->last_name<<endl;
      //cout<<hashtable[i]->last_name<<endl;
      Students* current= hashtable[i];
      while (current->next!=NULL){
        current=current->next;
        cout<<current->first_name<<endl;
      }
    }
    else{
      ;
    }
  }
}
