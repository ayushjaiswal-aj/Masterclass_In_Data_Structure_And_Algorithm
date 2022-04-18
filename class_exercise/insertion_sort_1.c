/* insertion sort implimentation 1 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void show_array(int *p_array, int size, char* msg);
void insertion_sort(int *p_array, int size);
void insert_at_sorting_position(int *p_array, int size);

int main(void){
    int array[8];
    int i;
    for(i = 0; i < 8; i++){
        array[i] = rand() % 100;
    }

    show_array(&array[0], 8, "original array");
    insertion_sort(&array[0], 8);
    show_array(&array[0], 8, "Array after sorting");
}

void show_array(int *p_array, int size, char* msg){
    if(msg){
        puts(msg);
    }

    int i;
    for(i = 0; i < size-1; i++){
        printf("*(p_array + %d): %d\n", i, *(p_array + i));
    }
}

void insertion_sort(int *p_array, int size){
    int i;
    for(i = 2; i <= size; i ++){
        insert_at_sorting_position(p_array, i);
    }
}

void insert_at_sorting_position(int *p_array, int size){
    int key, i;
    key = *(p_array + size - 1);
    i = size - 2;
    while(i > -1){
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