#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <cstring>
using namespace std;

class Student{
 public:
  Student();
  Student(char* firstNameInput,char* lastNameInput, int inputid, float inputgpa);
  char* getFirstName();
  char* getLastName();
  int getID();
  float getGPA();
  char* firstname;
  char* lastname;
  int id;
  int gpa;
};
#endif
