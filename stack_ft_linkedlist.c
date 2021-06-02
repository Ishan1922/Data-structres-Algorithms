#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *next;
};
struct node *top = NULL;

void insert()
{
    struct node *temp, *ptr;
    temp = (struct node *)malloc(sizeof(struct node *));
    printf("enter a number : ");
    scanf("%d", &temp->data);
    if (top == 0)
    {
        temp->next = 0;
        top = temp;
    }
    else
    {
        temp->next = top;
        top = temp;
    }
}

void display()
{
    if (top==0)
    {
        printf("\nStack is empty\n");
        return;
    }
    struct node *ptr = top;
    while (ptr != 0)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

void peek()
{
    if (top==0)
    {
        printf("\nStack is empty\n");
        return;
    }
    printf("\nElement at top of the stack is %d\n", top->data);
}

void delete ()
{
    //in stack
    //deletion takes place from top only
    if (top==0)
    {
        printf("\nStack is empty\n");
        return;
    }

    struct node *ptr = top;
    top = top->next;
    printf("\nValue deleted is %d\n", ptr->data);
    free(ptr);
}

int instructions()
{
    int choice;
    while (1)
    {
        printf("\nMain menu\n");
        printf("1.insert\n");
        printf("2.delete\n");
        printf("3.peek\n");
        printf("4.display the stack\n");
        printf("5.quit\n");
        printf("Enter you choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("end of program...");
            exit(0);
            break;

        default:
            printf("Invalid input\n");
            break;
        }

    }


}

int main()
{
    instructions();


    return 0;
}
