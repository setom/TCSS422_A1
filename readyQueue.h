
typedef enum {new, running, waiting, interrupted, halted} State;

//pcb struct pg. 243
typedef struct pcb{
	int id; 					//ID number of the PCB
	int priority;				//priority of the PCB (0-63)
    State state; 				//enum state
    struct pcb * next;          //next pcb in the queue/linked list
} pcb;

//typedef pcb * pcb_p; 


typedef struct Queue {
    int count;              	//count of elements
	struct pcb *head;			//head of the queue
	struct pcb *tail;			//tail of the queue
	
	//methods declarations
	void (*enqueue)(struct Queue*, struct pcb*);
	pcb (*dequeue)(struct Queue*);
	pcb (*peek)(struct Queue*);
	
} Queue;

//declare method to create new PCB
pcb* createPCB(int, int, State);

// method prototypes
Queue* createQueue();
pcb peek(Queue myQ);
int enqueue(Queue *myQ, pcb *myPcb);
pcb dequeue(Queue *myQ);


