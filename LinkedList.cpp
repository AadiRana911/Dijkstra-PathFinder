//
// Created by hp on 5/14/2019.
//

#include "LinkedList.h"
#include <iostream>
using namespace std;
vertexNode *LinkedList::add_edge(vertexNode *vtx, vertexNode *vtx1){
    //method defined for adding a adjacent vertix, i.e. creating an edge betwwen 2 vetrices
    head=vtx1->head;
    tail=vtx1->tail;
    edge *temp=new edge;
    temp->adjacentVertex=vtx;
    cout << "Enter the weight of edge";
    cin >> temp -> weight;
    if(head==NULL){
        head=tail=temp;
        temp->next=NULL;
    }
    else{
        tail->next=temp;
        temp->next=NULL;
        tail=temp;
    }
    vtx1->head=head;
    vtx1->tail=tail;
    return vtx1;//this returns the vertix for which we are forming the adjancency with the new head and tail
}
vertexNode* LinkedList::delete_edge(vertexNode *vtx){
    //this method deletes the edges that exist after deleting the vertix after deleting it from the list
    if(vtx->head==NULL){
        return vtx;
    }
    else if (vtx->head==tail && (head->adjacentVertex->index==vtx->index)){
        vtx->head=vtx->tail=NULL;
        return vtx;
    }
    else{
        edge *temp=vtx->head;
        while (temp!=NULL && temp->next->adjacentVertex->index != vtx->index){
            temp=temp->next;
        }
        if(temp!=NULL){
            if(temp->next->next==NULL){
                vtx->tail=temp;
            }
            temp->next=temp->next->next;
        }
        return vtx;//this returns the vertix for which we are forming the adjancency with the new head and tail
    }
}
void LinkedList::display(edge *h) {//method to display or all the adjecent vertix
    head = h;
    if (head == NULL) {
        cout << " Is An Isolated Vertix\n";
        return;
    } else {
        edge *temp = head;
        while (temp != NULL) {
            vertexNode *vtx = temp->adjacentVertex;
            cout << " -> " << vtx->name;
            temp = temp->next;//traversing throug the adjacent vertices
        }
    }
}
