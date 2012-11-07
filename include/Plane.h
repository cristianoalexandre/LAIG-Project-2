#ifndef PLANE_H
#define	PLANE_H

#include "CGFobject.h"

class Plane : public CGFobject
{
private:
    GLfloat control_points[2][6];
    GLfloat texture_points[2][6];
    GLfloat normal_points[2][6];
    GLint divisions[2];
    
public:
    Plane(GLint divisions_u = 10, GLint divisions_v = 10);
    ~Plane();
    void draw();
};

#endif	/* PLANE_H */