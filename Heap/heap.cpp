#include <iostream>
#include <cstring>

using namespace std;

void add (int* heap, int &size, int numtoadd);
void heapify (int* heap, int index);
void print (int* heap,int pos, int depth, int size);
int removeAll(int* heap, int index);


int main(){
  int heap[100];
  int size=0;

  for(int i = 1; i < 100; i++) {
    heap[i] = 0;
  }
  //heapify(heap, size-1);
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
  */

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


  int index=0;
  char input[200];
  cin>>input;
  cout<<input<<endl;
  
  if(strcmp(input,"Largest")==0){
    cout<<"got here"<<endl;
    cout<<removeAll(heap,index)<<endl;
  }
  
  else if (strcmp(input,"All")==0){
    while(heap[index] != 0) {
      cout<<removeAll(heap, index)<<endl;
    }
  }
  //removeAll(heap,size,size);
  //removeAll(heap,size,size);
  //print(heap,0,0,size);
}

void add (int* heap, int &size, int numtoadd){
  heap[size]=numtoadd;
  size++;
  heapify(heap,size-1);
}

void heapify (int* heap, int index){
  int parent=(index-1)/2;
  if(index==0){
    return;
  }
  if(heap[parent]>heap[index]){
    return;
  }
  else{
    //might be parent index;
    swap(heap[parent],heap[index]);
    heapify(heap,parent);
  }
  
}


void print (int* heap,int pos, int depth, int size){
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


int removeAll(int* heap, int index) {

  int temps=heap[0];
  int size=0;
  while(heap[size]!=0){
    size++;
  }
  //so you dont run of the end of the array
  size=size-1;
  int rightNode = index;

  //int temps=heap[0];
  //cout<<size<<endl;
  heap[index] = heap[size];
  heap[size] = 0;
  
  //if current node is smaller than right and left
  while((heap[rightNode] < heap[rightNode * 2]) || (heap[rightNode] < heap[rightNode * 2 + 1])) {
    //swap current with larger of left/right
    //current is now the one you swapped with
    //cout<<heap[rightNode]<<endl;
    //cout<<heap[rightNode*2]<<endl;
    //cout<<heap[rightNode*2+1]<<endl;
    //cout<<"while loop"<<endl;
    //if left is bigger than right, replace root with left
    if (heap[rightNode * 2] > heap[rightNode * 2 +1]) {
      //cout<<"got herre?"<<endl;
      int temp = heap[rightNode];
      heap[rightNode] = heap[rightNode*2];
      heap[rightNode*2] = temp;
      rightNode = rightNode*2;
    }

    //same thing but just for right so everything is +1
    else if (heap[rightNode * 2 +1] > heap[rightNode *2]) {
      //cout<<"got maybeee?"<<endl;
      int temp = heap[rightNode];
      heap[rightNode] = heap[rightNode*2+1];
      heap[rightNode*2+1] = temp; 
      rightNode = rightNode*2+1;
    }
  }
  //dont have to print heap everytime but can
  //print(heap,0,0,size);
  return temps; 
  //print(heap,0,0,size);
}
