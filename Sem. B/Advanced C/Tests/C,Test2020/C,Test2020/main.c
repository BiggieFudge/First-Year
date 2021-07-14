


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <string.h>
#include <math.h>


int Question1(char* str) {


	int i = 0;
	char Big=0, Small=0, Num=0, Etc=0;

	while (i < strlen(str)) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			if ((Big == 0) || (Big <= str[i]))
				Big = str[i];
			else if (Big > str[i])
				return 0;
		}
		else if (str[i] >= 'a' && str[i] <= 'z') {
			if ((Small == 0) || (Small <= str[i]))
				Small = str[i];
			else if (Small > str[i])
				return 0;
		}
		else if (str[i] >= '0' && str[i] <= '9') {
			if ((Num == 0) || (Num <= str[i]))
				Num = str[i];
			else if (Num > str[i])
				return 0;
		}

		else {
			if ((Etc == 0) || (Etc <= str[i]))
				Etc = str[i];
			else if (Etc> str[i])
				return 0;
		
		}
		i++;
	}

	return 1;
}



typedef struct item
{
	int data;
	struct item *next;
} Item;

Item* insertAfter(Item* list, int data){

	Item* newnode = (Item*)malloc(sizeof(Item));

	newnode->data = data;
	newnode->next = NULL;
	Item* temp = list;
	if (temp == NULL) {
		list = newnode;
		return list;
	}
	while (temp->next) {
		temp = temp->next;
	}
	temp->next = newnode;
	return list;
}





Item* Question2(Item** arr, int n, Item* L) {
	Item* temp1;
	Item* temp2;
	Item* Return=NULL;
	int i = 0;
	while (i < n) {
		temp2 = arr[i];
		temp1 = L;
		while (temp1->data == temp2->data) {
			temp1 = temp1->next;
			temp2 = temp2->next;
			if (temp1 == NULL) {
				Return = insertAfter(Return, i);
				break;
			}
		}
		i++;
		
	}
	return Return;
}
void freerow(Item* row) {
	while (row != NULL) {
		Item* next = row->next;
		free(row);
		row = next;
	}
	row = NULL;

}

void freearrlist(Item** list) {
	
	int i = 0;
	while (i < 5) {
		freerow(list[i]);
	}
	free(list);
}
#define COLS 5
int* SkepticMatrix(int** A, char* filename) {

	FILE* fp;
	fopen_s(&fp, filename, "r");
	char str[20];
	int i = 0,num=0;
	while(fgets(str, 20, fp)) {
		if (strcmp(str,"\n")) {
			num = str[0] - 48;
			A[num] = (int*)calloc(COLS, sizeof(int));
			for (int j = 3; j + 3 < strlen(str); j += 6) {

				A[num][str[j + 3] - 48] = str[j] - 48;

			}
		}
		fclose(fp);
		
	}

	
	return A;

}

int x;
void main() {
	

	printf("Function Returned:%d\n", Question1("B4$Ca%ds5P8P&9zY"));

	Item** list, *row=NULL;
	list = (Item**)calloc(5, sizeof(Item*));
	int num=0,i=0;
	
	while (i<5) {

		scanf_s("%d", &num);
		row = NULL;
		while (num != -1) {
			
			row = insertAfter(row, num);
			scanf_s("%d", &num);

		}

		list[i] = row;
		i++;
		
	}

	Question2(list, 5, row);
	freerow(row);
	freearrlist(list);
	/*int A[ROWS][COLS];
	SkepticMatrix(A, "input.txt");*/
	

	
}