#include "LineAnimation.h"




LineAnimation::LineAnimation(){
	
	setDelta_x(0.0);
	setDelta_y(0.0);
	setDelta_z(0.0);
	setAnimatedObject(NULL);
	setTotalAnimationTime(1.0);
	this->mili_secs = 0;
}

LineAnimation::~LineAnimation(){
}

void LineAnimation::setDelta_x(double x){

	this->delta_x = x;
}

void LineAnimation::setDelta_y(double y){

	this->delta_y = y;
}

void LineAnimation::setDelta_z(double z){

	this->delta_z = z;
}

void LineAnimation::setMiliSecs(unsigned int mSecs){
	this->mili_secs = mSecs;
}

void LineAnimation::setTotalAnimationTime(double s){

	this->total_animation_time = s;
}

void LineAnimation::setAnimatedObject(Object* obj){

	this->animatedObject = obj;
}

void LineAnimation::setControlPoints(ctrlPointsPair* cps){

	this->controlPoints = cps;
}

double LineAnimation::getDelta_x() const{

	return this->delta_x;
}

double LineAnimation::getDelta_y() const{

	return this->delta_y;
}

double LineAnimation::getDelta_z() const{

	return this->delta_z;
}

unsigned int LineAnimation::getMiliSecs() const{

	return this->mili_secs;
}

double LineAnimation::getTotalAnimationTime() const{

	return this->total_animation_time;
}

Object* LineAnimation::getAnimatedObject() const{

	return this->animatedObject;
}

ctrlPointsPair* LineAnimation::getControlPoints() const{

	return this->controlPoints;
}


void LineAnimation::init(){

	//INIT DELTAS BY CALCULATING TOTAL TRANSLATION FROM CTRLPOINTS

	double total_delta_x = 0;
	double total_delta_y = 0;
	double total_delta_z = 0;

	total_delta_x = controlPoints->second->at(X) - controlPoints->first->at(X);
	total_delta_y = controlPoints->second->at(Y) - controlPoints->first->at(Y);
	total_delta_z = controlPoints->second->at(Z) - controlPoints->first->at(Z);


	delta_x = (mili_secs/(total_animation_time*1000)) * total_delta_x;
	delta_y = (mili_secs/(total_animation_time*1000)) * total_delta_y;
	delta_z = (mili_secs/(total_animation_time*1000)) * total_delta_z;

	void (*func)(int);
	func = updateObjectPosition;
	
	/*vector<double>* deltas;
	deltas->push_back(delta_x);
	deltas->push_back(delta_y);
	deltas->push_back(delta_z);


	allAnimatedObjects.insert(this->getAnimatedObject(), deltas);*/

	allLineAnimations.push_back(this);
	int id = allLineAnimations.size() -1;

	glutTimerFunc(mili_secs, func, 0);
}


void LineAnimation::updateObjectPosition(int dummy){

	
	/*animatedObject->updatePosition(this->delta_x, this->delta_y, this->delta_z);

	cout << "Tou no update" << endl;

	cout << "Obj_x = " << animatedObject->getPos_x() << endl;
	cout << "Obj_y = " << animatedObject->getPos_y() << endl;
	cout << "Obj_z = " << animatedObject->getPos_z() << endl;*/

}

void LineAnimation::animate(){

}


