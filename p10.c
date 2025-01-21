#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>

#define MAX 3000

int mat1[MAX][MAX];
int mat2[MAX][MAX];
int result_seq[MAX][MAX];
int result_par[MAX][MAX];

int main() {
    int n;
    printf("Enter the dimensions of the square matrix (e.g., 1000, 2000, 3000): ");
    scanf("%d", &n);

    if (n > MAX) {
        printf("Matrix size exceeds the maximum allowed dimension of %d. Exiting...\n", MAX);
        return -1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat1[i][j] = rand() % 10;
            mat2[i][j] = rand() % 10;
            result_seq[i][j] = 0;
            result_par[i][j] = 0;
        }
    }

    time_t st, et;
    st = clock();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                result_seq[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    et = clock();
    printf("Sequential Time: %.6f seconds\n", (double)(et - st) / CLOCKS_PER_SEC);
    
    st = clock();
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                result_par[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    et = clock();
    printf("Parallel Time: %.6f seconds\n", (double)(et - st) / CLOCKS_PER_SEC);

    return 0;
}
