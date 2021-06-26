#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tree
{
    int data;
    struct tree *left, *right;
};

struct queue
{
    struct tree *address;
    struct queue *next;
};
struct queue *front = 0;
struct queue *rear = 0;

void enqueue(struct tree *root)
{
    struct queue *temp = (struct queue *)malloc(sizeof(struct queue *));
    temp->address = root;
    temp->next = 0;
    if (front == 0 && rear == 0)
    {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

struct queue *dequeue()
{
    struct queue *temp = front;
    if (front == 0)
    {
        printf("Empty");
        return 0;
    }
    else if (front == rear)
    {
        front = rear = 0;
    }
    else
    {
        front = front->next;
    }
    return front;
}
struct tree *newnode(int data)
{
    struct tree *new = (struct tree *)malloc(sizeof(struct tree *));
    new->data = data;
    new->left = 0;
    new->right = 0;
    return new;
}
struct tree *add(struct tree *root, int data)
{
    if (root == 0)
    {
        root = newnode(data);
    }
    else if (data <= root->data)
    {
        root->left = add(root->left, data);
    }
    else
    {
        root->right = add(root->right, data);
    }
    return root;
}

void levelorder(struct tree *root)
{
    if (root == 0)
    {
        return;
    }
    enqueue(root);
    struct queue *temp = front;
    while (temp)
    {
        struct queue *curr = front;
        printf("%d ", curr->address->data);
        temp = dequeue();
        if (curr->address->left != NULL)
        {
            enqueue(curr->address->left);
        }
        if (curr->address->right != NULL)
        {
            enqueue(curr->address->right);
        }
        temp = front;
    }
}

int main()
{
    struct tree *root = 0;
    root = add(root, 17);
    root = add(root, 2);
    root = add(root, 25);
    root = add(root, 27);
    root = add(root, 1);
    root = add(root, 7);

    levelorder(root);
    return 0;
}
