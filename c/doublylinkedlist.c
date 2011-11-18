#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *next;
    struct node *prev;
    int data;
};
typedef struct node node;

/*
	Structure:
	NULL 	<- 1 -> <- 2 -> NULL
	next					prev
*/

void push(node **head_ref, int data_new)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data_new;
    newnode->next = (*head_ref);
    newnode->prev = NULL;
    if((*head_ref) != NULL)
    {
    	(*head_ref)->prev = newnode;
    }
    (*head_ref) = newnode;
}


void printlist(node *head)
{
    while(head != NULL){
        printf("%d->", head->data);
        head = head->next;
    }

    printf("NULL\n");
}

void printcurrent(node *head)
{
	if (head != NULL)
	{
		printf("%d\n", head->data);
	}
}


int main(){
    node *head = NULL;;

    push(&head, 1);
    printcurrent(head);
    push(&head, 2);
    printcurrent(head);
    push(&head, 3);
    push(&head, 4);
    printlist(head);


	return 0;
}
