#include "DemoScene.h"
#include "CGFaxis.h"
#include "CGFapplication.h"

#include "ExampleObject.h"

#include <math.h>

#include "CGFappearance.h"
#include "Cylinder.h"
#include "Triangle.h"
#include "Sphere.h"

unsigned int mili_secs = 10;
double  obj_radius, obj_rotate, delta_radius, delta_rotate;
#define RADIUS_SPEED  0.4  // unidades de comprimento por segundo
#define ANGULAR_SPEED 0.5  // rotacoes por segundo

void myInitTransforms()
{
	delta_rotate = (double) mili_secs/1000.0 * ANGULAR_SPEED *360.0;
	delta_radius = (double) mili_secs/1000.0 * RADIUS_SPEED;
}

void myUpdateTransforms(int dummy)
{

	obj_rotate += delta_rotate;
	obj_radius += delta_radius;

	glutTimerFunc(mili_secs, myUpdateTransforms, 0);
}

void myObjectTransforms()
{
	glRotated(obj_rotate, 0,1,0);
	glTranslated(obj_radius,0.0,0.0);
}



void myGlutIdle( void )
{
  /* According to the GLUT specification, the current window is 
     undefined during an idle callback.  So we need to explicitly change
     it if necessary */
  //if ( glutGetWindow() != main_window ) 
  //glutSetWindow(main_window);  
  glutSetWindow(glutGetWindow());

  glutPostRedisplay();

  /****************************************************************/
  /*            This demonstrates GLUI::sync_live()               */
  /*   We change the value of a variable that is 'live' to some   */
  /*   control.  We then call sync_live, and the control          */
  /*   associated with that variable is automatically updated     */
  /*   with the new value.  This frees the programmer from having */
  /*   to always remember which variables are used by controls -  */
  /*   simply change whatever variables are necessary, then sync  */
  /*   the live ones all at once with a single call to sync_live  */
  /****************************************************************/

//  glui->sync_live();

}

void DemoScene::init()
{
    // Enables lighting computations
    glEnable(GL_LIGHTING);

    // Sets up some lighting parameters
    glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, CGFlight::background_ambient); // Define ambient light

    // Declares and enables a light
    float light0_pos[4] = {4.0, 6.0, 5.0, 1.0};
    light0 = new CGFlight(GL_LIGHT0, light0_pos);
    light0->enable();

    // Defines a default normal
    glNormal3f(0, 0, 1);

    obj = new ExampleObject();
   // materialAppearance = new CGFappearance();
    //textureAppearance = new CGFappearance("./textures/pyramid.jpg", GL_REPEAT, GL_REPEAT);
    //shader = new CGFshader("./shaders/texshader.vert", "./shaders/texshader.frag");
	glutTimerFunc(mili_secs, myUpdateTransforms, 0);
	GLUI_Master.set_glutIdleFunc(myGlutIdle);
	myInitTransforms();
    setUpdatePeriod(30);
}

void DemoScene::update(long t)
{
   /* shader->bind();
    shader->update(t / 400.0);
    shader->unbind();*/

}

void DemoScene::display()
{

    // ---- BEGIN Background, camera and axis setup

    // Clear image and depth buffer everytime we update the scene
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Initialize Model-View matrix as identity (no transformation
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Apply transformations corresponding to the camera position relative to the origin
    CGFscene::activeCamera->applyView();

    // Draw (and update) light
    light0->draw();

    // Draw axis
    axis.draw();

	myObjectTransforms();
	obj->draw();

    // ---- END Background, camera and axis setup


    // ---- BEGIN feature demos

    // Simple object
    //materialAppearance->apply();
    //obj->draw();

    // textured object

    //glTranslatef(0, 4, 0);
    //textureAppearance->apply();
	//obj->draw();
    
   
    // shader object

    //glTranslatef(0, 4, 0);
    //shader->bind();
    //obj->draw();
    //shader->unbind();


    // ---- END feature demos

    // We have been drawing in a memory area that is not visible - the back buffer, 
    // while the graphics card is showing the contents of another buffer - the front buffer
    // glutSwapBuffers() will swap pointers so that the back buffer becomes the front buffer and vice-versa
    glutSwapBuffers();
}

DemoScene::~DemoScene()
{
    delete(shader);
    delete(textureAppearance);
    delete(materialAppearance);
    delete(obj);
    delete(light0);
}