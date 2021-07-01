#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *createnew(int key)
{
    struct node *temp;

    temp = (struct node *)malloc(sizeof(struct node));
    // 12 bytes block will be allocated

    temp->data = key;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void add(struct node *root, int key)
{
    struct node *newnode = createnew(key);
    if (root == 0)
    {
        root = newnode;
    }
    else
    {
        struct node *p = root;
        while (p != 0)
        {
            if (p->data > key && p->left != 0)
            {
                p = p->left;
            }
            else if (p->right != 0)
            {
                p = p->right;
            }
            else
                break;
        }
        if (p->data > key)
            p->left = newnode;
        else
        {
            p->right = newnode;
        }
    }
}

void inorder(struct node *root)
{
    if (root == 0)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

struct node *inorder_successor(struct node *root)
{
    struct node *p = root;
    struct node *prev = 0;
    if (p->right != 0)
    {
        p = p->right;
    }
    else
    {
        printf("No inorder successor exists\n");
        return 0;
    }
    while (p->left != 0)
    {
        prev = p;
        p = p->left;
    }
    prev->left=0;
    return p;
}

struct node *inorder_predecessor(struct node *root)
{
    struct node *p = root;
    struct node *prev = 0;
    if (p->left != 0)
    {
        p = p->left;
    }
    else
    {
        printf("No inorder predecessor exists\n");
        return 0;
    }
    while (p->right != 0)
    {
        prev = p;
        p = p->right;
    }
    prev->right=0;
    return p;
}

struct node *search(struct node *root,int findkey)
{
    struct node *p = root;
    if (p->left==0 && p->right==0)
    {
        printf("Key not found");
        exit(0);
    }

    if(p->data==findkey)
    {
        return p;
    }
    else if (p->data>findkey)
    {
        return search(p->left,findkey);
    }
    else if (p->data<findkey)
    {
        return search(p->right,findkey);
    }


}
int main()
{
    struct node *root = 0;
    int rootdata;
    printf("enter data : ");
    scanf("%d", &rootdata);
    root = createnew(rootdata);
    while (1)
    {
        int key;
        printf("enter data : ");
        scanf("%d", &key);
        if (key == -1)
            break;
        add(root, key);
    }

    struct node *find=0;
    int findkey;
    printf("Enter the key of which you want to find the inorder predecessor and successor : ");
    scanf("%d",&findkey);
    find = search(root,findkey);
    printf("to find : %d",find->data);

    struct node *is = inorder_successor(find);
    struct node *ip = inorder_predecessor(find);

    if(inorder_successor(find)!=0)
    {
        printf("Inorder successor of %d : %d\n",find->data, is->data);
        //root = is;
    }
    if(inorder_predecessor(find)!=0)
    {
        printf("Inorder predecessor %d : %d\n",find->data, ip->data);
    }


    printf("Inorder : ");
    inorder(root);
    return 0;
}
