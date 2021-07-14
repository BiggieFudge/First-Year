#pragma once

#include "Node.h"
#include <iostream>
#include <string>
using namespace std;

class Queue
{
	friend void printCustomer(Queue &Que1);
private:
	int startindex;
	int endindex;
	Node* bank;

public:
	Queue();
	void resetQueue();
	void addNode(Node n1);
	Node& getNode();
	Node& topNode();
	int isFull();
	int isEmpty();
};

