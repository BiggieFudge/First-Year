#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define N 4
double Que1(double* arr, int n) {
	double q = arr[1] / arr[0];
	if (n < 3)
		return q;
	if (q != arr[2] / arr[1])
		return 0;
	return Que1(arr + 1, n - 1);

}
void Ex1() {
	double arr[5] = { 2.5,5,10,20,40 };
	printf("Function Returned:%.3f", Que1(arr, 5));
}

int* Que2(int* arr, int n) {
	int* counter = (int*)calloc(n, sizeof(int));
	assert(counter);
	int min = arr[0];

	for (int i = 0; i < n; i++) {
		if (arr[i] < min)
			min = arr[i];
	}
	for (int i = 0; i < n; i++){
		counter[arr[i]-min]++;
	}
	int index = 0, i = 0;
	while (i < n) {
		if (counter[i] != 0) {
			arr[index] = i + min;
			index++;
			counter[i]--;
		}
		else
			i++;
	}
	free(counter);
	return arr;
}
void Ex2() {
	int arr[8] = { 15,16,16,15,14,13,12,13 };
	int brr=Que2(arr, 8);
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

int Que3(int* arr, int* n) {
	int size = *n,small;
	if (arr[0] < arr[size - 1])
		small = arr[0];
	else
		small = arr[size - 1];
	int low = 0, high = size - 1, mid;
	while (low<high) {
		mid = (low + high) / 2;
		if (arr[mid + 1] > arr[mid])
			low = mid + 1;
		else
			high = mid;
	}
	*n = small;
	return low;
}
void Ex3() {
	int max = 10,key;
	int arr[10] = { 4, 10, 43, 72, 51, 38, 10, 8, 6, 2 };
	int min = Que3(arr, &max);
	key = bin_search_last(10, arr, min);
	printf("Function returned:%d", key);
}

void Ex4() {
	char* s1 = "the books are here";
	char* s2 = "the     books are h e r e ";
	printf("Function returned:%d", comparestr(s1, s2));
}
int comparestr(char* str1, char* str2) {

	int i = 0, j = 0;
	while (i < strlen(str1) || j < strlen(str2)) {
		if (str1[i] == 32)
			i++;
		if (str2[j] == 32)
			j++;
		if (str1[i] != 32 && str2[j] != 32) {
			if (str1[i] != str2[j])
				return 0;
			i++;
			j++;
		}
	}
	return 1;
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

void replaceAlahson(int arr[N][N]) {
	int n = N,temp;
	for (int i = 0; i < N; i++){
		temp = arr[i][i];
		arr[i][i] = arr[i][n - i - 1];
		arr[i][n - i - 1] = temp;
	}
	print_matrix(arr);
}
void Ex5() {
	int arr[4][4] = { {-7,12,1,6},{25,13,23,18},{27,26,36,91},{48,39,38,30} };
	replaceAlahson(arr);
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