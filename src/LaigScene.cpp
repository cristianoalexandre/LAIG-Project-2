#include <GL/glew.h>

#include "LaigScene.h"
#include "Patch.h"

void LaigScene::init()
{
    /** Enables lighting computations */
    glEnable(GL_LIGHTING);

    /** Sets up some lighting parameters */
    glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, CGFlight::background_ambient);

    /** Lights initialization */
    float light0_pos[4] = {4.0, 6.0, 5.0, 1.0};
    light0 = new CGFlight(GL_LIGHT0, light0_pos);
    light0->enable();

    /** Defines a default normal */
    glNormal3f(0, 0, 1);

    /** Declares the usage of display lists */
    //use_display_lists = false;

    /** Materials initialization */
    materialAppearance = new CGFappearance();
    textureAppearance = new CGFappearance("./textures/pyramid.jpg", GL_REPEAT, GL_REPEAT);

    /** Object initialization */
    plane1 = new Plane();
    plane1->setTexture(textureAppearance);

    GLfloat patch1_control_points[][3] = {
        {-0.5, 0, 0.5},
        {0.5, 0, 0.5},
        {-0.5, 0, -0.5},
        {0.5, 0, -0.5}
    };
    patch1 = new Patch(1, 1, 10, 10, patch1_control_points, 4, 3);
    patch1->setAppearance(textureAppearance);

    GLfloat patch2_control_points[][3] = {
        {0, 0, 0},
        {0, 0.6, 0.3},
        {0, 0.6, 0.6},
        {0, 0, 1},

        {0.3, 0.0, 0.0},
        {0.3, 0.6, 0.3},
        {0.3, 0.6, 0.6},
        {0.3, 0.0, 1},

        {0.6, 0, 0},
        {0.6, 0.6, 0.3},
        {0.6, 0.6, 0.6},
        {0.6, 0.0, 1},

        {1.0, 0, 0},
        {1.0, 0.6, 0.3},
        {1.0, 0.6, 0.6},
        {1.0, 0, 1}
    };

    patch2 = new Patch(3, 3, 20, 20, patch2_control_points, 16, 3);
    patch2->setAppearance(textureAppearance);
    setUpdatePeriod(30);

    tent1 = new Tent();
    terrain1 = new Terrain();
    shader1 = new DemoShader();
    //shader1 = new CGFshader("/shaders/lightMapping.vert", "./shaders/lightMapping.frag");
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

    /** Draw lights */
    light0->draw();

    /** Setting the cullface and frontface */
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    /** Draw objects */
    textureAppearance->apply();
    //plane1->draw();
    //patch1->draw();
    //patch2->draw();

    glPushMatrix();
    glTranslatef(3, 0, 3);
    tent1->draw();
    glPushMatrix();
    glTranslatef(9, 0, 6);
    glScalef(10, 1, 10);
    shader1->bind();
    terrain1->draw();
    shader1->unbind();
    glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();
}

void LaigScene::update(long t)
{

}

LaigScene::~LaigScene()
{
    delete light0;
    delete plane1;
    delete patch1;
    delete tent1;
}

void LaigScene::enableDisplayLists()
{
    use_display_lists = true;
}

void LaigScene::disableDisplayLists()
{
    use_display_lists = false;
}