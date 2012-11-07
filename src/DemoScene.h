#ifndef DEMOSCENE_H
#define DEMOSCENE_H

#include "CGFscene.h"
#include "CGFshader.h"


#include "LineAnimation.h"

class DemoScene : public CGFscene
{
public:
	void init();
	void display();
	void update(long t);
	~DemoScene();
private:
	CGFlight* light0;

	CGFappearance* materialAppearance;
	CGFappearance* textureAppearance;
	CGFshader* shader;

	Object* obj;
	vector<CGFobject*> sceneObjects;
	vector<LineAnimation*> sceneAnimations;
};

#endif