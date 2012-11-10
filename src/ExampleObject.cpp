#include "ExampleObject.h"

void ExampleObject::draw() 
{
	/*double orientation[NUM_COORD] = {0,0,1};
	double up[NUM_COORD] = {0,1,0};
	setOrientationVector(orientation);
	setUpVector(up);*/

	glutSolidTeapot(1);
}