//
// Created by hp on 5/14/2019.
//

#ifndef A_STAR_PATHFINDER_LINKEDLIST_H
#define A_STAR_PATHFINDER_LINKEDLIST_H

struct edge;
struct vertexNode{
    char name;
    vertexNode *parent;
    int index;
    int localGoal;
    edge *head;
    edge *tail;
    vertexNode *next;
};

struct edge{
    int weight;
    vertexNode *adjacentVertex;
    struct edge *next;
};

struct queueNode{
    vertexNode *vtxNode;
    queueNode *next;
};
class LinkedList {
private:
    edge *head, *tail;
public:
    vertexNode* add_edge(vertexNode *vtx, vertexNode *vtx1);

    vertexNode* delete_edge(vertexNode *vtx);

    void display(edge *h);
};


#endif //A_STAR_PATHFINDER_LINKEDLIST_H
