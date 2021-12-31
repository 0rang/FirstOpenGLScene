
#include "materials.h"
#include <GL/glu.h>
#include <QGLWidget>
#include "SceneWidget.h"
#include <QDebug>
#include <cmath>

// called when OpenGL context is set up
void SceneWidget::initializeGL() {
	// set the widget background colour
    glClearColor(0.3, 0.3, 0.3, 0.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90, 2, 0.2, 150);

    //glOrtho(-4.0, 4.0, -4.0, 4.0, -4.0, 4.0);
}


// called every time the widget is resized
void SceneWidget::resizeGL(int w, int h)
	{ // resizeGL()
    // set the both width and height equal to the smallest dimension of the viewport
    if (w < h) glViewport(0, 0, w, w);
    else       glViewport(0, 0, h, h);
	} // resizeGL()

void SceneWidget::SetCameraAngleHori(int angle){
    this->cameraAngleHori = angle;
    update();
}

void SceneWidget::SetCameraAngleVert(int angle){
    this->cameraAngleVert = angle;
    update();
}

void SceneWidget::SetCameraZoom(int distance){
    this->cameraZoom = distance;
    update();
}

void SceneWidget::pyramid(){
    // these are (hopefully) correctly calculated normals for the pyramid
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

void SceneWidget::cube(){

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


void SceneWidget::scene_objects(){
    this->spider();
}

// called every time the widget needs painting
void SceneWidget::paintGL()
{
	// clear the widget
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// You must set the matrix mode to model view directly before enabling the depth test
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST); // comment out depth test to observe the result
    glEnable(GL_NORMALIZE);

    // put a light in the world
    glPushMatrix();
	glLoadIdentity();
        GLfloat light_pos[] = {0, 10, -10, 1.};
        GLfloat light_dir_towards_origin[] = {0-light_pos[0], 0-light_pos[1], 0-light_pos[2]}; // make the light point to the origin
        GLfloat light_dir_custom[] = {0, -1, 1};
        glLightfv(GL_LIGHT0, GL_POSITION, light_pos); // set light position
        glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, light_dir_custom); //set light direction
        glLighti (GL_LIGHT0, GL_SPOT_EXPONENT, 10);
        glLightf (GL_LIGHT0, GL_SPOT_CUTOFF, 90); // set light cutoff
    glPopMatrix();

    //this->scene_objects();
    //this->test_things();

    this->spider_web();

    glLoadIdentity(); //insurance for if i stop caring about push/pop
    // camera position and rotation controlled by user sliders

    gluLookAt(0, 0, -cameraZoom, 0.0,0,0.0, 0.0,1,0);
    //TODO: make horizontal rotation happen around the vertical translation with some trig

    // camera movement, not ideal but it works fine for debugging
    glRotatef(-this->cameraAngleVert, 1, 0, 0);
    glRotatef(-this->cameraAngleHori, 0, 1, 0);

    /* trying to be smart with camera but it's not working :(
    glTranslatef(0, sinf(cameraAngleVert)*cameraZoom, 0);
    glRotatef(-this->cameraAngleHori, 0, 1, 0);
    glTranslatef(0, 0, -cosf(cameraAngleVert)*cameraZoom);
    */


    //glTranslatef()

	
	glFlush();	

}
