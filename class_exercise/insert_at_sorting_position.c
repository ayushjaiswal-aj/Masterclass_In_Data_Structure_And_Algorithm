#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void insert_at_sorting_pos(int *p_array, int N);
void show_array(int *p_array, int N, const char *msg);
void insert_at_sorting_pos_1(int *p_array, int N);

int main(void){
    int array[8] = {10, 20, 30, 40, 50, 60, 70, 25};
    show_array(&array[0], 8, "Original array");
    insert_at_sorting_pos_1(&array[0], 8);
    show_array(&array[0], 8, "Array after insert at sorting position 1");
    exit(0);
}

void show_array(int *p_array, int N, const char *msg){
    if(msg){
        puts(msg);
    }
    int i;
    for(i = 0; i < N; i ++){
        printf("*(p_array + %d): %d\n", i, *(p_array + i));
    }
}

void insert_at_sorting_pos(int *p_array, int N){
    int i;
    int key;
    key = *(p_array + N - 1);
    i = N - 2;
    while(i > -1){
        if(*(p_array + i) > key){
            *(p_array + i + 1) = *(p_array + i);
            i = i - 1;
        }
        else {
            break;
        }
        *(p_array + i + 1) = key;
    }
}

void insert_at_sorting_pos_1(int *p_array, int N){
    int i;
    int key;
    key = *(p_array + N - 1);
    for(i = N-2; (i > -1 && *(p_array + i) > key); i --){
        *(p_array + i + 1) = *(p_array + i);
    }
    *(p_array+i+1) = key;
}