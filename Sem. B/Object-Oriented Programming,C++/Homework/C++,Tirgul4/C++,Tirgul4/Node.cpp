#include <iostream>
#include "Node.h"
#include <string.h>
using namespace std;
int Node::idGenerator = 1;

Node::Node() {
	this->account = idGenerator;
	idGenerator++;
	this->balance = 0;
}
void Node::setAccount(double balance) {
	this->balance = balance;
}
void Node::setName(string name) {
	this->name = name;
}
double Node::getAccount() {
	return balance;
}
string Node::getName() {
	return this->name;
}
void printCustomer(const Node & n1) {
	cout << "Custumer name:" << n1.name << ".Status: " << n1.balance<<"."<<endl;
}
