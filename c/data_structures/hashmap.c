#include <stdio.h>
#include <stdlib.h>
#include "l_list.h"

long hash(char val[])
{
    long result = 0;
    for (int i = 0; val[i] != '\0'; i++)
    {
        result = val[i] * 15;
    }
    return result;
}

typedef struct Hashmap
{
    int size;
    struct Node** list;
}Hashmap;

void init(Hashmap* map, int size)
{
   map->size = size;
   map->list = malloc(sizeof(struct Node*) * size); 
}

long key_to_index(char key[], int size)
{
    long index = hash(key);
    index = index % size;
    return index;
}

void push(Hashmap* map, char key[], int value)
{
    int i = key_to_index(key, map->size);
    l_add(&(map->list[i]), value);
}

int h_get(Hashmap* map, char key[])
{
    long k_hash = hash(key);
    int i = key_to_index(key, map->size);
    struct Node* tmp = map->list[i];
    return tmp->val;    
}

void h_destroy(Hashmap* map)
{
    for (int i = 0; i < map->size; i++)
        l_destroy(&map->list[i]);
    free(map->list);
}

int main()
{
    Hashmap test;
    init(&test, 5);
    char key[] = "nuts";
    push(&test, key, 5);

    printf("%s->%d\n", key, h_get(&test, key));
    h_destroy(&test);
}
