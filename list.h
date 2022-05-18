/**
 * list data structure containing the tasks in the system
 */
#ifndef LIST_H
#define LIST_H

#include "task.h"

typedef struct node {
    Task *task;
    struct node *next;
} Node;

// insert and delete operations.
void insert(Node **head, Task *task);
void delete(Node **head, Task *task);
void traverse(Node *head);
Node* getLast(Node *head);
Node* getCurrentInPriority(Node *head);

#endif