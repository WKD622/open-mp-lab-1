#include <omp.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <time.h>

void runStatic(int N, int chunk)
{
    char *arr = malloc(sizeof(char) * N);
    double start;
    double end;
    size_t i;

    start = omp_get_wtime();
#pragma omp parallel shared(arr, chunk)
    {
        unsigned int seed = time(NULL);
#pragma omp for private(i) schedule(static, chunk)
        for (i = 0; i < N; i++)
        {
            arr[i] = rand_r(&seed);
        }
    }
    end = omp_get_wtime();
    printf("%s,%d,%f\n", "static", chunk, end - start);

    free(arr);
}

void runDynamic(int N, int chunk)
{
    char *arr = malloc(sizeof(char) * N);
    double start;
    double end;
    size_t i;

    start = omp_get_wtime();
#pragma omp parallel shared(arr, chunk)
    {
        unsigned int seed = time(NULL);
#pragma omp for private(i) schedule(dynamic, chunk)
        for (i = 0; i < N; i++)
        {
            arr[i] = rand_r(&seed);
        }
    }
    end = omp_get_wtime();
    printf("%s,%d,%f\n", "dynamic", chunk, end - start);

    free(arr);
}

void runGuided(int N, int chunk)
{
    char *arr = malloc(sizeof(char) * N);
    double start;
    double end;
    size_t i;

    start = omp_get_wtime();
#pragma omp parallel shared(arr, chunk)
    {
        unsigned int seed = time(NULL);
#pragma omp for private(i) schedule(guided, chunk)
        for (i = 0; i < N; i++)
        {
            arr[i] = rand_r(&seed);
        }
    }
    end = omp_get_wtime();
    printf("%s,%d,%f\n", "guided", chunk, end - start);

    free(arr);
}

void runRuntime(int N)
{
    char *arr = malloc(sizeof(char) * N);
    double start;
    double end;
    size_t i;

    start = omp_get_wtime();
#pragma omp parallel shared(arr)
    {
        unsigned int seed = time(NULL);
#pragma omp for private(i) schedule(runtime)
        for (i = 0; i < N; i++)
        {
            arr[i] = rand_r(&seed);
        }
    }
    end = omp_get_wtime();
    printf("%s,%d,%f\n", "runtime", 0, end - start);

    free(arr);
}

void runAuto(int N)
{
    char *arr = malloc(sizeof(char) * N);
    double start;
    double end;
    size_t i;

    start = omp_get_wtime();
#pragma omp parallel shared(arr)
    {
        unsigned int seed = time(NULL);
#pragma omp for private(i) schedule(auto)
        for (i = 0; i < N; i++)
        {
            arr[i] = rand_r(&seed);
        }
    }
    end = omp_get_wtime();
    printf("%s,%d,%f\n", "auto", 0, end - start);

    free(arr);
}

int main(int argc, char **argv)
{

    int chunks[] = {10, 100, 1000, 10000, 1000000};

    printf("schedule,chunk,time\n");
    int size = 1000000000;

    printf("Size %d \n", size);
    int j;
    for (j = 0; j < 5; j++)
        runStatic(size, chunks[j]);
    for (j = 0; j < 5; j++)
        runDynamic(size, chunks[j]);
    for (j = 0; j < 5; j++)
        runGuided(size, chunks[j]);

    runRuntime(size);
    runAuto(size);

    return 0;
}