#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to create a 2D array
int **create_2d_array(int nrow, int ncol) {
    int **a = (int **)malloc(nrow * sizeof(int *));
    for (int i = 0; i < nrow; i++) {
        a[i] = (int *)malloc(ncol * sizeof(int));
    }
    return a;
}

// Function to free memory allocated for a 2D array
void free_2d_array(int **a, int nrow) {
    for (int i = 0; i < nrow; i++) {
        free(a[i]);
    }
    free(a);
}

// Function to print a matrix
void print_matrix(int **a, int nrow, int ncol) {
    for (int i = 0; i < nrow; i++) {
        for (int j = 0; j < ncol; j++) {
            printf("%d", a[i][j]);
            if (j < ncol - 1)
                printf(" ");
        }
        printf("\n");
    }
}

// Function to read a matrix from a file
int **read_matrix(const char *filename, int *nrow, int *ncol) {
    FILE *f = fopen(filename, "r");
    fscanf(f, "%d %d\n", nrow, ncol);
    int **a = create_2d_array(*nrow, *ncol);
    for (int i = 0; i < *nrow; i++) {
        for (int j = 0; j < *ncol; j++) {
            fscanf(f, "%d", &a[i][j]);
        }
    }
    fclose(f);
    return a;
}

// Function to write a matrix to a file
void write_matrix(int **a, int nrow, int ncol, const char *filename) {
    FILE *f = fopen(filename, "w");
    fprintf(f, "%d %d\n", nrow, ncol);
    for (int i = 0; i < nrow; i++) {
        for (int j = 0; j < ncol; j++) {
            fprintf(f, "%d", a[i][j]);
            if (j < ncol - 1)
                fprintf(f, " ");
        }
        if (i < nrow - 1)
            fprintf(f, "\n");
    }
    fclose(f);
}

// Function to perform matrix multiplication
int **matrix_multiply(int **a, int **b, int nrow, int ncol) {
    int **result = create_2d_array(nrow, ncol);

    for (int i = 0; i < nrow; i++) {
        for (int j = 0; j < ncol; j++) {
            result[i][j] = 0;
            for (int k = 0; k < nrow; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return result;
}

// Main function
int main() {
    int nrow1, ncol1, nrow2, ncol2;

    // Prompt user for input choice
    printf("Enter '1' to input two file names or '2' for an integer: ");
    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        // Case 1: User inputs two file names
        char filename1[100], filename2[100];

        // Prompt user for file names
        printf("Enter the first matrix file name (matrix1.txt): ");
        scanf("%s", filename1);
        printf("Enter the second matrix file name (matrix2.txt): ");
        scanf("%s", filename2);

        // Read matrices from files
        int **matrix1 = read_matrix(filename1, &nrow1, &ncol1);
        int **matrix2 = read_matrix(filename2, &nrow2, &ncol2);

        // Check if matrix multiplication is possible
        if (ncol1 != nrow2) {
            printf("Error: Matrix multiplication not possible. Number of columns in matrix1 should be equal to the number of rows in matrix2.\n");
            free_2d_array(matrix1, nrow1);
            free_2d_array(matrix2, nrow2);
            return 1;
        }

        // Display input matrices
        printf("Matrix 1:\n");
        print_matrix(matrix1, nrow1, ncol1);

        printf("\nMatrix 2:\n");
        print_matrix(matrix2, nrow2, ncol2);

        // Perform matrix multiplication
        int **result = matrix_multiply(matrix1, matrix2, nrow1, ncol2);

        // Display result and save to file
        printf("\nMatrix Multiplication Result:\n");
        print_matrix(result, nrow1, ncol2);

        write_matrix(result, nrow1, ncol2, "matrix3.txt");

        // Free memory
        free_2d_array(matrix1, nrow1);
        free_2d_array(matrix2, nrow2);
        free_2d_array(result, nrow1);
    } else if (choice == 2) {
        // Case 2: User inputs an integer
        printf("Enter the number of rows and columns for the random matrices: ");
        scanf("%d", &nrow1);
        ncol1 = nrow1;

        // Generate random matrices
        int **matrix1 = create_2d_array(nrow1, ncol1);
        int **matrix2 = create_2d_array(nrow1, ncol1);

        // Initialize matrices with random values
        srand(time(NULL));
        for (int i = 0; i < nrow1; i++) {
            for (int j = 0; j < ncol1; j++) {
                matrix1[i][j] = rand() % 100;
                matrix2[i][j] = rand() % 100;
            }
        }

        // Write matrices to files
        write_matrix(matrix1, nrow1, ncol1, "matrix1.txt");
        write_matrix(matrix2, nrow1, ncol1, "matrix2.txt");

        // Display generated matrices
        printf("Matrix 1:\n");
        print_matrix(matrix1, nrow1, ncol1);

        printf("\nMatrix 2:\n");
        print_matrix(matrix2, nrow1, ncol1);

        // Perform matrix multiplication
        int **result = matrix_multiply(matrix1, matrix2, nrow1, ncol1);

        // Display result and save to file
        printf("\nMatrix Multiplication Result:\n");
        print_matrix(result, nrow1, ncol1);

        write_matrix(result, nrow1, ncol1, "matrix3.txt");

        // Free memory
        free_2d_array(matrix1, nrow1);
        free_2d_array(matrix2, nrow1);
        free_2d_array(result, nrow1);
    } else {
        printf("Invalid choice.\n");
        return 1;
    }

    return 0;
}
