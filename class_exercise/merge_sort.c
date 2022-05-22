#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define TRUE 1

void input(int* a, int N); 
void output(int* a, int N, const char* msg);
void merge_sort(int* a, int p, int r); 
void merge(int* a, int p, int q, int r); 
void sort(int* a, int N); 

int main(int argc, char *argv[]){
    int *p_arr = NULL;
    int N;

    if(argc != 2){
        printf("Invalid usage: %s nr_elements\n", argv[0]);
        return(EXIT_FAILURE);
    }

    N = atoi(argv[1]);
    assert(N > 0);

    p_arr = (int*)malloc(sizeof(int) * N);
    assert(p_arr != NULL);

    input(p_arr, N);
    output(p_arr, N, "Original Array:");
    sort(p_arr, N);
    output(p_arr, N, "Array after sorting");

    return (EXIT_SUCCESS);
}

void input(int* a, int N){
    int i;
    for(i = 0; i < N; i++){
        a[i] = rand();
    }
}

void output(int* a, int N, const char* msg){
    if(msg != NULL){
        puts(msg);
    }
    int i;
    for(i = 0; i < N; i++){
        printf("arr[%d]: %d\n", i, a[i]);
    }
}

void merge_sort(int* a, int p, int r){
    int q;
    if(p < r){
        q = (p + r)/2;
        merge_sort(a, p, q);
        merge_sort(a, q+1, r);
        merge(a, p, q, r);
    }
}

void merge(int* a, int p, int q, int r){
    int N1, N2;
    int i, j, k;
    int *arr1 = NULL;
    int *arr2 = NULL;

    N1 = q - p + 1;
    N2 = r - q;

    arr1 = (int*)malloc(sizeof(int) * N1);
    arr2 = (int*)malloc(sizeof(int) * N2);

    i = 0;
    for(i = 0; i < N1; i++){
        arr1[i] = a[p+i]; 
    }

    i = 0;
    for(i = 0; i < N2; i++){
        arr2[i] = a[q+i+1];
    }

    i = 0;
    j = 0;
    k = 0;

    while(TRUE){
        if(arr1[i] <= arr2[j]){
            a[p + k] = arr1[i];
            i++;
            k++;
            if(i == N1){
                while(j < N2){
                    a[p + k] = arr2[j];
                    k++;
                    j++;
                }
                break;
            }
        }
        else{
            a[p + k] = arr2[j];
            j++;
            k++;
            if(j == N2){
                while(i < N1){
                    a[p + k] = arr1[i];
                    i++;
                    k++;
                }
                break;
            }
        }
    }

    free(arr1);
    arr1 = NULL;

    free(arr2);
    arr2 = NULL;
}

void sort(int* a, int N){
    merge_sort(a, 0, N-1);
}