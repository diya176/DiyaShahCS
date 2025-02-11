#include <iostream>
#include <cstring>
#include <iterator>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;



/*
  This program mimics a max heap using an array. It is visualized using tabs to show the children of the roots. From this heap you can delete all the nodes in the heap which effectively sorts the heap. This is done by repeatedly calling the delete root function. The delete root function deletes only the root or parent node. Finally, you can also manually add nodes or put numbers in a file and add that file. 
  
  Author: Diya Shah
  
  Date: 2/11/2025
 */


//function prototypes 
void add (int* heap, int &size, int numtoadd);
void heapify (int* heap, int index);
void print (int* heap,int pos, int depth, int size);
int removeAll(int* heap, int index);


int main(){
  //creating the heap and setting the size
  int heap[101];
  int size=0;

  //making everything in the heap a 0
  for(int i = 1; i < 101; i++) {
    heap[i] = 0;
  }
  //heapify(heap, size-1);

  /*
  int numtoadd=20;
  add(heap,size,numtoadd);
  print(heap,0,0,size);
  cout<<endl;
  cout<<endl;
  
  numtoadd=10;
  add(heap,size,numtoadd);
  print(heap,0,0,size);
  cout<<endl;
  cout<<endl;

  numtoadd=15;
  add(heap,size,numtoadd);
  print(heap,0,0,size);
  cout<<endl;
  cout<<endl;

  numtoadd=7;
  add(heap,size,numtoadd);
  print(heap,0,0,size);
  cout<<endl;
  cout<<endl;

  numtoadd=2;
  add(heap,size,numtoadd);
  print(heap,0,0,size);
  cout<<endl;
  cout<<endl;

  /*
  numtoadd=1;
  add(heap,size,numtoadd);
  print(heap,0,0,size);
  cout<<endl;
  cout<<endl;
  

  numtoadd=11;
  add(heap,size,numtoadd);
  print(heap,0,0,size);
  cout<<endl;
  cout<<endl;


  
  numtoadd=13;
  add(heap,size,numtoadd);
  print(heap,0,0,size);
  cout<<endl;
  cout<<endl;
 
  numtoadd=3;
  add(heap,size,numtoadd);
  print(heap,0,0,size);

  
  numtoadd=6;
  add(heap,size,numtoadd);
  print(heap,0,0,size);
  cout<<endl;
  cout<<endl;

  numtoadd=9;
  add(heap,size,numtoadd);
  print(heap,0,0,size);
  cout<<endl;
  cout<<endl;


  
  numtoadd=18;
  add(heap,size,numtoadd);
  print(heap,0,0,size);
  cout<<endl;
  cout<<endl;

  */


  //running the actual code
  while (true){
    int index=0;
    char input[200];
    cout<<"Would you like to add MANUALLY, from a FILE, delete the LARGEST node, delete ALL the nodes, or QUIT?"<<endl;
    cin>>input;
    //cout<<input<<endl;

    //manually adding a certain amount of numbers (needs to be less than 100 
    if (strcmp(input,"MANUALLY")==0){
      int numofreps=0;
      //figuring out how many numbers the user wants to add
      cout<<"How many numbers would you like to add: ";
      cin>>numofreps;

      //amount of numbers to be added needs to be less than 100
      if(numofreps>100){
	cout<<"You can only add less than 100 numbers"<<endl;
	;
      }
      //if it is less than 100
      else{
	//add the number and then print out the heap visualizer
	for (int i=0;i<numofreps;i++){
	  int numtoadd;
	  cout<<"Please enter a number: ";
	  cin>>numtoadd;
	  add(heap,size,numtoadd);
	  print(heap,0,0,size);
	  cout<<endl;
	  cout<<endl;
	}
      }
      
      //int numtoadd;
      //cin>>numtoadd;
      
    }
    //add the numbers in through the file 
    else if (strcmp(input,"FILE")==0){
      char fileName[100];
      //figure out the file name
      cout << "Please enter your file name including the extension: ";
      cin>>fileName;
      cin.ignore();
      ifstream f;
      f.open(fileName);
      int input=0;
      int index=0;
      //read the numbers in from the file and add them into the heap
      //keep changing (incrementing the index)
      while (f>>input){
	add(heap,size,input);
	index++;
      }
      f.close();
      print(heap,0,0,size);
    }
    //delete just the root (parent) of the heap 
    else if(strcmp(input,"LARGEST")==0){
      //cout<<"got here"<<endl;
      cout<<removeAll(heap,index)<<endl;
      //decrease the size by 1 because now we have 1 less value
      size--;
    }
    //delete everything in the heap 
    else if (strcmp(input,"ALL")==0){
      //keep calling the removeAll function until we have removed all the values
      while(heap[index] != 0) {
	cout<<removeAll(heap, index)<<endl;
      }
      //nothing in the heap now so set the size to 0
      size=0;
    }
    else if (strcmp(input, "QUIT")==0){
      exit(0);
    }

  }
  
  //removeAll(heap,size,size);
  //removeAll(heap,size,size);
  //print(heap,0,0,size);
}

//add the value into the heap
//increase the size by 1
//then heapify it (or sort it in normal words)
void add (int* heap, int &size, int numtoadd){
  heap[size]=numtoadd;
  size++;
  heapify(heap,size-1);
}

//sort the heap to make sure that all the nodes are in the correct order
void heapify (int* heap, int index){
  //parent is the index -1 /2
  int parent=(index-1)/2;
  if(index==0){
    return;
  }
  if(heap[parent]>heap[index]){
    return;
  }
  else{
    //might be parent index;
    //swap if they are not in the correct order
    swap(heap[parent],heap[index]);
    heapify(heap,parent);
  }
  
}

//way to visualize the heap using tabs 
//Taken from back board in CS classroom 
void print (int* heap,int pos, int depth, int size){
  //need to add 1 because I am starting from 0 and not 1 
  if(pos*2+2<size){
    print(heap,pos*2+2, depth+1, size);
  }
  for (int a=0;a<depth;a++){
    cout<<'\t';
  }
  cout<<heap[pos]<<endl;
  if(pos*2+1<size){
    print(heap,pos*2+1, depth+1, size);
  }
}

//same function for both removing the root and removing everything 
int removeAll(int* heap, int index) {

  //returning the root 
  int temps=heap[0];
  //cout<<heap[0]<<endl;
  int sizes=0;
  //figure out the size of the heap
  while(heap[sizes]!=0){
    sizes++;
  }
  //so you dont run of the end of the array
  sizes=sizes-1;
  int rightNode = index;

  //int temps=heap[0];
  //cout<<size<<endl;
  heap[index] = heap[sizes];
  heap[sizes] = 0;
  
  //if current node is smaller than right and left
  while((heap[rightNode] < heap[rightNode * 2+1]) || (heap[rightNode] < heap[rightNode * 2 + 2])) {
    //swap current with larger of left/right
    //current is now the one you swapped with
    //cout<<"Current Index: "<<rightNode<<endl;
    //cout<<"Left Node Index: "<<rightNode*2+1<<endl;
    //cout<<"Current Node Value: "<<heap[rightNode]<<endl;
    //cout<<"Left Node Value: "<<heap[rightNode*2+1]<<endl;
    //cout<<"Right Node Value: "<<heap[rightNode*2+2]<<endl;
    //cout<<"while loop"<<endl;
    //if left is bigger than right, replace root with left
    if (heap[rightNode * 2+1] > heap[rightNode * 2 +2]) {
      //cout<<"got herre?"<<endl;
      int temp = heap[rightNode];
      heap[rightNode] = heap[rightNode*2+1];
      heap[rightNode*2+1] = temp;
      rightNode = rightNode*2+1;
    }

    //same thing but just for right so everything is +1
    else if (heap[rightNode * 2 +2] > heap[rightNode *2+1]) {
      //cout<<"got maybeee?"<<endl;
      int temp = heap[rightNode];
      heap[rightNode] = heap[rightNode*2+2];
      heap[rightNode*2+2] = temp; 
      rightNode = rightNode*2+2;
    }
  }
  //heapify(heap,heap[0]);
  //dont have to print heap everytime but can
  //cout<<endl;
  //cout<<endl;
  //cout<<endl;
  //cout<<endl;

  //print(heap,0,0,sizes);

  //temps=heap[0];
  return temps; 
  //print(heap,0,0,size);
}

