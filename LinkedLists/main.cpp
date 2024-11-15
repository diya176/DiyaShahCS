#include <iostream>
#include <cstring>
#include "Student.h"
#include "Node.h"

using namespace std;

/*

  This code checks all the functions in the .cpp files (Node.cpp and Student.cpp) to make sure that they work as expected.
  It starts by checking the creation of a student with all the required parameters. It then checks to make sure the first node is being created properly. It then adds another node and gets all the values of all the nodes in the list.  
  Author: Diya Shah
  Date: 11/15/2024

 */



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

  //adds another node and checks if it is being added to the list 
  Student* secondStudent=new Student ((char*)"Joanna",(char*)"Mei",418556,6.2);
  Node* secondNode=new Node (secondStudent);
  newNode->setNext(secondNode);
  cout<<"Who is added into the list and what the list has now:"<<endl;
  cout<<newNode->getStudent()<<","<<newNode->getNext()->getStudent()<<endl;

}
