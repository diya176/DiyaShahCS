#include <iostream>
#include <cstring>

using namespace std;





int getIndex(char* index,int &vertexCount,int adjMatrix[20][20],char* vertices) {
    //run through table to see if index # is there 
    for (int i = 0; i < vertexCount; i++) {
        if (vertices[i] == index){
            //return the index number
            return i;
        }
    }
    //boo not there -- what are you doing?
    return -1;
}


// Add a new vertex
void addVertex(char label,int &vertexCount,  int adjMatrix[20][20], char* vertices) {
    if (vertexCount >= 20) {
        cout << "Vertex limit reached.\n";
        return;
    }
    if (getIndex(label,vertexCount,adjMatrix,vertices) != -1) {
        cout << "Vertex already exists.\n";
        return;
    }
    vertices[vertexCount++] = label;
}


void addEdge(char* starting, char* ending, int weight, int &vertexCount,  int adjMatrix[20][20], char* vertices) {
  int i = getIndex(starting,vertexCount,adjMatrix,vertices);
  int j = getIndex(ending,vertexCount,adjMatrix,vertices);

    if (i == -1 || j == -1) {
        cout << "One or both vertices not found.\n";
        return;
    }
    //add the weight at that point (i,j) 
    //it might be j,i -- check on which is first row or column
    adjMatrix[i][j] = weight;
}
//exact same as add edge -- but just set weight back to 0
void removeEdge(char*starting, char*ending, int &vertexCount,  int adjMatrix[20][20], char* vertices) {
  int i = getIndex(starting,vertexCount,adjMatrix,vertices);
  int j = getIndex(ending,vertexCount,adjMatrix, vertices);

    if (i == -1 || j == -1) {
        cout << "One or both vertices not found.\n";
        return;
    }
    //add the weight at that point (i,j) 
    //it might be j,i -- check on which is first row or column
    adjMatrix[i][j] = 0;
}
void deleteVertex(char label, int &vertexCount, int adjMatrix[20][20], char* vertices) {
    int index = getIndex(label, vertexCount, adjMatrix, vertices);
    if (index == -1) {
        cout << "Vertex not found.\n";
        return;
    }

    // Shift vertices left to remove the label
    for (int i = index; i < vertexCount - 1; i++) {
        vertices[i] = vertices[i + 1];
    }

    // Shift rows up
    //so i is +1 
    //similar for loop situation to tictactoe
    for (int i = index; i < vertexCount - 1; i++) {
        for (int j = 0; j < vertexCount; j++) {
            adjMatrix[i][j] = adjMatrix[i + 1][j];
        }
    }

    // Shift columns left
    //so j is +1 
    // similar situation to tictactoe too 
    for (int i = 0; i < vertexCount - 1; i++) {
        for (int j = index; j < vertexCount - 1; j++) {
            adjMatrix[i][j] = adjMatrix[i][j + 1];
        }
    }

    vertexCount--;
}


// Print the adjacency matrix -- this is the graph 
void printAdjMatrix(int &vertexCount,  int adjMatrix[20][20], char* vertices) {
    cout << "Adjacency Table Printed:\n ";
    //print table taken from TicTacToe
    for (int i = 0; i < vertexCount; i++) {
      cout<<"\t" << vertices[i] << "\t";
    }
    cout << "\n";

    for (int i = 0; i < vertexCount; i++) {
      cout << vertices[i] << " ";
        for (int j = 0; j < vertexCount; j++) {
	  cout << "\t"<<adjMatrix[i][j] << "\t";
        }
        cout << "\n";
    }
}

int main() {
  int vertexCount = 0;
  int adjMatrix[20][20] = {0};
  char* vertices=new char [20];
  while (true){
    char input[100];
    cout<<"What would you like to do: add MANUALLY, from a FILE, PRINT, SEARCH, DELETE, or QUIT?"<<endl;
    cin>>input;
    if(strcmp(input,"REMOVEVERTEX")==0){
      char* firstEdge= new char [2];
      cout<<"Enter the Vertex you want to delete"<<endl;
      cin>>firstEdge;
      deleteVertex(firstEdge, vertexCount, adjMatrix, vertices);
    }
    else if (strcmp(input, "REMOVEEDGE")==0){
      char* firstEdge = new char [2];
      cout<<"Enter first Vertex: ";
      cin>>firstEdge;
      char* secondEdge=new char [2];
      cout<<"Enter second Vertex: ";
      cin>>secondEdge;
      removeEdge (firstEdge, secondEdge, vertexCount, adjMatrix, vertices);
      
    }
    else if (strcmp(input, "PRINT")==0){
      printAdjMatrix(vertexCount,adjMatrix, vertices);
    }
    else if (strcmp(input,"QUIT")==0){
      exit(0);
    }
  }
  /*
    addVertex('A',vertexCount, adjMatrix,vertices);
    addVertex('B',vertexCount,adjMatrix,vertices);
    addVertex('C',vertexCount,adjMatrix,vertices);

    addEdge('A', 'B', 5,vertexCount,adjMatrix,vertices);
    addEdge('B', 'C', 3,vertexCount,adjMatrix,vertices);

    printAdjMatrix(vertexCount,adjMatrix,vertices);
    removeEdge('A', 'B', 5,vertexCount,adjMatrix,vertices);
    deleteVertex('A', vertexCount, adjMatrix, vertices);

    printAdjMatrix(vertexCount,adjMatrix,vertices);
  */
    return 0;
}
