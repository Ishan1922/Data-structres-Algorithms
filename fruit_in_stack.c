#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    char *name;
    char *color;
    struct node *next;
};
struct node *head = 0;
void insert()
{
    char name[50];
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node *));
    printf("Enter the name of fruit : ");
    scanf("%s", name);
    temp->name = (char *)malloc(strlen(name + 1));
    strcpy(temp->name, name);

    char color[50];
    printf("enter fruit color : ");
    scanf("%s", color);
    temp->color = (char *)malloc(strlen(color + 1));
    strcpy(temp->color, color);
    temp->next = head;
    head = temp;
}
void delete ()
{
    char del[50];
    printf("enter the fruit name u want to delete : ");
    scanf("%s", del);
    struct node *ptr = head, *prevptr = head, *temp;
    if (strcmp(head->name, del) == 0)
    {
        temp = head;
        head = head->next;
        free(temp);
        return;
    }

    while (strcmp(ptr->name, del) != 0 && ptr->next != 0)
    {
        prevptr = ptr;
        ptr = ptr->next;
    }
    if (strcmp(ptr->name, del) != 0)
    {
        printf("%s doesn't exist in the list");
    }
    else
    {
        prevptr->next = ptr->next;
        free(ptr);
    }
}

void display()
{
    struct node *ptr = head;
    while (ptr != 0)
    {
        printf("Name : %s   Color : %s\n", ptr->name, ptr->color);
        ptr = ptr->next;
    }
}
void reverse()
{
    struct node *current, *next, *prev;
    current = head;
    prev = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
int instruction()
{
    int choice;
    printf("\nMain Menu");
    printf("\n1. Insrt a new fruit");
    printf("\n2. Delete a first fruit");
    printf("\n3. Print the list of fruit");
    printf("\n4. Print the reverse list of fruit");
    printf("\n5. Quit from Menu");
    printf("\nEnter your choice : ");
    scanf("%d", &choice);
    return choice;
}
int main()
{
    int choice;
    while(1)
    {
        there:
        choice = instruction();

        switch(choice)
        {
            case 1: insert();break;
            case 2: delete();break;
            case 3: display();break;
            case 4: reverse();break;
            case 5: exit(0);break;
            default: printf("Try again\n");goto there;
        }
    }

    return 0;
}
