#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#define N 4
#define R 3
#define C 5
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
void print_matrix(int arr[R][C]) {
	int i;
	for (i = 0; i < R; i++) {
		print_array(arr[i], C);
		printf("\n");
	}
}
void Ex1() {
	printf("Function returned:%d", Que1(98756));
}

int Que1(int n) {
	int last = n % 10, beforelast = n % 100 / 10;
	if (n < 100) {
		if (last > beforelast)
			return 1;
		else if (beforelast > last)
			return -1;
	}
	int srt = Que1(n / 10);
	if (srt == 1 && last > beforelast)
		return 1;
	if (srt == -1 && beforelast > last)
		return -1;
	return 0;
}
void Ex2() {
	int arr[8] = { -3,1,10,21,22,31,40 };
	int brr[9] = { -3,1,10,21,22,23,31,40 };
	printf("Function returned:%d\n", Que2(arr,brr,8));
}

int Que2(int* a, int* b, int n) {

	int num=0;
	int low = 0, mid = (n+1) / 2, high = n+1;
	while (!num) {
		if (a[mid] == b[mid]) {
			low = mid;
		}
		else {
			high = mid;
		}
		mid = (low + high) / 2;
		if ((a[mid] != b[mid]) && (a[mid - 1] == b[mid - 1]))
			break;
	}
	num = b[mid];
	return num;
}
int Que3(int* a, int n, int m, int* p) {
	int min = a[0], counter = 0,index=0;
	for (int i = 0; i < n; i++){
		if (a[i] <= m && p[a[i]-1]==0) {
			p[a[i]-1] = a[i];
			counter++;
		}
	}
	for (int i = 0; i < m; i++){
		if (p[i] != 0) {
			p[index] = p[i];
			index++;
		}
	}
	print_array(p, index);
	return counter;
}
void Ex3() {
	int a[12] = { 11,7,5,4,5,4,3,201,5,3,12,14 };
	int* p=(int*)calloc(7,sizeof(int));
	printf("Function returned:%d", Que3(a, 12, 7, p));
}

int is_prefix(char* s1, char* s2) {
	for (int i = 0; i < strlen(s2); i++){
		if (s1[i] != s2[i])
			return 0;
	}
	return 1;
}
int Que4(char* s1, char* s2) {
	int counter = 0;
	char* str;
	for (int i = 0; i <= strlen(s1)-strlen(s2); i++){
		if (is_prefix(s1 + i, s2))
			counter++;
	}
	return counter;
}
void Ex4() {
	printf("Function returned:%d", Que4("kababa", "aba"));
}
void Que5(int arr[R][C]) {
	int max = arr[0][0];
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			if (arr[i][j] > max)
				max = arr[i][j];
			else
				arr[i][j] = max;
		}
	}
	print_matrix(arr);
}
void Ex5() {
	int arr[R][C] = { {1,1,2,-5,-2},{3,-2,-1,0,4},{4,4,2,8,1} };
	Que5(arr);
}
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