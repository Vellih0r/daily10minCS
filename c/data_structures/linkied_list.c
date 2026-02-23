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
    root->next = NULL;
    l->root = root;
}

void add_ptp(struct Node **head, int value)
{
    struct Node * node = malloc(sizeof(struct Node));
    node->value = value;
    node->next = NULL;

    while (*head)
    {
        head = &(*head)->next;
    }
    *head = node;
}

void add(struct LinkedList * l, int value)
{
    struct Node * node = malloc(sizeof(struct Node));
    node->value = value;
    node->next = NULL;
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

void clear(struct LinkedList * l)
{
    struct Node * current = l->root;
    while (current)
    {
        struct Node * tmp = current;
        current = current->next;
        free(tmp);
    }
    l->root = NULL;
}

// deletes first occurance of key in linked list
void removeNode(struct LinkedList * l, int key)
{
    struct Node * current = l->root;
    struct Node * prev = NULL;
    // if root itself holds key to be deleted
    if (current != NULL && current->value == key)
    {
        l->root = current->next;
        free(current);
        return;
    }
    // search for key
    while (current != NULL && current->value != key)
    {
        prev = current;
        current = current->next;
    }

    // if key was not found
    if (current == NULL)
        return;
    // skip node with key
    prev->next = current->next;
    free(current);
}

// Linus Torvalds's more elegant remove
void remove_elegant(struct Node ** head, int key)
{
    while (*head && (*head)->value != key)
       head = &(*head)->next; 

    if (*head)
    {
        struct Node * tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }
}

void print_ll_ptp(struct Node **head)
{
    if (!*head)
    {
        printf("empty\n");
        return;
    }
    while((*head)->next)
    {
        printf("%d->", (*head)->value);
        head = &(*head)->next;
    }
    printf("%d\n", (*head)->value);
}

void print_ll(struct LinkedList * l)
{
    if (!l->root)
    {
        printf("empty\n");
        return;
    }
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
    struct Node * head = { NULL };
    add_ptp(&head, 5);
    print_ll_ptp(&head);
    struct LinkedList l = { NULL };
    add(&l, 0);
    add(&l, 1);
    add(&l, 2);
    add(&l, 3);

    print_ll(&l);
    removeNode(&l, 0);
    print_ll(&l);
    remove_elegant(&l.root, 1);
    print_ll(&l);
    remove_elegant(&l.root, 3);
    print_ll(&l);
    clear(&l);
    print_ll(&l);
    remove_elegant(&l.root,4);
}
