
//pcb struct pg. 243
typedef struct {
	int id; 					//ID number of the PCB
	int priority;				//priority of the PCB (0-63)
	//enum field_state state; 	//enum state
} pcb;

typedef pcb * pcb_p; 


typedef struct node {	
	pcb_p data;					//specific PCB of the node
	struct node *next;			//next node in the queue
} Node;
 
typedef Node * node_p;

typedef struct queue{
	struct node *head;			//head of the queue
	struct node *tail;			//tail of the queue
} Queue;

// declare methods for the queue
Queue* peek();
Queue* enqueue();
Queue* dequeue();
