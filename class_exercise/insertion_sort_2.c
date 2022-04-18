/* insertion sort implimentatino 2 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define SUCCESS 1
#define FAILURE 0

int* get_array(int *size);
int input_array(int *p_array, int size);
int release_array(int **pp_array);

void show_array(int *p_array, int size, char *msg);

int sort_array(int *p_array, int size);
void insert_at_sorting_position(int *p_array, int size);

int main(void){
    int *p_array = NULL;
    int size;

    p_array = get_array(&size);
    input_array(p_array, size);

    show_array(p_array, size, "original array");
    
    sort_array(p_array, size);
    show_array(p_array, size, "array after sorting");

    release_array(&p_array);

    exit (0);
}

int* get_array(int *size){
    int *p_array = NULL;
    
    printf("Enter size of array: ");
    scanf("%d", size);
    
    p_array = (int *) malloc(sizeof(int) * (*size));
    assert(p_array != NULL);
    
    memset(p_array, 0, ((*size) * sizeof(int)));
    
    return (p_array);
}

int input_array(int *p_array, int size){
    int i;
    for(i = 0; i < size; i ++){
        *(p_array + i) = rand() % 100;
    }
    return SUCCESS;
}

void show_array(int *p_array, int size, char *msg){
    if(msg) {
        puts(msg);
    }
    int i;
    for(i = 0; i < size; i++){
        printf("*(p_array + %d): %d\n", i, *(p_array + i));
    }
}

int release_array(int **pp_array){
    int *p = NULL;
    p = *pp_array;
    free(p);
    p = NULL;
    return SUCCESS;
}

int sort_array(int *p_array, int size){
    int i;
    for(i = 2; i <= size; i ++){
        insert_at_sorting_position(p_array, i);
    }
    return SUCCESS;
}

void insert_at_sorting_position(int *p_array, int size){
    int i;
    int key;
    key = *(p_array + size - 1);
    i = size - 2;
    while (i > -1){
        if(*(p_array + i) > key){
            *(p_array + i + 1) = *(p_array + i);
            i = i - 1;
        }
        else {
            break;
        } 
    }
    *(p_array + i + 1) = key;
}