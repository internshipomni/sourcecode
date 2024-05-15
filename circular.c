#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL,*tail,*temp;

void display()
{
    temp = head;
    if(head==NULL)
        printf("LIST IS EMPTY!");
    else
    {
        while(temp -> next != head)
        {
            printf("%d : : ",temp -> data);
            temp = temp -> next;
        }
        printf("%d ",temp -> data);
    }
}

void create(int n)
{
    struct node *new;
    temp = head;
    while(n)
    {
        new = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&new -> data);
        new -> next = NULL;
        if(head == NULL)
            head = temp = new;
        else
        {
            temp -> next = new;
            temp = new;
        }
        n--;
    }
    tail = temp;
    temp -> next = head;
    display();
}

void insertfront()
{
    struct node *new;
    temp = head;
    new = (struct node *)malloc(sizeof(struct node));
    printf("Enter element: ");
    scanf("%d",&new -> data);
    new -> next = NULL;
    if(head == NULL)
        head = temp = new;
    else
    {
        new -> next = head;
        head = new;
        tail -> next = new;
    }
    display();
}

void insertpos()
{
    struct node *new,*prev;
    int pos,i=1;
    temp = head;
    new = (struct node *)malloc(sizeof(struct node));
    printf("Enter position: ");
    scanf("%d",&pos);
    printf("Enter element: ");
    scanf("%d",&new -> data);
    new -> next = NULL;
    while(i<pos)
    {
        prev = temp;
        temp = temp->next;
        i++;
    }
    new -> next = temp;
    prev -> next = new;
    display();
}

void insertend()
{
    struct node *new;
    temp = head;
    new = (struct node *)malloc(sizeof(struct node));
    printf("Enter element: ");
    scanf("%d",&new -> data);
    new -> next = NULL;
    tail -> next = new;
    tail = tail -> next;
    tail -> next = head;
    display();
}

void delfront()
{
    temp = head;
    head = head -> next;
    tail -> next = head;
    free(temp);
    display(); 
}

void delpos()
{
    struct node *pre;
    int pos,i=1;
    temp = head;
    pre = temp;
    printf("Enter position: ");
    scanf("%d",&pos);
    while (i<pos)
    {
        pre = temp;
        temp = temp -> next;
        i++;
    }
    pre -> next = temp -> next;
    free(temp);
    display();
}

void delend()
{
    struct node *pre;
    temp = head;
    pre = temp;
    while(temp -> next != head)
    {
        pre = temp;
        temp = temp -> next;
    }
    tail = pre;
    tail -> next = head;
    free(temp);
    display();
}

int main()
{
    int n,c;
    printf("Enter no.of elements u want to enter: ");
    scanf("%d",&n);
    create(n);
    printf("\nEnter 1 to insert at front\n2 to insert at position\n3 to insert at end: ");
    scanf("%d",&c);
    if(c==1)
        insertfront();
    else if(c==2)
        insertpos();
    else if(c==3)
        insertend();
    else
        printf("Invalid choice! ");
    printf("\nEnter 1 to delete at front\n2 to delete at pos\n3 to delete at end: ");
    scanf("%d",&c);
    if(c==1)
        delfront();
    else if(c==2)
        delpos();
    else if(c==3)
        delend();
    else
        printf("Invalid choice! ");
}