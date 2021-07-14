#pragma once
using namespace std;
#include <iostream>
#include <string>
class Node
{
	friend void printCustomer(const Node &);


private:
	string name;
	double balance;
	int account;
	
	static int idGenerator;

public:
	 
	Node();
	void setName(string );
	void setAccount(double);
	double getAccount();

	string getName();

};

