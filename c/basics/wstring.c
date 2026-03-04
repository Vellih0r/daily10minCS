#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

// wndtn custom sting (wndtn stream)

typedef struct wstring
{
    uint8_t* data;
    size_t length;
    size_t how_much;
}str_t;

str_t* string_create(size_t length)
{
    str_t* string = (str_t*)malloc(sizeof(str_t));
    if(!string) return NULL;
    string->data = (uint8_t*)malloc(length);
    if(!string->data)
    {
        free(string);
        return NULL;
    }
    string->length = length;
    string->how_much = 0;
    return string;
}

void string_free(str_t* string)
{
    free(string->data);
    free(string);
}

size_t string_length(str_t* string)
{
    return string->how_much;
}

void print_string(str_t* string, FILE* file)
{
    fwrite(string->data, sizeof(uint8_t), string->how_much, file);
}

str_t* string_dup(const char* str)
{
    str_t* string = string_create((uint8_t)strlen(str));
    memcpy(string->data, str, string->length);
    string->how_much = string->length;
    return string;
}

str_t* string_concat(str_t* left, str_t* right)
{
    str_t* string = string_create(left->how_much + right->how_much);
    memcpy(string->data, left->data, left->how_much);
    memcpy(string->data + left->how_much, right->data, right->how_much);
    string->how_much = string->length;
    return string;
}

str_t* string_substr(str_t* string, size_t start, size_t end)
{
    if (!string || start > end || end > string->how_much)
        return string_dup("");

    size_t len = end - start;
    str_t* out = string_create(len);
    memcpy(out->data, string->data + start, len);

    out->how_much = len;
    return out;
}

str_t* string_reverse(str_t* str) 
{
    if (!str || !str->data || str->how_much < 2)
        return str;

    size_t left, right;
    uint8_t tmp;
    for (left = 0, right = str->how_much-1; left < right; left++, right--)
    {
        tmp = str->data[right];
        str->data[right] = str->data[left];
        str->data[left] = tmp; 
    }
    return str;
}

size_t partition(str_t* str, size_t low, size_t high)
{
    uint8_t pivot = str->data[high];
    size_t i = low;
    
    for (size_t j = low; j < high; j++)
    {
        if (str->data[j] <= pivot)
        {
            uint8_t tmp = str->data[i];
            str->data[i] = str->data[j];
            str->data[j] = tmp;
            i++;
        }
    }

    uint8_t tmp = str->data[i];
    str->data[i] = str->data[high];
    str->data[high] = tmp;

    return i;
}

void quicksort(str_t* str, size_t low, size_t high)
{
    if (low < high)
    {
        size_t mid = partition(str, low, high);

        if (mid > 0)
            quicksort(str, low, mid-1);
        quicksort(str, mid+1, high);
    }
}

int main(int argc, char** argv)
{
    str_t* hello_world = string_dup("heLlo, world");
    print_string(hello_world, stdout);

    fprintf(stdout, "\n length = %zu\n", string_length(hello_world));

    str_t* concated = string_concat(hello_world, hello_world);
    print_string(concated, stdout);
    fprintf(stdout, "\n length = %zu\n", string_length(concated));

    str_t* sub = string_substr(hello_world, 1, 3);
    print_string(sub, stdout);

    str_t* reversed = string_reverse(concated);
    print_string(reversed, stdout);
    putchar('\n');
    quicksort(reversed, 0, reversed->how_much-1);
    print_string(reversed, stdout);
    putchar('\n');

    string_free(hello_world);
    string_free(concated);
    string_free(sub);

    return 0;
}

