#ifndef LAIGSCENE_H
#define	LAIGSCENE_H

#include "Plane.h"
#include "Patch.h"
#include "Tent.h"
#include "Terrain.h"

#include "CGFscene.h"
#include "CGFappearance.h"
#include "CGFaxis.h"
#include "CGFapplication.h"
#include "CGFobject.h"
#include "CGFshader.h"
#include "DemoShader.h"
#include "FlyingDisk.h"
#include "ExampleObject.h"

#include "LineAnimation.h"
#include "PolyLineAnimation.h"

#include "Cylinder.h"
#include "Triangle.h"
#include "Sphere.h"

#include <math.h>
#include <vector>

static vector<PolyLineAnimation*> allPolyAnimations;

class LaigScene : public CGFscene
{
public:
    void enableDisplayLists();
    void disableDisplayLists();

    void init();
    void display();
    void update(long t);
    ~LaigScene();

private:
    bool use_display_lists;
    static const long update_time = 30;

    /** Lights declaration */
    CGFlight * light0;
    CGFlight * light1;
    CGFlight * light2;
    CGFlight * light3;

    /** Appearances declaration */
    CGFappearance* materialAppearance;
    CGFappearance* textureAppearance;
    CGFappearance* tentAppearance;

    /** Primitives declaration */
    Plane * plane1;
    Patch * patch1;
    Patch * patch2;
    Tent * tent1;
    Terrain * terrain1;
    FlyingDisk * spaceDisk;

	Object* obj;
    
    /** Shaders declaration */
    DemoShader * shader1;
};

#endif	/* LAIGSCENE_H */