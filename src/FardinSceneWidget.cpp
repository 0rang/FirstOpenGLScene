
#include "materials.h"
#include <GL/glu.h>
#include <QGLWidget>
#include "FardinSceneWidget.h"








// constructor
FardinSceneWidget::FardinSceneWidget(QWidget *parent)
	: QGLWidget(parent)
	{ // constructor
       

	} // constructor

// called when OpenGL context is set up
void FardinSceneWidget::initializeGL()
	{ // initializeGL()
	// set the widget background colour
    glClearColor(0.3, 0.3, 0.3, 0.0);
	

 
	} // initializeGL()


// called every time the widget is resized
void FardinSceneWidget::resizeGL(int w, int h)
	{ // resizeGL()
	// set the viewport to the entire widget
	glViewport(0, 0, w, h);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
   
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	GLfloat light_pos[] = {0., 0., 10., 1.};	
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
        glLightf (GL_LIGHT0, GL_SPOT_CUTOFF,15.);


                                                                                                                                                               
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-4.0, 4.0, -4.0, 4.0, -4.0, 4.0);

	} // resizeGL()


void FardinSceneWidget::cube(){

  // Here are the normals, correctly calculated for the cube faces below  
  GLfloat normals[][3] = { {1., 0. ,0.}, {-1., 0., 0.}, {0., 0., 1.}, {0., 0., -1.} };

  // Here we give every face the same normal
  //GLfloat normals[][3] = { {0.333, 0.333, 0.333 }, {0.333, 0.333, 0.333}, {0.333, 0.333, 0.333}, {0.3333, 0.3333, 0.333}};

  // Here we have permuted the first normal array
  //GLfloat normals[][3] = {{-1., 0., 0.}, {0., 0., 1.}, {0., 0., 1.}, {0., 0., -1.}};


  materialStruct *p_front = &brassMaterials;

  glMaterialfv(GL_FRONT, GL_AMBIENT, p_front->ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, p_front->diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, p_front->specular);
  glMaterialf(GL_FRONT, GL_SHININESS, p_front->shininess);

  glNormal3fv(normals[0]);
  glBegin(GL_POLYGON);
  glVertex3f(1.0, -1.0, 1.0);
  glVertex3f(1.0, -1.0, -1.0);
  glVertex3f(1.0, 1.0, -1.0);
  glVertex3f(1.0, 1.0, 1.0);
  glEnd();

  glNormal3fv(normals[3]);
  glBegin(GL_POLYGON);
  glVertex3f(-1.0, -1.0, -1.0);
  glVertex3f(1.0, -1.0, -1.0);
  glVertex3f(1.0, 1.0, -1.0);
  glVertex3f(-1.0, 1.0, -1.0);
  glEnd();

  glNormal3fv(normals[2]);
  glBegin(GL_POLYGON);
  glVertex3f(-1.0, -1.0, 1.0);
  glVertex3f(1.0, -1.0, 1.0);
  glVertex3f(1.0, 1.0, 1.0);
  glVertex3f(-1.0, 1.0, 1.0);
  glEnd();

  glNormal3fv(normals[1]);
  glBegin(GL_POLYGON);
  glVertex3f(-1.0, -1.0, 1.0);
  glVertex3f(-1.0, -1.0, -1.0);
  glVertex3f(-1.0, 1.0, -1.0);
  glVertex3f(-1.0, 1.0, 1.0);
  glEnd();
}


void FardinSceneWidget::spider(){
  glPushMatrix();

    materialStruct& material = obsidianMaterial;
    // set spider material
    glMaterialfv(GL_FRONT, GL_AMBIENT, material.ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, material.diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, material.specular);
    glMaterialf(GL_FRONT, GL_SHININESS, material.shininess);


    // draw main body
    GLUquadric* quadric = gluNewQuadric();
    gluSphere(quadric, 2, 20, 20);
    gluDeleteQuadric(quadric);
  glPopMatrix();
}

// called every time the widget needs painting
void FardinSceneWidget::paintGL()
	{ // paintGL()
	// clear the widget
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// You must set the matrix mode to model view directly before enabling the depth test

	glEnable(GL_DEPTH_TEST); // comment out depth test to observe the result                                                                                                    


    // put a light in the world
	glPushMatrix();
	glLoadIdentity();
        GLfloat light_pos[] = {0., 0., 10., 1.};
        glLightfv(GL_LIGHT0, GL_POSITION, light_pos); // set light position
        glLightf (GL_LIGHT0, GL_SPOT_CUTOFF,15.); // set light cutoff
	glPopMatrix();

    spider();


    //this->cube();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

       	gluLookAt(1.,1.,1., 0.0,0.0,0.0, 0.0,1.0,0.0); //wait a sec, the up vector doesn't make any sense!!
       
	
	// flush to screen
	glFlush();	

	} // paintGL()
