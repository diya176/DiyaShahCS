#include "student.h"
#include "node.h"
#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include <iomanip>
using namespace std;

/*
  This program creates a linked list of students that we can add to, delete from, and average. 
  Author: Diya Shah
  Date: 1/9/2024
 */

//Intialize functions
void ADD(Node* current, Node* previous, Student* newStudent, Node* &head);
void PRINT(Node* head);
void DELETE(Node* current, Node* previous, int id, Node* &head);
void AVERAGE(Node* current, Node* head, int count, float average);

int main() {
  //Intialize variables
  Node* head = NULL;
  Node* current = head;
  char input[20];

  while (true) {

    //User chooses to add, print, delete, average or quit
    cout << "ADD, PRINT, DELETE, AVERAGE or QUIT" << endl;
    cin>>input;
    cin.ignore();

    //User chooses to add, search for or delete media, or to quit program
    if (strcmp(input, "ADD") == false) {
      char* first= new char[100];
      char* last= new char[100];
      int id;
      float gpa;

      //get all the info 
      cout << "Please enter the student's first name: ";
      cin.getline(first, 100);

      cout << "Please enter the student's last name: ";
      cin.getline(last, 100);

      cout << "Please enter the student's ID: ";
      cin >> id;
      cin.ignore();

      cout << "Please enter the student's GPA: ";
      cin>>gpa;
      cin.ignore();

      //make a new student with first name last name id and gpa
      Student* newStudent = new Student((char*)first, (char*)last, id, (float)gpa);
      cout << endl;

      ADD(head, head, newStudent, head);
    }
    //print all the students unless there are not any 
    else if (strcmp(input, "PRINT") == false) {
        if (head == NULL) {
            cout << "There are no students in the list currently." << endl;
            ;
        }
        else{
            PRINT(head);
        }
    }
    else if (strcmp(input, "DELETE") == false) {
      cout << "Enter in the id of the student you'd like to delete: " << endl;
      int idfordelete = 0;
      cin >> idfordelete;
      cin.ignore();

      //cout << "You're deleting: " << idfordelete << endl;

      DELETE(head, head, idfordelete, head);
    }
    else if (strcmp(input, "AVERAGE") == false) {
      AVERAGE(head, head, 0, 0.0f);
    }
    else if (strcmp(input, "QUIT") == false) {
      exit(0);
    }
  }
  return 0;
}

//adding students using recursion
void ADD(Node* current, Node* previous, Student* newStudent, Node* &head) {
    // If the list is empty (head is NULL), student is the head then
    if (head == NULL) {
        head = new Node(newStudent);
        //cout << "Added student with ID: " << newStudent->getID() << " as the head." << endl;
        return;
    }

    // If the new student's ID is smaller than or equal to the current student's ID, insert before current
    if (current == NULL || newStudent->getID() <= current->getStu()->getID()) {
        Node* newNode = new Node(newStudent);

        // If current is NULL, we are at the end of the list
        if (current == NULL) {
            previous->setNext(newNode);
	    // cout << "Added student with ID: " << newStudent->getID() << " at the end." << endl;
        } else {
            // Insert before the current node
            newNode->setNext(current);
            previous->setNext(newNode);
	    //line below was part of figuring out what an error was 
	    //cout << "Added student with ID: " << newStudent->getID() << " before student with ID: " << current->getStudent()->getID() << endl;
        }
        return;  // Done yay!!!
    }

    // If new student's ID is greater than current student's ID, keep going to the next node
    ADD(current->getNext(), current, newStudent, head);
}

//Print out all students in database
void PRINT(Node* head) {
  if (head == NULL) {
    return;
  }
  else {
    if (head!= NULL) {
      cout<<head->getStu()->getFirstName()<< " ";
      cout<<head->getStu()->getLastName()<<",";
      cout<<fixed<<setprecision(2)<<head->getStu()->getID()<<",";
      cout<<head->getStu()->getGPA()<<endl;
      PRINT(head->getNext());
    }
  }
}

void AVERAGE(Node* current, Node* head, int count, float average) {
    //if there are no more students
    if (current == NULL) {
        //if there were no students to begin with
        if (count == 0) {
            cout << "No students to calculate average." << endl;
        //else add average and total gpa
        } else {
            // Set output to fixed point with 2 decimal places
            cout.setf(ios::fixed, ios::floatfield);
            cout.setf(ios::showpoint);
            cout.precision(2);
            cout << "Average GPA: " << average / count << endl;
        }
        return;  // End recursion
    }
    average += current->getStu()->getGPA();
    count++;  // Increment the count of students
    // Recursive call to the next student
    AVERAGE(current->getNext(), head, count, average);
}

//Delete a given student (node) based on ID number
void DELETE(Node* current, Node* pre, int id, Node* &head) {
    // Base case: if the list is empty
    if (current == NULL) {
        cout << "Nothing in database" << endl;
        return;
    }

    // If the node to delete is found
    if (current != NULL && current->getStu()->getID() == id){ 
        // If the node to delete is the head
        if (head == current) {
            head = current->getNext();
            delete current;
        }
        // If the node to delete is not the head (in the middle or end)
        else {
            pre->setNext(current->getNext());  // Update the previous node's next pointer
            delete current;  // Delete the current node
        }
        return;  // Node deleted, so return
    }

    // If the current node is not the one we're looking for, recurse
    DELETE(current->getNext(), current, id, head);
}


