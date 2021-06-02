#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;

void enqueue()
{
    struct node *q;
    q = malloc(sizeof(struct node *));
    printf("enter the number : ");
    scanf("%d", &q->data);
    q->next = front;
    if (rear == NULL)
    {
        rear = front = q;
    }
    else
    {
        rear->next = q;
        rear = q;
    }
    printf("The number %d is added\n", q->data);
}
int display()
{
    struct node *ptr;
    ptr = front;
    if (front == NULL && rear == NULL)
    {
        printf("Nothing to print\n");
        return 0;
    }
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != front);
    return 0;
}

int dequeue()
{
    struct node *ptr;
    ptr = front;
    if (rear == NULL && front == NULL)
    {
        printf("The list is empty\n");
        return 0;
    }

    else if (front == rear)
    {
        front = rear = NULL;
        printf("Number deleted is %d\n", ptr->data);
        free(ptr);
    }
    else
    {
        front = front->next;
        rear->next = front;
        printf("Number deleted is %d\n", ptr->data);
        free(ptr);
    }
    return 0;
}

void peek()
{
    if (front == NULL)
        printf("The list is empty\n");
    else
        printf("Peek value is %d\n", front->data);
}

void instructions()
{
    while (1)
    {
        int choice;
        printf("-----MAIN MENU-----\n");
        printf("1.Insert an element\n");
        printf("2.Delete an element\n");
        printf("3.Peek value\n");
        printf("4.Display the queue\n");
        printf("5.Quit the program\n\nEnter your choice : ");
        scanf("%d",&choice);
        if (choice == 1)
            enqueue();
        else if (choice == 2)
            dequeue();
        else if (choice == 3)
            peek();
        else if (choice == 4)
            display();
        else if (choice == 5)
        {
            printf("End of the program...");
            break;
        }
        else
            continue;

        printf("\n");
    }
}

int main()
{
    instructions();
    return 0;
}
