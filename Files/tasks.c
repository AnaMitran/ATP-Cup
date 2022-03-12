#include "utils.h"
#include "structures.h"
#include "list.h"
#include "tasks.h"
#include "stack.h"
#include "queue.h"
#include "bst.h"

void readQuery(FILE *query, FILE *fin, FILE *fout)
{
    int i, N, q; //N=numar tari
    NodeList *head;
   	fscanf(query, "%d", &q);
    if(q==1)//1=se executa cerinta
    { 
        head = task1(fin, fout, &N);
        fscanf(query, "%d", &q);
        if(q==1)
            task2(fout, &head, &N);
        else
            printList(fout, head);
    }
    fscanf(query, "%d", &q);
    Node *root=NULL;
    if(q==1)
    {
        fscanf(query, "%d", &q); 
        task3(fout, head, N, q, &root);    
    }
    fscanf(query, "%d", &q);
    if(q==1)
    {
        int d=task5(query, fout, root);
        if(d)
            fprintf(fout, "\n%d", d);
    }
}

NodeList* task1(FILE *fin, FILE *fout, int *N)
{
    NodeList *head = (NodeList*)malloc(sizeof(NodeList));
    //santinela
    head->prev = NULL;
    head->next = NULL;
    //citire date.in si crearea listei de tari
    int i, j, n;
    char S[30], s1[30], s2[30];
    fscanf( fin, "%d", &(*N));//numar echipe
    for(i=0;i<(*N);i++)
    {
        Country *country=(Country*)malloc(sizeof(Country));
        country->global_score=0;
        fscanf(fin, "%d", &n);//numar jucatori
        country->nr_players=n;
        country->players=(Player**)malloc(n*sizeof(Player));
        fscanf(fin, "%s", S);//nume tara
        country->name=strdup(S);
        fgetc(fin);
        for(j=0;j<n;j++)
        {
            country->players[j]=(Player*)malloc(sizeof(Player));
            fscanf(fin, "%s", s1);//prenume jucator
            country->players[j]->last_name=strdup(s1);
            fgetc(fin);
            fscanf( fin, "%s", s2);//nume jucator
            country->players[j]->first_name=strdup(s2);
            fgetc(fin);
            fscanf(fin, "%d", &country->players[j]->score);//scor
        }
        if(head->next==NULL)
            addAtBeginning(&head, country);
        else
            addAtEnd(&head, country);
    }
    //free(country);
    return head;
}


void task2(FILE *fout, NodeList **head, int *N)
{
    int i, p=1;//p=2 la puterea x care il aproximeaza pe N
    while(p*2<(*N))
        p*=2;
    while(p<(*N))
    {
        removeMin(fout, &(*head));
        (*N)--;
    }
    printList(fout, *head);
}

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
    //jucatori din echipe adversare au scorul maxim 
    if((*a==*c && *flag==2)||(*b==*c && *flag==1))
        *flag=0;
}

void printMatch(FILE *fout, Player *p1, Player *p2)
{
    fprintf(fout, "%s %s %d vs ", p1->last_name, p1->first_name, p1->score);
    fprintf(fout, "%s %s %d\n", p2->last_name, p2->first_name, p2->score);
}

void setMatch(FILE *fout, Player *p1, Player *p2, int *s1, int *s2, int *smax, int *flag)
{
    printMatch(fout, p1, p2);
    changeScores(&p1->score,&p2->score,s1,s2);
    findMaxScore(&p1->score, &p2->score, smax, flag);
}

void task3(FILE* fout, NodeList *head, int N, int ok, Node **root)
{
    Stack *stack, *stackW;//stackW este stiva pentru WINNER
    createStack(&stack);
    createStack(&stackW);
    Stack *temp; //pentru a retine ultimele 4 tari 
    createStack(&temp);
    int i, j, k;
    NodeList *headCopy=head;
    for(i=0;i<=N;i++)//si santinela
    {
        push(&stack, headCopy);
        headCopy=headCopy->next;
    }
    NodeList *node1, *node2;
    int count=0;
    fprintf(fout, "\n");
    while(N!=1)
    {
        count++;
        fprintf(fout, "====== ETAPA %d ======\n\n", count);
        for(i=1;i<N/2+1;i++)
        {
            int s1, s2, smax, flag;//smax=cel mai mare scor personal
            //flag-folosit pentru a retine ce echipa include jucatorul cu cel mai mare scor
            node1=pop(&stack);
            node2=pop(&stack);
            s1=0;//scorurile globale ale tarilor
            s2=0;
            smax=0;//initializez
            fprintf(fout, "%s %d ----- ", node1->country->name, node1->country->global_score);
            fprintf(fout, "%s %d\n", node2->country->name, node2->country->global_score);
            int n1, n2;
            n1=node1->country->nr_players;
            n2=node2->country->nr_players;
            Queue *queue;
            createQueue(&queue);
            enQueue(queue, node1->country->players[0]);
            for(j=0;j<n2;j++)
            {
                enQueue(queue, node2->country->players[j]);
                setMatch(fout, queue->front->val, queue->rear->val, &s1, &s2, &smax, &flag);
            }
            Player *aux=deQueue(queue);
            enQueue(queue, node1->country->players[1]);
            for(j=0;j<n2;j++)
            {
                setMatch(fout, queue->rear->val, queue->front->val, &s1, &s2, &smax, &flag);                   
                aux=queue->rear->val;
                enQueue(queue, deQueue(queue));
                enQueue(queue, aux);
            }
            for(j=2;j<n1;j++)
            {
                aux=deQueue(queue);
                enQueue(queue, node1->country->players[j]);
                for(k=0;k<n2;k++)
                {
                    setMatch(fout, queue->rear->val, queue->front->val, &s1, &s2, &smax, &flag);
                    aux=queue->rear->val;
                    enQueue(queue, deQueue(queue));
                    enQueue(queue, aux);
                    aux=deQueue(queue);
                }
            }
            //deleteQueue(queue);
            fprintf(fout, "\n");
            //fprintf(fout, "\n %d %d %s\n", smax, flag, node2->country->name);
            node1->country->global_score+=s1;
            node2->country->global_score+=s2;
            //fprintf(fout, "%d %d", s1, s2);
            if(s1>s2 )
                push(&stackW, node1);
            else
            {
                if(s1<s2)
                    push(&stackW, node2);
                else
                {
                    if(flag==1 || flag==0)
                        push(&stackW, node1);
                    if(flag==2)
                        push(&stackW, node2);
                }
            }
        }
        fprintf(fout, "=== WINNER ===\n");
        
        for(i=0;i<N/2;i++)
        {
            node1=pop(&stackW);
            push(&stack, node1);
            fprintf(fout, "%s --- %d\n", node1->country->name, node1->country->global_score);
            if(N==8 &&ok==1)
            {
                push(&temp,node1);
            }
        }
        N/=2;
        if(N!=1)
            fprintf(fout, "\n");
    }
    if(ok==1)
    {
        fprintf(fout,"\n====== CLASAMENT JUCATORI ======\n");
        for(i=0;i<4;i++)
        {
            node1=pop(&temp);
            for(j=0;j<node1->country->nr_players;j++)
                *root=insert(*root, node1->country->players[j]);
        }
        int c=0;
        DRS(fout, *root, N, &c);
    }
}

void inorderXY(Node*root, int x, int y, int *count) {
    if (root){
        inorderXY(root->left, x, y, &(*count));
        if((root->val->score)>x && (root->val->score)<y)
        {
            (*count)++;
        }
        inorderXY(root->right, x, y, &(*count));
    }
}

int task5(FILE *query, FILE *fout, Node *root)
{
    char s[20];int count=0;
    Player *p1=(Player*)malloc(sizeof(Player));
    Player *p2=(Player*)malloc(sizeof(Player));
    fscanf(query, "%s", s);
    p1->last_name=strdup(s);
    fgetc(query);
    fscanf(query, "%s", s);
    p1->first_name=strdup(s);
    fscanf(query, "%d", &p1->score);
    fscanf(query, "%s", s);
    p2->last_name=strdup(s);
    fgetc(query);
    fscanf(query, "%s", s);
    p2->first_name=strdup(s);
    fscanf(query, "%d", &p2->score);
    if(search(root, p1)==NULL){
        fprintf(fout, "\n%s %s nu poate fi identificat!", p1->last_name, p1->first_name);
    }
    else
        if(search(root, p2)==NULL)
            fprintf(fout, "\n%s %s nu poate fi identificat!", p2->last_name, p2->first_name);
        else
        {
            if(p1->score<p2->score)
                inorderXY(root, p1->score, p2->score, &count);
            else
                inorderXY(root, p2->score, p1->score, &count);
        }
    return count;
}

