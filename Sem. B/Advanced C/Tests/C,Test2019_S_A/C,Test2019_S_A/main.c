
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <string.h>


void ChangeText(char* filename) {
	FILE* fp,*fp1=NULL;
	fopen_s(&fp, filename, "r+");
	char str=0;
	int sum = 0;
	int i = 0;
	
	while (str=fgetc(fp)) {
		
			if (str == '\n') {
				fseek(fp1, i-1, SEEK_SET);
				fprintf(fp1, " %d %c", sum, (sum % 128));
				sum = 0;
				
			}
			else {
				sum += str;
				i++;
				fp1 = fp;
			}
		
	}

	fclose(fp);
}



typedef struct item
{
	char *string;
	struct item *next;
} Item;

void insertAfter(Item** list, char* string) {

	Item* newnode = (Item*)malloc(sizeof(Item));
	newnode->string = (char*)calloc(strlen(string), sizeof(char));
	
	for (int i = 0; i < strlen(string); i++) {
		newnode->string[i] = string[i];
	}

	newnode->string = string;
	newnode->next = NULL;
	Item* temp = *list;
	if (temp == NULL) {
		*list = newnode;
		return;
	}
	while (temp->next) {
		temp = temp->next;
	}
	temp->next = newnode;

}


Item* BuildList(char** String, int n) {
	Item* list = NULL;
	char* word=NULL;
	int i = 0,j=0;
	while (i < n) {
		j = 0;
		while (String[i][j] != ' ') {
			j++;
		}
		word = (char*)calloc(j, sizeof(char));
		memcpy(word, String[i], j * sizeof(char));
		word[j] = '\0';
		insertAfter(&list, word);
		i++;
	}
	return list;
}

int** quest3(int** arr, int** brr, int n, int* sa, int* sb, int** sc)
{
	int** crr;
	crr = (int**)calloc(n, sizeof(int*));
	int j = 0;
	int i = 0;
	*sc = (int*)calloc(n, sizeof(int));

	while (i < n)
	{
		int min;
		if (sa[i] > sb[i])
			min = sb[i];
		else
			min = sa[i];
		(*sc)[i] = min;
		crr[i] = (int)calloc(min, sizeof(int));
		j = 0;
		while (j < min)
		{
			crr[i][j] = arr[i][j] + brr[i][j];
			j++;

		}
		i++;

	}
	return crr;
}
int *fun() {
	static int x;
	x++;
	return &x;
}
void freelist(Item** list) {
	Item* temp = *list, *next;
	while (temp) {
		next = temp->next;
		free(temp);
		temp = next;
	}
	list = NULL;
}

void main() {

	/*char s1[] = "Moshe lives in Tel Aviv";
	char s2[] = "Irit was the first";
	char s3[] = "Avi has two children";
	char* s[] = { s1,s2,s3 };

	Item* list=BuildList(s, 3);
	freelist(&list);*/

	/*int a1[] = { 13,33 };
	int a2[] = { 15,17,19,21 };
	int a3[] = { 41,43,53,41,17,15 };
	int sa[3] = { 2,4,6 };
	int b1[] = { 20,19,56 };
	int b2[] = { 44,11,39 };
	int b3[] = { 55,50,27,14 };
	int sb[3] = { 3,3,4 };
	int* arr[3] = { a1,a2,a3 };
	int* brr[3] = { b1,b2,b3 };
	int* sc = NULL;
	int** crr = quest3(arr, brr, 3, sa, sb, &sc);


*/


/*
	char *str = "Hello";
	int p, i, len = strlen(str);
	for (i = 0, p = 1; i <= len; i++) {

		p *= *(str + i);
	}
	printf("%d", p);*/



	
	printf("%d", sizeof "/0\0");
}