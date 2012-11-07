#include "Cube.h"

MyCube::MyCube()
{
}

MyCube::~MyCube()
{
}

void MyCube::draw(){


	Rectangle* rect = new Rectangle();
	rect->setDownLeftX(0);
	rect->setDownLeftY(0);
	rect->setUpRightX(1);
	rect->setUpRightY(1);
	glPushMatrix();
	glTranslatef(-0.5,-0.5,0.5);
	rect->draw();
	glRotatef(90,0,1,0);
	rect->draw();
	glRotatef(90,0,1,0);
	rect->draw();
	glRotatef(90,0,1,0);
	rect->draw();
	glRotatef(90,0,0,1);
	rect->draw();
	glRotatef(180,0,0,1);
	rect->draw();
	glPopMatrix();
}
