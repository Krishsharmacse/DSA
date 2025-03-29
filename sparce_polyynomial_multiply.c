#include <stdio.h>
#include <stdlib.h>

// Define the structure for a sparse polynomial term
struct sparsePol {
    int coeff;  // Coefficient of the term
    int exp;    // Exponent of the term
};

// Function to multiply two sparse polynomials
struct sparsePol* sparseMultiplication(struct sparsePol *PolA, struct sparsePol *PolB, int m, int n, int *resSize) {
    // Allocate memory for the result polynomial (max possible size is m * n)
    struct sparsePol *result = (struct sparsePol*)malloc((m * n) * sizeof(struct sparsePol));  
    int index = 0;

    // Multiply each term of PolA by each term of PolB
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int exp = PolA[i].exp + PolB[j].exp;  // Sum of exponents
            int coeff = PolA[i].coeff * PolB[j].coeff;  // Product of coefficients

            // Check if the term with the same exponent already exists in the result polynomial
            int found = 0;
            for (int k = 0; k < index; k++) {
                if (result[k].exp == exp) {
                    // If the exponent exists, add the coefficients
                    result[k].coeff += coeff;
                    found = 1;
                    break;
                }
            }

            // If the term with the same exponent is not found, add it as a new term
            if (!found) {
                result[index].exp = exp;
                result[index].coeff = coeff;
                index++;
            }
        }
    }

    *resSize = index;  // Store the number of terms in the result
    return result;
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
    int resultSize = 0;

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

    // Perform multiplication of PolA and PolB
    struct sparsePol *product = sparseMultiplication(PolA, PolB, m, n, &resultSize);

    // Print result of multiplication
    printf("Multiplication: \n");
    printPolynomial(product, resultSize);

    // Free allocated memory
    free(product);

    return 0;
}
