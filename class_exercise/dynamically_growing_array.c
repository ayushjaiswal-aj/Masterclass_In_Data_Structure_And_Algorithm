#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define TRUE 1

int main(void){
    int n;
    int res;
    int *arr;
    int size = 0;
    int index = 0;
    int i;
    
    arr = (int*)calloc(1, sizeof(int));
    assert(arr != NULL);

    while(TRUE){
        printf("Do you want to enter number? Yes-> 1/ No-> 0:\t");
        scanf("%d", &res);

        if(res != 1){
            break;
        }

        printf("Enter the number:\t");
        scanf("%d", &n);

        size++;
        arr = (int*)realloc(arr, size);
        assert(arr != NULL);
        arr[index] = n;
        index ++;
    }

    printf("Size: %d\n", size);
    
    printf("Entered Elements are: \n");
    for(i = 0; i < size; i ++){
        printf("%d\n", arr[i]);
    }
    

    free (arr);
    arr = NULL;
    exit(0);
}