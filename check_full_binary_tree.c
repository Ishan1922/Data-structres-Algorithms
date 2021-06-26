#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tree
{
    int data;
    struct tree *right, *left;
};

struct tree *create()
{
    struct tree *temp;
    temp = (struct tree *)malloc(sizeof(struct tree *));
    printf("\nEnter -1 to  close\nEnter data : ");
    scanf("%d", &temp->data);
    if (temp->data == -1)
    {
        return 0;
    }
    printf("\nLeft tree of %d-----------", temp->data);
    temp->left = create();
    printf("\nRight tree of %d-----------", temp->data);
    temp->right = create();

    return temp;
}

void check(struct tree *root)
{
    if (root == 0)
        return;
    else if (root->left != 0 && root->right != 0)
    {
        check(root->left);
        check(root->right);
    }
    else if (root->left == 0 && root->right == 0)
    {
        return;
    }

    else
    {
        printf("Not a Full Binary Tree");
        exit(0);
    }
}
int main()
{
    struct tree *root = 0;
    root = create();
    check(root);
    printf("Yes its a Full Binary Tree");

    return 0;
}
