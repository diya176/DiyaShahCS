#include <iostream>
#include <cstring>

using namespace std;

void add (int* heap, int &size, int numtoadd);
void heapify (int* heap, int index);
void print (int* heap,int pos, int depth, int size);
void removeAll(int* heap, int index,int&size);


int main(){
  int heap[10]={20,10,15,7,2,11,13};
  int size=7;
  int numtoadd=5;
  add(heap, size, numtoadd);
  numtoadd=2;
  add(heap, size, numtoadd);
  print (heap,0,0,size);
  removeAll(heap,0,size);
  print(heap,0,0,size);
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


void removeAll(int* heap, int index, int& size) {
    // Base case: If the heap is empty, stop recursion
    if (size == 0) {
        return;
    }

    // Move the last element to the current index (root) and reduce size
    heap[index] = heap[size - 1];
    size--;

    // Recursive call to heapify and restore heap property
    int parent = index;
    int leftChild = 2 * parent + 1;
    int rightChild = 2 * parent + 2;
    int smallest = parent;

    //  if leftchild is less than size so we aren't at the end of the tree
    // and the leftchild of head is less than the smallest one (so
    //  15
    //20
    //   13
    if (leftChild < size && heap[leftChild] < heap[smallest]) {
        smallest = leftChild;
    }

    // Compare with right child
    if (rightChild < size && heap[rightChild] < heap[smallest]) {
        smallest = rightChild;
    }

    // If the smallest is not the parent, swap and recursively heapify
    if (smallest != parent) {
        swap(heap[parent], heap[smallest]);
        removeAll(heap, smallest, size);  // Recursively fix the heap
    }
}
