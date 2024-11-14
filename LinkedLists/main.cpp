#include <iostream>
#include <cstring>
#include "Student.h"
#include "Node.h"

int main(){
  Student* testStudent=new Student ((char*)"Diya",(char*)"Shah",419842,5);
  char firstName[100];
  char lastName[100];

  //test to make sure that student is being created properly and the fields (last name, id, and gpa) are being returned appropriately
  strcpy(firstName,testStudent->getFirstName());
  cout<<firstName<<endl;
  strcpy(lastName,testStudent->getLastName());
  cout<<lastName<<endl;
  cout<<testStudent->getID()<<endl;
  cout<<testStudent->getGPA()<<endl;

  
  //next section makes sure that the nodes are working properly 
  
  Node* newNode=new Node(testStudent);
  //cout<<newNode->getStudent()<<endl;
  newNode->setStudent(testStudent);
  cout<<"Who is in the List:"<<endl;
  cout<<newNode->getStudent()<<endl;


  Student* secondStudent=new Student ((char*)"Joanna",(char*)"Mei",418556,6.2);
  Node* secondNode=new Node (secondStudent);
  newNode->setNext(secondNode);
  cout<<"Who is added into the list and what the list has now:"<<endl;
  cout<<newNode->getStudent()<<","<<newNode->getNext()->getStudent()<<endl;

  //cout<<"this works"<<endl;
}
