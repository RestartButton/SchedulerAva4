/**
 * Various list operations
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "list.h"
#include "task.h"


// add a new task to the list of tasks
void insert(Node **head, Task *newTask) {
    // add the new task to the list 

    Node *newNode = malloc(sizeof(Node));


    newNode->task = newTask;
    newNode->next = *head;
    *head = newNode;

}

// delete the selected task from the list
void delete(Node **head, Task *task) {
    Node *temp;
    Node *prev;

    temp = *head;
    // special case - beginning of list
    if (strcmp(task->name,temp->task->name) == 0) {
        *head = (*head)->next;
    }
    else {
        // interior or last element in the list
        prev = *head;
        temp = temp->next;
        while (strcmp(task->name,temp->task->name) != 0) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = temp->next;
    }
}

// traverse the list
void traverse(Node *head) {
    Node *temp;
    temp = head;

    while (temp != NULL) {
        printf("[%s] [%d] [%d]\n",temp->task->name, temp->task->priority, temp->task->burst);
        temp = temp->next;
    }
}

Node* getLast(Node *head) {
    Node *temp = head;

    while (temp != NULL) {
        if(temp->next == NULL) return temp;
        temp = temp->next;
    }
    
    return temp;
}

Node* getCurrentInPriority(Node *head){
    Node *temp = head;
    Node *cNode = head;

    while (temp != NULL) {
        
        if(temp->task->priority <= cNode->task->priority) cNode = temp;

        temp = temp->next;
    }
    
    return cNode;
}

Node* getBurst(Node *head, int quant_process) {
    Node *temp = head;

    int bt[quant_process-1];

    int lower_bt;

    for( int i = 0; i < quant_process; i++){

        bt[i] = temp->task->burst;

        temp = temp->next;

    }

    lower_bt = bt[0];

    for (int i = 1; i < quant_process; i++){

        if (bt[i] <  lower_bt){
            lower_bt = bt[i];
        }
    }

    temp = head;

    while (temp != NULL) {
        if(temp->task->burst == lower_bt) return temp;
        temp = temp->next;
    }
    
    return temp;
}