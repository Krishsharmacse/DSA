#include <stdio.h>

#define MAX 100 // Maximum number of non-zero elements

typedef struct {
    int row;
    int col;
    int value;
} SparseMatrixElement;

typedef struct {
    SparseMatrixElement elements[MAX];
    int size; // Number of non-zero elements
} SparseMatrix;

// Function to initialize a sparse matrix
void initSparseMatrix(SparseMatrix *matrix) {
    matrix->size = 0;
}

// Function to insert an element into the sparse matrix
void insertElement(SparseMatrix *matrix, int row, int col, int value) {
    if (value != 0 && matrix->size < MAX) {
        matrix->elements[matrix->size].row = row;
        matrix->elements[matrix->size].col = col;
        matrix->elements[matrix->size].value = value;
        matrix->size++;
    }
}

// Function to add two sparse matrices
SparseMatrix addSparseMatrices(SparseMatrix *a, SparseMatrix *b) {
    SparseMatrix result;
    initSparseMatrix(&result);
    
    int i = 0, j = 0;

    while (i < a->size && j < b->size) {
        if (a->elements[i].row == b->elements[j].row && a->elements[i].col == b->elements[j].col) {
            // Same position, add values
            insertElement(&result, a->elements[i].row, a->elements[i].col, a->elements[i].value + b->elements[j].value);
            i++;
            j++;
        } else if (a->elements[i].row < b->elements[j].row || 
                   (a->elements[i].row == b->elements[j].row && a->elements[i].col < b->elements[j].col)) {
            // Element in matrix A comes first
            insertElement(&result, a->elements[i].row, a->elements[i].col, a->elements[i].value);
            i++;
        } else {
            // Element in matrix B comes first
            insertElement(&result, b->elements[j].row, b->elements[j].col, b->elements[j].value);
            j++;
        }
    }

    // Add remaining elements from matrix A
    while (i < a->size) {
        insertElement(&result, a->elements[i].row, a->elements[i].col, a->elements[i].value);
        i++;
    }

    // Add remaining elements from matrix B
    while (j < b->size) {
        insertElement(&result, b->elements[j].row, b->elements[j].col, b->elements[j].value);
        j++;
    }

    return result;
}

// Function to print the sparse matrix
void printSparseMatrix(SparseMatrix *matrix) {
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < matrix->size; i++) {
        printf("%d\t%d\t%d\n", matrix->elements[i].row, matrix->elements[i].col, matrix->elements[i].value);
    }
}

int main() {
    SparseMatrix matrixA, matrixB, result;
    
    // Initialize matrices
    initSparseMatrix(&matrixA);
    initSparseMatrix(&matrixB);

    // Insert elements into matrix A
    insertElement(&matrixA, 0, 0, 5);
    insertElement(&matrixA, 1, 2, 3);

    // Insert elements into matrix B
    insertElement(&matrixB, 0, 0, 2);
    insertElement(&matrixB, 1, 2, 4);

    // Add the two sparse matrices
    result = addSparseMatrices(&matrixA, &matrixB);

    // Print the result
    printf("Result of Sparse Matrix Addition:\n");
    printSparseMatrix(&result);

    return 0;
}