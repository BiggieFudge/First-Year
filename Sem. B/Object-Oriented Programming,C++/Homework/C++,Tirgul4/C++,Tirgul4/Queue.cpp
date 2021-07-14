
#include "Queue.h"
#include <iostream>
#include <string>
using namespace std;

Queue::Queue() {
	startindex = 0;
	endindex = 0;
	bank = new Node[5];
}


void Queue::resetQueue() {
	this->startindex = 0;
	this->endindex = 0;
}

void Queue::addNode(Node n1) {
	
	if (isFull()==0) {
		bank[endindex] = n1;
		this->endindex++;	
	}
	else
		cout << "Queue is full";
}
Node& Queue::getNode() {
	if (isEmpty()==1) {
		this->startindex++;
		return bank[startindex-1];
		
	}
	else
		cout << "Queue is empty";
}
Node& Queue::topNode() {
	if (isEmpty()==1) {
		return bank[startindex];
	}
	else
		cout << "Queue is empty";
}

int Queue::isEmpty() {
	if (startindex!=endindex)
		return 1;
	else
		return 0;
}
int Queue::isFull() {
	if (startindex == 0 && endindex == 5)
		return 1;
	else
		return 0;
}

void printCustomer(Queue &Que1) {
	
	while (Que1.isEmpty() ==1)
	{
		printCustomer(Que1.getNode());
		
	}
	
}