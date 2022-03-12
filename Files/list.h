#ifndef LIST_H_
#define LIST_H_
#include "utils.h"
#include "structures.h"


typedef struct NodeList NodeList;

struct NodeList{
    Country *country;
    struct NodeList *next, *prev;
};

NodeList *createNodeList(Country *X);
void addAtBeginning(NodeList**head, Country *X);
void addAtEnd(NodeList**head, Country *X);
void printList(FILE *fout, NodeList *head);
#endif
