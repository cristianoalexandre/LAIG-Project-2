#ifndef PLANE_H
#define	PLANE_H

#include "Object.h"
#include "CGFappearance.h"

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

typedef GLfloat vec3[3];
typedef GLfloat vec2[2];

class Plane : public Object
{
private:
    vec3 * control_points;
    vec2 * texture_points;
    int * divisions;
    
public:
    Plane(GLint divisions_u = 10, GLint divisions_v = 10);
    ~Plane();
    void draw();
    
};

#endif	/* PLANE_H */