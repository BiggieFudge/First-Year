#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data_item {
	int data;
	struct data_item *next;
} DataItem;

typedef struct ptr_item {
	DataItem *ptr;
	struct ptr_item *next;
} PtrItem;


void push(DataItem **list, int data) {
	DataItem* newitem = (DataItem*)malloc(sizeof(DataItem));
	newitem->data = data;
	newitem->next = NULL;
	DataItem* temp = *list;
	if (*list == NULL) {
		*list = newitem;
	}
	else {
		while (temp->next)
			temp = temp->next;
		temp->next = newitem;
	}

}


void pushPtr(PtrItem **list, DataItem* data) {
	PtrItem* newitem = (PtrItem*)malloc(sizeof(PtrItem));
	newitem->ptr = data;
	newitem->next = NULL;
	DataItem* temp = *list;
	if (*list == NULL) {
		temp = newitem;
	}
	else {
		while (temp->next)
			temp = temp->next;
		temp->next = newitem;
	}

}




int ArrByOrder(char** Arrstr, int N) {
	int check = strcmp(Arrstr[0], Arrstr[1]);
	for (int i = 2; i < N-1; i++){
		if (strcmp(Arrstr[i - 1], Arrstr[i])!=check)
			return 0;
	}
	return 1;
}


DataItem* Question2(PtrItem* list) {

	PtrItem* temp = list;
	DataItem* newlist=NULL;
	DataItem* tempnew = NULL;
	while (temp) {
		if (temp->ptr != NULL) {
			
			if (newlist == NULL) {
				newlist = temp->ptr;
				tempnew = newlist;
			}
			else {
				while (tempnew->next) {
					tempnew = tempnew->next;
				}
				tempnew->next = temp->ptr;
			}


		}
		temp = temp->next;
	}

	return newlist;
}

#define cols 8

void Question3(char* fileName, int A[][cols], int rows) {

	FILE *fp = fopen(fileName, "w");
	if (!fp)
		return;

	for (int i = 0; i < rows; i++) {
		fprintf(fp, "%d. ", i + 1);

		for (int j = 0; j <= cols-1; j++) {
			fprintf(fp, "%d-", A[i][j]);
			while (j<cols-1&&A[i][j] == A[i][j +1]) {
				j++;
			}
			fprintf(fp, "%d ", j);
		}
		fprintf(fp, "\n");
	}
	fclose(fp);
}


void main() {

	//Question 1
	/*char** arrstr = (char**)calloc(8, 1);
	arrstr[0] = "z2 $";
	arrstr[1] = "A very nice man! ";
	arrstr[2] = "Bring me, please.";
	arrstr[3] = "Many people";
	arrstr[4] = "0";
	arrstr[5] = "Paul 8-th";
	arrstr[6] = "Paul 9-th";
	arrstr[7] = "a is the first letter";

	ArrByOrder(arrstr, 8);*/


	//Question2
	/*PtrItem* list = NULL;
	DataItem* small = NULL;
	push(&small, 3);
	push(&small, 2);
	push(&small, 5);
	push(&list, small);
	small = NULL;
	push(&small, 6);
	push(&list, small);
	Question2(NULL);*/


	//Question 3

	int A[4][8] = { {2,3,3,6,6,6,6,9},
					{0,0,0,0,1,1,7,7},
					{5,5,5,5,5,5,5,5},
					{3,3,3,4,4,4,4,4} };



	Question3("output.txt", A, 4);

	printf("%d", 
		printf("%d", 
			printf("%d", 5)));
}