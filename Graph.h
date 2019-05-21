//
// Created by hp on 5/14/2019.
//

#ifndef A_STAR_PATHFINDER_GRAPH_H
#define A_STAR_PATHFINDER_GRAPH_H

#include "Stack.h"
#include "LinkedList.h"

class Graph : public LinkedList {
private:
    vertexNode *head, *tail;
public:
    Graph();

    void insert_vertex(int locIndex);

    //this methhod is used to complie an adjancency list for the representation of graph
    void insert_edge(int vtx, int edg);

    void delete_vtx(int info);

    //method to display the adjacency list
    void display_grf();

    vertexNode *getVertix(int pos);

//    void A_Star(vertexNode *s, int numOfVertices, vertexNode *e);

//    int heuristic(vertexNode* currVertex , vertexNode* destVertex);


//    void BFS (vertexNode* start, int numOfVertices, vertexNode *end);

    void BFS(vertexNode *start, int numOfVertices);

    bool isFound(vertexNode *vertices[] , int size , vertexNode *key);

    bool isEmpty(vertexNode *vertices[] , int size);

    Stack Dijkstra(vertexNode *start, int numOfVertices, vertexNode *destination);
    };

#endif //A_STAR_PATHFINDER_GRAPH_H
