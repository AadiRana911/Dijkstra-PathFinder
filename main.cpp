
/****************************************************************
 **Created By: Asad Imtiaz Rana                                **
 **Comsats University Islamabad Pakistan                       **
 **                                                            **
 ** This Program finds the shortest path between two vertices, **
 ** whether the graph is directed or undirected.               **
 ****************************************************************/


#include <iostream>
#include <cstdlib>
#include "LinkedList.h"
#include "Graph.h"
using namespace std;

void printMenu(){
    cout <<"Select an option of the following\n";
    cout <<"1 -> Print menu again\n";
    cout <<"2 -> Insert a vertex\n";
    cout <<"3 -> Insert an edge\n";
    cout <<"4 -> Find the shortest path\n";
    cout <<"5 -> Exit\n";
}

int main() {
    Graph G;
    int numOfVertices, numOfedges;
    cout << "Enter the number of vertices in your graph: ";
    cin >> numOfVertices;
    cout << endl;
    for (int i = 0; i < numOfVertices; i++) {
        G.insert_vertex(i);
    }

    cout << "Enter the number of edges to connect vertices: ";
    cin >> numOfedges;
    cout << endl;
    for (int j = 0; j < numOfedges; j++) {
        int startingVertex, endingVertex;
        cout << "Enter starting vertex: ";
        cin >> startingVertex;
        cout << "Enter ending vertex";
        cin >> endingVertex;
        G.insert_edge(startingVertex, endingVertex);
    }
    int sourceVertex, destinationVertex;
    cout << "<<<....NOW ITS TIME TO FIND SHORTEST PATH.....>>>\n";
    cout << "Enter the source vertex: ";
    cin >> sourceVertex;
    cout << endl;
    cout << "Enter the destination vertex: ";
    cin >> destinationVertex;
    cout << endl;
    Stack conclude = G.Dijkstra(G.getVertix(sourceVertex), numOfVertices, G.getVertix(destinationVertex));
    conclude.print();
    return 0;
}
