#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
    List* lista = (List*)malloc(sizeof(lista));
    lista -> head = NULL;
    lista -> tail == NULL;
    lista -> current = NULL;
    return lista;
}
/*La primera retorna el dato del primer nodo de la lista (head) y 
actualiza el current para que apunte a ese nodo.*/
void * firstList(List * lista) {
    if (!lista -> head) return NULL;
    lista-> current = lista-> head;
    return (lista->head->data);
}

/*La segunda función retorna el dato del nodo a continuación del current y 
actualiza el current para que apunte a ese nodo.*/
void * nextList(List * lista) {
    lista -> current -> data = lista -> current -> next;
    return (lista->current->next);
}
/*La primera retorna el dato del último elemento en la lista y 
actualiza el current al nodo correspondiente.*/
void * lastList(List * lista) {
    lista -> current = lista -> tail; 
    return (lista -> tail -> data);
}

/*La segunda función retorna el dato del nodo anterior a current y 
actualiza el current para que apunte a ese nodo.*/
void * prevList(List * lista) {
    lista->current->data = lista->current->prev;
    return (lista->current->prev);
}

void pushFront(List * list, void * data) {
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}