#include "Cellphone.h"
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;
Cellphone::Cellphone(string num){
	
	this->incomingcalls = new char[10]();
	this->outgoingcalls = new char[10]();
	this->Mynum = num;
}
//
Cellphone::~Cellphone(){
	delete[] incomingcalls;
	delete[] outgoingcalls;
}

Cellphone::Cellphone(const Cellphone & C1){
	for (int i = 0; i < 10; i++){
		this->incomingcalls[i] = C1.incomingcalls[i];
	}
	for (int i = 0; i < 10; i++) {
		this->outgoingcalls[i] = C1.outgoingcalls[i];
	}
}


void Cellphone::acceptCall(){
	int i = 0;
	long number = rand() % 479999999 + 520000000;
	while (this->incomingcalls[i] == 0) {
		i++;
		if (i == 10) {
			break;
		}
	}
	for (int j = 0; j <= 9 && i==10; j++) {
		this->incomingcalls[j] = this->incomingcalls[j + 1];
	}
	this->incomingcalls[i] = "0"+number;
}

void Cellphone::dialNumber(string number)
{
	
	int i = 0;
	while (this->outgoingcalls[i]==0){
		i++;
		if (i == 10)
			break;
	}
	for (int j = 0; j <= 9 && i == 10; j++) {
		this->incomingcalls[j] = this->incomingcalls[j + 1];
	}
	this->outgoingcalls[i] = number;
}

void Cellphone::showOutgoin()const{
	cout << "Printing Outgoingcalls:"<<endl;
	for (int i = 0; i < 10; i++){
		cout << this->outgoingcalls[i] << endl;
	}
	return;
}

void Cellphone::showIncoming()const{
	cout << "Printing Incoming:" << endl;
	for (int i = 0; i < 10; i++) {
		cout << this->incomingcalls[i] << endl;
	}
	return;
}

