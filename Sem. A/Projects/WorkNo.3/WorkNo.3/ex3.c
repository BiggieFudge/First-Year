// איתן רכלין 207207572
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Function declarations */
void Ex1();
void Ex2();
void Ex3();
void Ex4();
void Ex5();

/* Declarations of other functions */

int* inputArray();
int* IncomingArray(int*, int*, int, int);
void printArray(int*, int);
int FirstNumTwice(int *, int);
int IsByOrder(int *, int );
int LastNeg(int* , int);
int StringPali(char*, int*, int*);
/* ------------------------------- */
// no need to change the main function for matala 1.
// 
int main()
{
	int select = 0, i, all_Ex_in_loop = 0;
	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
	if (scanf_s("%d", &all_Ex_in_loop) == 1)
		do
		{
			for (i = 1; i <= 5; i++)
				printf("Ex%d--->%d\n", i, i);
			printf("EXIT-->0\n");
			do {
				select = 0;
				printf("please select 0-5 : ");
				scanf_s("%d", &select);
			} while ((select < 0) || (select > 5));
			switch (select)
			{
			case 1: Ex1(); break;
			case 2: Ex2(); break;
			case 3: Ex3(); break;
			case 4: Ex4(); break;
			case 5: Ex5(); break;
			}
		} while (all_Ex_in_loop && select);
		return 0;
}

/*.............................*/
void Ex1()
{   
	int a, b;
	int sizeofArray;
	int* arr = inputArray(&sizeofArray);
	printf("Enter a:");
	scanf_s("%d", &a);
	printf("\nEnter b:");
	scanf_s("%d", &b);
	int* brr=IncomingArray(arr, &sizeofArray, a, b);
	printArray(brr, sizeofArray);
	free(arr);

}
int* inputArray(int *PtrSize) {
	int n;
	printf("Enter n:");
	scanf_s("%d", &n);
	int* arr = (int*)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++) {
		printf("Enter arr[%d]:", i);
		scanf_s("%d", &arr[i]);
	}
	*PtrSize = n;
	return arr;
}
int* IncomingArray(int* arr, int* size, int a, int b) {
	int n = *size,min=arr[0],FirstMin=0,Elements=0;
	int* counter = (int*)calloc((b - a)+1, sizeof(int));
	if (counter == NULL) {
		printf("\nERROR");
		exit(1);
	}
	for (int i = 0; i < n; i++) {
		if (arr[i] >= a && arr[i] <= b) {
			Elements++;
			counter[arr[i] - a]++;
			if (arr[i] < min || FirstMin == 0) {
				min = arr[i];
				FirstMin++;
			}
		}
	}
	if (Elements == 0) {
		printf("No Numbers between and b");
		exit(1);
	}

	int* brr = (int*)calloc(Elements, sizeof(int));
	if (brr == NULL) {
		printf("\nERROR");
		exit(1);
	}
	int k = min - a;
	int j = 0;
	while (j != Elements) {
		while (counter[k] == 0)
			k++;
		if(counter[k]>0) {
			brr[j] = k + a;
			counter[k]--;
				j++;
		}
	}
	*size = Elements;
	free(counter);
	return brr;
}

void printArray(int *arr, int n) {
	for (int i = 0; i < n; i++)
		printf("arr[%d]:%d\n", i, arr[i]);
	free(arr);
}


/*.............................*/
void Ex2() {
	int sizeofArray;
	int* arr = inputArray(&sizeofArray);
	printf("Function Returned:%d\n", FirstNumTwice(arr, sizeofArray));
	free(arr);

}

int FirstNumTwice(int *arr, int n) {
	int *counter = calloc((3 * n)+1, sizeof(int));
	for (int i = 0; i < n; i++) {
		counter[arr[i]]++;
		if (counter[arr[i]] == 2) {
			free(counter);
			return arr[i];
		}
	}
	free(counter);
	return -1;
}
/*.............................*/
void Ex3() {
	int sizeofArray;
	int* arr = inputArray(&sizeofArray);
	printf("Function Returned:%d\n", IsByOrder(arr, sizeofArray));
}
int IsByOrder(int *arr, int n) {
	int min=arr[0], max=arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] > max)
			max = arr[i];
		else if (arr[i] < min)
			min = arr[i];
	}
	if (min == max)
		return 0;
	int* counter = (int*)calloc((max-min)+1, sizeof(int));
	for (int i = 0; i < n; i++) {
		counter[arr[i] - min]++;
	}
	for (int i = 0; i < (max - min) + 1; i++) {
		if (counter[i] == 0) {
			free(counter);
			free(arr);
			return 0;
		}
	}
	free(counter);
	free(arr);
	return 1;

}
/*.............................*/
void Ex4() {
	int sizeofArray;
	int* arr = inputArray(&sizeofArray);
	if (arr == NULL) {
		printf("\nERROR");
		exit(1);
	}
	printf("Last Negative number was:%d\n", LastNeg(arr, sizeofArray));
	free(arr);
	}

int LastNeg(int* arr, int n) {
	for (int i = n / 2; i < n; ) {
		if (arr[i] >= 0) {
			if (arr[i - 1] < 0) {
				return arr[i - 1];
			}
			i /= 2;
		}
		else {
			if (arr[i + 1] > 0) {
				return arr[i + 1];
			}
			i += i / 2;
		}
	}
}
/*.............................*/
void Ex5() {
	char str[20];
	int start = 0, end = 0;
	printf("Enter String up to 20 characters:\n");
	scanf_s(" %[^\n]s", str , sizeof(str)-1);
	printf("\nFunction Returned:%d\n", StringPali(str, &start , &end));
	printf("low=%d, high=%d\n", start, end);
}
/*      Worst Question ever   */
/*            1/10             */
/*    Would not answer again  */
int StringPali(char* str, int* start, int* end) {
	int i,j = 0, min, max;
	char newstr[20];
	int* spaces = (int*)calloc(strlen(str), sizeof(int));
	if (spaces == NULL) {
		printf("\nERROR");
		exit(1);
	}
	for (i = 0; str[i] != '\0';) {
		if (str[j] == 32) {
			spaces[j] = 1;
		}
		else {
			newstr[i] = tolower(str[j]);
			i++;
		}
		j++;
	}
	newstr[i] = '\0';
	int index = 1;
	if ((newstr[(strlen(newstr) / 2) - 1] == newstr[(strlen(newstr) / 2)]) || newstr[(strlen(newstr) / 2) - 1] == newstr[(strlen(newstr) / 2) + 1])
		index = (strlen(newstr) / 2);

	else {
		while (newstr[index - 1] != newstr[index + 1] && newstr[index - 1] != newstr[index]) {
			index++;
			if (index == strlen(newstr))
				return 0;
		}
	}
	int DistanceFromIndex = 1;
	i = 0;
	j = strlen(newstr) - 1;

	int pali = 0;
	while (i<strlen(newstr)) {
		min = i; 
		max = j;//שמירה של הפרטמרטרים שמתחילים לבדוק פלינדרום
		while (newstr[i]==newstr[j]) {
			if (i == j || i + 1 == j) {
				pali = 1;
				break;
			}
			i++; j--;
		}
		if (pali)
			break;
		if (j == i + 1) {
			i++;
			j = strlen(newstr)-1;
		}
		else {
			j = max - 1;
		}

	}
	for (int f = 0; f < max; f++) {
		if (spaces[f] == 1) {
			if (min >= f) {
				max++;
				min++;
			}
			else if (max >= f) {
				max++;
			}
		}
	}
	free(spaces);
	*start = min;
	*end = max;
	return 1;
}
