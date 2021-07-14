#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void quest1();
void quest2();
void quest3();
void quest4();
void quest5();
void quest6();
void quest7();
void quest8();


void inputArray(int *, int);
void printArray(int *, int);
int Byorder(int *, int *);
int ByorderRe(int *, int);
int CheckNeigh(int *, int);
void Reverse(int *, int);
void ReverseRe(int *, int);


void main() {
	quest5();
}



//                           Question 1
void quest1() {
	int n;
	printf("Enter n:");
	scanf_s("%d" , &n);
	int* arr = (int*)calloc(n, sizeof(int));
	inputArray(arr, n);
	printArray(arr, n);
	free(arr);
}
void inputArray(int *arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("\nEnter arr[%d]:", i);
		scanf_s("%d", &arr[i]);
	}
}

void printArray(int *arr, int n) {
	for (int i = 0; i < n; i++) 
		printf("\narr[%d]:%d", i, arr[i]);
}

//                                     Question 2
// Same as homework no.7 not doing it again

//                                     Question 3
int flagg = 1;
void quest3() {
	int n;
	printf("Enter n:");
	scanf_s("%d", &n);
	int* arr = (int*)calloc(n, sizeof(int));
	inputArray(arr, n);
	printf("Is by order:%d,", ByorderRe(arr, n));
	printf("\n*N:%d", flagg);
	free(arr);
}

int Byorder(int *arr, int *n) {
	int index = *n;
	int flag = 1;
	for (int i = 0; i < index-1; i++) {
		if (arr[i] > arr[i + 1]) {
			flag = 0;
			*n = flag;
			return 0;
		}
		if (arr[i] == arr[i + 1])
			flag = 0;
	}
	*n = flag;
	return 1;	
}

int ByorderRe(int *arr, int n) {
	if (n == 1) {
		return 1;
	}
	if (arr[n-2] > arr[n-1]) {
		flagg = 0;
		return 0;
		}
	else if (arr[n-2] == arr[n-1])
		flagg = 0;
	
	 return ByorderRe(arr,n-1);
	

	}

//                                 Question 4
void quest4() {
	int n;
	printf("Enter n:");
	scanf_s("%d", &n);
	int* arr = (int*)calloc(n, sizeof(int));
	inputArray(arr, n);
	printf("Function Returned:%d", CheckNeigh(arr, n));
}

int CheckNeigh(int *arr, int n) {
	for (int i = 0; i <= n-3; i++) {
		int x = arr[i] + arr[i + 2];
		if (x == arr[i + 1])
			return 1;
	}
	return 0;
}

//                                    Question 5
void quest5() {
	int n;
	printf("Enter n:");
	scanf_s("%d", &n);
	int* arr = (int*)calloc(n, sizeof(int));
	inputArray(arr, n);
	ReverseRe(arr, n);
	printArray(arr, n);
	free(arr);
}

void Reverse(int *arr, int n) {
	for (int i = 0; i < n / 2; i++) {
		int temp = arr[i];
		arr[i] = arr[n - 1 - i];
		arr[n - 1 - i] = temp;
	}
	return;
}

void ReverseRe(int *arr, int n) {
	if (n <= 1)
		return;
	int temp = arr[0];
	arr[0] = arr[n - 1];
	arr[n - 1] = temp;
	ReverseRe(arr+1, n - 2);

}