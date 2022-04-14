#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void pointer_to_array_of_int();
void pointer_to_array_of_long_int();
void pointer_to_array_of_char();
void pointer_to_array_of_float();
void pointer_to_array_of_double();

int main(void){
    
    pointer_to_array_of_int();
    pointer_to_array_of_long_int();
    pointer_to_array_of_char();
    pointer_to_array_of_float();
    pointer_to_array_of_double();

    exit(0);
}

void pointer_to_array_of_int(){
    int *pInt = NULL;
    int nArray[10];
    int i;

    for(i = 0; i < 10; i ++){
        nArray[i] = rand() % 10;
    }

    printf("Array of int:\n");
    printf("Printing int array using array dereferencing:\n");
    for(i = 0; i < 10; i ++){
        printf("array[%d]: %d\n", i, nArray[i]);
    }

    pInt = &nArray[0];      // this is equivalent => pInt = nArray

    printf("Printing int array using pointer:\n");
    for(i = 0; i < 10; i ++){
        printf("*(pInt + %d): %d\n", i, *(pInt + i));
    }

    printf("\n");
}

void pointer_to_array_of_long_int(){
    long int *pLongInt = NULL;
    long int lnArray[10];
    int i;

    for(i = 0; i < 10; i ++){
        lnArray[i] = rand() * rand();
    }

    printf("Array of long int: \n");
    printf("Printing long int array using array dereferencing: \n");
    for(i = 0; i < 10; i ++){
        printf("lnArray[%d]: %ld\n", i, lnArray[i]);
    }

    pLongInt = &lnArray[0];     // this is equivalent to => pLongInt = lnArray;
    printf("Printing long int array using pointer: \n");
    for(i = 0; i < 10; i ++){
        printf("*(pLongInt + %d): %ld\n", i, *(pLongInt + i));
    }

    printf("\n");
}

void pointer_to_array_of_char(){
    char *pChar = NULL;
    char cArray[10];
    int i;

    for(i = 0; i < 10; i ++){
        cArray[i] = (char)((rand() % 26) + 65);
    } 

    printf("Array of char: \n");
    printf("Printing char array using array dereferencing: \n");
    for(i = 0; i < 10; i ++){
        printf("cArray[%d]: %c\n", i, cArray[i]);
    }

    pChar = &cArray[0];
    printf("Printing char array using pointer: \n");
    for(i = 0; i < 10; i ++){
        printf("*(pChar + %d): %c\n", i, *(pChar + i));
    }

    printf("\n");
}

void pointer_to_array_of_float(){
    float *pFloat = NULL;
    float fArray[10];
    int i;

    for(i = 0; i < 10; i ++){
        fArray[i] = rand();
    }

    printf("Array of float: \n");
    printf("Printing float array using array dereferencing: \n");
    for(i = 0; i < 10; i ++){
        printf("fArray[%d]: %f\n", i, fArray[i]);
    }

    pFloat = &fArray[0];
    printf("Printing float array using pointer: \n");
    for(i = 0; i < 10; i ++){
        printf("*(pFloat + %d): %f\n", i, *(pFloat + i));
    }

    printf("\n");
}

void pointer_to_array_of_double(){
    double *pDouble = NULL;
    double dArray[10];
    int i;

    for(i = 0; i < 10; i ++){
        dArray[i] = rand();
    }

    printf("Array of double: \n");
    printf("Printing double array using array dereferencing: \n");
    for(i = 0; i < 10; i ++){
        printf("dArray[%d]: %lf\n", i, dArray[i]);
    }

    pDouble = &dArray[0];
    printf("Printing double array using pointer: \n");
    for(i = 0; i < 10; i ++){
        printf("*(pDouble + %d): %lf\n", i, *(pDouble + i));
    }

    printf("\n");
}