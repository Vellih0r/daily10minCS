#include <stdio.h>
#include <stdlib.h>
#include "l_list.h"


int hash(int val)
{
    return val*15;
}

typedef struct Hashmap
{
    int size;
    struct Node** list;
}Hashmap;

void init(Hashmap* h)
{
   h->size = 5;
   h->list = malloc(sizeof(struct Node*) * h->size); 
}

void push(Hashmap* map, int key, int value)
{
    int index = hash(key);
    index = index % map->size;
    l_add(&(map->list[index]), value);
}

int main()
{
    Hashmap test;
    init(&test);
    push(&test, 'a', 5);
    int i = hash('a');
    i = i % 5;
    printf("%d\n", i);
    l_add(&test.list[i], 10);
    l_print(&test.list[i]);
    int a = 75;
    printf("val %d\n", a);
    int h = hash(a);
    printf("hashed %d\n", h);
    return 0;
}
