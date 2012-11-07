#ifndef LINEANIMATION_H
#define LINEANIMATION_H

#include "Object.h"

#include <vector>
#include <iostream>
#include <map>


using namespace std;

#define NUM_COORD 3
#define X 0
#define Y 1
#define Z 2

typedef pair<vector<double>*,vector<double>*> ctrlPointsPair;

class LineAnimation
{
private:

	double delta_x;
	double delta_y;
	double delta_z;

	Object* animatedObject;

	unsigned int mili_secs;
	double total_animation_time;

	ctrlPointsPair* controlPoints;

	//static map<Object*,vector<double>*> allAnimatedObjects;


public:
	LineAnimation();
	~LineAnimation();

	void setDelta_x(double dx);
	void setDelta_y(double dy);
	void setDelta_z(double dz);
	void setMiliSecs(unsigned int mSecs);
	void setTotalAnimationTime(double s);
	void setAnimatedObject(Object* obj);
	void setControlPoints(ctrlPointsPair* cps);

	double getDelta_x() const;
	double getDelta_y() const;
	double getDelta_z() const;

	unsigned int getMiliSecs() const;
	double getTotalAnimationTime() const;

	Object* getAnimatedObject() const;
	ctrlPointsPair* getControlPoints() const;

	void init();
	void animate();
	
	static void updateObjectPosition(int dummy); //value parametre of glutTimerFunc(int msecs, void (*func) (int value), value)

};


static vector<LineAnimation*> allLineAnimations;


#endif