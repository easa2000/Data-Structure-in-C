#include<stdio.h>
#include<stdlib.h>
struct node
{
    int coeff;
    int expo;
    struct node *next;
};
struct node *insert(struct node *head, int co, int ex)
{
    struct node *t;
    struct node *n = malloc(sizeof(struct node));
    n->coeff = co;
    n->expo = ex;
    n->next = NULL;
    if(head == NULL || ex > head->expo)
    {
        n->next = head;
        head = n;
    }else{
        t = head;
        while(t->next != NULL && t->next->expo >= ex)
        {
            t = t->next;
        }
        n->next = t->next;
        t->next = n;
    }
    return head;
}


struct node *create(struct node *head)
{
    int n,i;
    int coef,expo;
    printf("\n Enter the number of terms: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("\n Enter the Coefficient of term %d: ",i+1);
        scanf("%d",&coef);
        printf("\n Enter the Exponent of term %d: ",i+1);
        scanf("%d",&expo);
        head = insert(head,coef,expo);
    }
    return head;
}

void print(struct node *head)
{
    struct node *t;
    if(head == NULL)
    {
        printf("\n No Polynomail.");
    }else{
        t = head;
        while(t!=NULL)
        {
            printf("(%dX^%d)",t->coeff,t->expo);
            t = t->next;

            if(t != NULL){
            printf(" + ");
        }else{
            printf("\n");
        }
        } 
        
    }
}


void polySub(struct node *head1, struct node *head2)
{
    struct node *ptr1 = head1;
    struct node *ptr2 = head2;
    struct node *head3;

    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1->expo == ptr2->expo)
        {
            head3 = insert(head3,ptr1->coeff - ptr2->coeff,ptr1->expo);
            ptr1 = ptr1 -> next;
            ptr2 = ptr2 -> next;
        }else if(ptr1->expo > ptr2->expo)
        {
            head3 = insert(head3, ptr1->coeff, ptr1->expo);
            ptr1 = ptr1 ->next;
        }else if(ptr1->expo < ptr2->expo)
        {
            head3 = insert(head3, ptr2->coeff , ptr2->expo);
            ptr2 = ptr2->next;
        }
    }

    while(ptr1 != NULL)
    {
        head3 = insert(head3, ptr1->coeff, ptr1->expo);
        ptr1 = ptr1->next;
    }

    while(ptr2 != NULL)
    {
        head3 = insert(head3, ptr2->coeff, ptr2->expo);
        ptr2 = ptr2 -> next;
    }
    printf("Added polynomial is: ");
    print(head3);

}
int main()
{
    struct node* head1 = NULL;
    struct node* head2 = NULL;
    printf("\n Enter the first polynomial: ");
    head1 = create(head1);
    printf("\n Enter the second polynomial: ");
    head2 = create(head2);

    polySub(head1, head2);
    return 0;   
}
