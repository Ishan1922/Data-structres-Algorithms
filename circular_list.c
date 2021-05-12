#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;

void insert();
void delete ();
void display();

int main()
{
    struct node *c;
    insert();
    insert();
    insert();
    insert();
    
    
    delete();
    display();

    return 0;
}

void insert()
{
    struct node *temp,*ptr;
    temp=(struct node*)malloc(sizeof(struct node*));
    printf("enter an element : ");
    scanf("%d",&temp->data);
    
    if(head==NULL){
        head=temp;
        temp->next=head;
    }
    else{
        ptr=head;
        while(ptr->next!=head){
            ptr=ptr->next;
        }
        ptr->next=temp;
        temp->next=head;
    }
}

/*void display()
{
    struct node *ptr;
    ptr=head;
    printf("the list is as follows...\n");    //dont do like this
    while (ptr->next!=head)      //will not print the last element
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    

}*/
void display()
{
    struct node *ptr;
    ptr = head;
    if (ptr == NULL)
        printf("list is empty");
    printf("the list is as follows...\n");
    do
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    } while (ptr!=head);
    
}

void delete()
{
    struct node *prevptr;
    int val;
    printf("enter a value to be deleted : ");
    scanf("%d",&val);
    struct node *ptr;
    ptr=head;
    while (ptr->data!=val)
    {
        prevptr=ptr;
        ptr=ptr->next;
        if(ptr->next==head)break;
    }
    prevptr->next=ptr->next;
    free(ptr);
    
}

