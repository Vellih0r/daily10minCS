#include <stdio.h>
#include "l_list.h"


int hash(int val)
{
    return val*15;
}

typedef struct hashmap
{
    int key;
    struct Node* list;
}Hashmap;

int main()
{

    struct Node *head = { NULL };
    Hashmap test;
    test.key = 'a';
    test.list = head;
    l_add(&test.list, 5);
    l_add(&test.list, 5);
    l_print(&test.list);
    int a = 75;
    printf("val %d\n", a);
    int h = hash(a);
    printf("hashed %d\n", h);
    return 0;
}
