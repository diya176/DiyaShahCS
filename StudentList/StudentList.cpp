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
  float gpa;
};

//declaration of different fuunctions
void AddName(vector <Students>& studentList);
void printName(vector <Students>& studentList);
void deleteName(vector <Students>&studentList);


int main()
{
  //vector declaration
  //this is the vector that will be passed everywhere
  vector <Students> studentList;
  
  while (true)
  {
    char input[21];
    cout<<"Would you like to ADD, PRINT, or DELETE a student or would you like to QUIT this program?"<<endl;
    cin>>input;
    //if add is inputted go to the AddName function 
    if (strcmp(input,"ADD")==0)
    {
      AddName(studentList);
    }
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
    else if (strcmp(input,"QUIT")==0)
    {
      exit(0);
    }
  }
 
}


//addName function which adds a student to the studentList
void AddName(vector <Students> & studentList)
{
  //inputting of all the variables needed to add a new person 
  char first_name[22];
  char last_name[22];
  int id;
  float gpa;
  cout<<"Please enter the student's first name: ";
  cin>>first_name;
  cout<<"Please enter the student's last name: ";
  cin>>last_name;
  cout<<"Please enter the student's ID number: ";
  cin>>id;
  cout<<"Please enter the student's GPA: ";
  cin>>gpa;
  //adding a new person
  Students new_person;

  //copying the first_name char array into the struct position for that 
  strcpy(new_person.first_name, first_name);
  strcpy(new_person.last_name, last_name);
  //adding the id and gpa to the positions in the struct
  new_person.id = id;
  new_person.gpa = gpa;
  //pushing that into the vector and the struct to make a new person
  studentList.push_back(new_person);
}

//printinng the name of the students 
void printName(vector<Students> & studentList)
{
  // vector iterator (line adapted from https://cplusplus.com/reference/vector/vector/begin/)
  for (std::vector<Students>:: iterator it=studentList.begin(); it!=studentList.end();++it)
  {
    //need to use the arrow instead of dot
    //outputting the things in the struct 
    cout<<it->first_name<<" "<<it->last_name<<" , "<<it->id<<" , "<<fixed<<setprecision(2)<<it->gpa<<endl;;
  }
}

//deleting a student from the vector and struct
void deleteName(vector<Students>& studentList)
{
  int id_to_delete;
  cin>>id_to_delete;
  int index=0;
  //same line from above 
  for (std::vector<Students>:: iterator it=studentList.begin(); it!=studentList.end();++it)
  {
    //index of the current place in the iterator 
    index=index+1;
    //if the id is the same as the id assignmed to one of the students 
    if (it->id==id_to_delete)
    {
      int value=index-1;
      //erase that person from the vector
      studentList.erase(studentList.begin()+value);
      //delete erase break out of function
      break;
    }
    //if not keep going with the program
    else
    {
      ;
    }
  }
}
