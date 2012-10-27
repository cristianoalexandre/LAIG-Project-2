#ifndef PRIMITIVE_H
#define	PRIMITIVE_H

#include "CGFobject.h"
#include "Point.h"

#include <iostream>
#include <string>

using namespace std;

class Primitive
{
private:
    string id;
public:

    virtual int addValues(string attr, string val)
    {
        return 0;
    };

    virtual void draw()
    {
    };
};

#endif	/* FIGURE_H */

