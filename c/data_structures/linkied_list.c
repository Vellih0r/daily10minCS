#include <stdio.h>

struct Node
{
    int value;
    struct Node* next;
};

struct LinkedList
{
    struct Node* root;
};

void LinkedList(struct LinkedList *l, int value)
{
    struct Node root;
    root.value = value;
    l->root = &root;
}

int main()
{
    struct LinkedList l;
    LinkedList(&l, 0);
    printf("%d\n", l.root->value);
    return 0;
}
