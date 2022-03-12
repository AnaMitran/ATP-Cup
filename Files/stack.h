#ifndef STACK_H_
#define STACK_H_
#include "list.h"
typedef NodeList Data;

typedef struct NodeStack
{
	Data *val; 
	struct NodeStack* next;
}NodeStack;

typedef struct Stack
{
	NodeStack *top; 
	int capacity, size; 
}Stack;

NodeStack *createNodeStack(Data *v);
void createStack(Stack **stack);
Data *pop(Stack **stack);
Data *top(Stack *stack);
void push(Stack **stack, Data *v);
void deleteStack(Stack **stack);
int isEmptyStack(Stack *stack);

#endif
