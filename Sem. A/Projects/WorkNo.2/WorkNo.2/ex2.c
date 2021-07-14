// איתן רכלין 207207572
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
/* Function declarations */
void Ex1();
void Ex2();
void Ex3();
void Ex4();
void Ex5();

/* Declarations of other functions */

int NumSwap(int);
int IsByorder(int, int);
int weirdSub();
int Kpali(int *, int, int);
int* inputArray(int);
int* NewArray(int *, int, int, int *);
/* ------------------------------- */
// no need to change the main function for matala 1.
// 
int main()
{
	int select = 0, i, all_Ex_in_loop = 0;
	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
	if (scanf_s("%d", &all_Ex_in_loop) == 1)
		do
		{
			for (i = 1; i <= 5; i++)
				printf("Ex%d--->%d\n", i, i);
			printf("EXIT-->0\n");
			do {
				select = 0;
				printf("please select 0-5 : ");
				scanf_s("%d", &select);
			} while ((select < 0) || (select > 5));
			switch (select)
			{
			case 1: Ex1(); break;
			case 2: Ex2(); break;
			case 3: Ex3(); break;
			case 4: Ex4(); break;
			case 5: Ex5(); break;
			}
		} while (all_Ex_in_loop && select);
		return 0;
}

/*.............................*/
void Ex1(){   
	int n;
	printf("Enter n:\n");
	scanf_s("%d", &n);
	printf("Function Returned:%d\n", NumSwap(n));
}

int NumSwap(int n){
	int x = n % 100;
	if (n < 10)
		return n;
	else if (n < 100)
		return (x % 10) * 10 + (x / 10);
	return (NumSwap(n / 100))* 100 + (x % 10) * 10 + ((x / 10));

}
/*.............................*/
void Ex2() {
	int n,f;
	printf("Enter n:\n");
	scanf_s("%d", &n);
	printf("Enter f:\n");
	scanf_s("%d", &f);
	printf("Function Returned:%d\n", IsByorder(n, f));
}

int IsByorder(int n,int f) {
	if (n < 10)
		return 1;
	int x = n % 100;
	switch (f){
		case(0):
			if (x % 10 >= x / 10)
				return 0;
			else IsByorder(n / 10, f);
			break;
		case(1):
			if (x % 10 <= x / 10)
				return 0;
			else IsByorder(n / 10, f);
			break;
		case(2):
			if (x / 10 >= x % 10) {
				do {
					n /= 10;
					x = n % 100;
				} while (x / 10 > x % 10);
				if (x < 10)
					return 0;
				return IsByorder(n, 1);
			}
			else 
				return 0;
			
			break;
		case(3):
			if (x / 10 <= x % 10) {
				do {
					n /= 10;
					x = n % 100;
				} while (x / 10 < x % 10);
				if (x < 10)
					return 0;
				return IsByorder(n, 0);
			}
			else
				return 0;
			break;
	}

}
/*.............................*/
void Ex3(){
	printf("Function Returned:%d\n", weirdSub());
}

int weirdSub() {
	int sum = 0, num;
	for (int i = 1; i <= 2; i++) {
		printf("Enter num:\n");
		scanf_s("%d", &num);
		if (num == -1)
			return (0-sum);
		sum += num;
	}
	printf("Enter num:\n");
	scanf_s("%d", &num);
	if (num == -1)
		return (0-sum);
	sum = num - sum;
	return (sum + weirdSub());
}
/*.............................*/
int* inputArray(int n) {
	if (n == 0)
		n++;
	int *arr = (int*)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++) {
		printf("Enter arr[%d]:", i);
		scanf_s("%d", &arr[i]);
	}
	return arr;
}
void Ex4() {
	int *arr,k,n;
	printf("Enter n:");
	scanf_s("%d", &n);
	printf("Enter k:");
	scanf_s("%d", &k);
	arr = inputArray(n);
	printf("Function Returned:%d\n", Kpali(arr,n,k));
	free(arr);
}
int Kpali(int *arr, int n, int k) {
	int sumFirst = 0, sumLast = 0;
	if (n < 2 * k) {
		free(arr);
		return 1;
	}
	for (int i = 0; i < k; i++) {
		sumFirst += arr[i];
		sumLast += arr[n - i - 1];
	}
	if (sumFirst == sumLast) {
		return Kpali(arr + k, (n - 2 * k), k);
	}
	else return 0;
}

/*.............................*/
void Ex5() {
	int *arr, k, n;
	printf("Enter n:");
	scanf_s("%d", &n);
	printf("Enter k:");
	scanf_s("%d", &k);
	arr = inputArray(n);
		int p=0;
		int *b = NewArray(arr, n, k,  &p);
		printf("Sum of new array is:%d ,New array is:\n", p);
		for (int i = 0; i < k; i++)
			printf("arr[%d]:%d\n", i, b[i]);
		free(b);
		free(arr);
}
int* NewArray(int *arr, int n, int k, int *p) {
	int* b = (int *)calloc(k,sizeof(int));
	int min=arr[0],savei=0,x=0;
	for (int j = 0; j < k; j++) {
		min = arr[0];
		for (int i = 0; i < n; i++) {
			if (arr[i] < min) {
				min = arr[i];
				savei = i;
			}
		}
		for (int h = savei; h < n -1; h++)
			arr[h] = arr[h + 1];
		n--;
		x += min;
		b[j] = min;
	}
	*p = x;
	return b;
}