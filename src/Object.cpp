#include "Object.h"



Object::Object(){

	setPos_x(0.0);
	setPos_y(0.0);
	setPos_z(0.0);
	setAnimated(false);
}

Object::~Object(){
}

void Object::setPos_x(double x){

	this->pos_x = x;
}

void Object::setPos_y(double y){

	this->pos_y = y;
}

void Object::setPos_z(double z){

	this->pos_z = z;
}

void Object::setAnimated(bool anim){

	this->animate = anim;
}


double Object::getPos_x(){

	return this->pos_x;
}

double Object::getPos_y(){

	return this->pos_y;
}

double Object::getPos_z(){

	return this->pos_z;
}

bool Object::getAnimated(){

	return this->animate;
}

void Object::updateToPosition(double x, double y, double z){

	setPos_x(x);
	setPos_y(y);
	setPos_z(z);
}

void Object::updatePosition(double delta_x, double delta_y, double delta_z){

	setPos_x(this->pos_x + delta_x);
	setPos_y(this->pos_y + delta_y);
	setPos_z(this->pos_z + delta_z);
}


void Object::draw(){

}