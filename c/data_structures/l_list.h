#ifndef L_LIST_H
#define L_LIST_H

struct Node {int val; struct Node *next;};
void l_print(struct Node **head);
void l_add(struct Node **head, int value);
struct Node* l_get(struct Node **head, int key);
void l_remove_key(struct Node **head, int key);
void l_remove_node(struct Node **head, struct Node **node);
void l_destroy(struct Node **head);

#endif
