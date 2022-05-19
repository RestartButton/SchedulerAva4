#include <stdlib.h>
#include <stdio.h>

#include "schedulers.h"
#include "CPU.h"
#include "list.h"

Node *readyQueue;
int queueCount = 0;

// add a task to the list 
void add(char *name, int priority, int burst){
   int id = 0;
   Task * newTask = malloc(sizeof(Task));

   newTask->name = name;
   newTask->priority = priority;
   newTask->burst = burst;
   newTask->tid = id++;

   insert(&readyQueue, newTask);
   queueCount++;

}

// invoke the scheduler
void schedule(){
   int time = 0;

   while(queueCount != 0){

      Task *runningTask  =  getBurst(readyQueue, queueCount)->task;

      do{

         run(runningTask, time);

         runningTask->burst -= QUANTUM;

         time += QUANTUM;

      }while (runningTask->burst >= 0);
     
      
      delete(&readyQueue, runningTask);
     
      queueCount--;

      free(runningTask);

      
   }

}
