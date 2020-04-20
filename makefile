all: 
	gcc -Wall bucket_sort.c -o bucket_sort -fopenmp
	./bucket_sort