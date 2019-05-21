//
// Created by hp on 5/14/2019.
//
#include <iostream>
#include "Graph.h"
#include "LinkedList.h"
#include "Stack.h"
#include <math.h>

using namespace std;
Graph::Graph() : LinkedList() {//constructor
    head = NULL;
    tail = NULL;
}

void Graph::insert_vertex(int locIndex) {
    //a method to add a vertix in the graph which initially isVisited isolated
    vertexNode *temp = new vertexNode;
    temp->index = locIndex;
    cout << "Enter the name of your vertex: ";
    cin >> temp ->name;
    temp -> localGoal = INT_MAX;
    cout << endl;
    temp->head = temp->tail = NULL;
    if (head == NULL) {
        head = tail = temp;
        temp->next = NULL;
    } else {
        tail->next = temp;
        tail = temp;
        tail->next = NULL;
    }
}

//this methhod isVisited used to complie an adjancency list for the representation of graph
void Graph::insert_edge(int vtx, int edg) {
    if (head == NULL) {
        cout << "\n Insert a Vertix First\n";
        return;
    } else if (head == tail) {
        cout << "\n Insert one more Vertix\n";
        return;
    } else {

        vertexNode *temp = head;
        while (temp != NULL && (temp->index != vtx)) {
            temp = temp->next;
        }
        vertexNode *tmp = head;
        while (tmp != NULL && (tmp->index != edg)) {
            tmp = tmp->next;
        }
        if (tmp != NULL && temp != NULL) {
            temp = add_edge(tmp, temp);
        }
        return;
    }
    cout << "\n NO Matching Vertix Found\n";
}



void Graph::delete_vtx(int info) {//a method to delete a vertix from the graph
    if (head == NULL) {
        cout << "\n The Graph isVisited Empty\n";
        return;
    } else if (head == tail && (head->index == info)) {
        head = tail = NULL;
        cout << "\n Graph isVisited now Empty\n";
        return;
    } else {
        vertexNode *temp = head;
        while (temp != NULL && temp->next->index != info) {
            temp = temp->next;
        }
        if (temp != NULL) {
            temp->next = temp->next->next;
        }
        temp = head;
        while (temp != NULL) {
            temp = delete_edge(temp);
            temp = temp->next;
        }
        return;
    }
}

//method to display the adjacency list
void Graph::display_grf() {
    if (head == NULL) {
        cout << "\n Graph isVisited Empty\n";
    } else {
        vertexNode *temp = head;
        while (temp != NULL) {
            cout << "\n Vertix " << temp->name;
            display(temp->head);
            temp = temp->next;
            cout << endl;
        }
    }
}


Stack Graph::Dijkstra(vertexNode *start, int numOfVertices, vertexNode *destination){
    Stack solution;
    BFS(start, numOfVertices);
    vertexNode *solver = destination;
    do{
        solution.push(solver);
        solver = solver -> parent;
    }while (solver != start);
    solution.push(start);
    return solution;
}

void Graph::BFS(vertexNode *start, int numOfVertices){
    start -> localGoal = 0;
    vertexNode *unvisited[numOfVertices];
    vertexNode *temp = start;
    for (int i = 0; i < numOfVertices; i++) {
        unvisited[i] = temp;
        temp = temp -> next;
    }
    int i = 0;
    while (!isEmpty(unvisited , numOfVertices)){
        vertexNode *par = unvisited[i];
        edge *trav = unvisited[i] -> head;
        while (trav != NULL){
                if (par -> localGoal + trav -> weight < trav -> adjacentVertex -> localGoal){
                    trav -> adjacentVertex ->localGoal = par -> localGoal + trav -> weight;
                    trav -> adjacentVertex -> parent = par;
                }
            trav = trav -> next;
        }
        unvisited[i] = NULL;
        i++;
    }

}

bool Graph::isEmpty(vertexNode *vertices[] , int size){
    for (int i = 0; i < size; i++) {
        if (vertices[i] != NULL){
            return false;
        }
    }
    return true;
}

vertexNode *Graph::getVertix(int pos) {
    vertexNode *temp = head;
    for (int i = 0; i < pos; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        return head;
    }
    return temp;
}
