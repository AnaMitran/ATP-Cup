#include "utils.h"
#include "stack.h"

NodeStack *createNodeStack(Data *v)
{
    NodeStack *newNode = (NodeStack*)malloc(sizeof(NodeStack));
    newNode->val = v;
    newNode->next = NULL;
    return newNode;
}

void createStack(Stack **stack)
{
    *stack = (Stack*)malloc(sizeof(Stack));
    (*stack)->top = NULL;
    (*stack)->size = 0;
}

Data *pop(Stack **stack)
{
    if (isEmptyStack((*stack)))
        return NULL;
    else
    {
        Data *v = (*stack)->top->val;
        NodeStack *aux = (*stack)->top;
        (*stack)->top = (*stack)->top->next;
        (*stack)->size--;
        free(aux);
        return v;
    }
}

Data *top(Stack *stack)
{
    if (isEmptyStack(stack))
        return NULL;
    return (stack->top)->val;
}

void push(Stack **stack, Data *v)
{
    NodeStack *newNode = createNodeStack(v);
    (*stack)->size++;
    if (isEmptyStack((*stack)))
    {
        (*stack)->top = newNode;
    }
    else
    {
        newNode->next =(*stack)->top;
        (*stack)->top = newNode;
    }
}


void deleteStack(Stack **stack)
{   
    NodeStack *temp;
    while (!isEmptyStack(*stack))
    {
        temp=(*stack)->top;
        (*stack)->top=((*stack)->top)->next;
        free(temp);
    }
    free(*stack);
}

int isEmptyStack(Stack *stack)
{
    return stack->size == 0;
}
