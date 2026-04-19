#include <stdio.h>
#include <stdlib.h>

#include "l_list.h"


long hash(int val)
{
    return val*15;
}

typedef struct Hashset
{
    int size;
    struct Node** bucket;
}Hashset;

void init(Hashset* set, int size)
{
   set->size = size;
   set->bucket = malloc(sizeof(struct Node*) * size); 
   for (int i = 0; i < size; i++)
       set->bucket[i] = NULL;
}

long key_to_index(int key, int size)
{
    long index = hash(key);
    index = index % size;
    return index;
}

void push(Hashset* set, int val)
{
    int i = key_to_index(val, set->size);
    printf("bucketindex = %d\n", i);
    l_add(&set->bucket[i], val);
}

int get(Hashset* set, int index)
{
    if (!set->bucket[index])
        return -1;
    return (set->bucket[index])->val;    
}

void s_destroy(Hashset* set)
{
    for (int i = 0; i < set->size; i++)
        l_destroy(&(set->bucket[i]));
    free(set->bucket);
}

void s_print(Hashset* set)
{
    for (int i = 0; i < set->size-1; i++)
    {
        l_print(set->bucket[i]);
        printf("\n");
    }
}

// bugs somewhere
int main()
{
    Hashset test;
    init(&test, 5);
    push(&test, 20);
    push(&test, 30);
    push(&test, 40);
    push(&test, 41);
    push(&test, 42);
    push(&test, 43);

    s_print(&test);
    s_destroy(&test);
}
