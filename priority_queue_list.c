#include <stdio.h>
#include <stdlib.h>
#include "priority_queue_list.h"

void
qlist(pqueue *head, void (*print_data)(void *)) {
	pqueue *p;
	
	for (p = head; p != NULL; p = p->next) {
		printf("%d: ", p->k);
		print_data(p->data);
		printf("\n");
	}
	
}

void
qinsert(pqueue **phead, void *data, int k) {
	pqueue* element = (pqueue *)malloc(sizeof(pqueue));
	pqueue* prevElement = *phead;
	if (*phead == NULL)
	{
		*phead = element;
		element->prev = NULL;
		element->next = NULL;
	}
	else
	{	

		while (prevElement->next != NULL && prevElement->k < k)
			prevElement = prevElement->next;
		if (prevElement->k < k)
		{
			element->next = prevElement->next;
			prevElement->next = element;
			element->prev = prevElement;
			
		}
		else
		{
			element->prev = prevElement->prev;
			prevElement->prev = element;
			element->next = prevElement; 
			*phead = element;
		}
		
	}
	element->data = data;
	element->k = k;
}


void
qremove(pqueue **phead, int k) {
	pqueue* element = *phead;
	while (element->k != k && element->next != NULL)
		element = element->next;

	if (element->k == k)
	{
		if(element->prev != NULL)
			element->prev->next = element->next;
		if (element->next != NULL)
		{
			element->next->prev = element->prev;
			if (element == *phead)
				*phead = element->next;
		}
		free(element);
	}
}

