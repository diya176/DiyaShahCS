#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;



struct node{
  int data;
  char color;
  node* left;
  node*right;
  node*parent;
};

/*
Red Black Tree implementation for insertion. Fixes violations and balances the tree.
Author: Diya Shah
Date: 4/10/25

*/




node* insert(node* &root, int &num);
void fixViolations(node* &root,node* &current); 
void print(node* root, int space); 
void rotateLeft(node * &x, node* &root);
void rotateRight(node* &x, node* &root);

int main(){
    
    node* root=NULL;
    int space=0;
    node* current=NULL;
    int num;
    //the while loop was basically taken from my binary search tree :)
    while (true){
        char input[100];
        cout<<"What would you like to do: add MANUALLY, from a FILE, PRINT, DELETE, or QUIT?"<<endl;
        cin>>input;
        if(strcmp(input,"MANUALLY")==0){
          int numofreps=0;
          cout<<"How many numbers would you like to add: ";
          cin>>numofreps;
          for (int i=0;i<numofreps;i++){
              cout<<"Please enter a number: ";
              cin>>num;
              current=insert(root,num);
              fixViolations(root,current); 
              print(root,space);
              cout<<endl;
              cout<<endl;
          }
        }
        else if (strcmp(input, "DELETE")==0){
          cout<<"ya....so this does not work yet :) check back in later"<<endl;
        }
        else if (strcmp(input, "PRINT")==0){
          print(root,space);
        }
        else if (strcmp(input, "FILE")==0){
          char fileName[100];
          //figure out the file name
          cout << "Please enter your file name including the extension: ";
          cin>>fileName;
          cin.ignore();
          ifstream f;
          f.open(fileName);
          //read the numbers in from the file and add them into the tree
          //keep changing (incrementing the index)
          while (f>>num){
              current=insert(root,num);
              fixViolations(root,current); 
              
          }
          f.close();
          print(root,space);
        }
        else if (strcmp(input,"QUIT")==0){
	  exit(0);
	}
    }
    /*
    current=insert (root, num);
    fixViolations(root,current); 
    //print(root, space); 
    num=11;
    current=insert (root, num);
    fixViolations(root,current); 
   // print(root, space);
    num=21;
    current=insert (root, num);
    fixViolations(root,current); 
   // print(root, space);
    num=15;
    current=insert (root, num);
    fixViolations(root,current); 
   // print(root, space);
    num=31;
    current=insert (root, num);
    fixViolations(root,current); 
   // print(root, space);
    num=33;
    current=insert (root, num);
    fixViolations(root,current);
    // print(root, space);
    num=41;
    current=insert (root, num);
    fixViolations(root,current); 
  //  print(root, space);
    num=61;
    current=insert (root, num);
    fixViolations(root,current); 
  //  print(root, space);
    num=53;
    current=insert (root, num);
    fixViolations(root,current); 
    print(root, space);
    */

}

//simply inserts the node into the right spot -- same as binary search tree
//always insert a red colored node
node* insert (node* &root, int &num){
    //create a new node with all the necessary stuff 
    node* current=new node();
    current->data=num;
    current->color='R';
    current->left=NULL;
    current->right=NULL;
    current->parent=NULL;
    
    //if there is no root
    if(root==NULL){
        //make the new node root
        root=current;
        //return and we are done!!
        return root;
    }
    else{
        //keep going!!
        if(num<root->data&&root->left){
            node*temp=root->left;
            return insert(temp,num);
            
        }
        //if it is at the base of the tree return
        else if(num<root->data&&!root->left){
            root->left=current;
            current->parent=root;
            //we are good and we can return 
            return current;
        }
        if(num>root->data&&root->right){
            node*temp=root->right;
            //keep going recursively 
            return insert(temp,num);
            
        }
        //if it is at the base of the tree return
        else if(num>root->data&&!root->right){
            root->right=current;
            current->parent=root;
            //we are good and we can return
            return current;
        }
        
        
    }
    return NULL; //theroretically should never happen?
    
}

//to print the RBT
void print(node* root, int space) {
    //base case
  if (root == NULL) {
    return;
  }
  int count = 5;
  space += count;
  print(root->right, space);
  cout << endl;
  for(int i = count; i < space; i++) {
    cout << " ";
  }
  /*
  if(root->parent != NULL) {
    cout << root->parent->data << ", ";
  }
  */
  //if the root is red or black add the color to the end just for debugging and checking purposes
  if(root->color=='R'){
      cout << root->data << "(R)" << endl;
  }
  if(root->color=='B'){
      cout << root->data << "(B)" << endl;
  }
  //recurisvely call print
  print(root->left, space);
}

//oh my! this is to fix all the violations to the cases 
//cases were based on the video on canvas and https://www.programiz.com/dsa/red-black-tree
void fixViolations(node* &root,node* &current){
    //set the family lineage all to NULL
    node* parent = NULL;
    node* grandparent = NULL;
    node* uncle = NULL;
    //while there are still violations...
    while((current != root) && (current->color != 'B') && (current->parent->color == 'R')) {
        parent = current->parent;
        grandparent = current->parent->parent;
        if(parent == grandparent->left){ //if parent is left child
            uncle = grandparent->right;
            //"Case-I: If the color of the right child of gP of z is RED, set the color of both the children of gP as BLACK and the color of gP as RED.Assign gP to newNode."
            if(uncle && uncle->color == 'R'){
                grandparent->color = 'R';
	            parent->color = 'B';
	            uncle->color = 'B';
	            current = grandparent;
            }
            //"Case-II: Else if current is the right child of p then, assign p to current. Left-Rotate current."
            else {
                if (current == parent->right) {
                    rotateLeft(parent, root);
                    current = parent;
                    parent = current->parent;
                }
                rotateRight(grandparent, root);
                //swap(parent->color, grandparent->color);
                parent->color = 'B';
                grandparent->color = 'R';
                current = parent;
            }
            
        }
        
        //Else, do the following:
        //If the color of the left child of gP of z is RED, set the color of both the children of gP as BLACK and the color of gP as RED.
        //Assign gP to newNode.
        //Else if newNode is the left child of p then, assign p to newNode and Right-Rotate newNode.
        //Set color of p as BLACK and color of gP as RED.
        else {
            uncle = grandparent->left;
            if((uncle != nullptr) && (uncle->color == 'R')) {
                grandparent->color = 'R';
                parent->color = 'B';
                uncle->color = 'B';
                current = grandparent;
            }
            else {
                if (current == parent->left) {
                    rotateRight(parent, root);
                    current = parent;
                    parent = current->parent;
                }
                rotateLeft(grandparent, root);
                //swap(parent->color, grandparent->color);
                parent->color = 'B';
                grandparent->color = 'R';
                current = parent;
            }
        }
    }
    //Rule #0: Root always has to be inserted as red and changed to black
    //this is the last violation before our tree is all balanced
    root->color = 'B';
}


//logic heavily based on: https://www.programiz.com/dsa/red-black-tree 
//phrases in "" are pieces of the algorithm taken from above link and then translated into actual code :)
//this goes for rotateRight too
void rotateLeft(node* &x, node* &root) {
  node* y = x->right;
  x->right = y->left;

    //"If y has a left subtree, assign x as the parent of the left subtree of y"
  if(y->left) {
    y->left->parent = x;
  }
  y->parent = x->parent;
  //"If the parent of x is NULL, make y as the root of the tree"
  //if x->parent==NULL, make root=y; 
  if(x->parent==NULL) {
    root = y;
  }
  //"Else if x is the left child of p, make y as the left child of p."
  //if x==x->parent->left -- make y the parent left
  else if(x == x->parent->left) {
    x->parent->left = y;
  }
  //"Else assign y as the right child of p"
  //right child of p of x
  else {
    x->parent->right = y;
  }
  y->left = x;
  //"Make y as the parent of x."
  //x's parent should point to y 
  x->parent = y;
  
}

void rotateRight(node * &x, node* &root) {
  node* y = x->left;
  x->left = y->right;

  //"If x has a right subtree, assign y as the parent of the right subtree of x."    
  if(y->right) {
    y->right->parent = x;
  }
  y->parent = x->parent;
  //If the parent of y is NULL, make x as the root of the tree.

  if(x->parent==NULL) {
    root = y;
  }
  //"Else if y is the right child of its parent p, make x as the right child of p."
  else if(x == x->parent->right) {
    x->parent->right = y;
  }
  //"Else assign x as the left child of p."
  //of y
  else {
    x->parent->left = y;
  }
  y->right = x;
  //"Make x as the parent of y."
  x->parent = y;
}
