#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SUCCESS 1
#define FAILURE 0

typedef struct {
    int *pIntArray;
    int nr_elements;
} Vector_int;

Vector_int* create_vector_int();
int add_element(Vector_int *pVecInt, int element);
void print_vector_int(Vector_int *pVecInt);
int destroy_vector_int(Vector_int **ppVecInt);

int main(void){
    
    Vector_int *pVecInt;
    int i;
    
    pVecInt = create_vector_int();
    print_vector_int(pVecInt);
    
    printf("Adding random elements to vector...\n");
    for(i = 0; i < 10; i ++){
        add_element(pVecInt, rand() % 10);
    }
    
    printf("After adding:\n");
    print_vector_int(pVecInt);
    
    printf("destroying vector int...\n");
    destroy_vector_int(&pVecInt);

    print_vector_int(pVecInt);
    
    exit(0);
}

Vector_int* create_vector_int(){
    Vector_int *pVecInt = (Vector_int*)malloc(sizeof(Vector_int));
    assert(pVecInt != NULL);
    pVecInt->nr_elements = 0;
    pVecInt->pIntArray = (int*)malloc(sizeof(int));
    assert(pVecInt->pIntArray != NULL);
    return pVecInt;
}

int add_element(Vector_int *pVecInt, int element){
    pVecInt->nr_elements ++;
    pVecInt->pIntArray = (int*)realloc(pVecInt->pIntArray, pVecInt->nr_elements);
    assert(pVecInt->pIntArray != NULL);
    printf("element: %d\n", element);
    *(pVecInt->pIntArray + (pVecInt->nr_elements - 1)) = element;
    printf("*(pVecInt->pIntArray + (pVecInt->nr_elements - 1)) = %d\n", *(pVecInt->pIntArray + (pVecInt->nr_elements - 1)));
    return SUCCESS;
}

void print_vector_int(Vector_int *pVecInt){
    if(pVecInt->nr_elements == 0){
        printf("No elements\n");
        return;
    }
    int i;
    printf("pVecInt->nr_elements: %d\n", pVecInt->nr_elements);
    for(i = 0; i < pVecInt->nr_elements; i++){
        printf("*(pVecInt->pIntArray + %d): %d\n", i, *(pVecInt->pIntArray + i));
    }
}

int destroy_vector_int(Vector_int **ppVecInt){
    Vector_int *pVecInt;
    pVecInt = *ppVecInt;
    free(pVecInt->pIntArray);
    pVecInt->pIntArray = NULL;
    pVecInt->nr_elements = 0;
    free(pVecInt);
    pVecInt = NULL;
    return SUCCESS;
}