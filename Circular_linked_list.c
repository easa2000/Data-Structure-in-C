    #include<stdio.h>
    #include<stdlib.h>
    #include<stdbool.h>
    struct node{
        int data;
        struct node *next;
    }*head, *n, *t;

    void ins_at_beg_cll(int num)
    {
        n = (struct node*)malloc(sizeof(struct node));
        n->data = num;
        n->next = NULL;
        if(head == NULL)
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
            n->next = head;
            head = n;
        }

    }

    void ins_end_cll(int num)
    {
        n = (struct node*)malloc(sizeof(struct node));
        n->data = num;
        n->next = NULL;
        if(head == NULL)
        {
            head = n;
            n->next = head;
        }else{
            t=head;
            while(t->next != head)
            {
                t = t->next;
            }
            t->next  = n;
            n->next = head;
        }
    }

    void ins_at_end_cll(int num,int mid)
    {
        n = (struct node*)malloc(sizeof(struct node));
        n->data = num;
        n->next = NULL;
        for(t=head;t->next != head; t=t->next)
        {
            if(t->data == mid)
            {
                break;
            }
            n->next = t->next;
            t->next = n;
        }
    }

void print_all_elements(struct node *head) {
    struct node *current = head;
    if(head != NULL){
        do{
            printf("%d\t",current->data);
            current = current ->next;
        }while(current != head);
    }
} 

void del_beg_cll()
{
    struct node *t1;
    t1 = head;
    t = head;
    while(t->next != head)
    {
        t = t -> next;
    }
    t->next = head->next;
    head = t->next;
    free(t1);
}

void del_end_cll()
{
    struct node *tp;
    t = head;
    while(t->next != head)
    {
        tp = t;
        t = t -> next;
    }
    tp->next = head;
    free(t);
}

void del_at_mid(int num)
{
    struct node *tp;
    t = head;
    while(t->data != num)
    {
        tp = t;
        t = t->next;
    }
    tp->next = t->next;
    free(t);
}

bool search(struct node *head, int num)
{
    struct node *current = head;
    while(current->next != NULL)
    {
        if(current->data == num){
            return true;
        }else{
            return false;
        }
            
    }
}

void main()
{
    ins_at_beg_cll(12);
    ins_at_beg_cll(34);
    ins_at_beg_cll(10);
    print_all_elements(head);
}
