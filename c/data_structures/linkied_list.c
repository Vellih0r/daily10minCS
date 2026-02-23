#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node * next;
};

struct LinkedList
{
    struct Node * root;
};

void init(struct LinkedList * l, int value)
{
    struct Node * root = malloc(sizeof(struct Node));
    root->value = value;
    l->root = root;
}

void add(struct LinkedList * l, int value)
{
    struct Node * node = malloc(sizeof(struct Node));
    node->value = value;
    if (!l->root)
    {
        l->root = node;
        return;
    }
    struct Node * current = l->root;
    while(current->next)
    {
        current = current->next;
    }
    current->next = node;
}

void delete(struct LinkedList * l)
{
    if (!l->root)
    {
        free(l);
        return;
    }
    struct Node * current = l->root;
    if (!current->next)
    {
        free(current);
        free(l);
        return;
    }
    while (current->next && current->next->next)
    {
        //free(current->next);
        current->next = current->next->next;
    }
    free(l);
}

void print_ll(struct LinkedList * l)
{
    struct Node * current = l->root;
    while (current->next)
    {
        printf("%d->", current->value);
        current = current->next;
    }
    printf("%d\n", current->value);
}

int main()
{
    struct LinkedList l;
    add(&l, 0);
    add(&l, 1);
    add(&l, 2);
    add(&l, 3);
    print_ll(&l);
    delete(&l);
    print_ll(&l);
    return 0;
}
