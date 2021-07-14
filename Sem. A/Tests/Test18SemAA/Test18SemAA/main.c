#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#define N 6
#define R 6
#define C 6
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
int bin_search(int key, int *a, int n)
{
	int low, high, mid;
	low = 0;
	high = n - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (key == a[mid])
			return mid;
		else if (key < a[mid])
			high = mid - 1;
		else /* key >a[mid] */
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
int Que1(int n) {

	if (n < 100) {
		if (n / 10 != n % 10)
			return 1;
		return 0;
	}
	if (n % 10 > n % 100 / 10) {
		if (n % 1000 / 100 > n % 100 / 10)
			return Que1(n / 10);
		return 0;
	}
	if (n % 10 < n % 100 / 10) {
		if (n % 1000 / 100 < n % 100 / 10)
			return Que1(n / 10);
		return 0;
	}
	return 0;
}
void Ex1() {
	printf("Function returned:%d\n", Que1(69438));
}
int Que2(int* arr, int x,int n) {
	int high = n-1,mid=n/2,low=0;
	while (low!=mid) {
		if (arr[mid]+ arr[mid + 1] > x)
			high = mid;
		else if (arr[mid] + arr[mid + 1] < x){
			low = mid;
		}
		if (arr[mid] + arr[mid + 1] == x)
			break;
		mid = (high + low) / 2;
	}
	if (arr[mid] + arr[mid + 1] == x)
		return mid;
	else
		return -1;
}
void Ex2() {
	int arr[7] = {-3,8,1,9,15,10,18};
	printf("Function returned:%d\n", Que2(arr,9,7));
}
void Que3(int* a, int n) {
	int counter = 0, index = 1;
	while (index < n) {
		if (a[index] == 1 && counter == 0)
			counter++;
		else if (a[index] == 1 && counter > 0) {
			counter++;
			a[index] = counter;
		}
		else if (a[index] == 0)
			counter = 0;
		index++;

	}
	print_array(a, n);
}
void Que3B(int* a, int n) {
	if (a[0])
		a[0] = n;
	for (int i = 1; i < n; i++){
		if (a[i])
			a[i] = a[i-1]+1;
	}
	for (int i = n - 2; i >= 0; i--) {
		if (a[i] > a[i + 1] + 1)
			a[i] = a[i + 1] + 1;
	}
	print_array(a, 7);
}
void Ex3() {
	int a[7] = { 0,1,1,1,0,1,0 };
	Que3B(a, 7);
}

int returnnum(char* str) {
	int num = 0,asarot=1;
	for (int i = strlen(str)-1; i >=0 ; i--) {
		if (str[i] >= '0'&& str[i] <= '9') {
			num = (num)+asarot * (str[i]-'0');
			asarot *= 10;
		}
		else
			num = num * -1;
	}
	return num;
}
void Ex4() {
	printf("Function returned:%d", returnnum("-2345"));
}

int maxAmuda(int a[N][N]) {
	int max = 0,maxp=0,maxtotal=0;
	for (int i = 0; i < N; i++){
		max = 0;
		for (int j = 1; j < N; j++) {
			if (a[j][i] > a[j - 1][i])
				max++;
			else {
				if (max > maxp) 
					maxp = max;
				max = 0;
				
			}
		}
		if (maxp>maxtotal)
			maxtotal = maxp+1;
		if (max >= maxtotal)
			maxtotal = max+1;
}
	return maxtotal;

}
void Ex5() {
	int arr[N][N] = { {-7,12,1,4,10,2},{5,3,23,-4,4,5},{1,-4,12,-2,-2,7},{-12,6,15,12,12,8},{3,7,-3,15,15,7},{8,10,4,20,20,8} };
	printf("Function returned:%d", maxAmuda(arr));
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