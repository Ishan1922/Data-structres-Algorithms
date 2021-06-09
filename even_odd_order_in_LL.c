#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *input(struct node *head, int n)
{
    for (int i = 0; i < n; i++)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        printf("Enter the number : ");
        scanf("%d", &temp->data);

        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            struct node *temp1 = head;
            while (temp1->next != NULL)
            {
                temp1 = temp1->next;
            }
            temp1->next = temp;
        }
    }
    return head;
}
struct node *rearrange(struct node *head, int n)
{
    int even[n], odd[n];

    int evenno = 0, oddno = 0;
    struct node *ptr = head;
    while (ptr != NULL)
    {
        if (ptr->data % 2 == 0)
        {
            even[evenno] = ptr->data;
            evenno++;
        }

        else
        {
            odd[oddno] = ptr->data;
            oddno++;
        }

        ptr = ptr->next;
    }
    ptr = head;
    printf("the reaaranged list is as follows...\n");
    for (int i = 0; i < evenno; i++)
    {
        ptr->data = even[i];
        ptr = ptr->next;
    }
    for (int i = 0; i < oddno; i++)
    {
        ptr->data = odd[i];
        ptr = ptr->next;
    }
    return head;
}

void print(struct node *head)
{
    struct node *temp = head;
    printf("list is:");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int n;

    struct node *head;
    head = NULL;
    printf("enter how many numbers you want to add in a list\n");
    scanf("%d", &n);


    head = input(head, n);
    print(head);
    rearrange(head, n);
    print(head);

    return 0;
}
