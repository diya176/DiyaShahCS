#ifndef NODE_H
#define NODE_H

#include <iostream>


using namespace std;

class Node{
 public:
  Node(Student*newStudent);
  ~Node();
  void setStudent (Student* newStudent);
  char* getStudent();
  void setNext(Node* newnext);
  Node* getNext();

 private:
  Student* value;
  Node* next;


}

#endif
