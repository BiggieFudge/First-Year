#pragma once
#include "Cellphone.h"
#include "Cellnocam.h"
#include <array>
#include <string>
#include <time.h>  
using namespace std;
#include <iostream>
class Cellnocam :public Cellphone
{
public:
	Cellnocam(string);
	~Cellnocam();
	void saveContact(string,string);
	void DeleteContact(int number);
	time_t printTime();
	void setTime();
private:
	bool IsFull;
	string* Contactnames;
	string* phonenumbers;
	time_t Timer = time(NULL);
};

