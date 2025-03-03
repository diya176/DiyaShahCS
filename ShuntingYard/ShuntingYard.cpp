#include <iostream>
#include <cstring>
#include <cctype> // For isdigit()

using namespace std;

/*
This program simulates the shunting yard algorithm and then 
allows users to change the output to postfix, prefix, or infix notation
depending on the demands. It does this using stacks, queues, and 
binary expression trees. 
Author: Diya Shah
References: https://en.wikipedia.org/wiki/Shunting-yard_algorithm and https://en.wikipedia.org/wiki/Binary_expression_tree
Date: March 3rd 

*/


struct node {
    char data;
    node* next;
    node* right;
    node* left;
};

//the three functions below are used for the stack 
void push(node*& head, node* toadd); 
node* peek(node* head);
void pop(node*& head); // Pass by reference to modify head-- for most functions you will need &


//the next two are used for the queue 
void enqueue(node*& head, char input); 
void dequeue(node*& head); // Dequeue is NOT a double ended queue that is something different

//next two functions are for the actual shunting yard algorithm 
void shuntingYard(node*& head, char* output); 
int precedence(char operators);

//final four functions are for building the binary expression tree and printing it in different forms 
void buildTree(node*& head);
void prefix(node* head);// when operators are at the beginning 
void infix(node* head); //this is the input
void postfix(node* head); //where the operators are at the end

int main() {
  node* head = NULL; // Initialize head; will be used everywhere
  while (true){
    char input[101];
    cout<<"Please enter an expression using single digit numbers and the following operators: ( , ) , + , - , * , / , ^: ";
    //cin.ignore();
    cin.getline(input, 100, '\n');
    //cin.ignore();
    int length = strlen(input);
    //to strip input of spaces (should be one after every character)
    char output[101];
    int a = 0;
    //run through input and add non space characters to new output character array
    for (int i = 0; i < length; i++) {
      if (input[i] != ' ') {
	output[a] = input[i];
	a++;
      }
    }
    shuntingYard(head, output);
    buildTree(head);
    while (true){
      char ins[102];
      cout<<endl;
      cout<<endl;
      cout<<"Would you like to display this in POSTFIX, PREFIX, or INFIX notation? Or would you like to try a NEW function or QUIT?: ";
      cout<<endl;
      //cin.ignore();
      cin.getline(ins,100,'\n');//ins;
      //cin.ignore();
      //to see the infix notation
      if (strcmp(ins,"INFIX")==0){
	cout << "Infix: ";
	infix(head);
      }
      //to see the postfix notation
      else if (strcmp(ins,"POSTFIX")==0){
	cout << "Postfix: ";
	postfix(head);
      }
      //to see the prefix notation
      else if (strcmp(ins,"PREFIX")==0){
	cout << "Prefix: ";
	prefix(head);
      }
      else if (strcmp(ins,"NEW")==0){
	main();
      }
      else if (strcmp(ins,"QUIT")==0){
	exit(0);
      }
    }
  }

/*
    cout << endl;
    
    cout << endl;
    cout << "Prefix: ";
    prefix(head);
    cout << endl;
*/
    return 0;
}

///STACK STUFF for shunting yard algorithm

//add a node to the stack
void push(node*& head, node* toadd) {
  if (head == NULL) {
    head = toadd;
  }
  else {
    node* current = head;
    while (current->next != NULL) {
      current = current->next;
    }
    //add new node to the end
    current->next = toadd;
  }
}

//peek
node* peek(node* head) {
  node* current = head;
  //traverse through the whole list
  while (current != NULL && current->next != NULL) {
    current = current->next;
  }
  //return the last (top) node
  return current;
}

//pop node for stack
void pop(node*& head) {
  node* current = head;
  //if there is only a head
  if (current->next == NULL) {
    //set the head to null
    head = NULL;
    //then delete current
    delete current;
    return;
  }

    //keep going until the second to last one is reached
  while (current->next->next != NULL) {
    current = current->next;
  }
  //delete the last one
  delete current->next;
  //set the next value to null
  current->next = NULL;
}

//QUEUE stuff for shunting yard 
//adding new node to end
void enqueue(node*& head, char input) {
  node* newNode = new node();
  newNode->data = input;
  newNode->next = NULL;

  //if head is NULL, then the new node becomes the head
  if (head == NULL) {
    head = newNode;
  }
  else {
    node* current = head;
    //traverse through the list until we get to the end
    while (current->next != NULL) {
      current = current->next;
    }
    //add the new node to the end
    current->next = newNode;
  }
}
//only used for expression tree not shunting yard 
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

//precdence function for operators
int precedence(char operators) {
  if (operators == '+' || operators == '-') {
    return 1; //lowest precedence but + and - are same
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
}


//building the expression tree function
void buildTree(node*& head) {
  node* current = head;
  //same as what was done for shunting yard algorithm
  node* operandStack = NULL;
  while (current != NULL) {
    //if the current character is a digit (number)
    if (isdigit(current->data)) {
      //create a new node and push that onto the stack
      node* operandNode = new node();
      operandNode->data = current->data; // Store operand data (character)
      push(operandStack, operandNode); // Push operand onto operand stack
    }
    else {
      // It's an operator! Yay! :(
      node* operatorNode = new node();
      //set the operatorNode to whatever the current is
      operatorNode->data = current->data;
      // create the right and left nodes of the tree
      node* rightOperand = new node();
      //right operand is the peek
      rightOperand->data=peek(operandStack)->data;
      //the right of the right operand is the right of the peek
      rightOperand->right=peek(operandStack)->right;
      //and the left is the left of the peek
      rightOperand->left=peek(operandStack)->left;// Right operand (first popped)
      //cout<<rightOperand->data<<endl;
      //then set the operatorNode (the "head")'s right to the rightOperand
      operatorNode->right = rightOperand;
      //finally pop the operandStack
      pop(operandStack);
      //same thing for left now
      node* leftOperand = new node();
      leftOperand->data=peek(operandStack)->data;
      leftOperand->right=peek(operandStack)->right;
      leftOperand->left=peek(operandStack)->left;// Left operand (second popped)
      //cout<<leftOperand->data<<endl;
      operatorNode->left = leftOperand;
      pop(operandStack);
      // Set left operand
      //cout<<rightOperand->data<<endl;
      //cout<<leftOperand->data<<endl;
      // Set right operand
      // Push the operator node onto the operand stack
      push(operandStack, operatorNode);
    }
    // Move to the next element in the list
    dequeue(head);
    current = head;
  }
  head = peek(operandStack); // The final tree root---DONT FORGET THIS OR NOTHING WILL WORK
}

//this should look the same as input
//infix: infix(left), val, infix(right)
void infix(node* head) {
  if (head != NULL) {
    //call on left
    infix(head->left);
    //then the value
    cout << head->data << " ";
    //then call function on right
    infix(head->right);
  }
}

//output from the shunting yard algorithm 
//postfix: postfix(left), postfix(right), val
void postfix(node* head) {
  if (head != NULL) {
    //call on the left node first
    postfix(head->left);
    //then the right
    postfix(head->right);
    //and then print out head
    cout << head->data << " ";
  }
}

//flipped version of postfix
//prefix: val, prefix(left), prefix(right)
void prefix(node* head) {
  if (head != NULL) {
    //print the value
    cout << head->data << " ";
    //then call on left
    prefix(head->left);
    //and then call on right
    prefix(head->right);
  }
}
