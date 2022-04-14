#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(void){
    int **pp;
    int n;
    int i, j;
    int count = 0;

    pp = (int**)malloc(sizeof(int*) * 5);
    assert(pp != NULL);

    for(i = 0; i < 5; i ++){
        *(pp + i) = (int *) malloc(sizeof(int) * 3);
        assert(*(pp + i) != NULL);
    }

    for(i = 0; i < 5; i ++){
        for(j = 0; j < 3; j ++){
            *(*(pp + i) + j) = count++;
        }
    }

    for(i = 0; i < 5; i ++){
        for(j = 0; j < 3; j ++){
            n = *(*(pp + i) + j);
            printf("n = %d\n", n);
        }
    }
}