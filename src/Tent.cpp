#include "Tent.h"

Tent::Tent()
{
    /** Defines the intermediate height for the tent */
    height = 4.0;
    z_bound = 3;
    x_bound = 3;
    
    /** Definines control points */
    GLfloat control_points[][3] = {
        {-x_bound, 0, z_bound},
        {-x_bound/2, height, z_bound},
        {x_bound/2, height, z_bound},
        {x_bound, 0, z_bound},

        {-x_bound, height, z_bound/2},
        {-x_bound/2, height+height*0.5, z_bound/2},
        {x_bound/2, height+height*0.5, z_bound/2},
        {x_bound, height, z_bound/2},

        {-x_bound, height, -z_bound/2},
        {-x_bound/2, height+height*0.5, -z_bound/2},
        {x_bound/2, height+height*0.5, -z_bound/2},
        {x_bound, height, -z_bound/2},

        {-x_bound, 0, -z_bound},
        {-x_bound/2, height, -z_bound},
        {x_bound/2, height, -z_bound},
        {x_bound, 0, -z_bound}
    };

    patch = new Patch(3, 3, 20, 20, control_points, 16, 3);
}

Tent::~Tent()
{
    delete patch;
}

void Tent::setAppearance(CGFappearance * appearance)
{
    patch->setAppearance(appearance);
}

void Tent::draw()
{
    patch->draw();
}