#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <string.h>
int Returnaij(int*** arr, int row, int col);
void PrintMatrix(int** arr, int row, int col) {

	for (int i = 0; i < row; i++) {
		for (int j = 0; j <= i; j++) {
			printf("%d ", Returnaij(&arr,i,j));
		}
		printf("\n");

	}
}
int** Enter_Matrix(int row, int col) {
	time_t t;
	srand((unsigned)time(&t));
	
	int** arr = (int**)calloc(row, sizeof(int*));
	for (int i = 0; i < row; i++) {
		arr[i] = (int*)calloc(i+1, sizeof(int));
		for (int j = 0; j <= i; j++) {
			if (j <= i) {
				arr[i][j] = (rand() % 9) +1;
			}
		}

	}
	
	
	return arr;
}
int Returnaij(int*** arr, int row, int col) {
	return (*arr)[row][col];
}
int Returnaij2(int*** arr, int row, int col);
void PrintMatrix2(int** arr, int row, int col) {

	for (int i = 0; i < row; i++) {
		for (int j = 0; j <col-i; j++) {
				printf("%d ", Returnaij(&arr, i, j));
		}
		printf("\n");
		for (int h = 0; h < i+1 && i!=col-1; h++)
		{
			printf("0 ");
		}
		

	}
}
int** Enter_Matrix2(int row, int col) {
	time_t t;
	srand((unsigned)time(&t));

	int** arr = (int**)calloc(row, sizeof(int*));
	for (int i = 0; i < row; i++) {
		arr[i] = (int*)calloc(col-i, sizeof(int));
		for (int j = 0; j <= col-i; j++) {
			arr[i][j] = (rand() % 9) + 1;
		}

	}


	return arr;
}
int Returnaij2(int*** arr, int row, int col) {
	return (*arr)[row][col];
}


void main() {
	int row, col;
	printf("Enter Rows and cols:"); scanf_s("%d %d", &row, &col);
	int** arr = Enter_Matrix(row, col);


	PrintMatrix(arr, row, col);
	/*int row2, col2;
	printf("Enter Rows and cols:"); scanf_s("%d %d", &row2, &col2);
	int** arr2 = Enter_Matrix2(row2, col2);


	PrintMatrix2(arr2, row2, col2);
*/
}