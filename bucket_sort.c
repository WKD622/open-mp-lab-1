#include <omp.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 


int main(int argc, char **argv) {
    clock_t begin = clock();

/* here, do your time-consuming job */

    srand(time(0)); 
    const int N = 100000;
    int i, a[N];

    #pragma omp parallel for
    for (i = 0; i < N; i++){
        int i = rand() % 100;
        a[i] = rand() % 100;
        printf("%d ", i);
    }
    
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time spent: %f\n", time_spent);

    return 0;
 }