#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;

void push();
void pop();
void top();
void display();

int main()
{
    push();
    push();
    push();
    pop();
    display();
    return 0;
}

void push()
{
    struct node *temp, *ptr;
    temp = (struct node *)malloc(sizeof(struct node *));
    printf("enter the element : ");
    scanf("%d", &temp->data);
    temp->next = NULL;

    if (head == NULL)
    {
        head=temp;
    }
    else
    {
        ptr = head;
        while (ptr != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}
void pop()
{
    struct node *prevptr=NULL, *ptr;
    ptr=head;
    if (ptr==NULL)
    {
        printf("\nStack Underflow");
    }
    else
    {
        while (ptr->next != NULL)
        {
            prevptr = ptr;
            ptr = ptr->next;
        }
        prevptr->next = NULL;
        printf("%d is removed", ptr->data);
        free(ptr);
    }
}
void display()
{
    struct node *ptr;
    ptr = head;
    if (ptr == NULL){
        printf("list is empty");
    }
    else
    {
        printf("the list is as follows...\n");
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }   
    }
}