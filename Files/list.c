#include"list.h"
#include"utils.h"
#include"structures.h"

NodeList *createNodeList(Country *X)
{
    NodeList* newNode = (NodeList*)malloc(sizeof(NodeList));
    newNode->country=X;
    newNode->next=NULL;
    newNode->prev=NULL;
}

void addAtBeginning(NodeList**head, Country *X)
{
    NodeList* newNode = (NodeList*)malloc(sizeof(NodeList));
    newNode->country=X;
    newNode->prev=*head;
    newNode->next=*head;
    (*head)->prev= newNode;
    (*head)->next=newNode;
}

void addAtEnd(NodeList**head, Country *X)
{
    NodeList* newNode = (NodeList*)malloc(sizeof(NodeList));
    newNode->country=X;
    newNode->next = *head;
    NodeList *headCopy = (*head)->next;
    while(headCopy->next!=*head)
        headCopy = headCopy->next;
    newNode->prev = headCopy;
    headCopy->next = newNode;
    (*head)->prev=newNode;
}


void printList(FILE *fout, NodeList *head)
{
    NodeList *headCopy=head->next;
    while(headCopy!=head)
    {
        fprintf(fout, "%s\n", headCopy->country->name);
        headCopy=headCopy->next;
    }
}