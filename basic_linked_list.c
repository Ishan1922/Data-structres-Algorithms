#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *next;
};

void insertatend();
void deleteaparticular();
void display();

struct node *head = NULL;

int main()
{
    insertatend();
    insertatend();
    deleteaparticular(44);
    insertatend();
    display();
    return 0;
}

void insertatend()
{
    struct node *temp, *ptr;
    temp = (struct node *)malloc(sizeof(struct node *));
    printf("enter the element : ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void display()
{
    struct node *ptr;
    ptr = head;
    if (ptr == NULL)
        printf("list is empty");
    printf("the list is as follows...\n");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

void deleteaparticular(int val)
{
    struct node *ptr, *prevptr, *temp;
    ptr = head;
    if(head->data==val){
        temp = head;
        head = head->next;
        free(temp);
        return;
    }
    while (ptr->data != val && ptr->next != NULL)
    {
        prevptr = ptr;
        ptr = ptr->next;
    }
    if (ptr->data != val && head->data!=val)
    {
        printf("\nvalue doesn't exist in the list\n");
    }
    else
    {
        prevptr->next = ptr->next;
        free(ptr);
    }
}
