#include <stdio.h> 
#include <stdlib.h> 

int a = 10; 
int b = 20; 
int c = 40; 
int d = 30; 

int status; 

void f1(int, int); 
int f2(int); 
int g1(int, int, int); 
float g2(int, float); 
int h1(int); 
void h2(void); 

int main(void)
{
    int ret; 
    if(a > b)
        f1(10, 20); 
    else 
        ret = f2(100); 

    return (status); 
}

void f1(int x, int y)
{
    float z; 

    z = ((float)(x+y))/2; 
}

int f2(int x)
{
    int sq;
    int tmp;  
    sq = x * x; 
    if(c > d)
        g1(1000, 2000, 3000); 
    else 
        tmp = g2(15, 3.14f); 
    return sq; 
}

int g1(int p, int q, int r)
{
    int tmp; 

    tmp = p*p + q*q + r*r; 
    h2(); 
    return tmp; 
}

void h2(void)
{
    int s; 
    int ret; 
    s = 3; 
    ret = h1(s); 
}

int h1(int x)
{
    int t; 
    t = x*x*x; 
    return (t); 
}

float g2(int a1, float b1){
    return b1;
}