#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void in_place_reversal_of_array_using_recurrsion(int *arr, int forward_index, int backward_index);
void print_array(int *arr, int size);

int main(void)
{
    int arr[8];
    int i;
    for (i = 0; i < 8; i++)
    {
        arr[i] = rand() % 100;
    }

    print_array(arr, 8);
    in_place_reversal_of_array_using_recurrsion(arr, 0, 8 - 1);
    print_array(arr, 8);

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

void in_place_reversal_of_array_using_recurrsion(int *arr, int forward_index, int backward_index)
{
    if (forward_index >= backward_index)
    {
        return;
    }

    if (forward_index < backward_index)
    {
        int temp;
        temp = arr[forward_index];
        arr[forward_index] = arr[backward_index];
        arr[backward_index] = temp;
    }
}