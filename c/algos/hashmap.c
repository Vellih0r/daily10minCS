#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct HashNode {
    char *key;
    int value;
    struct HashNode *next;
} HashNode;

typedef struct HashMap {
    HashNode **buckets;
    int size;
    int how_much;
} HashMap;

HashMap* createHashMap(int size) {
    if (size <= 0) {
        fprintf(stderr, "Size must be gerater than 0\n");
        return NULL;
    }
    HashMap *map = (HashMap *)malloc(sizeof(HashMap));
    map->size = size;
    map->how_much = 0;
    map->buckets = (HashNode **)malloc(size * sizeof(HashNode *));
    for (int i = 0; i < size; i++) {
        map->buckets[i] = NULL;
    }
    return map;
}

unsigned int hashFunction(const char *key, int size) {
    unsigned int hash = 0;
    while (*key) {
        hash = (hash * 31) + (*key++);
    }
    return hash % size;
}

void insert(HashMap *map, const char *key, int value) {
    if (!map) {
        fprintf(stderr, "HashMap is NULL\n");
        return;
    }
    if (map->how_much >= map->size) {
        fprintf(stderr, "HashMap is full\n");
        return;
    }
    unsigned int index = hashFunction(key, map->size);
    HashNode *newNode = (HashNode *)malloc(sizeof(HashNode));
    newNode->key = strdup(key);
    newNode->value = value;
    newNode->next = map->buckets[index];
    map->buckets[index] = newNode;
    map->how_much++;
}

void delete(HashMap *map, const char *key) {
    if (!map) {
        fprintf(stderr, "HashMap is NULL\n");
        return;
    }
    if (map->how_much == 0) {
        fprintf(stderr, "HashMap is empty\n");
        return;
    }
    unsigned int index = hashFunction(key, map->size);
    HashNode *current = map->buckets[index];
    HashNode *prev = NULL;
    while (current) {
        if (strcmp(current->key, key) == 0) {
            if (prev) {
                prev->next = current->next;
            } else {
                map->buckets[index] = current->next;
            }
            free(current->key);
            free(current);
            map->how_much--;
            return;
        }
        prev = current;
        current = current->next;
    }
}

HashNode* get(HashMap *map, const char *key) {
    if (!map) {
        fprintf(stderr, "HashMap is NULL\n");
        return NULL;
    }
    unsigned int index = hashFunction(key, map->size);
    HashNode *current = map->buckets[index];
    while (current) {
        if (strcmp (current->key, key) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void clear(HashMap *map) {
    if (!map) {
        fprintf(stderr, "HashMap is NULL\n");
        return;
    }
    if (!map->how_much) {
        fprintf(stderr, "HashMap is empty\n");
        return;
    }
    for (int i = 0; i < map->size; i++) {
        HashNode *current = map->buckets[i];
        while (current) {
            HashNode *temp = current;
            current = current->next;
            free(temp->key);
            free(temp);
        }
        map->buckets[i] = NULL;
    }
}

void freeHashMap(HashMap *map) {
    if (!map)
    {
        fprintf(stderr, "HashMap is NULL\n");
        return;
    }
    for (int i = 0; i < map->size; i++) {
        HashNode *current = map->buckets[i];
        while (current) {
            HashNode *temp = current;
            current = current->next;
            free(temp->key);
            free(temp);
        }
    }
    free(map->buckets);
    free(map);
}

void printHashMap(HashMap *map) {
    if (!map) {
        fprintf(stderr, "HashMap is NULL\n");
        return;
    }
    if (map->how_much == 0) {
        printf("HashMap is empty\n");
        return;
    }
    for (int i = 0; i < map->size; i++) {
        HashNode *current = map->buckets[i];
        while (current) {
            printf("%s: %d\n", current->key, current->value);
            current = current->next;
        }
    }
}

int main() {
    HashMap *map = createHashMap(10);
    insert(map, "tom", 22);
    insert(map, "artyom", 19);
    printf("Value for 'artyom': %d\n", get(map, "artyom")->value);
    printf("Before deletion:\n");
    printHashMap(map);
    delete(map, "tom");
    printf("After deletion:\n");
    printHashMap(map);
    clear(map);
    printf("After clearing map:\n");
    printHashMap(map);
    freeHashMap(map);
    printf("After freeing entire map:\n");
    printHashMap(map);
    return 0;
}