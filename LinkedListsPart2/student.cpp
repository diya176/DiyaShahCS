#include "student.h"
#include <iostream>
#include <cstring>
using namespace std;


/*
  This is the cpp file for Student.h. It sets the student with all the correct fields. 
  Author: Diya Shah
  Date: 11/15/2024
 */


//creates the student and sets all the inputted values to the correct fields 
Student::Student(char* firstNameInput,char* lastNameInput, int inputid, float inputgpa) {
  firstname = new char[200];
  lastname=new char[200];
  //need to strcpy into the appropriate fields 
  strcpy (firstname, firstNameInput);
  strcpy (lastname, lastNameInput);
  id=inputid;
  gpa=inputgpa;

}


//returns the firstname
char* Student::getFirstName() {
  return firstname;
}
//returns the lastname
char* Student::getLastName() {
  return lastname;
}
//returns id
int Student::getID() {
  return id;
}
//returns gpa
float Student::getGPA() {
  return gpa;
}
