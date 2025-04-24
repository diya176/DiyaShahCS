#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct node {
    int data;
    char color;
    node* left;
    node* right;
    node* parent;
};

/*
Red Black Tree implementation for insertion. Fixes violations and balances the tree.
Author: Diya Shah
Date: 4/10/25
Second Date: 4/24/2025 
*/




// Function declarations
node* insert(node*& root, int num);
void fixViolations(node*& root, node*& current);
void print(node* root, int space);
void rotateLeft(node*& x, node*& root);
void rotateRight(node*& x, node*& root);
bool search(node* root, int numToSearch);
void deleteNode(node*& root, int num);
void deleteHelper(node* root, node* node);
node* minimum(node* root);

int main() {
    node* root = NULL;
    int space = 0;
    node* current = NULL;
    int num;

    while (true) {
        char input[100];
        cout << "What would you like to do: add MANUALLY, from a FILE, SEARCH, PRINT, DELETE, or QUIT?" << endl;
        cin >> input;
        if (strcmp(input, "MANUALLY") == 0) {
            int numofreps = 0;
            cout << "How many numbers would you like to add: ";
            cin >> numofreps;
            for (int i = 0; i < numofreps; i++) {
                cout << "Please enter a number: ";
                cin >> num;
                current = insert(root, num);
                fixViolations(root, current);
                print(root, space);
                cout << endl;
            }
        } else if (strcmp(input, "DELETE") == 0) {
            cout<<"What number would you like to delete: ";
            int num;
            cin>>num;
            deleteNode(root, num);
            print(root, space);
        } else if (strcmp(input, "SEARCH") == 0) {
            cout << "What number would you like to search for: ";
            cin >> num;
            if (search(root, num)) {
                cout << "Found it: " << num << endl;
            } else {
                cout << "Not found: " << num << endl;
            }
        } else if (strcmp(input, "PRINT") == 0) {
            print(root, space);
        } else if (strcmp(input, "FILE") == 0) {
            char fileName[100];
            cout << "Please enter your file name including the extension: ";
            cin >> fileName;
            cin.ignore();
            ifstream f(fileName);
            while (f >> num) {
                current = insert(root, num);
                fixViolations(root, current);
            }
            f.close();
            print(root, space);
        } else if (strcmp(input, "QUIT") == 0) {
            exit(0);
        }
    }
}

// Search function: Finds a number in the tree
bool search(node* root, int numToSearch) {
    if (root == NULL) {
        return false;
    }
    if (numToSearch == root->data) {
        return true;
    }
    if (numToSearch < root->data) {
        return search(root->left, numToSearch);
    } else {
        return search(root->right, numToSearch);
    }
}

// Insert function: Inserts a node into the tree
node* insert(node*& root, int num) {
    node* current = new node();
    current->data = num;
    current->color = 'R';
    current->left = NULL;
    current->right = NULL;
    current->parent = NULL;

    if (root == NULL) {
        root = current;
        return root;
    }

    if (num < root->data) {
        if (root->left) {
            return insert(root->left, num);
        } else {
            root->left = current;
            current->parent = root;
            return current;
        }
    } else {
        if (root->right) {
            return insert(root->right, num);
        } else {
            root->right = current;
            current->parent = root;
            return current;
        }
    }
}

// Print function: Prints the tree
void print(node* root, int space) {
    if (root == NULL) {
        return;
    }
    int count = 5;
    space += count;
    print(root->right, space);
    cout << endl;
    for (int i = count; i < space; i++) {
        cout << " ";
    }
    if (root->color == 'R') {
        cout << root->data << "(R)" << endl;
    } else {
        cout << root->data << "(B)" << endl;
    }
    print(root->left, space);
}

// Helper function to find the minimum node
node* minimum(node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Fix violations in the red-black tree
void fixViolations(node*& root, node*& current) {
    node* parent = NULL;
    node* grandparent = NULL;
    node* uncle = NULL;
    while ((current != root) && (current->color != 'B') && (current->parent->color == 'R')) {
      parent = current->parent;
      grandparent = current->parent->parent;
      if (parent == grandparent->left) {
	uncle = grandparent->right;
	if (uncle && uncle->color == 'R') {
                grandparent->color = 'R';
                parent->color = 'B';
                uncle->color = 'B';
                current = grandparent;
            } else {
                if (current == parent->right) {
                    rotateLeft(parent, root);
                    current = parent;
                    parent = current->parent;
                }
                rotateRight(grandparent, root);
                parent->color = 'B';
                grandparent->color = 'R';
                current = parent;
            }
        } else {
            uncle = grandparent->left;
            if (uncle && uncle->color == 'R') {
                grandparent->color = 'R';
                parent->color = 'B';
                uncle->color = 'B';
                current = grandparent;
            } else {
                if (current == parent->left) {
                    rotateRight(parent, root);
                    current = parent;
                    parent = current->parent;
                }
                rotateLeft(grandparent, root);
                parent->color = 'B';
                grandparent->color = 'R';
                current = parent;
            }
        }
    }
    root->color = 'B';
}

// Left rotation function
void rotateLeft(node*& x, node*& root) {
    node* y = x->right;
    x->right = y->left;
    if (y->left) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == NULL) {
        root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

// Right rotation function
void rotateRight(node*& x, node*& root) {
    node* y = x->left;
    x->left = y->right;
    if (y->right) {
        y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == NULL) {
        root = y;
    } else if (x == x->parent->right) {
        x->parent->right = y;
    } else {
        x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
}

//whoa delete my my 
// Delete node from the tree
//logic taken from programiz website and geeks for geeks 
void deleteNode(node*& root, int value) {
    node* target = root;

    //while you have not found the target node (the one with the right value)  
    while (target && target->data != value) {
      if (value < target->data){
	target = target->left;
      }
      else{
	target = target->right;
      }
    }

    //you are good your number was not in the tree 
    if (!target){
      return; 

    }; // Node not found

    
    node* y = target;
    //apparently color matters 
    char yOriginalColor = y->color;
    node* x = NULL;
    node* xParent = NULL;

    // If node has two children, find successor and copy its value
    ///two child deletion taken from binary search tree with a color modification
    //i have no idea how to do predecessor 
    if (target->left && target->right) {
        y = minimum(target->right);
        yOriginalColor = y->color;
        target->data = y->data; // Replace value
        target = y; // Now delete the successor instead
    }

    //line taken from programiz 
    x = (target->left) ? target->left : target->right;
    xParent = target->parent;

    //if it exists (yay!) 
    if (x){
      x->parent = target->parent;
    }
    if (!target->parent){
      root = x;
    }
    else if (target == target->parent->left){
      target->parent->left = x;
    }
    else{
      target->parent->right = x;
    }
    //start of the cases
    //if the original color of y is black then we have more work to do 
    if (yOriginalColor == 'B') {
      //while the color is still black more manipulation needed 
        while (x != root && (!x || x->color == 'B')) {
            if (x == xParent->left) {
                node* sib = xParent->right;
                if (sib && sib->color == 'R') {
		  //similar to insertion -- need to left rotate because sibling is red 
                    sib->color = 'B';
                    xParent->color = 'R';
                    rotateLeft(xParent, root);
                    sib = xParent->right;
                }

                if ((!sib->left || sib->left->color == 'B') &&
                    (!sib->right || sib->right->color == 'B')) {
		  if (sib) {
		    sib->color = 'R';
		  }
                    x = xParent;
                    xParent = x->parent;
                }
		//otherwise right rotate 
		else {
                    if (!sib->right || sib->right->color == 'B') {
                        if (sib->left) sib->left->color = 'B';
                        sib->color = 'R';
                        rotateRight(sib, root);
                        sib = xParent->right;
                    }
                    sib->color = xParent->color;
                    xParent->color = 'B';
                    if (sib->right) sib->right->color = 'B';
                    rotateLeft(xParent, root);
                    break;
                }
            } else {
                node* sib = xParent->left;
                if (sib && sib->color == 'R') {
                    sib->color = 'B';
                    xParent->color = 'R';
                    rotateRight(xParent, root);
                    sib = xParent->left;
                }

                if ((!sib->left || sib->left->color == 'B') &&
                    (!sib->right || sib->right->color == 'B')) {
                    if (sib) sib->color = 'R';
                    x = xParent;
                    xParent = x->parent;
                } else {
                    if (!sib->left || sib->left->color == 'B') {
                        if (sib->right) sib->right->color = 'B';
                        sib->color = 'R';
                        rotateLeft(sib, root);
                        sib = xParent->left;
                    }
                    sib->color = xParent->color;
                    xParent->color = 'B';
                    if (sib->left) sib->left->color = 'B';
                    rotateRight(xParent, root);
                    break;
                }
            }
        }
        if (x) {
	  x->color = 'B';
	}
    }

    //if not then just delete!! simple if it is red 
    delete target;
}
