#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
void Que1(int* arr,int n) {
	int counter=0;
	int* brr = (int*)calloc(n, sizeof(int));
	assert(brr);
	for (int i = 0; i < n; i++){
		if (brr[counter - 1] != arr[i]) {
			brr[counter] = arr[i];
			counter++;
		}
		else
			continue;
	}
	counter--;
	brr = realloc(brr, counter*sizeof(int));
	for (int i = 0; i < counter; i++)
		printf(",%d  ", brr[i]);
	free(brr);
	return;
}
void Que2(int* arr, int n) {
	int counterodd = 0,countereven=0;
	int* oddarr = (int*)calloc(n, sizeof(int));
	int* evenarr = (int*)calloc(n, sizeof(int));
	assert(oddarr);
	assert(evenarr);
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) {
			evenarr[countereven] = arr[i];
			countereven++;
		}
		else {
			oddarr[counterodd] = arr[i];
			counterodd++;
		}
	}
	evenarr = realloc(evenarr, countereven * sizeof(int));
	oddarr = realloc(oddarr, counterodd * sizeof(int));
	printf("First Array:\n");
	for (int i = 0; i < countereven; i++)
		printf("arr[%d]:%d.  ",i ,evenarr[i]);
	free(evenarr);
	printf("\nSecond Array:\n");
	for (int i = 0; i < counterodd; i++)
		printf("arr[%d]:%d.  ", i, oddarr[i]);
	free(oddarr);
	return;
}


void main() {
	int arr[10] = { 6,57,14,21,11,3,22,42,9,15 };
	Que1(arr, 10);
}