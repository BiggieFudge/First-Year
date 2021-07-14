#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZEOF -

void Question1(char** Arrstr,int N, char* fileName) {
	FILE *fp;
	fp = fopen(fileName, "w");
	if (fp == NULL)
		return;
	for (int i = 0; i < N; i++) {
		fprintf(fp, "%d. %s\n", i + 1, Arrstr[i]);
	}
	fclose(fp);
}

typedef struct data_item {
	int data;
	struct data_item *next;
} DataItem;

typedef struct ptr_item {
	DataItem *ptr;
	struct ptr_item *next;
} PtrItem;


void  push(DataItem** List, int data) {
	DataItem* new_item = (DataItem*)calloc(1, sizeof(DataItem));
	
	new_item->data = data;
	new_item->next = (*List);
	
	
	(*List) = new_item;

}

void  pushPtr(PtrItem** List,DataItem* Di) {
	PtrItem* new_item = (PtrItem*)calloc(1, sizeof(PtrItem));
	
	new_item->ptr = Di;
	new_item->next = (*List);
	
	(*List) = new_item;
}




PtrItem* Question2(DataItem* L) {
	DataItem* temp = L;
	DataItem* DataItems = NULL;
	PtrItem* L2 = NULL;

	while (temp) {
		DataItems = NULL;
		for (int i = 0; i < temp->data; i++) {
			push(&DataItems,pow(2,i));
		}

		pushPtr(&L2, DataItems);
		temp = temp->next;
	}


	return L2;
}
#define rows 3
#define cols 4

int breaknum(int num) {
	int sum = 0;
	while (num > 9) {
		sum += num % 10;
		num /= 10;
	}
	return sum + num;
}

void Question3(int A[rows][cols], int num,int *r,int *c) {

	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < cols; j++) {
			if (breaknum(A[i][j]) == num) {
				*r = i;
				*c = j;
				return;
			}
		}
	}
	int i = -1;
	
	*r = i;
	*c = i;
	
}


void main() {
	char** Arrstr = (char**)calloc(4, sizeof(char*));
	Arrstr[0] = "Ben Gurion 32, Tel Aviv";
	Arrstr[1] = "Bugrashov 8, Rehovot";
	Arrstr[2] = "Ben Gurion 32, Tel Aviv";
	Arrstr[3] = "Bugrashov 8, Rehovot";
	Question1(Arrstr, 4, "output.txt");

	DataItem* L = NULL;
	push(&L, 4);
	push(&L, 2);
	push(&L, 0);
	push(&L, 3);
	Question2(L);

	int A[rows][cols] = { {35,67,789,12},{6,56,472,78},{45,25,5,90} };
	int i = 0, j = 0;

	Question3(A, 13, &i, &j);


	printf("%d", EOF SIZEOF(int)sizeof EOF);

}