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
void search (tree* fullTree, int numToFind); 


int main()
{
    tree* fullTree=new tree();
    fullTree->data=-1; 
    add(fullTree,6);
    add(fullTree,2);
    add(fullTree,3);
    add(fullTree,4);
    add(fullTree,5);
    add(fullTree,1);
    add(fullTree,7);
    add(fullTree,8);
    add(fullTree,9);

    //printTree(fullTree,0);
    search(fullTree,9);
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

void search (tree* fullTree, int numToSearch){
  while(fullTree!=NULL){
    if(numToSearch==fullTree->data){
      cout<<"Got here: "<<fullTree->data<<endl;
      exit(0);
    }
    else if (fullTree->left==NULL){
      cout<<fullTree->data<<endl;
      fullTree=fullTree->left;
    }
    else{
      fullTree=fullTree->right;
    }
  }
}
