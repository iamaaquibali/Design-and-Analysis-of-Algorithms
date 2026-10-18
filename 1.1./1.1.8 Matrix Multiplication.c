#include <stdio.h>

int main() {
    int r1, c1, r2, c2;
    
    // Read dimensions of Matrix A
    scanf("%d %d", &r1, &c1);

    int A[r1][c1];

    // Read Matrix A
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Read dimensions of Matrix B
    scanf("%d %d", &r2, &c2);

    // Check whether multiplication is possible
    if (c1 != r2) {
        printf("Invalid input\n");
        return 0;
    }

    int B[r2][c2];
    int result[r1][c2];

    // Read Matrix B only if multiplication is possible
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Initialize and calculate result matrix
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;

            for (int k = 0; k < c1; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Print result matrix
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d ", result[i][j]);

            // if (j < c2 - 1)
            //     printf(" ");
        }
        printf("\n");
    }

    return 0;
}
