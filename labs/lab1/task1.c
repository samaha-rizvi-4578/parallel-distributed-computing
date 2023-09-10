#include <stdio.h>
#include <omp.h>

int main() {
    int array_sizes[] = {1000, 3000, 5000, 7000, 10000}; // Different array sizes
    int num_sizes = sizeof(array_sizes) / sizeof(array_sizes[0]);

    for (int k = 0; k < num_sizes; k++) {
        int ARRAY_SIZE = array_sizes[k];

        int array1[ARRAY_SIZE];
        int array2[ARRAY_SIZE];
        int result[ARRAY_SIZE];

        // Initialize arrays with some values
        for (int i = 0; i < ARRAY_SIZE; i++) {
            array1[i] = i;
            array2[i] = 2 * i;
        }

        double start;
        double end;

        start = omp_get_wtime(); // Get start time

        // Parallelize the array addition using OpenMP
        #pragma omp parallel for num_threads(2)
        for (int i = 0; i < ARRAY_SIZE; i++) {
            result[i] = array1[i] + array2[i];
        }

        end = omp_get_wtime(); // Get end time

        printf("ARRAY_SIZE = %d: \tTime Taken =  %f seconds\n", ARRAY_SIZE, end - start); // Print execution time
	printf("\n===============================================\n");
    }

    return 0;
}
