// Inversion of a matrix in done by using 2D array only.

// 1) Imports
#include <iostream>
using namespace std;

// Function to Print matrix.
void printMatrix(float** ar, int n, int m)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << ar[i][j] << " ";
		}
		printf("\n");
	}
	return;
}

void printInverse(float** ar, int n, int m)
{
	for (int i = 0; i < n; i++) {
		for (int j = n; j < m; j++) {
			printf("%.3f ", ar[i][j]);
		}
		printf("\n");
	}
	return;
}

// Function to perform the inverse operation on the matrix.
void InverseOfMatrix(float** matrix, int order)
{
	// Matrix Declaration.
	float temp;

	// printMatrix function to print the element of the matrix.
	printf("=== Matrix ===\n");
	printMatrix(matrix, order, order);

	// Create the augmented matrix
	// Add the identity matrix of order at the end of original matrix.
	for (int i = 0; i < order; i++) {
		for (int j = 0; j < 2 * order; j++) {
			// Add '1' at the diagonal places of the matrix to create a identity matrix
			if (j == (i + order))
				matrix[i][j] = 1;
		}
	}

	printf("\n=== Augmented Matrix ===\n");
	printMatrix(matrix, order, order * 2);

	// Replace a row by sum of itself and a constant multiple of another row of the matrix
	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++) {
			if (j != i) {  // if not main diagonal
				temp = matrix[j][i] / matrix[i][i];
				for (int k = 0; k < 2 * order; k++) {

					matrix[j][k] -= matrix[i][k] * temp;
				}
			}
		}
	}

	// Multiply each row by a nonzero integer.
	// Divide row element by the diagonal element
	for (int i = 0; i < order; i++) {

		temp = matrix[i][i];
		for (int j = 0; j < 2 * order; j++) {

			matrix[i][j] = matrix[i][j] / temp;
		}
	}

	// print the resultant Inverse matrix.
	printf("\n=== Inverse Matrix ===\n");
	printInverse(matrix, order, 2 * order);

	return;
}

// Driver code
int main()
{
	int order;

	// Order of the matrix
	// The matrix must be a square a matrix
	order = 3;
	/*
	float matrix[20][20] = { { 5, 7, 9 },
							{ 4, 3, 8 },
							{ 7, 5, 6 },
							{ 0 } };
	*/
	float** matrix = new float*[20];
	for (int i = 0; i < 20; i++)
		matrix[i] = new float[20];

	matrix[0][0] = 5;
	matrix[0][1] = 7;
	matrix[0][2] = 9;
	matrix[1][0] = 4;
	matrix[1][1] = 3;
	matrix[1][2] = 8;
	matrix[2][0] = 7;
	matrix[2][1] = 5;
	matrix[2][2] = 6;

	// Get the inverse of matrix
	InverseOfMatrix(matrix, order);

	return 0;
}
