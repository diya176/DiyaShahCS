#include <iostream>
#include <cstring>
#include <climits>

using namespace std;


/*
Purpose: Simulates a graph and finds the shortest distance using Dijkstra's Algorithm.
Done using an adjacency matrix instead of an actual graph.
Author: Diya Shah + Java Diya Shah 
Date: May 28th 2025

*/

//get the index --- MOST IMPORTANT FUNCTION :)
int getIndex(char index, int &vertexCount, int adjMatrix[20][20], char vertices[20]) {
    for (int i = 0; i < vertexCount; i++) {
        if (vertices[i] == index) {
            return i; //returns value in terms of integer of where that location is 
        }
    }
    return -1; //returns -1 if it does not exist 
}

//adding vertex 
void addVertex(char label, int &vertexCount, int adjMatrix[20][20], char vertices[20]) {
    if (vertexCount >= 20) { //if you have more than 20 you have reached the limit
        cout << "Vertex limit reached.\n";
        return;
    }
    // getIndex should return -1 because it should not exist 
    if (getIndex(label, vertexCount, adjMatrix, vertices) != -1) {
        cout << "Vertex already exists.\n";
        return;
    }
    //add to verticies 
    vertices[vertexCount++] = label;
}

//add edge by finding index using getIndex and then set that location to weight
void addEdge(char starting, char ending, int weight, int &vertexCount, int adjMatrix[20][20], char vertices[20]) {
    int i = getIndex(starting, vertexCount, adjMatrix, vertices);
    int j = getIndex(ending, vertexCount, adjMatrix, vertices);

    if (i == -1 || j == -1) {
        cout << "One or both vertices not found.\n";
        return;
    }
    adjMatrix[i][j] = weight;
}

//same as add edge just set it to zero instead of value
void removeEdge(char starting, char ending, int &vertexCount, int adjMatrix[20][20], char vertices[20]) {
    int i = getIndex(starting, vertexCount, adjMatrix, vertices);
    int j = getIndex(ending, vertexCount, adjMatrix, vertices);

    if (i == -1 || j == -1) {
        cout << "One or both vertices not found.\n";
        return;
    }
    adjMatrix[i][j] = 0;
}

//delete vertex 
void deleteVertex(char label, int &vertexCount, int adjMatrix[20][20], char vertices[20]) {
    //find the right index
    int index = getIndex(label, vertexCount, adjMatrix, vertices);
    
    //if not found just stop
    if (index == -1) {
        cout << "Vertex not found.\n";
        return;
    }

    for (int i = index; i < vertexCount - 1; i++) {
        vertices[i] = vertices[i + 1];
    }

    // shift rows 
    //go through the matrix 
    for (int i = index; i < vertexCount - 1; i++) {
        for (int j = 0; j < vertexCount; j++) {
            adjMatrix[i][j] = adjMatrix[i + 1][j];
        }
    }
    //shift columns 
    for (int i = 0; i < vertexCount - 1; i++) {
        for (int j = index; j < vertexCount - 1; j++) {
            adjMatrix[i][j] = adjMatrix[i][j + 1];
        }
    }
    
    //we now have one less vertex so decrease vertex count  

    vertexCount--;
}

//heavily utilized tic tac toe board code 
//see my github for that :)
void printAdjMatrix(int &vertexCount, int adjMatrix[20][20], char vertices[20]) {
    cout << "Graph Visualization:\n ";
    for (int i = 0; i < vertexCount; i++) {
        cout << "\t" << vertices[i] << "\t";
    }
    cout << "\n";

    for (int i = 0; i < vertexCount; i++) {
        cout << vertices[i] << " ";
        for (int j = 0; j < vertexCount; j++) {
            cout << "\t" << adjMatrix[i][j] << "\t";
        }
        cout << "\n";
    }
}


//much of algorithm was taken from JAVA graph creator by Diya :)
void dijkstra(char start, char end, int vertexCount, int adjMatrix[20][20], char vertices[20]) {
    const int LARGENUMBER = 1e9; // Represents a very large number 
    int dist[20]; // Array to store the shortest distances from the start vertex --- will traverse to find shortest distance eventaully 
    bool visited[20] = {false}; // Tracks which vertices have been visited 

    // Find the index positions of the start and end vertices in the vertices array
    int startIndex = -1, endIndex = -1;
    for (int i = 0; i < vertexCount; i++) {
        if (vertices[i] == start){
            startIndex = i;
        }
        if (vertices[i] == end){
            endIndex = i;
        }
    }

    // If either vertex label is not found, error cause what are you doing
    if (startIndex == -1 || endIndex == -1) {
        cout << "Invalid vertex label.\n";
        return;
    }

    // Initialize all distances to a large number
    for (int i = 0; i < vertexCount; i++) {
        dist[i] = LARGENUMBER;// very large number needed 
    }
    // Distance to the start vertex is 0 cause you know you aren't going anywhere
    dist[startIndex] = 0;

    // Actual implementation loop of Dijkstra's algorithm
    for (int count = 0; count < vertexCount - 1; count++) {
        int u = -1;
        //start with really large to find smaller number
        int minDist = LARGENUMBER;

        // Find the unvisited vertex with the smallest distance
        for (int i = 0; i < vertexCount; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }

        // If no reachable unvisited vertex is left, exit the loop
        if (u == -1){
            break;
        }

        // Mark the selected vertex as visited
        //so we dont over traverse 
        visited[u] = true;

        // Update the distances 
        for (int v = 0; v < vertexCount; v++) {
            // if there is a value at that point and we have not visited  it yet 
            if (adjMatrix[u][v] > 0 && !visited[v]) {
                //add to the distance 
                if (dist[u] + adjMatrix[u][v] < dist[v]) {
                    dist[v] = dist[u] + adjMatrix[u][v];
                }
            }
        }
    }
    // Output the result
    if (dist[endIndex] == LARGENUMBER) {
        //if no path (so no change from large number) print no path
        cout << "No path from " << start << " to " << end << ".\n";
    } else {
        cout << "Shortest distance from " << start << " to " << end << " is " << dist[endIndex] << ".\n";
    }
}


//at bottom so no prototypes needed :) 

int main() {
    int vertexCount = 0;
    //actual tic tac toe looking matrix 
    int adjMatrix[20][20] = {0};
    char vertices[20];

    char input[50];
    while (true) {
        cout << "What would you like to do: ADDVERTEX, ADDEDGE, REMOVEEDGE, REMOVEVERTEX, PRINTMATRIX, SHORTESTDISTANCE, or QUIT: ";
        cin >> input;

        if (strcmp(input,"ADDVERTEX")==0) {
            char label;
            cout << "Enter vertex label: ";
            cin >> label;
            addVertex(label, vertexCount, adjMatrix, vertices);
            printAdjMatrix(vertexCount, adjMatrix, vertices);
        } 
        
        else if (strcmp(input,"ADDEDGE")==0) {
            char start;  //YAYYYY I FIGURED OUT THE CHAR PROBLEM
            char end;
            int weight;
            cout << "Enter start vertex: ";
            cin >> start;
            cout << "Enter end vertex: ";
            cin>>end;
            cout << "Enter weight: ";
            cin>> weight;
            addEdge(start, end, weight, vertexCount, adjMatrix, vertices);
            printAdjMatrix(vertexCount, adjMatrix, vertices);
        } 
        
        else if (strcmp(input,"REMOVEEDGE")==0) {
            char start;
            char end;
            cout << "Enter start vertex: ";
            cin>>start; 
            cout<<"Enter end vertex: ";
            cin >> end;
            removeEdge(start, end, vertexCount, adjMatrix, vertices);
        } 
        
        //remove vertex
        else if (strcmp(input,"REMOVEVERTEX")==0) {
            char label;
            cout << "Enter vertex to delete: ";
            cin >> label;
            deleteVertex(label, vertexCount, adjMatrix, vertices);
        } 
        
        //print
        else if (strcmp(input,"PRINTMATRIX")==0) {
            printAdjMatrix(vertexCount, adjMatrix, vertices);
        } 
        //dijkstra's algorithm 
        else if (strcmp(input,"SHORTESTDISTANCE")==0) {
            char start;
            char end;
            cout << "Enter start vertex for Dijkstra's algorithm: ";
            cin >> start;
            cout << "Enter end vertex for Dijkstra's algorithm: ";
            cin >> end;
            //void dijkstra(char start, char end, int vertexCount, int adjMatrix[20][20], char vertices[20]) {

            dijkstra(start, end, vertexCount, adjMatrix, vertices);
        }
        else if (strcmp(input,"QUIT")==0) {
            break;
        }
        else{
            ;
        }
    }

    return 0;
}
