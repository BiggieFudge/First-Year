


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <string.h>
#include <math.h>
typedef struct item
{
	int data;
	struct item* next;
} Item;

Item* insertAfter(Item* list, int data) {

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

Item* Question1(Item** Arr, int n) {
	Item* Temp;
	Item* List = NULL;
	int i = 0;

	while (i < n) {
		Temp = Arr[i];
		while (Temp != NULL) {
			List = insertAfter(List, Temp->data);

		}
		i++;
	}

}
int IsPrime(int x) {

	if (x == 0 || x == 1) return 0;
	for (int i = 2; i <= sqrt(x); i++) {
		if (x%i == 0)
			return 0;
	}
	return 1;
}


#define COLS 5
int Question2(int Arr[][COLS], int n) {
	int i = 0;
	int j = 0;
	int counter = 0;
	int* arr = (int*)calloc(1, sizeof(int));
	for (i=0; i < n; i++) {
		for (j=0; j < COLS; j++) {
			if (IsPrime(i + j)) {
				counter++;
				if(counter>1)arr = (int*)realloc(arr,counter*sizeof(int));
				arr[counter - 1] = Arr[i][j];
			}
		}
	}

	Arr = arr;

	return counter;

}


void Question3(char* filename) {

	FILE* fp;
	FILE* fc;
	fopen_s(&fp, filename, "r");
	char* str = (char*) calloc (500,sizeof(char));
	fgets(str, 500, fp);
	int i = 0;
	char* filename2 = (char*)calloc(500, sizeof(char));
	strcpy_s(filename2, 500, filename);
	filename2[0] = 'a';
	fopen_s(&fc, filename2,"w+");
	while (i < strlen(str)) {
		if (str[i] !='.') {
			fprintf(fc, "%c", str[i]);
		}
		else {
			fprintf(fc, "\n");
		}
		i++;
	}

	fclose(fc);
	fclose(fp);
}


void main() {
	strcmp("EOF+", "EOF+EOF");
	Question3("text.txt");
}