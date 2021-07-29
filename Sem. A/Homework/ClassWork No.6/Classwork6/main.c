#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <string.h>

typedef struct {
	int x;
	struct Node *link;
}Node;

void push(Node** node, int x) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->x = x;
	(*node)->link = new_node;
	new_node->link = NULL;
}

int InputNode(Node** Even, Node**  Odd) {
	Node* Even_num = NULL;
	Node* Odd_num = NULL;
	int input, count = 0;
	printf("Enter Num:");
	scanf_s("%d", &input);
	while (input != -1) {
		count++;
		if (input % 2 == 0) {
			push(&Even_num, input);
		}
		else {
			push(&Odd_num, input);
		}

		printf("Enter Num:");
		scanf_s("%d", &input);
	}
	(*Even) = Even_num;
	(*Odd) = Odd_num;
	return count;
}
void print_node(Node* node) {
	int i = 0;
	while (node != NULL) {
		printf("Node no.%d, x=%d\n", i, node->x);
		node = node->link;
		i++;
	}
}

void delete_node(Node** node) {
	Node* current = *node;
	Node* next;

	while (current != NULL) {
		next = current->link;
		free(current);
		current = next;
	}
	*node = NULL;
}

int CheckList(Node* node, int* pmin, int* pmax) {
	int sum = 0, min = node->x, max = 0;

	while (node != NULL) {
		sum += node->x;
		if (node->x > max)
			max = node->x;
		else if (node->x < min)
			min = node->x;
		node = node->link;
	}
	*pmin = min;
	*pmax = max;
	return sum;
}

void main() {

	//                                  Question 1+2
	Node* Even, *Odd;

	int fun = InputNode(&Even, &Odd);
	printf("Function Returend:%d\n", fun);
	printf("Printing Even nums:\n");
	print_node(Even);
	printf("Printing Odd nums:\n");
	print_node(Odd);
	int min, max;
	int sum = CheckList(Even, &min, &max);
	printf("Even_Checklist:%d . Min:%d . Max=%d\n", sum, min, max);
	sum = CheckList(Odd, &min, &max);
	printf("Odd_Checklist:%d . Min:%d . Max=%d", sum, min, max);
	delete_node(&Even);
	delete_node(&Odd);



	return;
}