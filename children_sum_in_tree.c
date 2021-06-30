#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//sum of data at children = root->data
struct node
{
    struct node *left;
    int data;
    struct node *right;
};

struct node *create()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node *));
    printf("\nEnter -1 to  close\nEnter data : ");
    scanf("%d", &temp->data);
    if (temp->data == -1)
    {
        return 0;
    }
    printf("\nLeft node of %d-----------", temp->data);
    temp->left = create();
    printf("\nRight node of %d-----------", temp->data);
    temp->right = create();

    return temp;
}

int flag = 0;
void check(struct node *root)
{
    if (root == 0 )
    {
        return;
    }
    if ((root->left==0 && root->right==0))
    {
        return;
    }

    if(root->left==0)
    {
        root->left->data=0;
    }
    if(root->right==0)
    {
        root->right->data=0;
    }


    if (root->left->data + root->right->data == root->data)
    {
        check(root->left);
        check(root->right);
    }
    else
    {
        flag = 1;
        return;
    }
}

int main()
{
    struct node *root = 0;
    root = create();
    check(root);
    if (flag == 1)
    {
        printf("Property not satisfied");
    }
    else
    {
        printf("Property satisfied");
    }
    return 0;
}
