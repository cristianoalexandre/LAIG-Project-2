#ifndef DEMOSCENE_H
#define DEMOSCENE_H

#include "CGFscene.h"
#include "CGFshader.h"

#include "CGFaxis.h"
#include "CGFapplication.h"

#include "ExampleObject.h"

#include <math.h>
#include <vector>

#include "CGFappearance.h"
#include "Cylinder.h"
#include "Triangle.h"
#include "Sphere.h"

#include "LineAnimation.h"
#include "PolyLineAnimation.h"

static vector<LineAnimation*> allLineAnimations;
static vector<PolyLineAnimation*> allPolyAnimations;


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
	Object* obj2;
	vector<CGFobject*> sceneObjects;
	//vector<LineAnimation*> sceneAnimations;
};

#endif