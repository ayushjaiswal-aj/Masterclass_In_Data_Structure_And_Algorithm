#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(void){
    int **p = (int **) malloc(5 * sizeof(int*));
    assert(p != NULL);
    int i;
    int n;

    for(i = 0; i < 5; i ++){
        *(p + i) = malloc(sizeof(int));
        assert(*(p+i) != NULL);
    }

    for(i = 0; i < 5; i ++){
        *(*p + i) = i * 100;
    }

    for(i = 0; i < 5; i ++){
        n = *(*p + i);
        printf("n = %d\n", n);
    }

    for(i = 0; i < 5; i ++){
        free(*(p + i));
        *(p + i) = NULL;
    }
    free(p);
    p =  NULL;
    exit (0);
}