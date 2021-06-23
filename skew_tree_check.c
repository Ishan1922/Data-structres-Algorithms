#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//checking if the tree is skew or not
// lab training set : 5


struct node {
    int data;
    struct node *left, *right;
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

struct node *check(struct node *root)
{
    if(root==0){
        return 0;
    }
    else if (root->left==0 && root->right==0)
    {
        return 0;
    }
    else if(root->left!=0 && root->right==0){
        check(root->left);
    }
    else if(root->right!=0 && root->left==0)
    {
        check(root->right);
    }
    else{

        return root;
    }
}


int main()
{
    struct node *root=0;
    root = create();
    struct node *p = check(root);
    if (p!=0)
    {
        printf("NO its not a skew tree");
    }
    else{
        printf("YES its skew tree");
    }

    return 0;
}
