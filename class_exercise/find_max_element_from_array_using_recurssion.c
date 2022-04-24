#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int get_max_using_recurrsion(int *arr, int forward_index, int backward_index);
void print_array(int *arr, int size);

int main(void)
{
    int arr[8];
    int i;
    int max;
    for (i = 0; i < 8; i++)
    {
        arr[i] = rand() % 100;
    }

    print_array(arr, 8);
    max = print_array_from_both_direction_using_recurrsion(arr, 0, 8 - 1);
    printf("max from array: %d\n", max);

    exit(EXIT_SUCCESS);
}

void print_array(int *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("arr[%d]: %d\n", i, arr[i]);
    }
}

int get_max_using_recurrsion(int *arr, int forward_index, int backward_index)
{
    int max;
    if (forward_index > backward_index)
    {
        return max;
    }

    if (forward_index <= backward_index)
    {
        
    }
}