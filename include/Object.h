#ifndef OBJECT_H
#define OBJECT_H

#include "CGFobject.h"


class Object: public CGFobject{

private:
	double pos_x;
	double pos_y;
	double pos_z;

	bool animate;


public:
	Object();
	~Object();

	void setPos_x(double x);
	void setPos_y(double y);
	void setPos_z(double z);
	void setAnimated(bool anim);

	double getPos_x();
	double getPos_y();
	double getPos_z();
	bool getAnimated();

	void updateToPosition(double x, double y, double z);
	void updatePosition(double delta_x, double delta_y, double delta_z);
	void draw();

};



#endif