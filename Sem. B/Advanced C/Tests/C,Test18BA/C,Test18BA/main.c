#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void** Question1(void** A, int* size, int n) {

	int*temp=NULL;

	int*temp2 = NULL;
	int i = 0;

	temp = A[0];
	for (i = 1; i < n-1; i++) {
	
		temp2 = A[i];
		A[i] = temp;
		temp = temp2;

	}
		
	A[0] = temp;
	int tmp=size[0], tmp2;
	for (i = 1; i <= n - 1; i++) {

		tmp2 = size[i];
		size[i] = tmp;
		tmp = tmp2;

	}

	size[0] = tmp;

	return A;
}


typedef struct num_pair
{
	int count;
	int sum;
} NumPair;

#define cols 5
#define rows 4


int Question2(int M[rows][cols], NumPair** zxc) {

	NumPair* A = (NumPair*)calloc(rows, sizeof(NumPair));
	int max=M[0][0];

	for (int i = 0; i < rows; i++) {
		A[i].count = 0;
		A[i].sum = 0;
		for (int j = 0; j < cols; j++) {
			A[i].sum += M[i][j];
			if (M[i][j] % 2 == 0)
				A[i].count++;
			if (M[i][j] > max)
				max = M[i][j];
		}
	}
	*zxc = A;
	return max;
}



void main() {
	

	//Question 1
	/*int **A = (int**)calloc(4, sizeof(int*));
	A[0] = (int*)calloc(4, sizeof(int));
	A[0][0] = 5, A[0][1] = 12, A[0][2] = 6, A[0][3] = 9;
	A[1] = (int*)calloc(5, sizeof(int));
	A[1][0] = 0, A[1][1] = 3, A[1][2] = 1, A[1][3] = 29, A[1][4] = 101;
	A[2] = (int*)calloc(2, sizeof(int));
	A[2][0] = 13, A[2][1] = 14;
	A[3] = (int*)calloc(3, sizeof(int));
	A[3][0] = 2, A[3][1] = 20, A[3][2] = 4;

	int size[4] = { 4,5,2,3 };

	int** B=Question1(A, size, 4);*/


	//Question 2
	int M[rows][cols] = { {6,0,4,8,7},{3,10,17,7,6},{9,1,5,31,1},{0,7,48,15,4} };
	NumPair* zxc = NULL;
	Question2(M, &zxc);

	int x = 'p'^'o'^'w'^'('^'p'^'o'^'w'^'(';
	printf("%d\n", (int)pow((int)"pow", x));
}