#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#define N 8
#define R 4
#define C 4
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

int is_even(int n) {
	if (n < 10)
		return ((n+1)%2);
	else
		return ((n % 10) + is_even(n / 10))%2;
}
void Ex1() {
	printf("Function returned:%d", is_even(8635));
}

int gcd(int* arr, int n) {
	int gcd = 2,gcdtotal=1;
	int index = 0;
	while (gcd <= arr[index]){
		if (arr[index] % (gcd) != 0) {
			gcd++;
			index = 0;
		}
		else if (index == n - 1) {
			gcdtotal = gcd;
			gcd++;
			index = 0;
		}
		else
			index++;
	}
	
	return (gcdtotal);
}
void Ex2() {
	int arr[5] = { 15,55,15,5,180 };
	printf("Function returned:%d", gcd(arr, 5));
}

void Que3(char *str) {
	int i,reset,index=1;
	for (i = 0; i < strlen(str)-1; i++){
		int count = 0;
		while (str[i] == str[i + 1]) {
			count++;
			i++;
		}
		reset = i;
		while (index <=strlen(str)-1 && count>0) {
			
			if (index == strlen(str) - 1) {
				str[index] = '\0';
				count = 0;
				index++;
			}
			char toadd = str[reset + index];
			index = reset - count + index;
			*(str+index) = toadd ;
			index++;
		}
	}
	puts(str);
}
void Ex3() {
	char* str = "bssdffFdcrrrtttii    ***#";
	Que3(str);
}

void Ex4() {}
int weirdsquare(int arr[N][N]) {
	int low, high, mid;
	low = 0;
	high = N - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (1 == arr[mid][mid]&& 0 == arr[mid-1][mid-1])
			break;
		else if (1 == arr[mid][mid])
			high = mid - 1;
		else /* key >a[mid] */
			low = mid + 1;
	}
	if (arr[mid][mid-1] == 0) {
		int mid2;
		while (low <= high)
		{
			mid2 = (low + high) / 2;
			if (1 == arr[mid2][mid])
				break;
			else if (1 < arr[mid2][mid])
				high = mid2 - 1;
			else /* key >a[mid] */
				low = mid2 + 1;
		}

	}
	
}
void Ex5() {
	int arr[N][N] = {{ 0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0 } ,{ 0,0,0,0,0,0,0,0 } ,{ 0,0,0,0,1,1,1,1 },{ 0,0,0,0,1,1,1,1 },{ 0,0,0,0,1,1,1,1 },{ 0,0,0,0,1,1,1,1 },{ 0,0,0,0,1,1,1,1 } };
	weirdsquare(arr);
}
void findnums(int* brr, int n, int k) {
	int max = arr[0], min = arr[0];
	int arr[N][N] = { { 0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0 } ,{ 0,0,0,0,0,0,0,0 } ,{ 0,0,0,0,1,1,1,1 },{ 0,0,0,0,1,1,1,1 },{ 0,0,0,0,1,1,1,1 },{ 0,0,0,0,1,1,1,1 },{ 0,0,0,0,1,1,1,1 } };

	for (int i = 0; i < n; i++){
		if (arr[i]<k && arr[i]>max)
			max = arr[i];
		else if (arr[i] > k && arr[i] < min)
			bin_search(1, arr[N-1], N);
		bin_search(1, arr[N - 1], N);

	}
}
void printcircly(int arr[R][C]) {
	int i = 0, j = 0, index = 0;

	while (index < C-2) {
		printf("%d  ", arr[i][j]);
		if (i + index == R-1 && j != index)
			j--;
		
		else if (j + index == C - 1)
			i++;
		else if (i   ==  index)
			j++;
		else if (j  == index)
			i--;
	
		if (j == index && i==index) {
			index++;
			j = index;
			i = index;
		}
		
	}

}
void Ex6() {
	int matrix[R][C] = { {1,5,2,3,},{4,8,11,9},{7,6,10,30},{23,16,17,20} };
	printcircly(matrix);
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