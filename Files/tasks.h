#ifndef TASKS_H_
#define TASKS_H_
#include"utils.h"
#include"bst.h"


NodeList* task1(FILE *fin, FILE *fout, int *N);
void task2(FILE *fout, NodeList **head, int *N);
void removeMin(FILE *fout, NodeList **head);

void task3(FILE* fout, NodeList *head, int N, int ok, Node **root);
void changeScores(int *a, int *b, int *s1, int *s2);
void findMaxScore(int *a, int *b, int *c, int *flag);
void printMatch(FILE *fout, Player *p1, Player *p2);
void setMatch(FILE *fout, Player *p1, Player *p2, int *s1, int *s2, int *smax, int *flag);

int task5(FILE *query, FILE *fout, Node *root);
void inorderXY(Node*root, int x, int y, int *count);

void readQuery(FILE *query, FILE *fin, FILE *fout);


#endif
