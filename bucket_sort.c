#include <omp.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 


int main(int argc, char **argv) {
    srand(time(0)); 
    const int N = 100000;
    int i, a[N];

    #pragma omp parallel for
    for (i = 0; i < N; i++)
        a[i] = rand() % 100;
    
    printf("dupa");

    return 0;
 }