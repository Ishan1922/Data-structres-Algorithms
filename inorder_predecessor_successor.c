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
    struct node *p = root, *q;
    while (p != 0)
    {
        q = p;
        if (p->data > key)
        {
            p = p->left;
        }

        else
        {
            p = p->right;
        }
    }
    if (q->data > key)
        q->left = newnode;
    else
    {
        q->right = newnode;
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

void printinorder(struct node *root)
{
    printf("Inorder : ");
    inorder(root);
    printf("\n");
}

struct node *inorder_successor(struct node *root)
{
    struct node *p = root;

    if (p->right == 0)
    {
        printf("No inorder successor exists\n");
        return 0;
    }
    else
    {
        p = p->right;

        while (p->left)
        {

            p = p->left;
        }
        return p;
    }
}

struct node *inorder_predecessor(struct node *root)
{
    struct node *p = root;
    struct node *prev = 0;
    if (p->left == 0)
    {
        printf("No inorder predecessor exists\n");
        return 0;
    }
    else
    {
        p = p->left;

        while (p->right != 0)
        {

            p = p->right;
        }
        return p;
    }
}

struct node *search(struct node *root, int findkey)
{
    struct node *p = 0;
    p = root;
    if (p == 0)
        return 0;
    if (p->data == findkey)
    {
        return p;
    }
    else if (p->data > findkey)
    {
        return search(p->left, findkey);
    }
    else
    {
        return search(p->right, findkey);
    }
}

void print_succ_pred(struct node *root)
{
    int findkey;
    printf("Enter the key of which you want to find the inorder predecessor and successor : ");
    scanf("%d", &findkey);

    struct node *find = search(root, findkey);
    printf("press 1 to find inorder successor\n");
    printf("press 2 to find inorder predecessor\n");
    int choice;
    scanf("%d", &choice);
    if (choice == 1)
    {
        struct node *is;
        is = inorder_successor(find);
        if (is != 0)
        {
            printf("Inorder successor of %d : %d\n", find->data, is->data);
        }
    }
    else if (choice == 2)
    {
        struct node *ip = inorder_predecessor(find);
        if (ip != 0)
        {
            printf("Inorder predecessor %d : %d\n", find->data, ip->data);
        }
    }
    else
    {
        printf("Invalid input");
    }
}

void get_parent(struct node *root)
{
    printf("Enter the element to get parent : ");
    int get;
    scanf("%d", &get);
    struct node *p = root, *prev = 0;
    while (1)
    {
        if (p->data == get)
        {
            printf("%d is the parent of %d\n", prev->data, get);
            return;
        }
        else if (p->data > get)
        {
            prev = p;
            p = p->left;
        }
        else if (p->data < get)
        {
            prev = p;
            p = p->right;
        }
    }
    printf("Its NULL\n");
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
    while (1)
    {
        int choice;
        printf("to find inorder successor/predecessor press 1\n");    
        printf("to find the parent node press 2\n");
        printf("To view tree press 3\n");
        scanf("%d",&choice);
        if(choice==1)
        {
            print_succ_pred(root);
        }
        else if (choice==2)
        {
            get_parent(root);
        }
        else if (choice==3)
        {
            printinorder(root);
            break;
        }
        else{
            printf("INvalid input");
            break;
        }
    }
    
    

    return 0;
}
