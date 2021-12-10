#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev, *next;
}*n,*head, *tail, *t;

void ins_at_beg_cdl(int num)
{
    n = (struct node*)malloc(sizeof(struct node));
    n->data = num;
    n->prev = NULL;
    n->next = NULL;
    
    if(head == NULL)
    {
        head = n;
        n->next = head;
    }else{
        t = head;
        while(t->next != head)
        {
            t = t->next;
        }
        t->next = n;
        n->prev = t;
        n->next = head;
        head->prev = n;
        head = n;
    }
}

void ins_at_end_cdl(int num)
{
    n = (struct node*)malloc(sizeof(struct node));
    n->data = num;
    n->prev = NULL;
    n->next = NULL;
    if(head = NULL)
    {
        head = n;
        n->next = head;
    }
    else
    {
        t = head;
        while(t->next != head)
        {
            t = t->next;
        }
        t->next = n;
        n->prev = t;
        head->prev = n;
    }
}

void del_at_beg_cdl()
{
    if(head == NULL)
    {
        printf("\n Underflow");
        exit(0);
    }else{
        t = head;
        while(t->next != head)
        {
            t = t->next;
        }
        t->next = head->next;
        head->next->prev = t;
        free(head);
        head = t->next;
    }
}

void del_at_end_cdl(){
    if(head == NULL)
    {
        printf("\n Underflow");
        exit(0);
    }else{
        t = head;
        while(t->next != head)
        {
            t = t->next;
        }
        t->prev->next = head;
        head->prev = t->prev;
        free(t);

    }
}
