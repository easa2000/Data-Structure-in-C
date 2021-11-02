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

// inside at end
void ins_at_end_dll(int  num) {
    n = (struct node*)malloc(sizeof(struct node));
    n -> data = num;
    n -> next = NULL;
    n -> prev = NULL;
    if(head == NULL) {
        head = n;
        tail = n;
    }else{
        tail->next = n;
        n->prev = tail;
        tail = n;
    }
}

// insert at middle

void ins_at_mid_dll(int num, int mid) {
    n = (struct node*)malloc(sizeof(struct node));
    n -> data = num;
    n -> next = NULL;
    n -> prev = NULL;
    for(t=head; t!=NULL; t=t->next) {
        if(t->data == mid){
            break;
        }
        n->next = t->next;
        n->prev = t;
        t->next->prev = n;
        t->next = n;

    }
}

// delete at beginning

void del_at_beg_dll()
{
    t = head;
    head = head->next;
    head->prev = NULL;
    free(t);
}

// delete at end
void del_at_end()
{
 t = head;
 while(t->next != NULL)
 {
     t = t->next;
 }
 tail = tail->prev;
 tail -> next = NULL;
 free(t);
}

// delete at mid value

void delete_at_mid(int num)
{
    t = head;
    while(t->data != num)
    {
        t = t->next;
    }
    t->prev->next = t->next;
    t->next->prev = t->prev;
    free(t);
}

// search an elements
bool search(struct node* head, int val) {
    struct node* current = head;
    while(current != NULL)
    {
        if(current->data == val){
            return true;
        }else{
            return false;
        }
    }
}

// print all elements in Linked list
void print_elements(struct node *head)
{
    t = head;
    while(t!= NULL){
        printf("%d\t",t->data);
        t = t->next;
    }
}

int main(){

    ins_at_beg_dll(1);
    ins_at_beg_dll(15);
    ins_at_beg_dll(18);
    ins_at_beg_dll(45);
	ins_at_beg_dll(59);
    ins_at_end_dll(89);
//    ins_at_mid_dll(78,1);
	del_at_beg_dll();
	del_at_end();
	delete_at_mid(18);
	print_elements(head);
	search(head,45) ? printf("\n Found ") : printf("\n Not Found");
	
	
    
    
}
