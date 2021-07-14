#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <string.h>
#include <math.h>


typedef struct three {
	int key;
	int i;
	int j;
}Three;

int CheckArr(int arr[][5], int r, int c,Three **brr) {

	Three* Threearr = NULL;
	int counter=0;
	int i = 0, j = 0;
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {

			if (arr[i][j] == i + j) {
				
				Threearr = (Three*)realloc(Threearr, (++counter) * (sizeof(Three)));
				Threearr[counter - 1].key = arr[i][j];
				Threearr[counter - 1].i = i;
				Threearr[counter - 1].j = j;
			}
		}
	}
	if (counter==0) { return NULL; }
	*brr = Threearr;
	return counter;
}



void Question2(char* str) {

	int i = 0;
	char* newstr = NULL;
	newstr = (char*)calloc(1, sizeof(char));
	int counter = 0;
	while(i<strlen(str)){
		if (str[i] >= 'A' && str[i] <= 'Z') {
			counter++;
			if(counter>1) newstr = (char*)realloc(newstr, (counter) * sizeof(char));
			newstr[counter-1] = (str[i] - ('A' - 'a'));
		}
		else if (str[i] >= 'a' && str[i] <= 'z') {
			counter++;
			if (counter > 1) newstr = (char*)realloc(newstr, (counter) * sizeof(char));
			newstr[counter-1] = str[i] + ('A' - 'a');
		}
		else if (str[i] >= '1' && str[i] <= '9') {
			
			newstr = (char*)realloc(newstr, (counter + (str[i] -48)) * sizeof(char));
			char j = '1';
			while (j <= str[i]) {
				counter++;
				newstr[counter-1] = j;
				j++;
				
			}
			
		}
		i++;
	}

	free(newstr);
}

typedef struct item {
	int data;
	struct item* next;
}Item;

void Insert(Item** List,int data) {
	if ((*List) == NULL) {
		(*List) = (Item*)calloc(1, sizeof(Item));
		(*List)->data = data;
		(*List)->next = NULL;
	}
	else {
		Item* temp = *List;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = (Item*)calloc(1, sizeof(Item));
		temp->next->data = data;
		temp->next->next = NULL;
		
	}
}


//int found(Item* List, int n) {
//	Item* temp = List;
//	while (temp!=NULL) {
//		if (temp->data == n) {
//			return 1;
//		}
//		temp = temp->next;
//	}
//	return 0;
//}



Item* Question3(int* arr, int n) {
	Item* List = NULL;
	int i = 0;
	while (i < n) {
		if (!found(List, arr[i])) {
			Insert(&List, arr[i]);
		}
		i++;

	}
	return List;
}

typedef struct node
{
	int data;
	struct node * next;
}Node;

int found(Node* list, int key)
{
	Node* temp = list;
	while (temp != NULL) {
		if (temp->data == key) { return 1; }
		temp = temp->next;
	}
	return 0;
}
void insert(Node** list, int key)
{
	Node * item = (Node*)calloc(1, sizeof(Node));
	Node * temp = list;

	item->data = key;
	item->next = NULL;

	if ((*list) == NULL) {
		(*list) = item;
	}
	else {
		while (temp != NULL) { temp = temp->next; }
		temp->next = item;
	}
}
void freel(Node** list)
{
	Node * temp =*list;
	Node * temp2;
	while (temp != NULL) {
		temp2 = temp;
		temp = temp->next;
		free(temp2);
	}
}

Node* buildL(int* arr, int size){
	Node* list = NULL;

	for (int i = 0; i < size; i++) {
		if (!found(list, arr[i])) {
			insert(&list, arr[i]);
		}
	}
	return list;
}

void freelist(Item** List) {
	Item* temp = *List;
	Item* next = NULL;
	while (temp != NULL) {
		next = temp->next;
		free(temp);
		temp = next;
	}
	*List = NULL;
}

void main() {
	//Question1
	int arr[4][5] = { {3,2,5,3,6},{8,3,4,6,5},{0,6,4,5,7},{9,8,6,6,1} };
	Three* Threearr = NULL;
	CheckArr(arr, 4, 5, &Threearr);
	free(Threearr);

	//Question 2
	Question2("A$q0#3D4");

	//Question 3
	int brr[7] = { 9,5,9,2,4,5,9 };
	Item* List =NULL;
	List=Question3(brr, 7);
	freelist(&List);

	List= buildL(arr, 7);
}