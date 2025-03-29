#include <stdio.h>
#include <stdlib.h>

typedef struct matrix {
    int Row;
    int Col;
    int Val;
} matrix;

void printMatrix(matrix *X, int size);
matrix* SparseMultiplication(matrix *A, matrix *B, int m, int n, int *Index);
matrix* FastTranspose(matrix *B, int n, int *BtSize);

int main() {
    int m = 4, n = 3, MulIndex = 0;
    matrix A[] = {
        {0, 1, 5},
        {1, 0, 2},
        {2, 2, 4},
        {3, 1, 7}
    };

    matrix B[] = {
        {0, 1, 2},
        {1, 2, 3},
        {2, 1, 5}
    };

    matrix *mul = SparseMultiplication(A, B, m, n, &MulIndex);

    printf("Multiplication Result: \n");
    printMatrix(mul, MulIndex);

    free(mul);
    return 0;
}

void printMatrix(matrix *X, int size) {
    printf("Row   Column   Value\n");
    for (int i = 0; i < size; i++) {
        printf("%d      %d       %02d\n", X[i].Row, X[i].Col, X[i].Val);
    }
    printf("\n");
}

matrix* SparseMultiplication(matrix *A, matrix *B, int m, int n, int *Index) {
    int BtSize;
    matrix *Bt = FastTranspose(B, n, &BtSize);

    // Result can have at most m * n non-zero entries, but we will resize it later
    matrix *result = (matrix *)malloc(m * n * sizeof(matrix));
    int k = 0; // To count the number of non-zero entries

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < BtSize; j++) {
            if (A[i].Col == Bt[j].Row) {
                int product = A[i].Val * Bt[j].Val;
                int found = 0;

                for (int r = 0; r < k; r++) {
                    if (result[r].Row == A[i].Row && result[r].Col == Bt[j].Col) {
                        result[r].Val += product;
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    result[k].Row = A[i].Row;
                    result[k].Col = Bt[j].Col;
                    result[k].Val = product;
                    k++;
                }
            }
        }
    }

    // Resize result to the actual number of non-zero entries
    result = (matrix *)realloc(result, k * sizeof(matrix));
    *Index = k;

    free(Bt);

    return result;
}

matrix* FastTranspose(matrix *B, int n, int *BtSize) {
    int maxCol = 0;

    // Find the maximum column index to determine size of Bt
    for (int i = 0; i < n; i++) {
        if (B[i].Col > maxCol) {
            maxCol = B[i].Col;
        }
    }

    int C = maxCol + 1; // Number of columns in B
    matrix *Bt = (matrix*)malloc(n * sizeof(matrix));
    int *counter = (int*)calloc(C, sizeof(int));
    int *PosBt = (int*)calloc(C, sizeof(int));

    // Count occurrences of each column
    for (int i = 0; i < n; i++) {
        counter[B[i].Col]++;
    }

    // Calculate the starting position for each column in Bt
    PosBt[0] = 0;
    for (int i = 1; i < C; i++) {
        PosBt[i] = PosBt[i - 1] + counter[i - 1];
    }

    // Fill the transposed matrix
    for (int i = 0; i < n; i++) {
        int col = B[i].Col;
        Bt[PosBt[col]].Row = col;
        Bt[PosBt[col]].Col = B[i].Row;
        Bt[PosBt[col]].Val = B[i].Val;
        PosBt[col]++;
    }

    free(counter);
    free(PosBt);

    *BtSize = n; // Size of transposed matrix is the same as B
    return Bt;
}