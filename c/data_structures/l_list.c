#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node *next;
};

void l_print(struct Node **head)
{
    if (head == NULL)
        return;
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

void l_add(struct Node **head, int value)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->val = value;
    newNode->next = NULL;

    while(*head)
        head = &(*head)->next;
    *head = newNode;
}

struct Node* l_get(struct Node **head, int key)
{
    while(*head && (*head)->val != key)
        head=&(*head)->next;
    return *head;
}

void l_remove_key(struct Node **head, int key)
{
    while(*head && (*head)->val != key)
        head = &(*head)->next;
    struct Node *tmp = *head;
    *head = (*head)->next;
    free(tmp);
}  

void l_remove_node(struct Node **head, struct Node **node)
{
    while(*head && *head != *node)
        head = &(*head)->next;
    *head = (*head)->next;
    free(*node);
}

void l_destroy(struct Node **head)
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

/*
int main() {
    struct Node *head = { NULL };
    l_print(&head);
    l_add(&head, 5);
    l_add(&head, 7);
    l_add(&head, 9);
    l_print(&head);
    struct Node *node = l_get(&head, 5);
    printf("get %d\n", node->val);
    
    struct Node *tmp = (*head).next;
    l_remove_node(&head, &tmp);
    
    l_print(&head);
    l_destroy(&head);
    l_print(&head);
}
*/
