#include"functions.h"
#include "utils.h"
#include "list.h"


void removeMin(FILE *fout, NodeList **head)
{
    NodeList *headCopy=(*head)->next;
    NodeList *temp;
    int  i, n;
    float sum, min=0;
    while(headCopy!=*head)
    {
        sum=0;
        n=headCopy->country->nr_players;
        for(i=0;i<n;i++)
            sum+=headCopy->country->players[i]->score;
        if(headCopy==(*head)->next || min>sum/n )
        {
            min=sum/n;
            temp=headCopy;
        }
        headCopy=headCopy->next;
    }
   	(temp->next)->prev=temp->prev;
    (temp->prev)->next=temp->next;

    free(temp);
}

void changeScores(int *a, int *b, int *s1, int *s2)
{
    if(*a>*b)
    {
        *a+=5;
        *s1+=3;
    }
    else
        if(*a<*b)
        {
            *b+=5;
            *s2+=3;
        }
        else
        {
            *a+=2;
            *b+=2;
            *s1+=1;
            *s2+=1;
        }                  
}

void findMaxScore(int *a, int *b, int *c, int *flag)
{
    if(*a>*c)
    {
        *c=*a;
        *flag=1;
    }
    if(*b>*c)
    {
        *c=*b;
        *flag=2;
    }
}