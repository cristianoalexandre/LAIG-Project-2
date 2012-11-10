#ifndef POLYLINEANIMATION_H
#define POLYLINEANIMATION_H

#define PI 3.14159265

#include "LineAnimation.h"
#include "Animation.h"
#include <math.h>


class PolyLineAnimation: public Animation{

private:

	int total_time;
	double total_distance;

	int current_animation_ind;

	vector<LineAnimation*> animSegments;
	Object* obj;

public:

	PolyLineAnimation();
	~PolyLineAnimation();

	PolyLineAnimation(Object* obj, double tot_time);

	int getTotalTime();
	double getTotalDistance();
	Object* getAnimatedObject();

	
	void setTotalTime(int totalTime);
	void setTotalDistance(double dist);
	void setAnimatedObject(Object* obj);
	void initValues(Object* obj, vector<vector<double>*>* controlPoints, double totalTime);

	void init();
	int updateObjectPosition();
	void rotateObject();
	void animate();

};


#endif