#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;


struct tree{
  int data;
  tree* right;
  tree* left;
};

void add(tree* fullTree, int toAdd);
void printTree(tree* fullTree, int depth);
bool search (tree* fullTree, int numToFind); 
tree* deletes(tree* fullTree, int toDelete);


int main()
{
  tree* fullTree=new tree();
  fullTree->data=-1; 

  char input [100];
  cout<<"What would you like to do: ADD, PRINT, SEARCH, DELETE?" <<endl;
  cin>>input;
  while (true){
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
    else if (strcmp(input, "PRINT")==0){
      printTree(fullTree,0);
    }
    else if (strcmp(input, "SEARCH")==0){
      int num;
      cout<<"What number would you like to search up: ";
      cin>>num;
      if(search(fullTree,num)==true){
	cout<<"Found it: " <<num<<endl;
	;
      }
      else{
	cout<<"Not found it: "<<num<<endl;
	break;
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

void add(tree* fullTree, int toAdd){
  if(fullTree->data==-1){
    fullTree->data=toAdd;
    return;
  }
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



tree* deletes(tree* fullTree, int toDelete){
  // Base case
  if (fullTree == NULL){
    return fullTree;
  }
  // If key to be searched is in a subtree
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



bool search (tree* fullTree, int numToSearch){
  if(numToSearch==fullTree->data){
    return true;
    exit(0);
  }
  else if (numToSearch<fullTree->data){
    if(!fullTree->left){
      cout<<fullTree->data<<endl;
    }
    else{
      search(fullTree->left,numToSearch);
    }
  }
  else if (numToSearch>fullTree->data){
    if(!fullTree->right){
      cout<<fullTree->data<<endl;
    }
    else{
      search(fullTree->right,numToSearch);
    }
  }
  else{
    return false;
  }
}
