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
void pop (node*&head);
void enqueue(node*&head, char input);
void dequeue(node* &head);
void shuntingYard(node*&head, char* output); 

int main(){
  node* head=new node();

  char input[101];
  cin.getline(input,100,'\n');
  //cout<<input<<endl;

  int length=strlen(input);
  //cout<<length<<endl;

  char output[101];
  int a=0;
  for (int i=0;i<length;i++){
    //cout<<input[i]<<endl;
    if(input[i]==' '){
      ;
    }
    else{
      output[a]=input[i];
      a++;
    }
  }

  shuntingYard(head,output);

  //cout<<peek(head)->data<<endl;
  /*
  node*toadd=new node();
  toadd->data='D';
  push(head, toadd);

  node*toadde=new node();
  toadde->data='I';
  push(head, toadde);


  node*toadder=new node();
  toadder->data='Y';
  push(head, toadder);


  node*toadds=new node();
  toadds->data='A';
  push(head, toadds);

  */

  

  /*
  cout<<"Got it"<<endl;
  cout<<peek(head)->data<<endl;

  
  pop(head);
  cout<<head->data<<endl;
  cout<<peek(head)->data<<endl;


  pop(head);
  cout<<head->data<<endl;
  cout<<peek(head)->data<<endl;

  //enqueue(head,'L');
  dequeue(head);
  cout<<head->data<<endl;
  cout<<peek(head)->data<<endl;
  //cout<<head->data<<endl;
  */
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

void pop(node*&head){
  node* current=head;
  if(current->next==NULL){
    head=NULL;
    delete current;
  }
  while(current->next->next!=NULL){
    current=current->next; 
  }
  delete current->next;
  current->next=NULL; 
  
}

void enqueue(node*&head, char input){
  if(head==NULL){
    head=new node();
    head->data=input;
  }

  node*current=head;

  //add new node to the end 
  while (current->next!=NULL){
    current=current->next; 
  }
  node*temp=new node();
  temp->data=input;
  current->next=temp; 
}

void dequeue(node* &head) {
  node*current=head;
  if (current->next== NULL) {
    head = NULL;
    delete current;
  }

  current=head;
  if (current->next!= NULL) {
    node* temp = current->next;
    head = NULL;
    delete current;
    head = temp;
  }
}

void shuntingYard(node*&head, char* output){
  cout<<output<<endl;
  int length=strlen(output);
  //cout<<length<<endl;
  int len=0;
  while(len<length){
    if(isdigit(output[len])){
      enqueue(head, output[len]);
    }
    len++;
  }
}
