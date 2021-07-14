#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <string.h>
void PrintMatrix(int** arr, int row, int col);
void replaceROWS(void*** arr, int row1,int row2, int cols) {
	int brr = (int*)calloc(cols, sizeof(int));
	brr =(*arr)[row1];
	(*arr)[row1] = (*arr)[row2];
	(*arr)[row2] = brr;
}
int** Enter_Matrix(int *row,int *col) {
	time_t t;
	srand((unsigned)time(&t));
	int row1, col1;
	printf("Enter Rows:"); scanf_s("%d", &row1);
	printf("\nEnter Cols:"); scanf_s("%d", &col1);
	int** arr = (int**)calloc(row1, sizeof(int*));
	for (int i = 0; i < row1; i++){
		arr[i] = (int*)calloc(col1, sizeof(int));
		for (int j = 0; j < col1; j++){
			arr[i][j] = rand() % 10;
		}
		
	}
	PrintMatrix(arr, row1, col1);
	*col = col1;
	*row = row1;
	return arr;
}
void PrintMatrix(int** arr,int row,int col) {

	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			printf("%d ", arr[i][j]);
		}
		printf("\n");

	}
}
void ReplaceCols(int*** arr, int rows, int col1, int col2) {
	int temp;
	for (int i = 0; i < rows; i++){
		temp = (*arr)[i][col1];
		(*arr)[i][col1] = (*arr)[i][col2];
		(*arr)[i][col2] = temp;
	}
}

void main() {
	
	int row, col;
	int **arr = Enter_Matrix(&row,&col);
	printf("\nEnter Rows to change:");
	int rowT1, rowT2;
	scanf_s(" %d %d", &rowT1, &rowT2);
	replaceROWS(&arr, rowT1, rowT2, col);
	PrintMatrix(arr, row, col);
	int colT1, colT2;
	printf("\nEnter Cols to change:");
	scanf_s(" %d %d", &colT1, &colT2);
	ReplaceCols(&arr, row, colT1, colT2);
	PrintMatrix(arr, row, col);
	//ADD FREE
}