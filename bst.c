#include"utils.h"
#include"bst.h"
#include"structures.h"

Node* newNode(Info *data)
{ 
	Node* node = (Node*)malloc(sizeof(Node));
	node->val = data;
	node->left = node->right = NULL;
	return node;
}

Node* insert(Node* node, Info *X)
{ 
	if (node == NULL) 
		return newNode(X);
	if (X->score < node->val->score) 
		node->left = insert(node->left, X);
	else 
		if (X->score > node->val->score)
			node->right = insert(node->right, X);
		else
			//se modifica node daca numele jucatorului este mai mic din punct de vedere lexicografic
			if(strcmp(node->val->last_name, X->last_name)>0 || //prenume diferit
			  (strcmp(node->val->last_name, X->last_name)==0 && (strcmp(node->val->first_name, X->first_name)>0)))//nume diferit
			{
				strcpy(node->val->last_name,X->last_name);
				strcpy(node->val->first_name,X->first_name);
			}
	return node;
}

Node * minValueNode(Node* node)
{
	Node* aux = node;
	while (aux->left != NULL)
		aux = aux->left;
	return aux;
}

void DRS(FILE *fout, Node*root, int N, int *count) 
{
	if (root){
		DRS(fout, root->right, N, &(*count));
		fprintf(fout, "%s %s %d",root->val->last_name, root->val->first_name, root->val->score);
		if(*count!=N)
			fprintf(fout, "\n");
		*count++;
		DRS(fout, root->left, N, &(*count));
	}
}

Node* search(Node* root, Info *X)
{
	if (root == NULL || ((strcmp(root->val->last_name, X->last_name)==0) && (strcmp(root->val->first_name, X->first_name)==0)))
		return root;
	if (root->val->score < X->score) 
		return search(root->right, X);
	return search(root->left, X);
} 

