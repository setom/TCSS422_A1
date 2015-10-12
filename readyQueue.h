
//pcb struct pg. 243
typedef struct {
	int id; 					//ID number of the PCB
	int priority;				//priority of the PCB (0-63)
	//enum field_state state; 	//enum state
} pcb;

typedef pcb * pcb_p; 


typedef struct {	
	pcb_p data;					//specific PCB of the node
	struct node *next;			//next node in the queue
} Node;
 
typedef Node * node_p;

typedef struct {
	struct node *head;			//head of the queue
	struct node *tail;			//tail of the queue
} Queue;

//declare method to create new PCB
pcb* createPCB();
//declare method to create new Node
Node* createNode();
// declare methods for the queue
Queue* createQueue();
Queue* peek();
Queue* enqueue();
Queue* dequeue();

