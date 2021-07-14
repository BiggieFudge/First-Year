#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#define N 4
#define R 4
#define C 3
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
	while (i <= q) // j>r
		temp[k++] = a[i++];

	for (i = p, k = 0; i <= r; i++, k++) // copy temp[] to a[]
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
void Ex1() {

	
	printf("Function Returned:%d\n", diff_even_odd(9467));
}
int diff_even_odd(int n) {
	
	
	if (n < 10)
		return (n % 2==0? 1 : -1);
	if ((n % 10) % 2 == 0)
		return 1 + diff_even_odd(n / 10);
	else
		return -1 +diff_even_odd(n / 10);

}
void Que2(int* arr, int n) {
	int max = arr[0], i, savei = 0;
	int* newarr = (int*)calloc(n, sizeof(int));
	assert(newarr);
	for (i = 1; i < n; i++) {
		if (arr[i] < max)
			break;
		else
			max = arr[i];
	}
	savei = i;
	i = 0;
	int j = n - 1, index = 0;
	while (index < n) {
		if (arr[i] > arr[j]) {
			newarr[index] = arr[j];
			j--;
		}
		else {
			newarr[index] = arr[i];
			i++;
		}
		index++;
	}
	copy_array(newarr, arr, n);
}
void Ex2() {
	int arr[10] = { 3,10,43,72,51,38,10,8,6,2 };
	Que2(arr, 10);
	print_array(arr, 10);
}


void Ex3() {
	char arr[] = { 'd','f','a','-','b','r','b','r','$','a','6' };
	char str = "barbara";
	printf("Function returned:%d", Que3("barbar", arr, 12));
}
int Que3(char* str,char* arr,int n) {
	int* countA = (int*)calloc(26, sizeof(int));
	int* countB = (int*)calloc(26, sizeof(int));
	for (int i = 0; i < strlen(str); i++){
		countB[str[i] - 'a']++;
	}
	for (int i = 0; i < n; i++){
		if (arr[i] >= 'a' && arr[i] <= 'z')
			countA[arr[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		if (countB[i] > countA[i])
			return 0;
	}
	return 1;

}
int Que4(int arr[R][C]) {

	for (int i = 0; i < R - 1; i++) {

		for (int j = 0; j < C; j++) {
			if (arr[i][j] > arr[i + 1][j])
				return 0;
		}
	}
	return 1;

}
void Ex4() {
	int arr[R][C] = { {-7,12,1},{25,13,23},{27,26,36},{48,39,38} };
	printf("Function returned:%d", Que4(arr));
}


void Ex5() {}
void Ex6() {}
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