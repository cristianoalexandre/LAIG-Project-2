#include <GL/glew.h>

#include "LaigScene.h"
#include "Patch.h"

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


void LaigScene::init()
{
    /** Enables lighting computations */
    glEnable(GL_LIGHTING);

    /** Sets up some lighting parameters */
    glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, CGFlight::background_ambient);

    /** Lights initialization */
    float light0_pos[4] = {-4.0, 20.0, 5.0, 1.0};
    light0 = new CGFlight(GL_LIGHT0, light0_pos);
    light0->enable();

    float light1_pos[4] = {8.0, 20.0, 5.0, 1.0};
    light1 = new CGFlight(GL_LIGHT1, light1_pos);
    light1->enable();

    float light2_pos[4] = {-4.0, 20.0, 10.0, 1.0};
    light2 = new CGFlight(GL_LIGHT2, light2_pos);
    light2->enable();

    float light3_pos[4] = {8.0, 20.0, 10.0, 1.0};
    light3 = new CGFlight(GL_LIGHT3, light3_pos);
    light3->enable();

    /** Defines a default normal */
    glNormal3f(0, 0, 1);
	
    /** Declares the usage of display lists */
    //use_display_lists = false;

    /** Materials initialization */
    materialAppearance = new CGFappearance();
    textureAppearance = new CGFappearance("../textures/pyramid.jpg", GL_REPEAT, GL_REPEAT);
    tentAppearance = new CGFappearance("../textures/tent.jpg", GL_REPEAT, GL_REPEAT);

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
    patch1->setTexture(textureAppearance);

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
    patch2->setTexture(textureAppearance);
    setUpdatePeriod(30);

    tent1 = new Tent();
    tent1->setTexture(tentAppearance);
	
    terrain1 = new Terrain();
    spaceDisk = new FlyingDisk();

    /** Shaders declaration*/
    shader1 = new DemoShader();

	LineAnimation::setMiliSecs(10);
	
	double x1 = 0, y1 = 0, z1 = 0;
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
	x1 = 10.0;
	y1 = 0.0;
	z1 = 0.0;
	p2->push_back(x1);
	p2->push_back(y1);
	p2->push_back(z1);
	ctrPoints->push_back(p2);
	vector<double>* p3 = new vector<double>();
	x1 = 10.0;
	y1 = 5.0;
	z1 = -20.0;
	p3->push_back(x1);
	p3->push_back(y1);
	p3->push_back(z1);
	ctrPoints->push_back(p3);
	vector<double>* p4 = new vector<double>();
	x1 = -10.0;
	y1 = 5.0;
	z1 = -20.0;
	p4->push_back(x1);
	p4->push_back(y1);
	p4->push_back(z1);
	ctrPoints->push_back(p4);
	vector<double>* p5 = new vector<double>();
	x1 = -10.0;
	y1 = 5.0;
	z1 = 0.0;
	p5->push_back(x1);
	p5->push_back(y1);
	p5->push_back(z1);
	ctrPoints->push_back(p5);
	vector<double>* p6 = new vector<double>();
	x1 = 10.0;
	y1 = 5.0;
	z1 = 0.0;
	p6->push_back(x1);
	p6->push_back(y1);
	p6->push_back(z1);
	ctrPoints->push_back(p6);
	vector<double>* p7 = new vector<double>();
	x1 = 10.0;
	y1 = 5.0;
	z1 = -20.0;
	p7->push_back(x1);
	p7->push_back(y1);
	p7->push_back(z1);
	ctrPoints->push_back(p7);
	
	obj = new ExampleObject();	
	PolyLineAnimation* poly = new PolyLineAnimation();
	//Animation* poly = new PolyLineAnimation();
	poly->initValues(spaceDisk, ctrPoints, 30);
	poly->setRepeatAnimation(true);
	poly->setResetSegment(2);
	allPolyAnimations.push_back(poly);
	
	/*FOR CIRCULAR TRAJECTORIES
	double inc = 0.05;
	for(double i = 0; i <= 100; i++){

		vector<double>* p1 = new vector<double>;
			
		x1 = 0 - 5* cosl(PI/2 - (2*PI) * (i/100));
		if(i == 0){
			y1 = 0;
		}else{
			y1 += inc;
		}
		z1 = 10 + 5* cosl(PI/2 - (PI*2) * (i/100));

		cout << "x1 = " << x1 << endl;
		cout << "z1 = " << z1 << endl;

		p1->push_back(x1);
		p1->push_back(y1);
		p1->push_back(z1);
		ctrPoints->push_back(p1);
	}
	cin.get();*/
	glutTimerFunc(LineAnimation::getMiliSecs(), updateTransforms, 0);
    //materialAppearance = new CGFappearance();
    //textureAppearance = new CGFappearance("./textures/pyramid.jpg", GL_REPEAT, GL_REPEAT);
    //shader = new CGFshader("./shaders/texshader.vert", "./shaders/texshader.frag");
	
	//GLUI_Master.set_glutIdleFunc(myGlutIdle);
    //setUpdatePeriod(10);
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
    light1->draw();
    light2->draw();
    light3->draw();

    /** Setting the cullface and frontface */
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    /** Draw objects */
    //plane1->draw();
    //patch1->draw();
    //patch2->draw();

	for(unsigned int i = 0; i < allPolyAnimations.size(); i++){
		allPolyAnimations[i]->animate();
	}


    glPushMatrix();
		//glTranslatef(3, 0, 3);
		glPushMatrix();
			glScalef(2,0.5,1);
			glTranslatef(-5,0,20);
			tent1->draw();
		glPopMatrix();
		glPushMatrix();
			//glTranslatef(9, 0, 6);
			glScalef(50, 2, 50);
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
    delete spaceDisk;
}

void LaigScene::enableDisplayLists()
{
    use_display_lists = true;
}

void LaigScene::disableDisplayLists()
{
    use_display_lists = false;
}