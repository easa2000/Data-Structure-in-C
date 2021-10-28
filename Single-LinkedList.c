#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
	int data;
	struct node *next;
}*head,*tail,*n,*t;

void ins_at_beg(int num) {
	n = (struct node*)malloc(sizeof(struct  node));
	n->data = num;
	n->next = NULL;
	if(head == NULL){
		head = n;
		tail = n;
	}else{
		n->next = head;
		head = n;
	}
}

void ins_at_end(int num) {
	n = (struct node*)malloc(sizeof(struct node));
	n->data = num;
	n->next = NULL;
	if(head == NULL) {
		head = n;
		tail = n;
	}else{
		tail->next = n;
		tail = n;
	}
}

void ins_at_mid(int num, int mid){
	n = (struct node*)malloc(sizeof(struct node));
	n->data = num;
	n->next = NULL;
	
	for(t=head; t!=NULL; t=t->next) {
		if(t->data == mid)
			break;
	}
	n->next = t->next;
	t->next = n;
}

void del_at_beg(){
	t = head;
	head = t->next;
	free(t);
}

void del_at_end() {
	struct node *tp;
	t = head;
	while(t->next != NULL){
		tp = t;
		t = t->next;
	}
	tail = tp;
	tail->next = NULL;
	free(t);
}

void del_at_mid(int num) {
	struct node *tp;
	t = head;
	while(t->data != num) {
		tp = t;
		t = t->next;
	}
	tp->next = t->next;
	free(t);
}

bool search(struct node* head,int  val) {
	struct node* current = head;
	while(current != NULL){
		if(current->data == val){
			return true;
		}else{
			return false;
		}
	}
}

void print_elements(struct node *head){
	t = head;
	while(t!=NULL){
		printf("\n The elements are: ");
		printf("\t %d",t->data);
		t = t->next;
	}
}
void main() {
	ins_at_beg(1);
	ins_at_beg(5);
	ins_at_beg(9);
	ins_at_beg(8);
	ins_at_end(10);
	ins_at_mid(15,1);
	del_at_beg();
	del_at_end();
	del_at_mid(1);
	search(head, 9)? printf("Found") : printf("Not Found");
	print_elements(head);
	
}
