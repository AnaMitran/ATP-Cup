#ifndef BST_H_
#define BST_H_

#include"structures.h"
 typedef struct N
 {
 	Info *val;
 	struct N*left, *right;
 }Node;

Node* newNode(Info *data);
Node* insert(Node* node, Info *X);
Node * minValueNode(Node* node);
Node* search(Node* root, Info *X);
 //Node* deleteNode(Node* root, int key);

void DRS(FILE *fout, Node*root, int N, int *count) ;


#endif