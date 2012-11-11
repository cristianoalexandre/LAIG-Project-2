#include "FlyingDisk.h"

FlyingDisk::FlyingDisk()
{
    /** Defines control points */
    GLfloat control_points[][3] = {
        {-3 + 0.3, 0, 3},
        {-3 / 2, 0, 3 + 1.5},
        {3 / 2, 0, 3 + 1.5},
        {3 - 0.3, 0, 3},

        {-3 - 1.5, 0, 3 / 2},
        {-3 / 2, 5, 3 / 2},
        {3 / 2, 5, 3 / 2},
        {3 + 1.5, 0, 3 / 2},

        {-3 - 1.5, 0, -3 / 2},
        {-3 / 2, 5, -3 / 2},
        {3 / 2, 5, -3 / 2},
        {3 + 1.5, 0, -3 / 2},

        {-3 + 0.3, 0, -3},
        {-3 / 2, 0, -3 - 1.5},
        {3 / 2, 0, -3 - 1.5},
        {3 - 0.3, 0, -3}
    };

    topPart = new Patch(3, 3, 20, 20, control_points, 16, 3);
    disk = new Cylinder(9, 9, 0.5, 255, 10);
}

FlyingDisk::~FlyingDisk()
{
    delete topPart;
    delete disk;
}

void FlyingDisk::draw()
{
    glPushMatrix();
    glScalef(0.2,0.2,0.2);
    if (appearance != NULL)
        topPart->setTexture(appearance);
    topPart->draw();
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    if (appearance != NULL)
        disk->setTexture(appearance);
    disk->draw();
    glPopMatrix();
    glPopMatrix();
}