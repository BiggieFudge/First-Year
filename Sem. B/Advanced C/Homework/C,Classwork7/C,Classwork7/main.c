#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <string.h>


typedef struct {
	char c;
	struct Node *link;
}Node;

void push(Node** node, char x) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->c = x;
	Node* temp = *node;
	while (temp != NULL) {
		Node* next = (*node)->link;
		
		if ((temp)->c > x) {
			new_node->link = temp;
			temp = new_node;
			*node = temp;
			return;

		}
		if (((temp)->c <= x) && ((temp)->link == NULL || next->c > x ))
			break;
		else
			(temp) = (temp)->link;

		
	}

	if (temp == NULL) {
		new_node->link = NULL;
		temp = new_node;
	}
	else {
		new_node->link = temp->link;
		temp->link = new_node;
	}
	
	*node = temp;
}

Node* Build_New_List() {
	Node* node = NULL;
	int n;
	printf("Enter How many chars you want to enter:\n");
	scanf_s(" %d", &n);
	char c;
	for (int i = 0; i < n; i++)
	{
		printf("Enter char:");
		scanf_s(" %c", &c);
		push(&node, c);
	}
	return node;
}
void Reverse_node(Node** node) {
	Node* temp = (*node);
	Node* next;
	Node* pre = NULL;
	
	while (temp != NULL) {
		next = temp->link;
		temp->link = pre;
		pre = temp;
		temp = next;

		
		
	}
	*node = pre;
}

void Delete_Node(Node** node) {
	Node* temp;
	Node* curr = (*node);
	while (curr != NULL) {
		temp = curr->link;
		free(curr);
		curr = temp;
	}
	*node = NULL;


}

void main() {
	
	Node* node=Build_New_List();
	
	Reverse_node(&node);
	Delete_Node(&node);
	return;
}