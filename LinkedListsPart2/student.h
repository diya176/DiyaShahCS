#ifndef STUDENT_H
#define STUDENT_H


#include <iostream>
#include <cstring>
using namespace std;

/*
  This file contains the function prototypes of the Student class. It has a function to create a new student and then get all the individual features of that student (First Name, Last Name, ID, GPA).  
  Author: Diya Shah
  Date: 1/7/2025
 */



class Student{
 public:
  //Student();
  //creates a new student with first name, last name, id, and gpa
  Student(char* firstNameInput,char* lastNameInput, int inputid, float inputgpa);
  //returns the first name
  char* getFirstName();
  //returns the last name
  char* getLastName();
  //returns the id number (int)
  int getID();
  //returns the gpa value (float)
  float getGPA();
  //variables used in cpp file 
  char* firstname;
  char* lastname;
  int id;
  float gpa;
};
#endif
