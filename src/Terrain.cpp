#include "Terrain.h"

using namespace std;

Terrain::Terrain()
{
    plane = new Plane();
}

Terrain::~Terrain()
{
    delete plane;
}

void Terrain::draw()
{
    plane->draw();
}