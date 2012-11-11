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

class LaigScene : public CGFscene
{
private:
    bool use_display_lists;
    static const long update_time = 30;

    /** Lights declaration */
    CGFlight * light0;

    /** Appearances declaration */
    CGFappearance* materialAppearance;
    CGFappearance* textureAppearance;

    /** Primitives declaration */
    Plane * plane1;
    Patch * patch1;
    Patch * patch2;
    Tent * tent1;
    Terrain * terrain1;
    FlyingDisk * spaceDisk;
    
    /** Shaders declaration */
    DemoShader * shader1;

public:
    void enableDisplayLists();
    void disableDisplayLists();

    void init();
    void display();
    void update(long t);
    ~LaigScene();
};

#endif	/* LAIGSCENE_H */