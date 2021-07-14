#include <stdio.h>
#include <assert.h>
int Ex1(int num) {
	int lastdig = num % 100;
	if (num < 10 && num % 2 == 0)
		return 1;

	if (((lastdig % 10) % 2 != 0)|| (lastdig / 10) % 2 != 1) {
		return 0;
	}
	Ex1(num / 100);
	
}
void Que1() {
	printf("Enter Num:");
	int num;
	scanf_s("%d", &num);
	printf("Function Returned:%d\n", Ex1(num));
}
//     ******************************************************************************************//
int* inputArray(int *PtrSize) {
	int n;
	printf("Enter n:");
	scanf_s("%d", &n);
	int* arr = (int*)calloc(n, sizeof(int));
	assert(arr);
	for (int i = 0; i < n; i++) {
		printf("Enter arr[%d]:", i);
		scanf_s("%d", &arr[i]);
	}
	*PtrSize = n;
	return arr;
}
int Que2(int* arr,int size) {
	int counter = 0;
	int* brr = (int*) calloc(size, sizeof(int));
	assert(brr);
	for (int i = 0; i < size; i++) {
		if (arr[i] >= 0 && arr[i] <= size - 1)
			if (brr[arr[i]] == 0) {
				brr[arr[i]]++;
				counter++;
			}
	}
	free(arr);
	return counter;
}
void Ex2() {
	int size;
	int* arr = inputArray(&size);
	printf("Function Returned:%d\n", Que2(arr, size));
}
// *********************************************************************************************//


void Ex3() {
	int size;
	int* arr = inputArray(&size);
	//                 ?????????????????????????????????????????//
}
// *********************************************************************************************//

int Que4(int* arr,int* brr,int size,int size2) {
	int index = 0,i,flag=0;
	int first = arr[0];
	for (i = 0; i < size2; i++) {
		if (first == brr[i])
			break;
	}
	while (arr[index]==brr[i]) {
		index++;
		i++;
		if (i == size2)
			i = 0;
		if (index == size) {
			flag = 1;
				break;
		}
	}
	free(arr);
	free(brr);
	return flag;
}

int Ex4() {
	int size;
	int* arr = inputArray(&size);
	int size2;
	int* brr = inputArray(&size2);
	printf("Function Returned:%d\n", Que4(arr, brr, size, size2));
}
//         **********************************************************************************//
void print_array(int *a, int sz) {
	int i;
	for (i = 0; i < sz; i++)
		printf("%3d", a[i]);
}

int* Que5(int* arr,int size) {
	int i,index;
	for (i = 0; i < size - 1; i++) {
		if (arr[i] > arr[i + 1]) {
			i++;
			break;
		}
	}
	int x = i;
	int* brr = (int*)calloc(size, sizeof(int));
	int j = 0;
	for (index = 0; index < size; index++) {
		if (j == x) {
			brr[index] = arr[i];
				i++;
		}
		else if (i == size) {
			brr[index] = arr[j];
			j++;
		}
		else if (arr[j] > arr[i]) {
			brr[index] = arr[i];
			i++;
		}
		else {
			brr[index] = arr[j];
			j++;
			
		}
		
	}
	return brr;
}

int Ex5() {
	int size;
	int* arr = inputArray(&size);
	int* newarray = Que5(arr, size);
	print_array(newarray,size);
}
//***********************************************************************************************//

int Que6(int arr[3][3],int a,int b) {
	int Howmuchchecked = 0,x=0,y=0, locationx=0,locationy=0,i=0;
	int* brr = (int*)calloc(8, sizeof(int));
	while (Howmuchchecked < a*b) {
		i = 0;
		x = locationx - 1;
		y = locationy - 1;
			for (int k = x; k < x + 3; k++) {
				for (int j = y; j < y + 3; j++) {
					if ((j != locationy || k != locationx) && ((j >= 0 && k >= 0))) {
						brr[i] = arr[k][j];
						i++;
					}
				}
			}
		for(int z=0;z<a*b;z++){
			if (arr[locationx][locationy] == brr[i])
				return 0;
		}
		Howmuchchecked++;
		if (locationy != b)
			locationx++;
		else
			locationy++;

	}
	return 1;
}


void Ex6() {
	int arr[3][3] = { { 11,10,11 }, { 17,13,13 }, { 10,11,10 } };
	printf("Function Returned:%d\n", Que6(arr, 3, 3));
}
int main()
{
	int select = 0, i, all_Ex_in_loop = 0,num;
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
			case 1: Que1(); break;
			case 2: Ex2(); break;
			case 3: Ex3(); break;
			case 4: Ex4(); break;
			case 5: Ex5(); break;
			case 6: Ex6(); break;
			}
		} while (all_Ex_in_loop && select);
		return 0;
}