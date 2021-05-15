#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *front=NULL;
struct node *rear=NULL;

void add();
void delete();
void print();

int main()
{
    add();
    add();
    add();
    add();
    delete();
    print();
    return 0;
}

void add()
{
    struct node *prevptr,*ptr,*temp;
    temp=(struct node *)malloc(sizeof(struct node*));
    printf("enter the queue element : ");
    scanf("%d",&temp->data);
    
    if (rear==NULL && front==NULL)
    {
        front=temp;
        rear=temp;
        front->next=rear->next=NULL;
    }
    else{
        rear->next=temp;
        rear=temp;
        rear->next=NULL;
    }
    
}
void delete()
{
    if (front==NULL)
    {
        printf("the queue is empty");
        return;
    }
    struct node *ptr;
    ptr=front;
    front=front->next;
    free(ptr);
}
void print()
{
    struct node *ptr;
    ptr=front;
    do
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    } while (ptr!=NULL);
    
}