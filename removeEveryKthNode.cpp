/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int num;
	struct node *next;
};

struct node * removeEveryKthNode(struct node *head, int K)
{
	if (head == NULL)
	{
		return NULL;
	}
	if (K == 1 || K == 0 || K < 0)
		return NULL;
	struct node *pvr = head, *pre = NULL;
	int count = 0;
	while (pvr != NULL)
	{
		count++;
		if (K == count)
		{
			delete(pre->next);
			pre->next = pvr->next;
			count = 0;
		}
		if (count != 0)
			pre = pvr;
		pvr = pre->next;
	}
	return head;

}