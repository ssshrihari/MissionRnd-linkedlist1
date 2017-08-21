/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.

*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int num;
	struct node *next;
};
struct node* Merge(struct node* a, struct node* b)
{
	struct node* r = NULL;
	if (a == NULL)
		return(b);
	else if (b == NULL)
		return(a);
	if (a->num <= b->num)
	{
		r = a;
		r->next = Merge(a->next, b);
	}
	else
	{
		r = b;
		r->next = Merge(a, b->next);
	}
	return(r);
}

void two(struct node* s, struct node** front, struct node** back)
{
	struct node* f;
	struct node* s1;
	if (s == NULL || s->next == NULL)
	{
		*front = s;
		*back = NULL;
	}
	else
	{
		s1 = s;
		f = s->next;
		while (f != NULL)
		{
			f = f->next;
			if (f != NULL)
			{
				s1 = s1->next;
				f = f->next;
			}
		}
		*front = s;
		*back = s1->next;
		s1->next = NULL;
	}
}
void MergeSort(struct node** hr)
{
	struct node* head = *hr;
	struct node* a;
	struct node* b;
	if ((head == NULL) || (head->next == NULL))
	{
		return;
	}
	two(head, &a, &b);
	MergeSort(&a);
	MergeSort(&b);
	*hr = Merge(a, b);
}


struct node * sortLinkedList(struct node *head)
{
	MergeSort(&head);
	return head;
}