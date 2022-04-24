/*
    print array elements from both forward and backword direction

    print_array_both_direction(*arr, forward_index, backword_index)

            forward_index > backward_index
                return ;

            forward_index == backward_index
                print arr[forward_index]

            forward_index < backward_index
                print arr[forward_index]
                print arr[backward_index]
                print_array_both_direction(*arr, forward_index + 1, backward_index - 1)

    print_array_from_both_direction_single_index(*arr, size, index)

        if()


*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void print_array_from_both_direction_using_recurrsion(int *arr, int forward_index, int backward_index);
void print_array_from_both_direction_single_index(int *arr, int size, int index);
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
    print_array_from_both_direction_using_recurrsion(arr, 0, 8 - 1);
    print_array(arr, 8);

    exit(EXIT_SUCCESS);
}

void print_array_from_both_direction_using_recurrsion(int *arr, int forward_index, int backward_index)
{
    if (forward_index > backward_index)
    {
        return;
    }

    if (forward_index == backward_index)
    {
        printf("i = j = %d : array[%d]: %d\n", forward_index, backward_index, arr[forward_index]);
    }

    if (forward_index < backward_index)
    {
        printf("i = %d : array[%d]: %d :: j = %d : array[%d]: %d\n", forward_index, arr[forward_index], backward_index, arr[backward_index]);
        print_array_from_both_direction_using_recurrsion(arr, forward_index + 1, backward_index - 1);
    }
}