
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <string.h>
//void swap(void** Arr, void** Brr) {
//	void* temp = *Arr;
//	*Arr = *Brr;
//	*Brr = temp;
//
//}
//
//void* Question(void** A, int* size,int n) {
//
//	int i = 0;
//
//	while (i < n / 2) {
//
//		void** temp = A[i];
//		A[i] = A[n - i - 1];
//		A[n - i - 1] = temp;
//		int* itemp = size[i];
//		size[i] = size[n - i - 1];
//		size[n - i - 1] = itemp;
//		i++;
//	}
//	
//}
//
//
//typedef struct item
//{
//	int data;
//	struct item* next;
//} Item;
//
//Item* Q3(Item* L);
//void main()
//{
//
//}
//
//Item* Q3(Item* L)
//{
//	int i;
//	Item* temp, *temp2;
//	temp = L;
//
//	if (L == NULL)
//	{
//		return NULL;
//	}
//
//	while (temp->next->data > temp->data)
//	{
//		temp = temp->next;
//	}
//
//	temp2 = temp->next; // head
//	temp->next = NULL;
//	return temp2;
//}

#define SIZEOF -
 typedef struct item
{
	int data;
	struct item* next;
} Item;

void insertafter(Item* L, int data)
{
	Item* temp;
	Item* newitem;
	 temp = L;
	newitem = (Item*)malloc(sizeof(Item));
	newitem->next = NULL;
	if (L == NULL)
	{
		L = newitem;
	}
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;		
		}
		temp = newitem;
	}
}



void main() {

	/*int** A = (int**)calloc(4,sizeof(int*));
	
	int size [4]= {4,5,2,3};
	int A1[] = { 5,12,6,9 };
	int A2[] = { 0,3,1 ,29, 101};
	int A3[] = { 13,14 };
	int A4[] = { 2, 20 ,4 };

	A[0] = A1;
	A[1] = A2;
	A[2] = A3;
	A[3] = A4;

	Question(A, size, 4);*/
	

	
	printf("%d", (int)sizeof EOF);
	

	//printf("%d", EOF SIZEOF(int)sizeof EOF);
	

}