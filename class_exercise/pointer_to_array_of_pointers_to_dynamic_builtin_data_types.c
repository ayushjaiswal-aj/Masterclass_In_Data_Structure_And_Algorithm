#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void pointer_to_array_of_pointers_to_dynamic_int();
void pointer_to_array_of_pointers_to_dynamic_long_int();
void pointer_to_array_of_pointers_to_dynamic_char();
void pointer_to_array_of_pointers_to_dynamic_float();
void pointer_to_array_of_pointers_to_dynamic_double();

int main(void){

    pointer_to_array_of_pointers_to_dynamic_int();
    pointer_to_array_of_pointers_to_dynamic_long_int();
    pointer_to_array_of_pointers_to_dynamic_char();
    pointer_to_array_of_pointers_to_dynamic_float();
    pointer_to_array_of_pointers_to_dynamic_double();

    exit (0);
}

void pointer_to_array_of_pointers_to_dynamic_int(){
    int **ppInt = NULL;
    int i;

    ppInt = (int**) malloc(sizeof(int*) * 10);
    for(i = 0; i < 10; i ++){
        *(ppInt + i) = (int *)malloc(sizeof(int));
        *(*(ppInt + i)) = rand() % 10;
    }

    printf("array of pointer to dynamic int\n");
    for(i = 0; i < 10; i ++){
        printf("*(*(ppInt + %d)): %d\n", i, *(*(ppInt + i)));
    }
    printf("\n");

    for(i = 0; i < 10; i ++){
        free(*(ppInt+i));
        *(ppInt + i) = NULL;
    }
    free(ppInt);
    ppInt = NULL;
}

void pointer_to_array_of_pointers_to_dynamic_long_int(){
    long int **ppLongInt = NULL;
    int i;

    ppLongInt = (int **) malloc(sizeof(int *) * 10);
    for(i = 0; i < 10; i ++){
        *(ppLongInt + i) = (int *)malloc(sizeof(int));
        *(*(ppLongInt + i)) = rand();
    }

    printf("array of pointer to dynamic long int\n");
    for(i = 0; i < 10; i ++){
        printf("*(*(ppLongInt + %d)): %ld\n", i, *(*(ppLongInt + i)));
    }
    printf("\n");

    for(i = 0; i < 10; i ++){
        free(*(ppLongInt + i));
        *(ppLongInt + i) = NULL;
    }
    free(ppLongInt);
    ppLongInt = NULL;
}

void pointer_to_array_of_pointers_to_dynamic_char(){
    char **ppChar = NULL;
    int i;

    ppChar = (char **)malloc(sizeof(char*) * 10);
    for(i = 0; i < 10; i ++){
        *(ppChar + i) = (char*)malloc(sizeof(char));
        *(*(ppChar + i)) = (char) (rand() % 26 + 65);
    }

    printf("array of pointer to dyanmic char\n");
    for(i = 0; i < 10; i ++){
        printf("*(*(ppChar + %d)): %c\n", i, *(*(ppChar + i)));
    }
    printf("\n");

    for(i = 0; i < 10; i ++){
        free(*(ppChar + i));
        *(ppChar + i) = NULL;
    }
    free(ppChar);
    ppChar = NULL;
}

void pointer_to_array_of_pointers_to_dynamic_float(){
    float **ppFloat = NULL;
    int i;

    ppFloat = (float **)malloc(sizeof(float*) * 10);
    for(i = 0; i < 10; i ++){
        *(ppFloat + i) = (float*)malloc(sizeof(float));
        *(*(ppFloat + i)) = (float) rand();
    }

    printf("array of pointer to dyanmic float\n");
    for(i = 0; i < 10; i ++){
        printf("*(*(ppFloat + %d)): %f\n", i, *(*(ppFloat + i)));
    }
    printf("\n");

    for(i = 0; i < 10; i ++){
        free(*(ppFloat + i));
        *(ppFloat + i) = NULL;
    }
    free(ppFloat);
    ppFloat = NULL;
}

void pointer_to_array_of_pointers_to_dynamic_double(){
    double **ppDouble = NULL;
    int i;

    ppDouble = (double **)malloc(sizeof(double*) * 10);
    for(i = 0; i < 10; i ++){
        *(ppDouble + i) = (double*)malloc(sizeof(double));
        *(*(ppDouble + i)) = (double) rand();
    }

    printf("array of pointer to dyanmic double\n");
    for(i = 0; i < 10; i ++){
        printf("*(*(ppDouble + %d)): %f\n", i, *(*(ppDouble + i)));
    }
    printf("\n");

    for(i = 0; i < 10; i ++){
        free(*(ppDouble + i));
        *(ppDouble + i) = NULL;
    }
    free(ppDouble);
    ppDouble = NULL;
}