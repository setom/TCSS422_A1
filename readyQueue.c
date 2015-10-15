#include <stdio.h>
#include <stdlib.h>
#include "readyQueue.h"

int main (int argc, char* argv[]){
	
  int userVal; 
  int i;
  int PRIORITIES = 64;
	//make a new array of queues with 64 places
	Queue priorityArray [PRIORITIES];
	for(i = 0; i < PRIORITIES; i++){
	  priorityArray[i] = *createQueue();
	  printf("Created Queue for index %d\n", i);
	}

	//prompt the user for an input
	  printf("Please enter a priority value for a new process (0-63):\n");
	  scanf("%d", &userVal);
	  if(userVal >= 0 && userVal<=PRIORITIES+1){
	    //do work to put it in the queue
	    printf("Successfully added to Ready Queue\n");
	  } else {
	    printf("Invalid priority specified\n");
	  }
}

Queue* createQueue() {
  Queue *Q;
  //allocate memory for the queue
  Q=(Queue *)malloc(sizeof(Queue));
  Q->head = NULL;
  Q->tail = NULL;
  Q->count = 0;
  return Q;
}

//enqueue new item to the tail
//dequeue items from the head
Queue* enqueue(Queue *myQ, pcb *myPcb){
	
	//if the queue is null
	if(myQ->head == NULL){
		myQ->head = myPcb;
	} else {
		//if not null, add it to the tail
		myQ->tail->next = myPcb;
	}
	
	myQ->tail = myPcb;
	//increment the count of nodes
	myQ->count++;
	
	return 0;
}

pcb* dequeue(Queue *myQ){
	
	//TODO: **** Check for memory leaks later*****
	
	//takes the pcb from the head, returns it
	
	//make a holder for the head pcb
	pcb myPcb = myQ->head;
	//move the head to head.next
	myQ->head = head->next;
	//decrement count
	myQ->count--;
	//return the pcb 
	return myPcb;
	
}

pcb peek(Queue *myQ){
	
	//get the pcb from the head
	pcb myPcb = myQ->head;
	//return it
	return myPcb;
	
}

pcb* createPCB(int newID, int newPri, State newState){
	pcb *myPcb;
	//allocate memory for it
	myPcb=(pcb *)malloc(sizeof(pcb));
	myPcb->id = newID;
	myPcb->priority = newPri;
	myPcb->state = newState;
	return myPcb;	
}