using namespace std;
#include <iostream>
#include <string>
#include "Node.h"
#include "Queue.h"

Node CreateNode() {
	string name;
	double balance;
	cout << "Enter Name:";
	cin >> name;
	cout << "Enter Balance:";
	cin >> balance;
	Node NewAccount;
	NewAccount.setName(name);
	NewAccount.setAccount(balance);
	return NewAccount;

}


void main() {
	Queue Que1;
	int input;
	cout << "(1)-Reset Node\n(2)-Add Node\n(3)-get Node\n(4)-Top Node\n(5)-Is Empty?\n(6)-Print Node\nEnter Input:";
	cin >> input;
	while (input >= 1 && input <= 6) {
		int x = Que1.isEmpty();
		switch (input){
		
		case(1):
			Que1.resetQueue();
			break;
		case(2):
			Que1.addNode(CreateNode());
			break;
		case(3):
			if (x == 1)
				printCustomer(Que1.getNode());
			else
				cout << "Enter Queue first"<< endl;
			break;
		case(4):
			if (x == 1)
				printCustomer(Que1.topNode());
			else
				cout << "Enter Queue first"<< endl;
			break;
		case(5):
			if (x == 0)
				cout << "Empty!" << endl;
			else
				cout << "Not Empty!" << endl;
			break;
		case(6):
			printCustomer(Que1);
			break;
			
		}

	
		cout << "(1)-Reset Node\n(2)-Add Node\n(3)-get Node\n(4)-Top Node\n(5)-Is Empty?\n(6)-Print Node\nEnter Input:";
		cin >> input;
	}
	return;
}
