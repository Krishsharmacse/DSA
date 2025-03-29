#include <stdio.h>
#include <stdlib.h>

// Define the structure for a sparse polynomial term
struct sparsePol {
    int coeff;  // Coefficient of the term
    int exp;    // Exponent of the term
};

// Function to add two sparse polynomials
struct sparsePol* sparseAddition(struct sparsePol *PolA, struct sparsePol *PolB, int m, int n, int *Index) {
    // Allocate memory for the result polynomial
    struct sparsePol *sum = (struct sparsePol*)malloc((m + n) * sizeof(struct sparsePol));  
    int i = 0, j = 0;
    *Index = 0;  // Initialize index of result polynomial

    // Traverse both polynomials and add them term by term
    while (i < m && j < n) {
        if (PolA[i].exp == PolB[j].exp) {
            // If exponents are the same, add the coefficients
            sum[*Index].exp = PolA[i].exp;
            sum[*Index].coeff = PolA[i].coeff + PolB[j].coeff;
            i++; j++;  // Move to next terms in both polynomials
        } else if (PolA[i].exp < PolB[j].exp) {
            // If exponent of PolA is smaller, take the term from PolB
            sum[*Index] = PolB[j];
            j++;
        } else {
            // If exponent of PolB is smaller, take the term from PolA
            sum[*Index] = PolA[i];
            i++; 
        }
        (*Index)++;
    }

    // Copy remaining terms from PolA if any
    while (i < m) {
        sum[*Index] = PolA[i];
        i++;
        (*Index)++;
    }

    // Copy remaining terms from PolB if any
    while (j < n) {
        sum[*Index] = PolB[j];
        j++;
        (*Index)++;
    }

    return sum;
}

// Function to print the result polynomial
void printPolynomial(struct sparsePol *Pol, int size) {
    if (size == 0) {
        printf("0\n");
        return;
    }

    for (int i = 0; i < size - 1; i++) {
        printf("%dx^%d + ", Pol[i].coeff, Pol[i].exp);
    }
    printf("%dx^%d\n", Pol[size - 1].coeff, Pol[size - 1].exp);
}

int main() {
    int m = 3, n = 4;
    int additionIndex = 0;

    struct sparsePol PolA[m], PolB[n];

    // Initialize PolA: 1x^7 + 6x^1 + 1x^0
    PolA[0] = (struct sparsePol){1, 7};
    PolA[1] = (struct sparsePol){6, 1};
    PolA[2] = (struct sparsePol){1, 0};

    // Initialize PolB: 2x^100 + 3x^99 + 6x^45 + 8x^0
    PolB[0] = (struct sparsePol){2, 100};
    PolB[1] = (struct sparsePol){3, 99};
    PolB[2] = (struct sparsePol){6, 45};
    PolB[3] = (struct sparsePol){8, 0};

    // Perform addition of PolA and PolB
    struct sparsePol *sum = sparseAddition(PolA, PolB, m, n, &additionIndex);

    // Print result of addition
    printf("Addition: \n");
    printPolynomial(sum, additionIndex);

    // Free allocated memory
    free(sum);

    return 0;
}


