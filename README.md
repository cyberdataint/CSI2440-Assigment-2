# CSI2440-Assigment-2
# Matrix Multiplication in C

This C program performs matrix multiplication using either user-input matrices from files or randomly generated matrices. The resulting matrix is then saved to a file.

## Program Description

This program utilizes C to perform matrix multiplication. It supports two modes of operation: 
1. User provides two matrices through file input.
2. The program generates two random matrices based on user input for the matrix dimensions.

The matrix multiplication result is then displayed and saved to a file (`matrix3.txt`). The program also includes functions for matrix creation, printing, reading from files, and writing to files.

## Prerequisites

Make sure you have a C compiler installed on your system.

## How to Use

### 1. Clone the Repository

~~~ 
git clone https://github.com/cyberdataint/CSI2440-Assigment-2.git
~~~

### Go to working directory

~~~
cd CSI2440-Assigment-2
~~~

### 2. How to compile the Program 

~~~
gcc test.c
~~~

### 3. How to run the program

~~~
a.exe
~~~

## How the Program Works
### 1. User Input:

- The program begins by prompting the user to enter '1' to input two file names or '2' for an integer.

### 2. Case 1 - User Inputs File Names:

- If the user chooses '1,' they are prompted to enter the file names for two matrices (matrix1.txt and matrix2.txt).
- The matrices are then read from the files, and their dimensions are checked to ensure matrix multiplication is possible.
- The input matrices are displayed, and the result of the multiplication is calculated, displayed, and saved to a file (matrix3.txt).
### 3. Case 2 - User Inputs Integer:

- If the user chooses '2,' they are prompted to enter the number of rows and columns for randomly generated matrices.
- Two matrices (matrix1.txt and matrix2.txt) are created with random values and saved to files.
- The generated matrices are displayed, and the result of the multiplication is calculated, displayed, and saved to a file (matrix3.txt).

### 4. Invalid Choice:

- If the user enters an invalid choice, an error message is displayed, and the program exits with a status code of 1.

