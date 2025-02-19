#include <iostream>
#include <cstring>

using namespace std;


struct node
{
    char data;
    node * next;
};

void push(node* &head, node*toadd);
node*peek(node* &head);
int main(){
  node* head=new node();
  head->data='C';
  node*toadd=new node();
  toadd->data='D';
  push(head, toadd);
  cout<<"Got it"<<endl;
  cout<<peek(head)->data<<endl;
  return 0; 
}

///STACK STUFF for shunting yard algorithm
//need a push pop and peek function


void push(node* &head, node* toadd){
  if(head==NULL){
    head=toadd;
  }
  node*current=head;
  while(current->next!=NULL){
    current=current->next;
  }
  current->next=toadd;
}

//needs to return the last element which in a stack is the top
node* peek(node* &head){
  node*current=head;
  //traverse until you reach the end 
  while(current->next!=NULL){
    current=current->next;
  }
  //return the last node
  return current;
}
