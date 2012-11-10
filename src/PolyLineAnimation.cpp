
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

	/*
	double prev_vector_x = 0;
	double prev_vector_y = 0;
	double prev_vector_z = 0;
	int ind = current_animation_ind -1;

	while(prev_vector_x == 0 && ind >= 0){

		prev_vector_x = animSegments.at(ind)->getTotal_delta_x();
		ind--;
	}
	
	cout << "prev_vector_x = " << prev_vector_x << endl;
		cout << "prev_vector_y = " << prev_vector_y << endl;
		cout << "prev_vector_z = " << prev_vector_z << endl;
		cout << "ind = " << ind << endl;
		
	double prev_vector_x = animSegments.at(current_animation_ind -1)->getTotal_delta_x();
	double prev_vector_y = animSegments.at(current_animation_ind -1)->getTotal_delta_y();
	double prev_vector_z = animSegments.at(current_animation_ind -1)->getTotal_delta_z();
	
	prev_vector_x = 1;
	prev_vector_y = 0;
	prev_vector_z = 0;
	
	double current_vector_x = animSegments.at(current_animation_ind)->getTotal_delta_x();
	double current_vector_y = animSegments.at(current_animation_ind)->getTotal_delta_y();
	double current_vector_z = animSegments.at(current_animation_ind)->getTotal_delta_z();


	double scalar_product_XY = (prev_vector_x*current_vector_x) + (prev_vector_y*current_vector_y);
	double scalar_product_XZ = (prev_vector_x*current_vector_x) + (prev_vector_z*current_vector_z);

	double prev_normal_XY = sqrtl(powl(prev_vector_x,2.0) + powl(prev_vector_y,2.0));
	double prev_normal_XZ = sqrtl(powl(prev_vector_x,2.0) +	powl(prev_vector_z,2.0));
		
	double curr_normal_XY = sqrtl(powl(prev_vector_x,2.0) + powl(prev_vector_y,2.0));
	double curr_normal_XZ = sqrtl(powl(prev_vector_x,2.0) + powl(prev_vector_y,2.0));

	double cosAng_XY = scalar_product_XY/(prev_normal_XY * curr_normal_XY);
	double cosAng_XZ = scalar_product_XZ/(prev_normal_XZ * curr_normal_XZ);


	double ang_XY = 0; //NOT BEING USED RIGHT NOW,
	double ang_XZ;

	/*if(current_vector_y == 0){
		ang_XY = 0;
	}else{
		ang_XY = acosl(cosAng_XY) * 180/PI;
	}

	if(current_vector_z == 0){
		ang_XZ = 0;
	}else{
		ang_XZ = acosl(cosAng_XZ) * 180/PI;
	}

	animSegments.at(current_animation_ind)->getAnimatedObject()->setRotationAngleOnZZaxis(ang_XY);
	animSegments.at(current_animation_ind)->getAnimatedObject()->setRotationAngleOnYYaxis(ang_XZ);
	//cout << "ang_XY = " << ang_XY << endl;
	cout << "cosAng_XZ = " << cosAng_XZ << endl;
	cout << "ang_XZ = " << ang_XZ << endl;
	cin.get();*/


	double delta_x = animSegments.at(current_animation_ind)->getTotal_delta_x();
	double delta_z = animSegments.at(current_animation_ind)->getTotal_delta_z();

	double ang = atan2l(delta_x, delta_z) *180/PI;

	cout << "delta_x = " << delta_x << endl;
	cout << "delta_z = " << delta_z << endl;

	cout << "ang_xz = " << ang << endl;
	animSegments.at(current_animation_ind)->getAnimatedObject()->setRotationAngleOnYYaxis(ang);
	cout << "obj ang = " << animSegments.at(current_animation_ind)->getAnimatedObject()->getAng_XZ();
	cin.get();
}


void PolyLineAnimation::animate(){

	
	if(current_animation_ind < animSegments.size()){
		animSegments.at(current_animation_ind)->animate();
	}else{
		animSegments.at(animSegments.size() -1)->animate();
	}

}
