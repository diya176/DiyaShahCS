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
  int hash;
  float gpa;
  Students* next = NULL;
};


void AddName(Students** hashtable, int size);
Students** add(Students* student, Students** hashtable, int size);

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


void AddName(Students** hashtable, int size)
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


Students** add(Students* student, Students** hashtable, int size) {
  Students* current = hashtable[student->hash];
  int collisions = 1;

  if(current == NULL){
    
    hashtable[student->hash] = student;
  }
  //if something is already there
  else if(hashtable[student->hash]!=NULL){
    
    
    while(current->next!=NULL){
      current = current->next;
      
      collisions++;
      
    }
    
    current->next = student;
  }
    /*
  //Check and rehash if needed
  if (current == NULL) {
    table[student->hash] = student;
  }
  else if (table[student->hash] != NULL) {
    while (current->next !=NULL) {
      current = current->next;
      collisions++;
    }
    current->next = student;
  }
	    */
  //  cout << "Student added!" << endl;
  return hashtable;  
}
