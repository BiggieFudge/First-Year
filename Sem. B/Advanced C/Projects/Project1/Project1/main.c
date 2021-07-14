//Work by Tony 'King' Hason ID:316047281 and Eytan Rahlin ID:207207572;

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
//#define INT_MIN -2147483647;
//#define INT_MAX 2147483647;
/* Function declarations */

void Ex1();
void Ex2();
void Ex3();
void Ex4();
void Ex5();
void Ex6();
void Ex7();

/* Declarations of other functions */
typedef struct {
	int value;
	int i;
	int j;
}Three;

typedef struct {
	Three item;
	struct Node* link;
}Node;

typedef struct {
	int num;
	struct Node4* link;
}Node4;


//question 1
int* powerArray(int n);

//question 2
void print_mat(int** mat, int row, int col);
int** input_mat(int** mat, int* row, int* col);
int** build_dinamic(int** b, int row, int col);
void neighborMaxMin(int* max, int* min, int** mat, int i, int j);
int** matrixMaxNeighbor(int** mat, int row, int col);
void free_dinamic(int** b, int row);
//Question 3
int createArrayAndList(int** arr, int row, int col, Three** return_arr, Node** return_list);
Three createThree(int number, int i, int j);
void createThreeList(Three item, Node** List);
Three* createThreeArr(Node* List, int n);
void PrintThree(Three item);
void PrintList(Node* List);
void PrintArr(Three* arr, int n);
void free_list(Node** List);

//question 4
void free_list4(Node4** List);
void print_list(Node4* list);
Node4* createList(Node4** list);
void Insert(Node4** new_list, int num);
int Delete(Node4** old_list);

//Question 5
Node4* createList2(Node4** list);
void Insert2(Node4** List, Node4* object);

//question 6
Node4** input_arr(int* n);
//void input_list(Node4** list);
Node4* input_list();
void removeDupList(Node4** list);
void removeDupArrayLists(Node4** arr_list, int n);
void print_list_char(Node4* list);


//Question 7 
Node4* disassemblyList(Node4* ListToBreak, Node4** small, Node4** Capital, Node4** numbs);


int main()
{
	int select = 0, i, all_Ex_in_loop = 0;
	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
	if (scanf("%d", &all_Ex_in_loop) == 1)
		do
		{
			for (i = 1; i <= 7; i++)
				printf("Ex%d--->%d\n", i, i);
			printf("EXIT-->0\n");
			do {
				select = 0;
				printf("please select 0-7 : ");
				scanf("%d", &select);
			} while ((select < 0) || (select > 7));
			switch (select)
			{
			case 1: Ex1(); break;
			case 2: Ex2(); break;
			case 3: Ex3(); break;
			case 4: Ex4(); break;
			case 5: Ex5(); break;
			case 6: Ex6(); break;
			case 7: Ex7(); break;
			}
		} while (all_Ex_in_loop && select);
		return 0;
}
/**************************************************************************************/
/* Function definitions */

//Question 1
int* powerArray(int n) {
	int* arr = (int*)calloc(n, sizeof(int));
	assert(arr);
	int i;
	for (i = 0; i < n; i++) {
		arr[i] = (int)(pow(2, (i % 32)));
	}
	return arr;
}

void Ex1() {
	int i, n;
	printf("Enter n:");
	scanf("%d", &n);
	int* arr = powerArray(n);
	for (i = 0; i < n; i++) {
		printf("arr[%d]=%d;\n", n, arr[i]);
	}
	free(arr);
}

/**************************************************************************************/
/* Question 2 */
void print_mat(int** mat, int row, int col)
{

	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" mat[%d][%d]=%d ", i, j, mat[i][j]);

		}
		printf("\n");
	}

}

int** input_mat(int** mat, int* row, int* col)
{
	printf("enter row and col\n");
	scanf("%d%d", row, col);
	mat = build_dinamic(mat, *row, *col);
	int i, j;
	for (i = 0; i < *row; i++)
	{
		for (j = 0; j < *col; j++)
		{
			printf("enter position [%d][%d]\n", i, j);
			scanf("%d", &mat[i][j]);
		}
	}
	return(mat);
}

void free_dinamic(int** b, int row)
{
	int i;
	for (i = 0; i < row; i++)
	{
		free(b[i]);
	}
	free(b);
}

int** build_dinamic(int** b, int row, int col)
{
	b = (int**)calloc(row, sizeof(int));
	assert(b);
	int i;
	for (i = 0; i < row; i++)
	{
		b[i] = (int*)calloc(col, sizeof(int));
		assert(b[i]);
	}
	return(b);
}


void neighborMaxMin(int* max, int* min, int** mat, int i, int j)
{
	int row = *max, col = *min;
	*max = INT_MIN;
	*min = INT_MAX;
	if (j + 1 < col)
	{
		if (mat[i][j + 1] > *max)
		{
			*max = mat[i][j + 1];
		}
		if (mat[i][j + 1] < *min)
		{
			*min = mat[i][j + 1];
		}
	}

	if (j - 1 >= 0)
	{
		if (mat[i][j - 1] > *max)
		{
			*max = mat[i][j - 1];
		}
		if (mat[i][j - 1] < *min)
		{
			*min = mat[i][j - 1];
		}
	}

	if (i + 1 < row)
	{
		if (mat[i + 1][j] > *max)
		{
			*max = mat[i + 1][j];
		}
		if (mat[i + 1][j] < *min)
		{
			*min = mat[i + 1][j];
		}
	}

	if (i - 1 >= 0)
	{
		if (mat[i - 1][j] > *max)
		{
			*max = mat[i - 1][j];
		}
		if (mat[i - 1][j] < *min)
		{
			*min = mat[i - 1][j];
		}
	}
}

int** matrixMaxNeighbor(int** mat, int row, int col)
{
	int i, j, min, max;
	int** b = NULL;
	b = build_dinamic(b, row, col);
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			max = row;
			min = col;
			neighborMaxMin(&max, &min, mat, i, j);
			b[i][j] = max;
		}
	}
	return(b);
}

void Ex2()
{
	int** mat = NULL;
	int row, col;
	mat = input_mat(mat, &row, &col);

	int** b = NULL;
	b = matrixMaxNeighbor(mat, row, col);

	print_mat(b, row, col);
	free_dinamic(mat, row);
	free_dinamic(b, row);
}

/**************************************************************************************/
//* Question 3 */
int createArrayAndList(int** arr, int row, int col, Three** return_arr, Node** return_list) {
	int i, j, min, max, counter = 0;
	Three newitem;
	Node* List = NULL;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			min = col;
			max = row;
			neighborMaxMin(&max, &min, arr, i, j);
			if (min >= arr[i][j]) {
				counter++;
				newitem = createThree(arr[i][j], i, j);
				createThreeList(newitem, &List);
			}
		}
	}
	*return_list = List;
	*return_arr = createThreeArr(List, counter);
	return counter;
}

Three createThree(int number, int i, int j) {
	Three Item;
	Item.value = number;
	Item.i = i;
	Item.j = j;
	return Item;
}

void createThreeList(Three item, Node** List) {
	Node* temp = *List;
	Node* newitem;
	if (temp == NULL) {
		temp = (Node*)calloc(1, sizeof(Node));
		temp->item = item;
		temp->link = NULL;
		*List = temp;
	}
	else {
		while (temp->link) {
			temp = temp->link;
		}
		newitem = (Node*)calloc(1, sizeof(Node));
		newitem->item = item;
		newitem->link = NULL;
		temp->link = newitem;
	}
}


Three* createThreeArr(Node* List, int n) {
	int i = 0;
	Node* temp = List;
	Three* arr = NULL;
	if (n != 0) {
		arr = (Three*)calloc(n, sizeof(Three));
		assert(arr);

		while (temp) {
			arr[i] = temp->item;
			i++;
			temp = temp->link;
		}
	}
	return arr;
}
void PrintThree(Three item) {
	printf("Number:%d, Row:%d, Col:%d\n", item.value, item.i, item.j);
}

void PrintList(Node* List) {
	Node* temp = List;
	while (temp) {
		PrintThree(temp->item);
		temp = temp->link;
	}
}

void PrintArr(Three* arr, int n) {
	int i;
	for (i = 0; i < n; i++) {
		PrintThree(arr[i]);
	}
}
void free_list(Node** List) {
	Node* temp = *List;
	Node* next;
	while (temp) {
		next = temp->link;
		free(temp);
		temp = next;
	}
	*List = NULL;
}

void Ex3() {
	int** mat = NULL;
	int row, col, n;
	Three* arr = NULL;
	Node* List = NULL;
	mat = input_mat(mat, &row, &col);
	n = createArrayAndList(mat, row, col, &arr, &List);
	printf("List:\n");
	PrintList(List);
	printf("\nArray:\n");
	PrintArr(arr, n);
	free_dinamic(mat, row);
	free_dinamic(arr, 0);
	free_list(&List);
}

/**************************************************************************************/
//Question 4
int Delete(Node4** old_list)
{
	int num;
	if ((*old_list)->link == NULL)//only one node
	{
		num = (*old_list)->num;
		free((*old_list));
	}
	else
	{
		Node4* previous = *old_list;
		Node4* temp = (previous->link);
		previous->link = temp->link;
		num = temp->num;
		free(temp);

	}
	return(num);
}

void Insert(Node4** new_list, int num)
{
	Node4* temp = *new_list;
	if (temp == NULL)
	{
		temp = (Node4*)calloc(1, sizeof(Node4));
		temp->link = NULL;
		temp->num = num;
		*new_list = temp;
	}
	else
	{
		while (temp->link)
		{
			temp = temp->link;
		}
		temp->link = (Node4*)calloc(1, sizeof(Node4));
		temp = temp->link;
		temp->num = num;
		temp->link = NULL;
	}
}

Node4* createList(Node4** list)
{
	Node4* temp = *list;
	Node4* new_list = NULL;
	Node4* previous = NULL;
	Node4* next = NULL;
	int previous_num;
	if (temp == NULL)//empty list
	{
		return(new_list);
	}
	else if (temp->link == NULL)//only one node
	{
		Insert(&new_list, Delete(&temp));

	}
	else
	{
		while (temp)
		{
			next = temp->link;
			if (previous == NULL)//first node
			{

				if (temp->num > next->num)//bigger
				{
					previous_num = temp->num;
					previous = temp;
					free(temp);
					Insert(&new_list, previous_num);
					temp = next;
				}
				else//smaller
				{
					previous_num = temp->num;
					previous = temp;
					temp = temp->link;
				}

			}
			else//not first node
			{
				if (temp->link == NULL)//last node
				{
					if (temp->num > previous_num)//bigger
					{
						Insert(&new_list, Delete(&previous));
						temp = next;
					}
				}
				else//in the middle
				{
					if (temp->num > next->num && temp->num > previous_num)//bigger than both sides
					{
						previous_num = temp->num;
						Insert(&new_list, Delete(&previous));
						previous = temp;
						temp = next;
					}
					else
					{
						previous_num = temp->num;
						previous = temp;
						temp = temp->link;
					}
				}

			}


		}
	}
	return(new_list);
}

void print_list(Node4* list)
{
	printf("\n");
	while (list)
	{
		printf(" %d \n", list->num);
		list = list->link;

	}
}

void free_list4(Node4** List)
{
	Node4* temp = *List;
	Node4* next;
	while (temp) {
		next = temp->link;
		free(temp);
		temp = next;
	}
	*List = NULL;
}


void Ex4()
{
	int num = 0;
	Node4* old_list = NULL;
	printf("\nenter number:");
	scanf("%d", &num);
	while (num != -1)
	{
		Insert(&old_list, num);
		printf("\nenter number:");
		scanf("%d", &num);
	}
	Node4* new_list = createList(&old_list);
	printf("new list:\n");
	print_list(new_list);
	printf("old list:\n");
	print_list(old_list);
	free_list4(&new_list);
	free_list4(&old_list);
}

/**************************************************************************************/
//Question 5
Node4* createList2(Node4** list)
{
	Node4* temp = *list;
	Node4* new_list = NULL;
	Node4* previous = NULL;
	Node4* next = NULL;
	int previous_num;
	if (temp == NULL) {//empty list
		return(new_list);
	}
	else if (temp->link == NULL){//only one node
		Insert2(&new_list, temp);
	}
	else{
		while (temp){
			next = temp->link;
			if (previous == NULL)//first node
			{

				if (temp->num > next->num)//bigger
				{
					previous_num = temp->num;
					previous = temp;
					Insert2(&new_list, temp);
					temp = next;
					*list = temp;//tony wants note, delete first node from old list.
				}
				else//smaller
				{
					previous_num = temp->num;
					previous = temp;
					temp = temp->link;
				}

			}
			else//not first node
			{
				if (temp->link == NULL)//last node
				{
					if (temp->num > previous_num)//bigger
					{
						Insert2(&new_list, temp);
						previous->link = NULL;
						temp = NULL;
					}
				}
				else//in the middle
				{
					if (temp->num > next->num && temp->num > previous_num)//bigger than both sides
					{
						previous_num = temp->num;
						Insert2(&new_list, temp);
						previous->link = next;
						temp = next;
					}
					else
					{
						previous_num = temp->num;
						previous = temp;
						temp = temp->link;
					}
				}

			}


		}
	}
	return(new_list);
}

void Insert2(Node4** List, Node4* object) {
	Node4* temp = *List;
	object->link = NULL;
	if (temp == NULL) {
		*List = object;
		(*List)->link = NULL;
	}
	else {
		while (temp->link != NULL) {
			temp = temp->link;
		}
		temp->link = object;
	}
	
	
}


void Ex5()
{
	int num = 0;
	Node4* old_list = NULL;
	printf("\nenter number:");
	scanf("%d", &num);
	while (num != -1)
	{
		Insert(&old_list, num);
		printf("\nenter number:");
		scanf("%d", &num);
	}
	Node4* new_list = createList2(&old_list);
	printf("new list:\n");
	print_list(new_list);
	printf("old list:\n");
	print_list(old_list);
	free_list4(&new_list);
	free_list4(&old_list);
}


/**************************************************************************************/
//question 6




void removeDupArrayLists(Node4** arr_list, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		removeDupList(&((arr_list)[i]));

	}

}
void removeDupList(Node4** list)
{
	int count_arr[26] = { 0 }, i;
	Node4* temp = *list;
	Node4* previous = NULL;
	if (temp != NULL)
	{
		while (temp)
		{
			count_arr[(temp->num) - 'a']++;
			if (count_arr[(temp->num) - 'a'] > 1)
			{
				i = Delete(&previous);
				temp = previous->link;
			}
			else
			{
				previous = temp;
				temp = temp->link;
			}


		}
	}
}

Node4* input_list()
{

	Node4* temp = NULL;
	char c;
	printf("Enter char:");
	rewind(stdin);
	c = getchar();
	while (c!='\n')
	{
		Insert(&temp, c);
		printf("Enter char:");
		rewind(stdin);
		c = getchar();
	}
	return(temp);
}

Node4** input_arr(int* n)
{
	int new_n, i;
	Node4** arr;
	printf("enter size:\n");
	scanf("%d", &new_n);
	arr = (Node4**)calloc(new_n, sizeof(Node4*));
	for (i = 0; i < new_n; i++)
	{
		arr[i] = NULL;
		printf("\nenterting list number %d\n", i + 1);
		arr[i] = input_list();
	}
	*n = new_n;
	return(arr);
}


void print_list_char(Node4* list)
{
	printf("\n");
	while (list)
	{
		printf(" %c \n", list->num);
		list = list->link;

	}
}

void Ex6()
{
	Node4** arr;
	int n;
	arr = input_arr(&n);
	removeDupArrayLists(arr, n);
	int i;
	for (i = 0; i < n; i++)
	{
		print_list_char(arr[i]);
		free_list4(&(arr[i]));
	}

}


/**************************************************************************************/
//Question 7


Node4* disassemblyList(Node4* ListToBreak, Node4** small, Node4** Capital, Node4** numbs) {
	Node4* temp = ListToBreak;
	Node4* speicalchar=NULL;
	if (temp == NULL)
		return NULL;
	Node4* next;
	while (temp) { 
		next = temp->link;
		if (temp->num >= 'a' && temp->num <= 'z') {
			
			Insert2(small, temp);
			
		}
		else if (temp->num >= 'A' && temp->num <= 'Z') {
			
			Insert2(Capital, temp);
			
		}
		else if (temp->num >= '0' && temp->num <= '9') {
			
			Insert2(numbs, temp);
			
		}
		else {

			Insert2(&speicalchar, temp);
			
		}

		
		temp = next;
	}

	return speicalchar;
}



void Ex7() {
	int i = 0;
	Node4* List1 = NULL,*List2 = NULL, *List3 = NULL, *List4 = NULL;
	List1=input_list();
	List1 =disassemblyList(List1, &List2, &List3, &List4);
	Node4** arr[4] = { List2,List3,List4,List1 };
	for (; i <= 3; i++)
	{
		printf("List%d:\n" , i);
		print_list_char(arr[i]);
		free_list4(&arr[i]);
	}
	
}