#include <stdio.h>
#include <assert.h>
int Que1(int *arr, int n) {
	if (n <= 1)
		return 1;
	if (arr[0] != arr[n - 1])
		return 0;
	Que1(arr + 1, n - 2);
}

void Ex1() {
	int arr[5] = { 1,2,3,2,1 };
	printf("Function Redturn:%d", Que1(arr, 5));
}
int Que2(int *arr, int n) {
	int x = 0;
	int* counter = (int*)calloc(n, sizeof(int));
	int* toadd = (int*)calloc(n, sizeof(int));
	assert(counter);
	for (int i = 0; i < n; i++) {
		counter[arr[i]]++;
	}
	for (int i = 0; i < n; i++) {
		if (counter[i] % 2 == 1)
			x++;
	}
	if (x < 2)
		return 0;
	int index = 0;
	for (int i = 0; i < n; i++) {
		if (counter[i] % 2 == 1) {
			toadd[index] = i;
			index++;
			x--;
		}
		if (x < 2)
			break;

	}
	for (int i = 0; i < index; i++) {
		printf("%d      ,", toadd[i]);
	}
}

void Ex2() {
	int arr[5] = {2,2,0,4,1};
	printf("Function Redturn:%d", Que2(arr, 5));
}
int Que3(int* a,int* b,int n) {
	int i = 0, j = n-1;
	while (i<n && j>=0) {
		if (a[i] == b[j]) {
			return 0;
		}
		if (a[i] < b[j])
			i++;
		else
			j--;
	}
	return 1;
}
void Ex3() {
	int a[5] = { 1,2,3,4,6 }, b[5] = { 10,9,6,0,-1 };
	printf("Function Returned:%d", Que3(a, b, 5));

}

void Ex4() {
	int arr[3][3] = { {12,19,14},{17,15,13},{16,11,18} };
	printf("Function returned:%d", Que4(arr, 3));

}
int Que4(int arr[3][3],int n) {
	int *Rows = (int*)calloc(n, sizeof(int));
	int *Colum = (int*)calloc(n, sizeof(int));
	int *Alhson = (int*)calloc(2, sizeof(int));
	assert(Rows);
	assert(Colum);
	assert(Alhson);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++) {
			Rows[i] += arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			Colum[i] += arr[j][i];
		}
	}
	for (int i = 0; i < n; i++) {
			Alhson[0] += arr[i][i];	
	}
	for (int i = 0; i < n; i++) {
		Alhson[1] += arr[n-i-1][i];
	}
	for (int i = 0; i < n -1; i++) {
		if (Rows[i] != Rows[i + 1])
			return 0;
		if (Rows[i] != Alhson[i])
			return 0;
	}
	for (int i = 0; i < n; i++) {
		if (Rows[i] != Colum[i])
			return 0;
	}
	return 1;
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