#include<stdio.h>
#include"heap.h"

Heap * create (int capac, int heap_type)
{
	Heap * h= (Heap *) malloc (sizeof(Heap));
	if (h==NULL) 
	{ 
		printf(“Nu s-a putut aloca spatiu”); 
		return;
	}
	h->size=0; 
	h->capacity = capac;
	h->vec = (Data*) malloc(sizeof(Data)*h->capacity);
	if (h->vec==NULL) 
	{ 
		printf(“Nu s-a putut aloca spatiu”);
		return;
	}
	h->type=heap_type;
	return h;
}

void resize(Heap *h, int newCapacity){
	Data * v=(Data * )realloc( h->vec , newCapacity);
	if (v == NULL) 
	{ 
		printf ( “out-of-memory”);
		return;
	}
	h->vec=v;
}