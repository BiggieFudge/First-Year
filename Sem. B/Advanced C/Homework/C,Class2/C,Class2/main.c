#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <string.h>
void printarray(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("\narr[%d]=%d", i, arr[i]);
	}
}

void Que1() {
	time_t t;
	srand((unsigned)time(&t));
	int* arr = (int*)calloc(5, (sizeof(int)));
	assert(arr);
	for (int i = 0; i < 5; i++) {
		arr[i] = (rand() % 10) + 1;
	}
	arr = realloc(arr, 6 * (sizeof(int)));
	assert(arr);
	arr[5] = (rand() % 10) + 1;
	printarray(arr, 6);
	free(arr);

}


int* Ques1(int* A, int *b,int* n1,int* n2) {
	int even=0, odd=0;
	int* c = (int*)calloc((*n1), sizeof(int));
	int* d = (int*)calloc(*n1,sizeof(int));
	assert(c);
	assert(d);
	for (int i = 0; i < *n1; i++){
		if (A[i] % 2 == 0) {
			d[even] = A[i];
			even++;
		}
		else {
			c[odd] = A[i];
			odd++;
		}
	}
	*b = d;
	d = realloc(d, even * sizeof(int));
	c = realloc(c, odd * sizeof(int));
	assert(d);
	assert(c);
	*n1 = even;
	*n2 = odd;
	return c;
}

void LaunchQues1() {
	int arr[10] = { 50,60,72,81,81,81,93,1,2,3 };
	int *b, *c;
	int n1 = 10, n2 = 0;
	c = Ques1(arr, &b, &n1, &n2);
	printarray(b, n1);
	printarray(c, n2);
	free(b);
	free(c);
}

void CreateArrays(char* s1,char** c,char** d) {
	 *c =(char*) malloc (255);
	 *d =(char*) malloc (255);
	assert(*c); assert(*d);
	int indexa = 0, indexb = 0;
	for (int i = 0; i < strlen(s1); i++){
		if (s1[i] >= 'a' && s1[i] <= 'z') {
			*c[indexa] = s1[i];
			indexa++;
		}
		else {
			*d[indexb] = s1[i];
			indexb++;
		}
	}
	*c=realloc(*c, indexa * sizeof(char*));
	assert(*c);
	*d=realloc(*d, indexb * sizeof(char*));
	assert(*d);
	
	
	
}

void LaunchQues2() {
	char *c="", *d="";
	CreateArrays("aYmOUtRheSEbeLstF", &c, &d);
	printf("%s \n",c);
	puts(d);
	printf("%p, %p", c, d);
	free(c);
	free(d);
}


int* RemoveDup1(int* arr, int *n) {
	int counter = 0;
	int* brr = (int*)calloc(*n, sizeof(int));
	assert(brr);
	for (int i = 0; i < *n; i++) {
		if (brr[counter - 1] != arr[i]) {
			brr[counter] = arr[i];
			counter++;
		}
		else
			continue;
	}
	
	brr = realloc(brr, counter * sizeof(int));
	*n = counter;
	return brr;
}


int RemoveDup2(int** arr, int n,int *a) {
	int counter = 0;
	int* brr = (int*)calloc(n, sizeof(int));
	assert(brr);
	for (int i = 0; i < n; i++) {
		if (brr[counter - 1] != arr[i]) {
			brr[counter] = arr[i];
			counter++;
		}
		else
			continue;
	}

	brr = realloc(brr, counter * sizeof(int));
	assert(brr);
	*a = brr;

	return counter;
}
void main() {
	int arr[10] = { 50,60,72,72,81,81,81,93,93,93 };
	int *A;
	int n = 10;
	n=RemoveDup2(arr, 10, &A);
	
	printarray(A, n);
	free(A);

}