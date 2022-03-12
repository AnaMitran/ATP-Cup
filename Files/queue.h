#ifndef QUEUE_H_
#define QUEUE_H_

#include "structures.h"

typedef struct NodeQueue
{
    Info *val;
    struct NodeQueue *next;
} NodeQueue;

typedef struct Queue
{
    NodeQueue *front, *rear;
} Queue;

NodeQueue *createNodeQueue(Info *v);
void deleteNodeQueue(NodeQueue *X);
void createQueue(Queue **queue);
void enQueue(Queue *queue, Info *v);
Info *deQueue(Queue*queue); 
void deleteQueue(Queue *queue);
int isEmptyQueue(Queue *queue);

#endif