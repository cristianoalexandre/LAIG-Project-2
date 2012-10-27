#include "Sphere.h"

Sphere::Sphere()
{
    texture_quad = gluNewQuadric();
}

Sphere::~Sphere()
{
}

Sphere::Sphere(float rad, int slcs, int stcks)
{
    this->texture_quad = gluNewQuadric();
    this->radius = rad;
    this->slices = slcs;
    this->stacks = stcks;
}

void Sphere::setRadius(float rad)
{
    this->radius = rad;
}

void Sphere::setSlices(int slcs)
{
    this->slices = slcs;
}

void Sphere::setStacks(int stcks)
{
    this->stacks = stcks;
}

int Sphere::addValues(string attr, string val)
{

    if (attr == "radius")
    {
        setRadius(atof(val.c_str()));
    }
    else
    {
        if (attr == "slices")
        {
            setSlices(atof(val.c_str()));
        }
        else
        {
            if (attr == "stacks")
            {
                setStacks(atof(val.c_str()));
                return 1;
            }
        }
    }
    return 0;
}

void Sphere::draw()
{
    gluQuadricTexture(texture_quad, true);
    gluSphere(texture_quad, this->radius, this->slices, this->stacks);
    //glutSolidSphere(this->radius, this->slices, this->stacks);
}