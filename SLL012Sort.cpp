/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes
will be followed by ones and then twos.

You should only change the links and shouldnt swap the data. Basically no write operation should be done on data field.

INPUTS:  SLL head pointer
OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2
ERROR CASES:
NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};

/*
Optional : For this function swapping data is allowed.Although this wont be tested on our end.
It is only for learning purpose.
*/
void sll_012_sort_swapData(struct node **head){

}

/*
This is the actual function. You are supposed to change only the links.
*/
void sll_012_sort(struct node **head)
{
	if (*head == NULL)
		return;
	struct node* last = *head;
	int num = 1;
	while (last->next != NULL)
	{
		last = last->next;
		num++;
	}
	struct node*tail = last;
	struct node *ptr = *head;
	struct node *prev = *head;
	for (int i = 0; i<num; i++)
	{
		struct node* temp = ptr;
		ptr = ptr->next;
		if (temp->data == 0)
		{
			if (prev != temp)
			{
				temp->next = *head;
				*head = temp;
				prev->next = ptr;
			}
		}
		else if (temp->data == 2)
		{
			tail->next = temp;
			temp->next = NULL;
			tail = temp;
			if (prev == temp)
				*head = prev = ptr;
			else
				prev->next = ptr;
		}
		else
		{
			if (prev != temp)
				prev = prev->next;
		}
	}
	//return head;
}


