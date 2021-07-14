#pragma once
#include "CellNocam.h"
#include <string>
class Cellcam:public Cellnocam
{
public:
	Cellcam(string);
	~Cellcam();

	void Capture(int);
	void ShowPicture(int) const;

private:
	int* Photos;
};

