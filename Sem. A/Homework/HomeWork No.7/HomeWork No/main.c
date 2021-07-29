#include <stdio.h>
#include <math.h>
#define SIZE 4
void quest1();
void quest2();
void quest3();
void quest4();
void quest5();
void quest6();
void quest7();
void quest8();
void quest9();
void quest10();
void quest11();

void enterarr(int *,int);
void Denterarr(double *, int);
void swap(int *, int *, int *);
double avgchecker(int, int *);
double nigzeret(int *, int *, int *);
int sumcheck(int [], int);
int keycheck(int [], int *, int *);
void maxmax(int [], int, int *, int *, int *, int *);
int ispali(int [], int);
int ispalib(int [], int);
int printarr(int[], int);
int printarrre(int[], int);
double avg(int[], int);
int ByOrderCheck(double[], int);
int SuperOle(int [], int );
int SuperOleRe(int[], int);

void main() {
	quest1();





}

void enterarr(int *arr,int n) {
	for (int i = 0; i < SIZE; i++) {
		printf("Enter arr[%d]:\n", i);
		scanf_s("%d", &arr[i]);
	}
	return;
}
void Denterarr(double *arr, int n) {
	for (int i = 0; i < SIZE; i++) {
		printf("Enter arr[%d]:\n", i);
		scanf_s("%lf", &arr[i]);
	}
	return;
}

void quest1() {
	int x1 = 10, x2 = 5, x3 = 15;
	swap(&x1, &x2, &x3);
	printf("ptr1:%d.ptr2:%d.ptr3:%d", x1, x2, x3);
}

void swap(int *num1ptr, int *num2ptr, int *num3ptr) {
	int a,b,c;
	a = *num1ptr;
	b = *num2ptr;
	c = *num3ptr;
	if (b > c && b > a) {
		a += b;
		b = a - b;
		a = a - b;
	}
	else if (c > a && c > b) {
		a += c;
		c = a - c;
		a = a - c;
	}
	if (c > b) {
		b += c;
		c = b - c;
		b = b - c;
	}
	*num1ptr = a;
	*num2ptr = b;
	*num3ptr = c;}

void quest2() {
	int x = 4;
	int * ptr = &x;
	printf("Avg is:%lf", avgchecker(928743, ptr));
	printf("\nNo. of digits:%d", *ptr);

}

double avgchecker(int num, int *ptr) {
	int dig = *ptr;
	if (num < 0)
		num *= -1;
	double sum = 0;
	int i = 0;
	do{
		if (num % 10 < dig) {
			i++;
			sum = sum + (num % 10);
		}
		num = num / 10;
	} while (num > 0);
	*ptr = i;
	if (i == 0) {
		return 0;
	}
	else {
		return (double)(sum / i);
	}
		
}
void quest3() {
	int n=4, x=5, c =8 ;
	
	printf("(cx^n)=%.1f", nigzeret(&c, &x, &n));
	printf("\nc:%d ; n:%d", c, n);
}
double nigzeret(int *c, int *x, int *n) {
	int a=*c, b=*n;
	a *= b;
	b--;
	*c = a;
	*n = b;
	return (pow(*x, b)*a);
}


void quest4() {
	int n = SIZE;
	int arr[SIZE];
	printf("Max sum is:%d", sumcheck(arr,n));



}

int sumcheck(int ar[],int n) {
	int maxsum = ar[0] + ar[1];
	for (int i = 1; i < n; i++) {
		if ((ar[i] + ar[i + 1]) > maxsum) {
			maxsum = ar[i] + ar[i + 1];
		}
	}
	return maxsum;
}


void quest5() {
	
	int n = SIZE, arr[SIZE] = {1,6,2,4},size=SIZE, key = 4;
	printf("%d", keycheck(arr, &size, &key));
	printf("\nThe two eivarim are: %d, %d", size ,key);
}

int keycheck(int ar[],int *n, int *key) {
	int sum, x, y;
	for (int i = 0; i < SIZE-2; i++) {
		for (int j=i+1; j < SIZE-1;j++) {
			x = ar[i]; y = ar[j];
			sum = x + y;
			if (sum < *key) {
				*n = x;
				*key = y;
				return 1;
			}
		}
	}
	x = -1;
	y = -1;
	*n = x;
	*key = y;
	return 0;


}

void quest6() {
	int arr[SIZE] = { 9,3,4,3 }, n = SIZE, *max_even=NULL, even, max_odd, odd;
	maxmax(arr, n, &max_even, &even, &max_odd, &odd);
	if (even && odd)
		printf("max even:%d, even:%d, max odd:%d, odd:%d", max_even, even, max_odd, odd);
	else if (even)
		printf("max even:%d, even:%d, odd:%d", max_even, even, odd);
	else
		printf("max odd:%d, odd:%d, even:%d", max_odd, odd, even);
	
}
void maxmax(int ar[], int n, int *max_even, int *even, int *max_odd, int *odd) {
	int maxeven = 0, maxodd = 0, od=0,eve=0;
	for (int i = 0; i < SIZE - 1; i++) {
		if (ar[i] % 2 == 0) {
			eve = 1;
			if (ar[i] > maxeven)
				maxeven = ar[i];
		}
		else {
			od = 1;
			if (ar[i] > maxodd)
				maxodd = ar[i];
		}
	}
	*max_even = maxeven;
	*even = eve;
	*max_odd = maxodd;
	*odd = od;
}

void quest7() {
	int ar[SIZE] = { 1,3,6,6}, n = SIZE;
	printf("Palindome:%d", ispali(ar, n));
}

int ispali(int arr[], int n) {
	for (int i = 0; i <= n - 1; i++) {
		if (arr[n-1-i] != arr[i])
			return 0;
	}
	return 1;
}

int ispalib(int arr[], int n) {
	int arr2[SIZE];
	if (n <= 1)
		return 1;
	if (arr[0] == arr[n - 1]) {
		for (int i = 0; i < n-2 ; i++)
			arr2[i] = arr[i+1];
		n -= 2;
		ispalib(arr2, n);
	}
	else
		return 0;
}

void quest8() {
	int arr[SIZE] = { 0,11,1,2}, n = SIZE;
	printarr(arr, n);
}

int printarr(int arr[], int n) {
	int arr2[SIZE];
	if (n == 0)
		return 1;
	else {
		n--;
		printf("%d ,", arr[0]);
		for (int i = 0; i <= n-1; i++)
			arr2[i] = arr[i+1];
		printarr(arr2, n);
	}
}

int printarrre(int arr[], int n) {
	int arr2[SIZE];
	if (n == 0)
		return 1;
	else {
		printf("%d ,", arr[n-1]);
		for (int i = 0; i <= n - 2; i++)
			arr2[i] = arr[i];
		n--;
		printarrre(arr2, n);
	}
}

void quest9() {
	int arr[SIZE];
	enterarr(arr,SIZE);
	printf("%.2f", avg(&arr, SIZE));
}

double avg(int arr[], int n) {
	int arr2[SIZE];
	if (n == 0) {
		return 0;}
	
	else {
		for (int i = 0; i <= n - 2; i++)
			arr2[i] = arr[i+1];
		if (n==SIZE)
			return (arr[0] + avg(arr2, n-1))/n;
		else 
			return (arr[0] + avg(arr2, n - 1));
	}
}

void quest10() {
	double arr[SIZE];
	Denterarr(arr, SIZE);
	printf("Is by order:%d", ByOrderCheck(arr, SIZE));
}


int ByOrderCheck(double arr[], int n) {
	for (int i = 0; i < SIZE -1; i++) {
		if ((int)(arr[i] / 1) > (int)(arr[i + 1] / 1))
			return 0;
		if (fmod(arr[i],1) < fmod(arr[i + 1],1))
			return 0;
	}
	return 1;
}


void quest11() {
	int arr[SIZE];
	enterarr(arr, SIZE);
	printf("Is SuperOle:%d", SuperOleRe(arr, SIZE));

}

int SuperOle(int arr[], int n) {
	int sum=0;
	for (int i = 0; i < SIZE; i++) {
		if (sum < arr[i])
			sum = sum + arr[i];
		else return 0;

	}
	return 1;
}

int SuperOleRe(int arr[], int n) {
	if (n == 0)
		return 1;
	if (arr[n] > arr[n-1]) {
		arr[0] = arr[0] + arr[1];
		SuperOleRe(arr, n - 1);
	}
	else
		return 0;
}