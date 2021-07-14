#include "Figure2D.h"

Figure2D::Figure2D(double l, double h, double x, double y){
	this->length = l;
	this->heigth = h;
	this->x = x;
	this->y = y;
}

Figure2D::Figure2D(const Figure2D & f){
	*this = f;
}

Figure2D::Figure2D(){
	this->x = 0; this->y = 0; this->length = 0; this->heigth = 0;
}

Figure2D::~Figure2D(){
	delete[] this->name;
}

Figure2D & Figure2D::operator=(const Figure2D & d){
	this->x = d.x;
	this->y = d.y;
	this->length = d.length;
	this->heigth = d.heigth;
	this->setName(d.getName());

	return *this;
}

void Figure2D::setName(const char * name){
	//strcpy(this->name, name);
	int i = 0;
	int len = 0;
	const char* copy = name;
	for (; *copy; copy++, len++);
	this->name = new char[len + 1]();
	for (i = 0; i <= len; i++){
		this->name[i] = name[i];
	}
	return; 
	
	
}

double Figure2D::getX()const {
	return this->x;
}

double Figure2D::getY() const {
	return this->y;
}

double Figure2D::getLength() const {
	return this->length;
}

double Figure2D::getHeigth() const {
	return this->heigth;
}

const char * Figure2D::getName() const
{
	return this->name;
}

void Figure2D::Shift(double dx, double dy){

}

void Figure2D::MoveTo(double newX, double newY){
	this->x = newX;
	this->y = newY;
}

ostream & operator<<(ostream & o, Figure2D & d)
{
	// TODO: insert return statement here
	o << " " << d.getName() << " with center (" << d.getX()+ (d.getLength()/2) 
	<< ", " << d.getY() + (d.getLength() / 2) << ") and side = " << d.getLength() << endl;
	return o;
}
