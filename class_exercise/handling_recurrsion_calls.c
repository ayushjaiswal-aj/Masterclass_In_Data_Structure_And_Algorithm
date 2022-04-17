#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void print_1_to_N(int N);
void print_N_to_0(int N);
void print_array(int *pArray, int size, int index);

int main(){
    int n;
    int array[10] = {0,1,2,3,4,5,6,7,8,9};

    printf("Enter N: ");
    scanf("%d", &n);
    assert(n > 0);
    print_1_to_N(n);
    print_N_to_0(n);
    print_array(&array[0], 10, 0);
}

void print_1_to_N(int N){
    if(N > 0){
        print_N_to_0(N-1);
        printf("N: %d\n", N);
    }
    else {
        return ;
    }
}

void print_N_to_0(int N){
    if(N < 0){
        return ;
    }
    else {
        printf("N: %d\n", N);
        print_N_to_0(N-1);
    }
}

void print_array(int *pArray, int size, int index){
    if(index < size){
        printf("array[%d]: %d\n", index, *(pArray + index));
        print_array(pArray, size, index+1);
    }
    else {
        return;
    }
}