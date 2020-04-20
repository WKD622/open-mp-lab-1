#include <omp.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 


int main(int argc, char **argv) {
    clock_t begin = clock();

    srand(time(0)); 
    const int N = 10000000;
    int *a = malloc(N * sizeof(int));
    int i;

    for (i = 0; i < N; i++){
        int i = rand() % 100;
        a[i] = rand() % 100;
    }
    
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time spent: %f\n", time_spent);

    return 0;
 }