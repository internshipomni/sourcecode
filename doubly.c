#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL,*temp;

void display()
{
    temp = head;
    if(temp == NULL)
        printf("NO ELEMENTS!!!");
    else
    {
        while(temp != NULL)
        {
            printf("%d ",temp -> data);
            temp = temp -> next;
        }
    }
}

void create(int n)
{
    struct node *new;
    temp = head;
    while(n)
    {
        new = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&new -> data);
        new -> prev = NULL;
        new -> next = NULL;
        if(head == NULL)
            head = temp = new;
        else
        {
            temp -> next = new;
            new -> prev = temp;
            temp = new;
        }
        n--;
    }
    display();
}

void insertfront()
{
    struct node *new;
    temp = head;
    new = (struct node *)malloc(sizeof(struct node));
    printf("Enter element: ");
    scanf("%d",&new -> data);
    new -> prev = NULL;
    new -> next = temp;
    temp -> prev = new;
    head = new;
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
    while(temp -> next != NULL)
        temp = temp -> next;
    temp -> next = new;
    new -> prev = temp;
    display();
}

void insertpos()
{
    struct node *new,*pre;
    temp = head;
    int pos,i=1;
    new = (struct node*)malloc(sizeof(struct node));
    printf("Enter position: ");
    scanf("%d",&pos);
    printf("Enter data: ");
    scanf("%d",&new -> data);
    while(i<pos)
    {
        pre = temp;
        temp = temp -> next;
        i++;
    }
    pre -> next = new;
    temp -> prev = new;
    new -> prev = pre;
    new -> next = temp;
    display();
}

void delfront()
{
    temp = head;
    if(head == NULL)
        printf("NO ELEMENTS IN LIST!");
    else
    {
        head = head -> next;
        head -> prev = NULL;  
        free(temp);
    }
    display();  
}

void delend()
{
    struct node *pre;
    temp = head;
    if(head == NULL)
        printf("LIST IS EMPTY!");
    else
    {
        while(temp -> next != NULL)
        {
            pre = temp;
            temp = temp -> next;
        }
        pre -> next = NULL;
        free(temp);
    }
    display();
}

void delpos()
{
    struct node *new,*pre;
    temp = head;
    int pos,i=1;
    printf("Enter position: ");
    scanf("%d",&pos);
    while(i<pos)
    {
        pre = temp;
        temp = temp -> next;
        i++;
    }
    new = temp -> next;
    pre -> next = new;
    new -> prev = pre;
    free(temp);
    display();
}

int main()
{
    int n,num;
    printf("Enter no.of elements u want to enter: ");
    scanf("%d",&n);
    create(n);
    printf("\n1:insert at front \n2: insert at end \n3:insert at position\n");
    scanf("%d",&num);
    if(num==1)
        insertfront();
    else if(num==2)
        insertend();
    else if(num==3)
        insertpos();
    else
        printf("Invalid choice!");
    printf("\n1:Delete at front \n2:Delete at end \n3:Delete at pos :");
    scanf("%d",&num);
    if(num==1)
        delfront();
    else if(num==2)
        delend();
    else if(num==3)
        delpos();
    else
        printf("Invalid Choice!");
    /*printf("press 1 to know length of list: ");
    scanf("%d",&num);
    if(num==1)
        search();
    else
        printf("THANK YOU!!!");*/
}