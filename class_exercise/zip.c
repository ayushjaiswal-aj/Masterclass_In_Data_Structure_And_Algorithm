#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Every index will be initialized by (index + 1) * 10
int *allocate_and_input_array(int *p_size);
// zip array
void zip(int *p_arr, int size);
// output array
void output_array(int *p_arr, int size, const char *msg);
// release array
void release_array(int **pp_arr);

int main(void)
{
    int *p_arr = NULL;
    int N = 0;

    p_arr = allocate_and_input_array(&N);
    output_array(p_arr, N, "Before zip:");
    zip(p_arr, N);
    output_array(p_arr, N, "After zip:");
    release_array(&p_arr);

    return (EXIT_SUCCESS);
}

// Every index will be initialized by (index + 1) * 10
int *allocate_and_input_array(int *p_size)
{
    printf("Enter the size of array: ");
    scanf("%d", p_size);
    int i;
    int *p_array;

    p_array = (int*) malloc(sizeof(int) * *P_size);
    for (i = 0; i < *p_size; i++)
    {
        *(p_array + i) = rand() % 100;
    }

    return p_array;
}

// zip array
void zip(int *p_arr, int size){
    
}

// output array
void output_array(int *p_arr, int size, const char *msg)
{
    if(msg){
        puts(msg);
    }

    int i;
    for(i = 0; i < size; i++)
    {
        printf("*(p_array + %d): %d\n", i, *(p_arr));
    }
}

// release array
void release_array(int **pp_arr){
    free(*pp_arr);
    *pp_arr = NULL;
}