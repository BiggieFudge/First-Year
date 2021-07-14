#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#define N 8
#define R 3
#define C 4

void swap(int *v, int *u)
{
	int temp;
	temp = *v;
	*v = *u;
	*u = temp;
}
int partition(int *a, int left, int right)
{
	int first = left;
	int pivot = a[first];
	int pos;
	while (left < right)
	{
		while (a[right] > pivot) right--;
		while ((left < right) && (a[left] <= pivot)) left++;
		if (left < right)
			swap(a + left, a + right);
	}
	pos = right;
	a[first] = a[pos];
	a[pos] = pivot;
	return pos;
}
void quick_sort(int *a, int first, int last)
{
	int pos;
	if (first < last)
	{
		pos = partition(a, first, last);
		quick_sort(a, first, pos - 1);
		quick_sort(a, pos + 1, last);
	}
}
void merge(int *a, int p, int q, int r)
{
	int i = p, j = q + 1, k = 0;
	int* temp = (int*)calloc(r - p + 1, sizeof(int));
	while ((i <= q) && (j <= r))
		if (a[i] < a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	while (j <= r) // if( i>q )
		temp[k++] = a[j++];
	while (i <= q) { temp[k] = a[i]; k++; i++; }//child porn

	for (i = p, k = 0; i <= r; i++, k++) // copy tzemp[] to a[]
		a[i] = temp[k];
	free(temp);
}
void merge_sort(int *a, int first, int last)
{
	int middle;
	if (first < last)
	{
		middle = (first + last) / 2;
		merge_sort(a, first, middle);
		merge_sort(a, middle + 1, last);
		merge(a, first, middle, last);
	}
}
void copy_array(int *a, int *b, int size) {
	while (size-- > 0)
		*(b++) = *(a++);
}
int bin_search_last(int key, int *a, int n)
{
	int low, high, mid;
	low = 0;
	high = n - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (key < a[mid])
			high = mid - 1;
		else
			if (key > a[mid])
				low = mid + 1;
			else //key=a[mid]
				if ((low == high) || (a[mid + 1] > key))
					return mid;
				else
					low = mid + 1;
	}
	return -1;
}
void print_array(int *a, int sz) {
	int i;
	for (i = 0; i < sz; i++)
		printf("%3d", a[i]);
}
void print_matrix(int arr[N][N]) {
	int i;
	for (i = 0; i < N; i++) {
		print_array(arr[i], N);
		printf("\n");
	}
}


int IsSumPairsNotIncreasing(int n) {
	if (n < 100 && n>9)
		return 1;
	int tms = n % 100 / 10 + (n % 100) % 10;;
	int now = n / 100 %100 ;
	now = now / 10 + now % 10;
	if (now < tms)
		return 0;
	else
		return IsSumPairsNotIncreasing(n / 100);

}

void Ex1() {
	printf("Function returned:%d\n", IsSumPairsNotIncreasing(81623370));
}
int bin_search(double *a, int n)
{
	int low, high, mid;
	low = 0;
	high = n - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (mid == a[mid])
			return mid;
		else if (mid < a[mid])
			high = mid - 1;
		else 
			low = mid + 1;
	}
	return -1;
}
int ItemEqualIndex(double* array, int size) {

	return bin_search(array, size);
}
void Ex2() {
	double array[5] = { 0,2,5,8.1,4 };
	printf("%d\n",ItemEqualIndex(array, 5));
}
void que3(int* arr,int a,int b,int n) {
	int *brr = (int*)calloc(n, sizeof(int));
	assert(brr);
	int index = 0;
	for (int i = 0; i < n; i++){
		if (arr[i] <= a) {
			brr[index] = arr[i];
			index++;
		}
	}
	for (int i = 0; i < n; i++) {
		if (arr[i] > a && arr[i]<=b) {
			brr[index] = arr[i];
			index++;
		}
	}
	for (int i = 0; i < n; i++) {
		if (arr[i] >= b) {
			brr[index] = arr[i];
			index++;
		}
	}
	print_array(brr, n);
	free(brr);
}
void Ex3() {
	int arr[6] = { 12,10,5,9,-15,2 };
	que3(arr, -1, 9, 6);
}
int que4() {

}
void Ex4() {

}
void Ex5() {

}
void Ex6() {

}

int main()
{
	int select = 0, i, all_Ex_in_loop = 0, num;
	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
	if (scanf_s("%d", &all_Ex_in_loop) == 1)
		do
		{
			for (i = 1; i <= 5; i++)
				printf("Ex%d--->%d\n", i, i);
			printf("EXIT-->0\n");
			do {
				select = 0;
				printf("please select 0-6 : ");
				scanf_s("%d", &select);
			} while ((select < 0) || (select > 6));
			switch (select)
			{
			case 1: Ex1(); break;
			case 2: Ex2(); break;
			case 3: Ex3(); break;
			case 4: Ex4(); break;
			case 5: Ex5(); break;
			case 6: Ex6(); break;
			}
		} while (all_Ex_in_loop && select);
		return 0;
}