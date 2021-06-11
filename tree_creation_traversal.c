#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    scanf("%d",&temp->data);
    if(temp->data==-1){
        return 0;
    }
    printf("\nLeft node of %d-----------",temp->data);
    temp->left=create();
    printf("\nRight node of %d-----------",temp->data);
    temp->right=create();

    return temp;
}

void preorder(struct node *root)
{
    if(root==0){
        return;
    }

    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node *root)
{
    if (root==0)
    {
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);

}
void postorder(struct node *root)
{
    if (root==0)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);

}
int main()
{
    struct node *root = 0;

    root = create();
    printf("Pre order : ");
    preorder(root);
    printf("\nInorder : ");
    inorder(root);
    printf("\nPost order : ");
    postorder(root);
    return 0;
}
