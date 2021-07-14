#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#define N 8
#define R 3
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
	while (i <= q){temp[k] = a[i]; k++; i++;}//child porn

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

int is_even(int n) {
	if (n < 10)
		return ((n + 1) % 2);
	else
		return ((n % 10) + is_even(n / 10)) % 2;
}
int Que1(int* arr,int n,int i) {
	if (n == 0)
		return 0;
	if (i == 0) {
		return arr[0]+Que1(arr + 1, n - 1, i);
	}
	else {
		Que1(arr + 1, n - 2, i - 1);
	}


}
void Ex1() {
	int arr[12] = { 0,1,0,1,1,1,0,1,0,1,0,1 };
	printf("Function returned:%d", Que1(arr, 12, 5));
}
typedef struct {
	char name[20];
	double unitprice;
}Product;
void printproduct(Product s1) {
	printf("%s ,%.0f\n",s1.name,s1.unitprice);
}
void printproductsOrderByNames(Product* s1, Product* s2, int size) {
	int count = 0,i=0,j=size-1;
	while (count<size*2) {
		
		if (j==-1 ||(0 > strcmp(s1[i].name, s2[j].name))) {
			printproduct(s1[i]);
			i++; count++;
		}
		else  {
			if ((i == 3 || (0 < strcmp(s1[i].name, s2[j].name)))) {
				printproduct(s2[j]);
				j--; count++;}
			else {
				if (s1[i].unitprice > s2[j].unitprice)
					printproduct(s1[i]);
				else
					printproduct(s2[j]);
				i++; j--;
				count += 2;
			}
		}
		
	}}

void Ex2() {
	Product s1[3] = { {"Alice Mutton",90},{"Chai",85},{"Tofu", 87} };
	Product s2[3] = { {"Vegie-spread",80},{"Pavlova",10},{"Alice Mutton",70} };
	printproductsOrderByNames(s1, s2, 3);

}
int checkforabc(char* str) {
	int i = 1, count = 0;

	while (str[i]!='\0') {
		if (str[i] == str[i - 1] + 1 || str[i] == str[i - 1] + 1 - ('a' - 'A') || str[i] == str[i - 1] + 1 - ('A' - 'a'))
			count++;
		else
			count = 0;
		i++;
		if (count == 2)
			return 1;
	}
	
	return 0;

}
void Ex3() {
	printf("Function returned:%d\n", checkforabc("abC"));
}


int IsArithmeticSeries(int matrix[R][C]) {

	int d;
	for (int i = 0; i < R; i++){
		d = matrix[i][1] - matrix[i][0];
		for (int j = 2; j < C; j++){
			if (matrix[i][j] - matrix[i][j - 1] != d)
				return 0;
		}
	}
	return 1;
}

void Ex4() {
	int arr[R][C] = { {2,4,6,8},{7,7,7,7},{-1,-4,-7,-10} };
	printf("Function returned:%d\n", IsArithmeticSeries(arr));
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