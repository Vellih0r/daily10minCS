#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node *next;
};

void print_ll(struct Node **head)
{
    while(*head)
    {
        if (!(*head)->next)
        {
            printf("%d\n", (*head)->val);
            return;
        }
        printf("%d->", (*head)->val);
        head = &(*head)->next;
    }
}

void add(struct Node **head, int value)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->val = value;
    newNode->next = NULL;

    while(*head)
        head = &(*head)->next;
    *head = newNode;
}

void remove_key(struct Node **head, int key)
{
    while(*head && (*head)->val != key)
        head = &(*head)->next;
    struct Node *tmp = *head;
    *head = (*head)->next;
    free(tmp);
}  

void remove_node(struct Node **head, struct Node **node)
{
    while(*head && *head != *node)
        head = &(*head)->next;
    *head = (*head)->next;
    free(*node);
}

void destroy(struct Node **head)
{
    struct Node *current = *head;
    struct Node *next;
    while(current)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

int main() {
    struct Node *head = { NULL };
    print_ll(&head);
    add(&head, 5);
    add(&head, 7);
    add(&head, 9);
    print_ll(&head);
    
    struct Node *tmp = (*head).next;
    remove_node(&head, &tmp);
    
    print_ll(&head);
    destroy(&head);
    print_ll(&head);
    free(head);
}
