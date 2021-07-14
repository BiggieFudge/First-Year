#include <stdio.h>
#include <stdlib.h>
void Que1();
void Que2();
void Que3();
void Que4();
void Que5();
void Que6();
void Que7();
void Que8();
void Que9();
void Que10();

void printArray(int *, int);
int* LucasGen(int);
int* inputArray(int);
int* SortArrayEvenOdd(int*, int* , int);
int* CrossProduct(int* , int*);
void ProductArray(int*, int);
int* WierdArray(int* , int*);
int Fun6(int* , int);
int Fun7(int* , int);
int Fun8(int*, int);
int* Fun9(int*, int, int);
int* Fun10(int*, int);

void main() {
	Que10();
}
//                                 Question 1
void Que1() {
	int n;
	printf("Enter n:");
	scanf_s("%d", &n);
	int *arr = LucasGen(n);
	printArray(arr, n);
	free(arr);//לבדוק אם צריך לעשות את הפרי גם בפונקציה
}
int* LucasGen(int n) {//  לבדוק כמה איברים באמת הפונקציה מחזירה
	int* arr = (int*) calloc(n, sizeof(int));
	arr[0] = 2;
	if (n > 0)
		arr[1] = 1;
	for (int i = 2 ; i < n; i++) {
		arr[i]= arr[i-1]+arr[i-2];
	}
	return arr;
}

void printArray(int *arr, int n) {
	for (int i = 0; i < n; i++)
		printf("\narr[%d]:%d", i, arr[i]);
	free(arr);
}

//------------------------------------------------------------------//
void Que2() {
	int n,isEven;
	printf("Enter n:");
	scanf_s("%d", &n);
	int *arr = inputArray(n);
	printf("Enter 1 for even,0 for odd:");
	scanf_s("%d", &isEven);
	int *brr = (int*)calloc(n, sizeof(int));
	brr = SortArrayEvenOdd(arr, &n, isEven);
	printArray(brr, n);
	printf("\nn:%d", n);
	free(arr);
}

int* inputArray(int n) {
	int *arr = (int*)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++) {
		printf("Enter arr[%d]:", i);
		scanf_s("%d", &arr[i]);
	}
	return arr;
}

int* SortArrayEvenOdd(int* arr, int* n, int isEven) {
	int j = 0,size=*n;
	int *brr = (int*) calloc (size,sizeof(int));
	if (isEven==1) {
		for (int i = 0; i < size; i++) {
			if (arr[i] % 2 == 0) {
				brr[j] = arr[i];
				j++;
			}
		}
	}
	else 
		for (int k = 0; k <size ;k++){
			if (arr[k] % 2 != 0) {
				brr[j] = arr[k];
				j++;
			}

		
	}
	*n = j;
	return brr;
}

void Que3() {
	int *arr = inputArray(3);
	int *brr = inputArray(3);
	int *result = CrossProduct(arr, brr);
	printArray(result, 3);
}

int* CrossProduct(int* arr, int* brr) {
	int* result=(int*) calloc (3,sizeof(int));
	result[0] = (arr[1] * brr[2]) - (arr[2] * brr[1]);
	result[1] = (arr[2] * brr[0]) - (arr[0] * brr[2]);
	result[2] = (arr[0] * brr[1]) - (arr[1] * brr[0]);
	return result;
}
//------------------------------------------------------------------//

void Que4() {
	int n;
	printf("Enter n:");
	scanf_s("%d", &n);
	int *arr = inputArray(n);
	ProductArray(arr, n);
	printArray(arr, n);
}

void ProductArray(int* arr, int n) {
	int* brr = (int*)calloc(n, sizeof(int));
	int index=0;
	for (int i = 0; i < n; i++) {
		brr[i] = 1;
		index = 0;
		while (index < n) {
			if (index != i) {
				brr[i] *= arr[index];
				index++;
			}
			else
				index++;
		}
	}
	for (int i = 0; i < n; i++) 
		arr[i] = brr[i];
	free(brr);
	return;
}


//------------------------------------------------------------------//
void Que5() {
	int n;
	printf("Enter n:");
	scanf_s("%d", &n);
	int *arr = inputArray(n);
	int *brr =  WierdArray(arr, &n);
	printf("New array lenght is:%d", n);
	printArray(brr, n);
}


int* WierdArray(int* arr, int* n) {
	int index = 0, j = 0, size = *n;
	int* brr = (int*)calloc(size, sizeof(int));
	if (size == 0) {
		int* crr = (int*)calloc(1, sizeof(int));
		size = 1;
		*n = size;
		return crr;
	}
	int* crr = (int*)calloc(size, sizeof(int));
	for (int i = 0; i < size; i++) {
		brr[arr[i]]++;
		}
	for (int i = 0; i < size; i++) {
		if (brr[i] == 0) {
			crr[j] = i;
			j++;
		}
	}
	free(arr);
	free(brr);
	*n = j;
	return crr;
}


//------------------------------------------------------------------//
void Que6() {
	int n;
	printf("Enter n:");
	scanf_s("%d", &n);
	int *arr = inputArray(n);
	printf("Most of arr is:%d", Fun6(arr,n));
}


int Fun6(int* arr, int n) {
	int* brr = (int*)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++) {
		brr[arr[i]]++;
	}
	for (int i = 0; i < n; i++) {
		if (brr[arr[i]] > (n / 2))
			return arr[i];
		else
			return -1;
	}

}


void Que7() {
	int n;
	printf("Enter n:");
	scanf_s("%d", &n);
	int *arr = inputArray(n);
	printf("Highest sum is of number:%d", Fun7(arr, n));
}


int Fun7(int* arr, int n) {
	int max = 0;
	int* brr = (int*)calloc(n+1, sizeof(int));
	for (int i = 0; i < n; i++) {
		brr[arr[i]]++;
	}
	for (int j = 1; j< n; j++) {
		if (brr[j]*j > brr[max] * max)
			max = j;
	}
	return max;


}

void Que8() {
	int n;
	printf("Enter n:");
	scanf_s("%d", &n);
	int *arr = inputArray(n);
	printf("Greatest num not showing in array is:%d", Fun8(arr, n));
}


int Fun8(int* arr, int n) {
	int* brr = (int*)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++) {
		brr[arr[i]]++;
	}
	int max = 0;
	for (int j = 1; j < n; j++) {
		if (brr[j]==0)
			max = j;
		}
	return max;
}
void Que9() {
	int n,amount;
	printf("Enter n:");
	scanf_s("%d", &n);
	printf("Enter amount:");
	scanf_s("%d", &amount);
	int *arr = inputArray(n);
	printf("New array is:\n");
	int *brr = Fun9(arr, n, amount);
	printArray(arr, n);
}


int* Fun9(int* arr, int n,int amount) {
	int temp,Pre;
	while (amount % n != 0) {
		temp = arr[0];
		for (int i = 1; i < n; i++) {
			Pre = arr[i];
			arr[i] = temp;
			temp = Pre;
			
		}
		arr[0] = temp;
		amount--;
	}
	return arr;
}


void Que10() {
	int n;
	printf("Enter n:");
	scanf_s("%d", &n);
	int *arr = inputArray(n);
	printf("New array is:");
	int *brr = Fun10(arr, n);
	printArray(arr, n);
}


int* Fun10(int* arr, int n) {
	int nextBigNum,numTocheck,index = 1;
	for (int i = 0; i < n; i++) {
		numTocheck = arr[i];
		while (arr[index] <= numTocheck && index<n) {
			index++;
		}
		if (index == n)
			nextBigNum = -1;
		else
			nextBigNum = arr[index];
		arr[i] = nextBigNum;
		index = i + 2;
	}
	return arr;
}
