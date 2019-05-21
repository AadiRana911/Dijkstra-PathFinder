//
// Created by hp on 5/15/2019.
//

#ifndef A_STAR_PATHFINDER_STACK_H
#define A_STAR_PATHFINDER_STACK_H

#include <iostream>
#include "LinkedList.h"
using namespace std;
class Stack{
    queueNode *top=NULL;
public:
    void push(vertexNode *temp);

    vertexNode* pop();

    bool isEmpty();
    void print();
};


#endif //A_STAR_PATHFINDER_STACK_H
