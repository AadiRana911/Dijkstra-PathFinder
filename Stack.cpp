//
// Created by hp on 5/15/2019.
//

#include "Stack.h"
#include <iostream>
#include "LinkedList.h"
using namespace std;
void Stack::push(vertexNode *temp){
    queueNode *tem=new queueNode;
    tem->vtxNode = temp;
    if(top==NULL){
        top=tem;
        top->next=NULL;
    }
    else{
        tem->next=top;
        top=tem;
    }
}
vertexNode* Stack::pop(){
    if(top==NULL){
        return NULL;
    }
    else{
        vertexNode *temp=top->vtxNode;
        top=top->next;
        return temp;
    }
}
bool Stack::isEmpty(){
    return top==NULL;
}
void Stack::print(){
        queueNode* temp;

        // check for stack underflow
        if (top == NULL) {
            cout << "Stack UnderFlow";
        }
        else {
            temp = top;
            while (temp -> next != NULL) {

                // print node data
                cout << temp->vtxNode->name << " -> ";

                // assign temp link to temp
                temp = temp->next;
            }
            cout << temp -> vtxNode -> name;
        }
}
