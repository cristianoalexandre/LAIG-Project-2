#ifndef VERTEX_H
#define	VERTEX_H


class Point2D
{

void SetY(float y)
{
    this->y = y;
}

float GetY() const
{
    return y;
}

void SetX(float x)
{
    this->x = x;
}

float GetX() const
{
    return x;
}

public:
    float x;
    float y;
};

class Point3D
{

void SetZ(float z)
{
    this->z = z;
}

float GetZ() const
{
    return z;
}

void SetY(float y)
{
    this->y = y;
}

float GetY() const
{
    return y;
}

void SetX(float x)
{
    this->x = x;
}

float GetX() const
{
    return x;
}

public:
    float x;
    float y;
    float z;
};

#endif	/* VERTEX_H */

