#include <stdio.h>

int main()
{
    char my_str[] = "Hello";
    int n = 5;
    int *p = &n;
    *p = 10;
    printf("%d\n", *p);
    printf("%d\n", n);
    printf("%s\n", my_str);

    for (char *c = my_str; *c != '\0'; c++)
    {
        printf("%c", *c);
    }
    printf("\n");

    for (int c = 0; my_str[c] != '\0'; c++)
    {
        printf("%c", my_str[c]);
    }
    printf("\n");
}