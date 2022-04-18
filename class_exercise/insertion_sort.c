#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include <string.h> 

void input_array(int* p, int N); 
void sort_array(int* p, int N); 
void output_array(int* p, int N); 
void release_array(int** pp); 

void insert_at_sorting_pos(int* p, int N); 

int main(int argc, char *argv[]){
    int *p;
    int size;

    if(argc != 2){
        printf("Invalid usage\n");
        exit (EXIT_FAILURE);
    }

    size = atoi(argv[1]);
    if(size <= 0){
        printf("Invalid array size\n");
        exit (EXIT_FAILURE);
    }

    p = (int*) malloc(sizeof(int) * size);
    if(p == NULL){
        printf("Array memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    input_array(p, size);
    printf("Original array\n");
    output_array(p, size);
    sort_array(p, size);
    printf("Array after sorting\n");
    output_array(p, size);
    release_array(&p);

    exit(0);
}

void input_array(int* p, int N){
    int i;
    for(i = 0; i < N; i++){
        *(p + i) = rand();
    }
}

void sort_array(int* p, int N){
    int i;
    for(i = 2; i <= N; i++){
        insert_at_sorting_pos(p, i);
    }
}

void output_array(int* p, int N){
    int i;
    for(i = 0; i < N; i++){
        printf("*(p + %d): %d\n", i, *(p + i));
    }
}

void release_array(int** pp){
    free(*pp);
    *pp = NULL;
} 

void insert_at_sorting_pos(int* p, int N){
    int i, key;
    key = *(p + N - 1);
    i = N - 2;
    while(i > -1){
        if(*(p+i) > key){
            *(p+i+1) = *(p+i);
            i = i - 1;
        }
        else {
            break;
        }
    }
    *(p+i+1) = key;
}