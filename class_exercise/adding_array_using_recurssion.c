/*
    P5: Write a recurrsive function to find summation of all elements of array
    P6: Write a recurrsive funciton to find multiplication of all elements of array
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int recurrsive_array_addition(int *pArray, int size, int index);
int recurrsive_array_multiplication(int *pArray, int size, int index);

int main(void)
{
    int array[5] = {2, 5, 8, 9, 11};
    printf("addition of array: %d\n", recurrsive_array_addition(&array[0], 5, 0));
    printf("Multiplication of array: %d\n", recurrsive_array_multiplication(&array[0], 5, 0));
}

int recurrsive_array_addition(int *pArray, int size, int index){
    if(index == size){
        return 0;
    }
    return pArray[index] + recurrsive_array_addition(pArray, size, index+1);
}

int recurrsive_array_multiplication(int *pArray, int size, int index){
    if(index == size){
        return 1;
    }
    return pArray[index] * recurrsive_array_multiplication(pArray, size, index+1);
}
