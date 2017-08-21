/*
Problem Code : ISDIVSLL

You are Given an SLL where each Node has a character (which is picked from digits or '-'/'+') and a Key integer .
Example SLL : '1' -> '2' -> '3' -> '4'

You need to return 1 if the sum of numbers formed by (the SLL and reverse SLL) is divisible by key ,Return 0 otherwise . Return -1 for invalid cases  .

Sample Input :
SLL: '+'->'1'->'3'->'6'; (which is 136) and Key is 59 .

Sample Output :
1

If Key is 67 in the above example ,You should return 0 .

Explanation :
SLL is 136 , Reverse SLL is 631 . Sum is 631+136 = > 767 . 767 is divisible by 59 , So you should return 1 .

Constraints :

->Characters Range will be in from the following string "+-0123456789" .
->Length of SLL will be less than 10Nodes .
->0<=Key<=10000000
->First char need not defenetly be a sign , if its a digit ,it is considered as a positive number .

Note : Reverse of a negetive SLL is negetive only .And -963 can be divided by 3 .
*/

#include <stddef.h>
#include <malloc.h>
#include <stdio.h>

struct charNode{
	char letter;
	struct charNode *next;
};

int isDivisibleSLL(struct charNode * head, int key)
{
	int sum1 = 0;
	int sum2 = 0;
	int x = 0, j = 10;
	if (head == NULL || key == 0)
		return -1;
	struct charNode *temp = head;
	struct charNode* prev = NULL;
	struct charNode* current = head;
	struct charNode* next;
	//struct charNode *start = head;
	//struct charNode *last = head;
	while (head != NULL)
	{
		x = head->letter;
		if (x == 43 || x == 45)
			head = head->next;
		else
		{
			x = x - 48;
			sum1 = (sum1*j) + x;
			head = head->next;
		}
	}

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
	while (head != NULL)
	{
		x = head->letter;
		if (x == 43 || x == 45)
			head = head->next;
		else
		{
			x = x - 48;
			sum2 = (sum2*j) + x;
			head = head->next;
		}
	}
	//head = temp;
	int y=0;
	y = sum1 + sum2;
	if (y%key == 0)
		return 1;
	else 
		return 0;

}

