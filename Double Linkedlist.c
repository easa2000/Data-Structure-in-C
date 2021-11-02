#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
    int data;
    struct node *next, *prev;
}*n,*head, *tail, *t;

// inside at beginning

void ins_at_beg_dll(int num) {
    n = (struct node*)malloc(sizeof(struct node));
    n->data  = num;
    n->next  = NULL;
    n->prev = NULL;

    if(head == NULL) {
        head = n;
        tail = n;
    }
    else
    {
        n->next = head;
        head->prev = n;
        head = n;
    }
}
