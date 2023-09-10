#include <stdio.h>
#include <omp.h>

#define MIN_ARRAY_SIZE 1000
#define MAX_ARRAY_SIZE 10000

int main() {
    double start, end;
    int chunk_sizes[] = {1, 2};
    int LENGTH = sizeof(chunk_sizes) / sizeof(chunk_sizes[0]);

    printf("ARRAY SIZE\tCHUNK SIZE\tSCHEDULING\tTIME\n");

    for (int ARRAY_SIZE = MIN_ARRAY_SIZE; ARRAY_SIZE <= MAX_ARRAY_SIZE; ARRAY_SIZE += 2000) {
        int array[ARRAY_SIZE];

        for (int i = 0; i < ARRAY_SIZE; i++) {
            array[i] = i + 1;
        }

        for (int i = 0; i < LENGTH; i++) {
            int CHUNK_SIZE = chunk_sizes[i];
            int sum = 0;

            // Static Scheduling
            start = omp_get_wtime();
            #pragma omp parallel for schedule(static, CHUNK_SIZE) reduction(+:sum)
            for (int j = 0; j < ARRAY_SIZE; j++) {
                sum += array[j];
            }
            end = omp_get_wtime();
            printf("%d\t\t%d\t\tStatic\t\t%f\n", ARRAY_SIZE, CHUNK_SIZE, end - start);
            sum = 0; // Reset sum for the next iteration

            // Dynamic Scheduling
            start = omp_get_wtime();
            #pragma omp parallel for schedule(dynamic, CHUNK_SIZE) reduction(+:sum)
            for (int j = 0; j < ARRAY_SIZE; j++) {
                sum += array[j];
            }
            end = omp_get_wtime();
            printf("%d\t\t%d\t\tDynamic\t\t%f\n", ARRAY_SIZE, CHUNK_SIZE, end - start);
        }
    }

    return 0;
}

