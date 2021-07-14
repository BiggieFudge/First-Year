#include "Cellcam.h"
#include <string>
Cellcam::Cellcam(string num) : Cellnocam(num){
	this->Photos = new int[10]();
}

Cellcam::~Cellcam()
{
	delete[] Photos;
}

void Cellcam::Capture(int photo){
	int i = 0;
	for(i = 0; i < 10; i++){
		if (this->Photos[i] == 0) {
			this->Photos[i] == photo;
		}
	}
	if (i == 11) {
		int num;
		cout << "Pictures FULL"<< endl;
		cout << "Which picture whould you like to remove" << endl;
		cin >> num;
		this->Photos[num] = photo;
	}
}

void Cellcam::ShowPicture(int PictureToShow) const{
	cout << this->Photos[PictureToShow] << endl;
}
