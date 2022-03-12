#include "utils.h"
#include "queue.h"

NodeQueue *createNodeQueue(Info *v)
{
    NodeQueue *newNode = (NodeQueue *) malloc(sizeof(NodeQueue));
    newNode-> val= v;
    newNode->next = NULL;
    return newNode;
}

void deleteNodeQueue(NodeQueue *X){
    free(X->val);
    X->next = NULL;
}

void createQueue(Queue **queue)
{
    *queue = (Queue*)malloc(sizeof(Queue));
    (*queue)->front = (*queue)->rear = NULL;
}

void enQueue(Queue *queue, Info *v)
{
    NodeQueue *newNode = (NodeQueue*)createNodeQueue(v);
    if (queue->rear==NULL) //adaugare la finalul cozii
    	queue->rear=newNode;
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    if (queue->front==NULL)
    	queue->front=queue->rear; 
}


Info *deQueue(Queue*queue)
{
	NodeQueue* aux; Info *d;
	if (isEmptyQueue(queue))
		return NULL ;
	aux =queue->front;
	d= aux->val;
	queue->front=(queue->front)->next;
	free(aux);
	return d;
}

int isEmptyQueue(Queue *queue)
{
    return ((queue->front == queue->rear) && (queue->front == NULL));
}