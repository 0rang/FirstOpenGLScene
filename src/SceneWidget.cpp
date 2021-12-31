
#include "materials.h"
#include <GL/glu.h>
#include <QGLWidget>
#include "FardinSceneWidget.h"

// constructor
FardinSceneWidget::FardinSceneWidget(QWidget *parent)
	: QGLWidget(parent)
	{ // constructor
       this->cameraAngleHori = 0;
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
    gluPerspective(90, 2, 0.2, 15);
    //glOrtho(-4.0, 4.0, -4.0, 4.0, -4.0, 4.0);

	} // resizeGL()

void FardinSceneWidget::SetCameraAngleHori(int angle){
    this->cameraAngleHori = angle;
}

void FardinSceneWidget::pyramid(){
    // these should be correct
    GLfloat normals[5][3] = {{0, -1, 0}, {0, 2, 1}, {-1, 2, 0}, {0, 2, -1}, {1, 2, 0}};

    // base
    glNormal3fv(normals[0]);
    glBegin(GL_POLYGON);
    glVertex3f(1, 0, 1);
    glVertex3f(-1, 0, 1);
    glVertex3f(-1, 0, -1);
    glVertex3f(1, 0, -1);
    glEnd();

    // triangle walls
    glNormal3fv(normals[1]);
    glBegin(GL_POLYGON);
    glVertex3f(0, 2, 0);
    glVertex3f(1, 0, 1);
    glVertex3f(-1, 0, 1);
    glEnd();

    glNormal3fv(normals[2]);
    glBegin(GL_POLYGON);
    glVertex3f(0, 2, 0);
    glVertex3f(-1, 0, 1);
    glVertex3f(-1, 0, -1);
    glEnd();

    glNormal3fv(normals[3]);
    glBegin(GL_POLYGON);
    glVertex3f(0, 2, 0);
    glVertex3f(-1, 0, -1);
    glVertex3f(1, 0, -1);
    glEnd();

    glNormal3fv(normals[4]);
    glBegin(GL_POLYGON);
    glVertex3f(0, 2, 0);
    glVertex3f(1, 0, -1);
    glVertex3f(1, 0, 1);
    glEnd();

}

void FardinSceneWidget::cube(){

  // Here are the normals, correctly calculated for the cube faces below  
  GLfloat normals[][3] = { {1., 0. ,0.}, {-1., 0., 0.}, {0., 0., 1.}, {0., 0., -1.} };

  // Here we give every face the same normal
  //GLfloat normals[][3] = { {0.333, 0.333, 0.333 }, {0.333, 0.333, 0.333}, {0.333, 0.333, 0.333}, {0.3333, 0.3333, 0.333}};

  // Here we have permuted the first normal array
  //GLfloat normals[][3] = {{-1., 0., 0.}, {0., 0., 1.}, {0., 0., 1.}, {0., 0., -1.}};

  glNormal3fv(normals[0]);
  glBegin(GL_POLYGON);
  glVertex3f(1.0, -1.0, 1.0);
  glVertex3f(1.0, -1.0, -1.0);
  glVertex3f(1.0, 1.0, -1.0);
  glVertex3f(1.0, 1.0, 1.0);
  glEnd();

  glNormal3fv(normals[1]);
  glBegin(GL_POLYGON);
  glVertex3f(-1.0, -1.0, 1.0);
  glVertex3f(-1.0, -1.0, -1.0);
  glVertex3f(-1.0, 1.0, -1.0);
  glVertex3f(-1.0, 1.0, 1.0);
  glEnd();

  glNormal3fv(normals[2]);
  glBegin(GL_POLYGON);
  glVertex3f(-1.0, -1.0, 1.0);
  glVertex3f(1.0, -1.0, 1.0);
  glVertex3f(1.0, 1.0, 1.0);
  glVertex3f(-1.0, 1.0, 1.0);
  glEnd();

  glNormal3fv(normals[3]);
  glBegin(GL_POLYGON);
  glVertex3f(-1.0, -1.0, -1.0);
  glVertex3f(1.0, -1.0, -1.0);
  glVertex3f(1.0, 1.0, -1.0);
  glVertex3f(-1.0, 1.0, -1.0);
  glEnd();

}


void FardinSceneWidget::spider(){
    setMaterial(blackPlasticMaterial);

    // draw main body
    GLUquadric* quadric = gluNewQuadric();
    glPushMatrix();
      glScalef(0.8, 1, 0.5);
      gluSphere(quadric, 2, 20, 20);
    glPopMatrix();





    gluDeleteQuadric(quadric);
}

// leg consisting of two cylinders and one sphere joint
void FardinSceneWidget::spider_leg(){
    GLUquadric* quadric = gluNewQuadric();
    gluSphere(quadric, 0.2, 20, 20);

    glPushMatrix();
      glRotatef(90, 0, 1, 0);
      glRotatef(30, 1, 0, 0);
      gluCylinder(quadric, 0.2, 0.2, 2, 20, 20); //
    glPopMatrix();

    glPushMatrix();
      glRotatef(-90, 0, 1, 0);
      glRotatef(30, 1, 0, 0);
      gluCylinder(quadric, 0.2, 0.2, 2, 20, 20); //
    glPopMatrix();
    gluDeleteQuadric(quadric);
}

void FardinSceneWidget::scene(){

}

// called every time the widget needs painting
void FardinSceneWidget::paintGL()
{
	// clear the widget
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// You must set the matrix mode to model view directly before enabling the depth test
    glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST); // comment out depth test to observe the result                                                                                                    



    // put a light in the world
    glPushMatrix(); // why push
	glLoadIdentity();
        GLfloat light_pos[] = {0., 0, 10., 1.};
        glLightfv(GL_LIGHT0, GL_POSITION, light_pos); // set light position
        glLightf (GL_LIGHT0, GL_SPOT_CUTOFF,30); // set light cutoff
    glPopMatrix();

    //this->spider();
    this->pyramid();

    glLoadIdentity(); //insurance for if i stop caring about push/pop
    //glPushMatrix();
    glRotatef(cameraAngleHori, 0, 1, 0);
    gluLookAt(0, 0, -4, 0.0,0.0,0.0, 0.0,1,0);
    //glPopMatrix();
	
	glFlush();	

}
