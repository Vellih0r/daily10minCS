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

int main()
{
    struct Node root;
    root.value = 0;
    struct LinkedList l;
    l.root = &root;
    printf("%d\n", l.root->value);
    return 0;
}
