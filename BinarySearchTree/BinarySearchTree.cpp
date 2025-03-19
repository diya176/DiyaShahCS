#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

/*

  This program simulates a binary search tree. With this tree you can add nodes, delete particular numbers, print the tree, and check if a number is in the tree. 
  Author: Diya Shah
  Date: 3/19/2025

 */


//tree structure with data, tree right, and tree left as parameters
struct tree{
  int data;
  tree* right;
  tree* left;
};

//function prototypes
//there is an add, print, search, and delete function
void add(tree* fullTree, int toAdd);
void printTree(tree* fullTree, int depth);
bool search (tree* fullTree, int numToFind); 
tree* deletes(tree* fullTree, int toDelete);


int main()
{
  //make the new tree and set the root node to -1 to show that there is nothing in the tree
  tree* fullTree=new tree();
  fullTree->data=-1; 
  while (true){
    char input[100];
    cout<<"What would you like to do: add MANUALLY, from a FILE, PRINT, SEARCH, DELETE, or QUIT?"<<endl;
    cin>>input;
    if(strcmp(input,"MANUALLY")==0){
      int numofreps=0;
      cout<<"How many numbers would you like to add: ";
      cin>>numofreps;
      for (int i=0;i<numofreps;i++){
	int numtoadd;
	cout<<"Please enter a number: ";
	cin>>numtoadd;
	add(fullTree,numtoadd);
        printTree(fullTree,0);
        cout<<endl;
	cout<<endl;
      }
    }
    else if (strcmp(input, "DELETE")==0){
      int numToDelete;
      cout<<"What number would you like to delete: ";
      cin>>numToDelete;
      deletes(fullTree,numToDelete);
    }
    else if (strcmp(input, "PRINT")==0){
      printTree(fullTree,0);
    }
    else if (strcmp(input, "FILE")==0){
      char fileName[100];
      //figure out the file name
      cout << "Please enter your file name including the extension: ";
      cin>>fileName;
      cin.ignore();
      ifstream f;
      f.open(fileName);
      int input=0;
      //read the numbers in from the file and add them into the tree
      //keep changing (incrementing the index)
      while (f>>input){
	    add(fullTree,input);
      }
      f.close();
      printTree(fullTree,0);
    }
    else if (strcmp(input, "SEARCH")==0){
      int num;
      cout<<"What number would you like to search up: ";
      cin>>num;
      if(search(fullTree,num)==true){
	cout<<"Found it: " <<num<<endl;
      }
      else{
	cout<<"Not found it: "<<num<<endl;
      }
    }
    else if (strcmp(input,"QUIT")==0){
      exit(0);
    }
  }

/*
  add(fullTree,6);
  add(fullTree,2);
  add(fullTree,3);
  add(fullTree,4);
  add(fullTree,5);
  add(fullTree,1);
  add(fullTree,7);
  add(fullTree,8);
  add(fullTree,9);

  printTree(fullTree,0);
  int num=4;
  if(search(fullTree,num)==true){
    cout<<"Found it: " <<num<<endl;
  }
  else{
    cout<<"Not found it: "<<num<<endl;
  }
  deletes(fullTree,3);
  printTree(fullTree,0);
*/
}

//adding a node to the tree
void add(tree* fullTree, int toAdd){
  //if there is nothing in the tree
  if(fullTree->data==-1){
    //make the new node the root
    fullTree->data=toAdd;
    return;
  }
  //or sort it into the correct spot
  //need to check for left and right positions as opposed to just parent!!!!
  else{
    if(toAdd<fullTree->data && fullTree->left){
      fullTree=fullTree->left;
      add(fullTree, toAdd);
    }
    else if(toAdd<fullTree->data && !fullTree->left){
      tree* newNode=new tree();
      newNode->data=toAdd;
      fullTree->left=newNode;
      return;
    }
    if(toAdd>fullTree->data && fullTree->right){
      fullTree=fullTree->right;
      add(fullTree, toAdd);
    }
    else if(toAdd>fullTree->data && !fullTree->right){
      tree* newNode=new tree();
      newNode->data=toAdd;
      fullTree->right=newNode;
      return;
    }

  }

}

//print the tree
//adapted from the version from heap just don't need the array elements 
void printTree(tree* fullTree, int depth){
  if(fullTree->right){
    //cout<<fullTree->right->data<<endl;
    printTree(fullTree->right, depth+1);
  }
  for(int i = 0; i < depth; i++) {
    cout << "\t";
  }
  cout << fullTree->data << endl;
  if(fullTree->left){
    //cout<<fullTree->left->data<<endl;
    printTree(fullTree->left, depth+1);
  }  
}


//delete a particular number from the tree
tree* deletes(tree* fullTree, int toDelete){
  //if there is nothing in the tree, just return nothing
  if (fullTree == NULL){
    return fullTree;
  }
  if (fullTree->data > toDelete){
    fullTree->left = deletes(fullTree->left, toDelete);
  }
  else if (fullTree->data < toDelete){
    fullTree->right = deletes(fullTree->right, toDelete);
  }
  // WE FOUND IT! So, now we have to delete it
  else {
    //THIS IS NOT TRIVIAL; make sure the three cases - no children, one child, two children - are covered, including deleting the root
    // CASE FOR NO CHILDREN
    if (fullTree->left == NULL) {
      tree* temp = fullTree->right;
      delete fullTree;
      return temp;
    }
    //CASE FOR ONE CHILD
    if (fullTree->right == NULL) {
      tree* temp = fullTree->left;
      delete fullTree;
      return temp;
    }
    // When THERE ARE TWO CHILDREN
    //want to find the smallest- so left side needs to be traversed
    tree*start=fullTree;
    while(start->left!=NULL){
      start=start->left;
    }
    tree*smallestNext=start;
    fullTree->data=smallestNext->data;
    fullTree->right=deletes(fullTree->right,smallestNext->data);
  }
  return fullTree;
}


//search to see if a particular number is in the tree
bool search (tree* fullTree, int numToSearch){
  //if the number we are searching for is the root YAY!
  if(numToSearch==fullTree->data){
    return true;
    exit(0);
  }
  //if it is not check if it is less than or greater than the root
  else if (numToSearch<fullTree->data){
    //if it is less than the root keep going to the left 
    if(!fullTree->left){
      //cout<<fullTree->data<<endl;
    }
    //recursively keep going until you get to the number or you go through all the nodes and it is not there
    else{
      search(fullTree->left,numToSearch);
    }
  }
  //if it is greater go down the right path
  else if (numToSearch>fullTree->data){
    if(!fullTree->right){
      //cout<<fullTree->data<<endl;
    }
    else{
      search(fullTree->right,numToSearch);
    }
  }
  else{
    return false;
  }
  //return false;
}
