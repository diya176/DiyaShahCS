#include <iostream>
#include <cstring>
#include <cctype> // For isdigit()

using namespace std;

struct node
{
  char data;
  node * next;
  node* right;
  node* left; 
};


struct treeNode
{
  char data;
  node* right;
  node* left; 
};


void push(node* &head, node* toadd); // Using pass-by-reference for the pointer manipulation
node* peek(node* head);
void pop(node* &head); // Pass by reference to modify head
void enqueue(node* &head, char input); // Pass by reference
void dequeue(node* &head); // Pass by reference
void shuntingYard(node* &head, char* output); // Pass by reference
int precedence (char operators);
void buildTree(node*&head); 
void prefix(node*head);

int main(){
  node* head = NULL; // Initialize head to nullptr
  
  char input[101];
  cin.getline(input, 100, '\n');

  int length = strlen(input);

  char output[101];
  int a = 0;
  for (int i = 0; i < length; i++) {
    if (input[i] != ' ') {
      output[a] = input[i];
      a++;
    }
  }

  shuntingYard(head, output);

  buildTree(head);

  prefix(head);
  return 0;
}

///STACK STUFF for shunting yard algorithm

void push(node*& head, node* toadd) { // Pass by reference to modify the head pointer
  if (head == NULL) {
    head = toadd;
  } 
  else {
    node* current = head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = toadd;
  }
}

/*
node* peek(node* head) {
  node* current = head;
  while (current->next != NULL) {
    current = current->next;
  }
  return current;
}
*/

node* peek(node* head) {
  node* current = head;
  while (current!=NULL && current->next != NULL) {
    current = current->next;
  }
  return current;
}


void pop(node*& head) { 
  node* current = head;
  if (current->next == NULL) {
    head = NULL;
    delete current;
    return;
  }

  while (current->next->next != NULL) {
    current = current->next;
  }
  delete current->next;
  current->next = NULL;
}

void enqueue(node*& head, char input) { 
  node* newNode = new node();
  newNode->data = input;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    node* current = head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = newNode;
  }
}


void dequeue(node* &head) {
  node*current=head;
  if (current->next== NULL) {
    head = NULL;
    delete current;
  }
  else if (current->next!= NULL) {
    node* temp = current->next;
    head = NULL;
    delete current;
    head = temp;
  }
}

int precedence(char operators) {
  if (operators == '+' || operators == '-') {
    return 1; // ent->dataent->datalowest precedence but + and - are same
  }
  else if (operators == '*' || operators == '/') {
    return 2; // Higher precedence
  }
  else if (operators=='^'){
    return 3; //most important but also right associate not left
  }
  return 0;
}




void shuntingYard(node*& head, char* output) {
  cout << "Input expression: " << output << endl;
  int length = strlen(output);
  //this is the operator stack -- anytime the queue isn't being used this should be used as the stack head
  node* operatorStack = NULL;
  //for the number of characters (including numbers and operators)
  for (int i = 0; i < length; i++) {
    //if it is a digit
    if (isdigit(output[i])) {
      //just add it right to the output queue
      enqueue(head, output[i]);
    }
    //if it is an open parentheses
    else if (output[i] == '(') {
      node* temp = new node();
      temp->data = '(';
      temp->next = NULL;
      temp->right=NULL;
      temp->left=NULL; 
      //add it to the operator stack
      push(operatorStack, temp);
    }
    //if it is a closed parentheses
    else if (output[i] == ')') {
      //keep popping out of the stack and adding to output queue until you find the open one
      while (peek(operatorStack) && peek(operatorStack)->data != '(') {
	//keep adding to the output queue
	enqueue(head, peek(operatorStack)->data); // Add operator to output
	//if you are adding to the output queue you need to remove it from the stack
	pop(operatorStack);
      }
      //if you find the open parentheses
      if (peek(operatorStack) && peek(operatorStack)->data == '(') {
	//pop it off the stack BUT DO NOT add it to the queue because you don't want parentheses
	pop(operatorStack); // Remove '(' from stack
      }
    }
    else if (!isdigit(output[i]) && output[i] != '(' && output[i] != ')') {
      //^ IS RIGHT SO MAKE SURE NOT TO INCLUDE IT :((((
      while (peek(operatorStack) && precedence(peek(operatorStack)->data) >= precedence(output[i]) &&output[i]!='^') {
	enqueue(head, peek(operatorStack)->data); // Add operator to output
	pop(operatorStack);
      }
      node* temp = new node();
      temp->data = output[i];
      temp->next = NULL;
      temp->right=NULL;
      temp->left=NULL; 
      push(operatorStack, temp);
    }
  }
  while (operatorStack != NULL) {
    // Add the rest of the operators to output to then show the postfix thing
    enqueue(head, peek(operatorStack)->data);
    pop(operatorStack);
  }
  
  cout << "Postfix expression: ";
  node* current = head;
  while (current != NULL) {
    cout << current->data << " ";
    current = current->next;
  }
  cout << endl;
}


void buildTree(node*&head){
  node* current=head;
  while(current->next!=NULL){
    //cout<<"got here?"<<endl;
    if(isdigit(current->data)){
      cout<<"got here?"<<endl;
      node* newNode=new node();
      newNode->data=current->data;
      push(head, newNode); 
    }
    else if(!isdigit(current->data)){
      cout<<"stuck here?"<<endl; 
      node*currentnow=new node();
      currentnow->data=current->data; 
      node* rightNode=new node();
      rightNode->right=peek(current)->right;
      //cout<<peek(current)->right->data<<endl; 
      rightNode->left=peek(head)->left;
      currentnow->right=rightNode;
      pop(head);

      
      node* leftNode=new node(); 
      leftNode->right=peek(head)->right;
      leftNode->left=peek(head)->left;
      currentnow->left=leftNode;
      pop(head);
      
      push(head, currentnow);
    }
    current=current->next;
    dequeue(head); 
    //current=current->next;
    
    
  }
}


void prefix(node* head) {
  //print numbers after operations
  //node*current=head;
  if (head != NULL) {
    cout<<"got here"<<endl;
    cout << head->data << endl;
    prefix(head->left);
    prefix(head->right);
  }
}
