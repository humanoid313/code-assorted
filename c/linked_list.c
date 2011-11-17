//#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//using namespace std;

struct node{
    struct node *next;
    int data;
};
typedef struct node node;


void push(node **head_ref, int data_new){
    // Pushes before
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data_new;
    newnode->next = (*head_ref);
    (*head_ref) = newnode;
}


void printlist(node *head){
    while(head != NULL){
        printf("%d->", head->data);
        head = head->next;
    }

    printf("NULL\n");
}

void printreverse(node *head){
    if(head==NULL){
        return;
    }
    else{
        printreverse(head->next);
        printf("%d\n", head->data);
    }
}

void reverse(node **head_ref){
    node *curr =  (*head_ref);
    node *prev=NULL;
    node *next;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    (*head_ref) = prev;
}

void recursiveReverse(node **head_ref)
{
    node *first;
    node *rest;

    /* empty list */
    if (*head_ref == NULL)
       return;

    /* suppose first = {1, 2, 3}, rest = {2, 3} */
    first = *head_ref;
    rest  = first->next;

    /* List has only one node */
    if (rest == NULL)
       return;

    /* put the first element on the end of the list */
    recursiveReverse(&rest);
    first->next->next  = first;

    /* tricky step -- see the diagram */
    first->next  = NULL;

    /* fix the head pointer */
    *head_ref = rest;
}

int main(){
    node *head = NULL;;

    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    printlist(head);
    //printreverse(head);
    printf("\n\n\n");
    reverse(&head);
    printf("\n\n\n");
	printlist(head);
	return 0;
}
