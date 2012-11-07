#include "LaigScene.h"

void LaigScene::init()
{
    /** Enables lighting computations */
    glEnable(GL_LIGHTING);

    /** Sets up some lighting parameters */
    glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, CGFlight::background_ambient);

    /** Declares the usage of display lists */
    use_display_lists = true;

}

void LaigScene::display()
{
    /** Clear image and depth buffer everytime we update the scene */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /** Initialize Model-View matrix as identity (no transformation */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    /** Apply transformations corresponding to the camera position relative to the origin */
    CGFscene::activeCamera->applyView();
    
    /** Draw axis */
    axis.draw();
    
    /** @TODO:add drawing here.*/
    
    glutSwapBuffers();
}

void LaigScene::update(long t)
{
    
}

LaigScene::~LaigScene()
{

}

void LaigScene::enableDisplayLists()
{
    use_display_lists = true;
}

void LaigScene::disableDisplayLists()
{
    use_display_lists = false;
}