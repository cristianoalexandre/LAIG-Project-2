
#include "PolyLineAnimation.h"


PolyLineAnimation::PolyLineAnimation(){
	setAnimatedObject(NULL);
	setTotalTime(0);
	setTotalDistance(0);
}

PolyLineAnimation::PolyLineAnimation(Object* obj, double tot_time){

	setAnimatedObject(obj);
	setTotalTime(tot_time);
}

PolyLineAnimation::~PolyLineAnimation(){

}

int PolyLineAnimation::getTotalTime(){

	return this->total_time;
}

double PolyLineAnimation::getTotalDistance(){

	return this->total_distance;
}

Object* PolyLineAnimation::getAnimatedObject(){

	return this->obj;
}

void PolyLineAnimation::setTotalTime(int totalTime){

	this->total_time = totalTime;
}

void PolyLineAnimation::setTotalDistance(double dist){

	this->total_distance = dist;
}

void PolyLineAnimation::setAnimatedObject(Object* ob){

	this->obj = ob;
}

void PolyLineAnimation::initValues(Object* obj, vector<vector<double>*>* controlPoints, double totalTime){
	
	setAnimatedObject(obj);
	setTotalTime(totalTime);

	for(unsigned int i = 0; i < controlPoints->size() -1; i++){

		LineAnimation* anim = new LineAnimation();

		ctrlPointsPair* p = new ctrlPointsPair(controlPoints->at(i), controlPoints->at(i+1));
		anim->setControlPoints(p);

		this->animSegments.push_back(anim);
	}

	init();
}


void PolyLineAnimation::init(){

	for(unsigned int i = 0; i < animSegments.size(); i++){

		animSegments.at(i)->setAnimatedObject(this->obj);
		animSegments.at(i)->initValues();

		total_distance += animSegments.at(i)->getTotalAnimationDistance();
	}
	for(unsigned int i = 0; i < animSegments.size(); i++){

		animSegments.at(i)->setTotalAnimationTime((animSegments.at(i)->getTotalAnimationDistance() * total_time)/total_distance);
		animSegments.at(i)->init();
	}
	this->current_animation_ind = 0;
}

int PolyLineAnimation::updateObjectPosition(){

	if(current_animation_ind >= animSegments.size()){
		return 1;
	}else{

		if(animSegments.at(current_animation_ind)->updateObjectPosition() == 1){
			current_animation_ind++;

			if(current_animation_ind >= animSegments.size()){
				//TODO reset();
			}else{
				this->animSegments.at(current_animation_ind)->init();
				cout << "attempting rotation" << endl;
				rotateObject();
				cout << "rotation complete" << endl;
			}
			
		}	
		if(current_animation_ind == 0 && obj->getAng_XZ() == 0){
			rotateObject();
		}
	}

	return 0;
}


void PolyLineAnimation::rotateObject(){

	int octant;
	if(obj->getPos_x() >= 0){
		if(obj->getPos_z() >= 0){
			if(obj->getPos_y() >= 0){
				octant =1;
			}else{
				octant =5;
			}
		}else{
			if(obj->getPos_y() >= 0){
				octant =2;
			}else{
				octant =6;
			}
		}
	}else{
		if(obj->getPos_z() >= 0){
			if(obj->getPos_y() >= 0){
				octant =4;
			}else{
				octant =8;
			}
		}else{
			if(obj->getPos_y() >= 0){
				octant =3;
			}else{
				octant =7;
			}
		}
	}

	int orientation_x;
	int orientation_z;

	if(animSegments.at(current_animation_ind)->getObj_ini_postion_z() < animSegments.at(current_animation_ind)->getObj_end_postion_z()){
		orientation_z = 1;
	}else{
		orientation_z = -1;
	}
	if(animSegments.at(current_animation_ind)->getObj_ini_postion_x() < animSegments.at(current_animation_ind)->getObj_end_postion_x()){
		orientation_x = 1;
	}else{
		orientation_x = -1;
	}

	double delta_x = fabs(animSegments.at(current_animation_ind)->getTotal_delta_x());
	double delta_z = fabs(animSegments.at(current_animation_ind)->getTotal_delta_z());

	double ang = atan2l(delta_z, delta_x) *180/PI;
	/*cout << "delta_x = " << delta_x << endl;
	cout << "delta_z = " << delta_z << endl;

	cout << "ang_xz = " << ang << endl;
	*/
	if(delta_x != 0 || delta_z != 0){//IF BOTH ARE 0, ANGLE DOES NOT CHANGE AS THERE IS ONLY MOVEMENT IN THE YY AXIS DIRECTION

		if(orientation_x < 0 && orientation_z < 0){//angle is calculated from the positive xx axis towards the object's path in the first quadrant
			ang += 180;							   //these calculations correct the angle in case the object moves to or is in other quadrants
		}else{
			if(orientation_x < 0){
				ang = ang + (180 - (2*ang));
			}
			if (orientation_z < 0){
				ang = ang * -1;
			}
		}

		if(delta_x == 0){//IF ONLY DELTA_X IS 0, THEN ANGLE IS EITHER 90 OR -90 DEPENDING ON DIRECTION OF MOVEMENT
			if(animSegments.at(current_animation_ind)->getObj_ini_postion_z() < animSegments.at(current_animation_ind)->getObj_end_postion_z()){
				ang = 90;
			}else{
				ang = -90;
			}		
		}else{
			if(delta_z == 0){// IF ONLY DELTA_Z IS 0, THEN ANGLE IS EITHER 0 OR 180 DEPENDING ON DIRECTION OF MOVEMENT
				if(animSegments.at(current_animation_ind)->getObj_ini_postion_x() < animSegments.at(current_animation_ind)->getObj_end_postion_x()){
					ang = 0;
				}else{
					ang = 180;
				}
			}
		}
		animSegments.at(current_animation_ind)->getAnimatedObject()->setRotationAngleOnYYaxis(ang);	
	}
	//cout << "obj ang = " << animSegments.at(current_animation_ind)->getAnimatedObject()->getAng_XZ();
	//cin.get();
}


void PolyLineAnimation::animate(){

	
	if(current_animation_ind < animSegments.size()){
		animSegments.at(current_animation_ind)->animate();
	}else{
		animSegments.at(animSegments.size() -1)->animate();
	}

}
