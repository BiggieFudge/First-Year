#include <iostream>
#include "CellNocam.h"
#include "Cellphone.h"
#include "Cellcam.h"
using namespace std;
void main() {
	Cellcam c1("0526219020");
	c1.printTime();
	c1.dialNumber("088540464");
	c1.saveContact("Eytan", "0526219020");
	c1.setTime();
	c1.acceptCall();

	return;
}