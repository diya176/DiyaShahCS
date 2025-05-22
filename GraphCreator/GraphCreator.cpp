#include <iostream>
#include <cstring>

using namespace std;





int getIndex(char index,int &vertexCount,int adjMatrix[20][20],char vertices[20]) {
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
void addVertex(char label,int &vertexCount,  int adjMatrix[20][20], char vertices[20]) {
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


void addEdge(char starting, char ending, int weight, int &vertexCount,  int adjMatrix[20][20], char vertices[20]) {
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
void removeEdge(char starting, char ending, int weight, int &vertexCount,  int adjMatrix[20][20], char vertices[20]) {
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

// Print the adjacency matrix -- this is the graph 
void printAdjMatrix(int &vertexCount,  int adjMatrix[20][20], char vertices[20]) {
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
    char vertices[20];


    addVertex('A',vertexCount, adjMatrix,vertices);
    addVertex('B',vertexCount,adjMatrix,vertices);
    addVertex('C',vertexCount,adjMatrix,vertices);

    addEdge('A', 'B', 5,vertexCount,adjMatrix,vertices);
    addEdge('B', 'C', 3,vertexCount,adjMatrix,vertices);

    printAdjMatrix(vertexCount,adjMatrix,vertices);
    removeEdge('B', 'C', 3,vertexCount,adjMatrix,vertices);

    printAdjMatrix(vertexCount,adjMatrix,vertices);

    return 0;
}
