#include "CellNocam.h"
#include <string>

Cellnocam::Cellnocam(string num) :Cellphone(num){
	this->phonenumbers = new string[10]();
	this->Contactnames = new string[10]();

}
Cellnocam::~Cellnocam() {
	delete[] phonenumbers;
	delete[] Contactnames;
}

void Cellnocam::saveContact(string name, string phonenumber){
	int i = 0;
	if (IsFull == false) {
		for (i=0; i < 10; i++){
			if (this->Contactnames[i].compare(NULL) == 0) {

			}
		}
		if (i == 10) {
			this->IsFull = true;
			cout << "Pls remove a contact first"<<endl;
		}
		this->phonenumbers[i] = phonenumber;
		this->Contactnames[i] = name;
	}
	else {
		int IndexToRemove;
		cout << "Enter Conact to remove:" << endl;
		cin >> IndexToRemove;
		this->Contactnames[IndexToRemove] = name;
		this->phonenumbers[IndexToRemove] = phonenumber;
	}
}

void Cellnocam::DeleteContact(int number){
	this->IsFull = false;
	this->Contactnames[number] = "";
	this->phonenumbers[number] = "";
}

time_t Cellnocam::printTime(){
	cout << Timer;
}

void Cellnocam::setTime(){
	int H, M;
	cout << "Enter HH:MM" << endl;
	cin >> H >> M;
	cout << endl << "Time Set Is:" << H << M;
}
