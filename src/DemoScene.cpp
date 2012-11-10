#include "DemoScene.h"

unsigned int LineAnimation::mili_secs = 0;


void updateTransforms(int dummy){


	for(unsigned int i = 0; i < allPolyAnimations.size(); i++){

		allPolyAnimations[i]->updateObjectPosition();
	}

	glutTimerFunc(LineAnimation::getMiliSecs(),updateTransforms,dummy);
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

	LineAnimation::setMiliSecs(45);
	double x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4;
	vector<vector<double>*>* ctrPoints = new vector<vector<double>*>();
	vector<double>* p1 = new vector<double>();
	x1 = 0.0;
	y1 = 0.0;
	z1 = 0.0;
	p1->push_back(x1);
	p1->push_back(y1);
	p1->push_back(z1);
	ctrPoints->push_back(p1);
	vector<double>* p2 = new vector<double>();
	x2 = 5.0;
	y2 = 0.0;
	z2 = 0.0;
	p2->push_back(x2);
	p2->push_back(y2);
	p2->push_back(z2);
	ctrPoints->push_back(p2);
	vector<double>* p3 = new vector<double>();
	x3 = 5.0;
	y3 = 5.0;
	z3 = 0.0;
	p3->push_back(x3);
	p3->push_back(y3);
	p3->push_back(z3);
	ctrPoints->push_back(p3);
	vector<double>* p4 = new vector<double>();
	x4 = 5.0;
	y4 = 5.0;
	z4 = 5.0;
	p4->push_back(x4);
	p4->push_back(y4);
	p4->push_back(z4);
	ctrPoints->push_back(p4);

	
	obj = new ExampleObject();
	PolyLineAnimation* poly = new PolyLineAnimation();
	poly->initValues(obj, ctrPoints, 10);

	allPolyAnimations.push_back(poly);

	glutTimerFunc(LineAnimation::getMiliSecs(), updateTransforms, 0);

	
   // materialAppearance = new CGFappearance();
    //textureAppearance = new CGFappearance("./textures/pyramid.jpg", GL_REPEAT, GL_REPEAT);
    //shader = new CGFshader("./shaders/texshader.vert", "./shaders/texshader.frag");
	
	//GLUI_Master.set_glutIdleFunc(myGlutIdle);
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

	for(unsigned int i = 0; i < allPolyAnimations.size(); i++){

		allPolyAnimations[i]->animate();
	}


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
	//glPopMatrix();

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