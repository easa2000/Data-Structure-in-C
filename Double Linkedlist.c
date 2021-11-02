#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
    int data;
    struct node *next, *prev;
}*n,*head, *tail, *t;
