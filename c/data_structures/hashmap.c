#include <stdio.h>
#include <l_list.c>


int hash(int val)
{
    return val*15;
}

int main()
{
    struct Node* node = { NULL };
    node = l_add(&node, 5);
    l_print(&node);
    int a = 75;
    printf("val %d\n", a);
    int h = hash(a);
    printf("hashed %d\n", h);
    return 0;
}
