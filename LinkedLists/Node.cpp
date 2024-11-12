#include "Node.h"

Node::Node(Student *newStudent){
  value=newStudent;
  next=NULL; 
}

Node::~Node(){
  delete &value;
  next=NULL;
}

void Node::setStudent(Student *newStudent){
  value=newStudent;
}

char* Node::getStudent(){
  //return value;
}

void Node::setNext(Node* newnext){
  next=newnext;
}

Node*Node::getNext(){
  return next;
}
