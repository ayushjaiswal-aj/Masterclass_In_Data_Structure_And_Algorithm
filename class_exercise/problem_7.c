#include <stdio.h> 
#include <stdlib.h> 

// take value of N as 8 for practice 

int N; 

void f(int i, int j); 

int main(void)
{
    printf("Enter N:"); 
    scanf("%d", &N); 
    f(1, N); 
    return (0); 
}

void f(int i, int j)
{
    int mid; 
    if(i < j)
    {
        printf("i=%d, j=%d\n", i, j); 
        mid = (i+j)/2; 
        f(i, mid); 
        f(mid+1, j); 
    }
}