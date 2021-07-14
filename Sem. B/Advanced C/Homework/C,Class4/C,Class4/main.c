#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <string.h>

typedef struct {
	char address[30];
	int rooms;
	double price;
} apart;

typedef struct {
	apart A;
	struct node *link;
}node;

node* CheckApart(node* Apart_Units, int RoomReq, int MaxPrice,int* ptr) {
	int i = 0,count = 0;
	node* Apart_For_Customer = (node*) malloc (sizeof(node));
	node* temp = Apart_For_Customer;
	do {
		if (Apart_Units->A.price <= MaxPrice && Apart_Units->A.rooms == RoomReq) {
			
				temp->A = Apart_Units->A;
				temp->link = (node*)malloc(sizeof(node));
				temp = temp->link;
				count++;
			}	
		Apart_Units = Apart_Units->link;
		} while (Apart_Units->link != NULL);
	temp->link = NULL;
	*ptr = count;

	return Apart_For_Customer;
}

node* EnterList(int num) {
	node* Apart_Units = (node*)malloc(sizeof(node));
	node* temp = Apart_Units;
	double rooms;
	int price;
	char address[30];
	apart a1;
	for (int i = 0; i < num; i++){
		printf("Enter Appartmnet No.%d \nEnter price:" , i+1);
		scanf_s("%d", &price);
		printf("Enter rooms:");
		scanf_s("%lf", &rooms);
		printf("Enter Address:");
		scanf_s(" %[^\n]s", address, sizeof(address) - 1);
		
		strcpy_s(a1.address, 30,address);
		a1.rooms = rooms;
		a1.price = price;	
		
		temp->A = a1;
		temp->link = (node*)malloc(sizeof(node));
		temp= temp->link;
		
		}

	temp->link = NULL;
	return Apart_Units;
}

void printnode(node* Apart_For_Customer,int n) {
	printf("We Found %d apartments suited for you:", n);
	int i = 1;
	do {
		printf("\nDira Mispar:%d ,  Rooms:%d   ,    Price:%lf, Address:", i++ ,Apart_For_Customer->A.rooms, Apart_For_Customer->A.price);
		puts(Apart_For_Customer->A.address);
		Apart_For_Customer = Apart_For_Customer->link;

	} while (Apart_For_Customer->link != NULL);
}

void main() {
	int num;
	printf("Enter List length:");
	scanf_s("%d", &num);
	node* Apart_Units = EnterList(num);
	int ptr =0;
	node* Apart_For_Customer = CheckApart(Apart_Units, 5, 25, &ptr);
	printnode(Apart_For_Customer, ptr);
	return;
}