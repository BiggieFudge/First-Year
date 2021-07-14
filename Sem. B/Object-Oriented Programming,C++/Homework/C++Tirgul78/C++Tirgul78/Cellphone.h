#pragma once
#include <string>

class Cellphone{

public:
	Cellphone(string);
	~Cellphone();
	Cellphone(const Cellphone &);
	void acceptCall();
	void dialNumber(string);
	void showOutgoin()const;
	void showIncoming()const;



private:
	string Mynum;
	char* outgoingcalls;
	char* incomingcalls;

};







