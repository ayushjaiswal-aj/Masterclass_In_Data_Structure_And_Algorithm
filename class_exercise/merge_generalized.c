#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define TRUE 1

int *allocate_and_input_array(int *p_size);
void output_array(int *p_arr, int size, const char *msg);
void release_array(int **pp_arr);
void merge_generalize(int *p_arr, int p, int q, int r);

int main(void)
{

    int *p_arr = NULL;
    int N = 0;

    p_arr = allocate_and_input_array(&N);
    output_array(p_arr, N, "Before merge:");
    merge_generalize(p_arr, 0, N / 2, N-1);
    output_array(p_arr, N, "After merge:");
    release_array(&p_arr);
    return (EXIT_SUCCESS);
}

int *allocate_and_input_array(int *p_size)
{
    int *p_arr = NULL;
    int N;
    int i;
    int mid;

    printf("Enter the size of array: ");
    scanf("%d", p_size);
    assert(*p_size > 0);
    N = *p_size;
    p_arr = (int *)malloc(sizeof(int) * *p_size);
    assert(p_arr != NULL);
    mid = N / 2;
    for (i = 0; i <= mid; i++)
    {
        p_arr[i] = (i + 1) * 10;
    }

    for (i = mid + 1; i < N; i++)
    {
        p_arr[i] = (i + 1) * 5;
    }

    return p_arr;
}

void output_array(int *p_arr, int size, const char *msg)
{
    int i;
    if (msg)
    {
        puts(msg);
    }
    for (i = 0; i < size; i++)
    {
        printf("p_arr[%d]: %d\n", i, *(p_arr + i));
    }
}

void release_array(int **pp_arr)
{
    int *p_arr = NULL;
    p_arr = *pp_arr;
    free(p_arr);
    *pp_arr = NULL;
}

void merge_generalize(int *p_arr, int p, int q, int r)
{
    int *pa1 = NULL, *pa2 = NULL;
    int N1;
    int N2;
    int i, j, k;
    int cnt;

    N1 = q - p + 1;
    N2 = r - q;

    pa1 = (int *)malloc(sizeof(int) * N1);
    assert(pa1 != NULL);

    pa2 = (int *)malloc(sizeof(int) * N2);
    assert(pa2 != NULL);

    for (cnt = 0; cnt < N1; cnt++)
    {
        pa1[cnt] = p_arr[p + cnt];
    }
    for (cnt = 0; cnt < N2; cnt++)
    {
        pa2[cnt] = p_arr[q + 1 + cnt];
    }

    i = 0;
    j = 0;
    k = 0;

    while (TRUE)
    {
        if (pa1[i] <= pa2[j])
        {
            p_arr[p + k] = pa1[i];
            k = k + 1;
            i = i + 1;
            if (i == N1)
            {
                while (j < N2)
                {
                    p_arr[p + k] = pa2[j];
                    j = j + 1;
                    k = k + 1;
                }
                break;
            }
        }
        else
        {
            p_arr[p + k] = pa2[j];
            k = k + 1;
            j = j + 1;
            if (j == N2)
            {
                while (i < N1)
                {
                    p_arr[p + k] = pa1[i];
                    i = i + 1;
                    k = k + 1;
                }
                break;
            }
        }
    }
    free(pa1);
    pa1 = NULL;
    free(pa2);
    pa2 = NULL;
}
