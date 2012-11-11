#ifndef FLYINGDISK_H
#define	FLYINGDISK_H

#include "Object.h"
#include "Patch.h"
#include "Cylinder.h"

class FlyingDisk : public Object
{
private:
    Patch * topPart;
    Cylinder * disk;
public:
    FlyingDisk();
    ~FlyingDisk();
    void draw();
};

#endif	/* FLYINGDISK_H */

