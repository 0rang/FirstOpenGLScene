
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

    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

    glGenTextures(3, textureIDs);

    *marcQimg = QGLWidget::convertToGLFormat(*marcQimg);

    *markusQimg = QGLWidget::convertToGLFormat(*markusQimg);

    *earthQimg = QGLWidget::convertToGLFormat(*earthQimg);


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90, 1, 0.2, 150);

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
    this->updateGL();
}

void SceneWidget::SetCameraAngleVert(int angle){
    this->cameraAngleVert = angle;
    this->updateGL();
}

void SceneWidget::SetCameraZoom(int distance){
    this->cameraZoom = distance;
    this->updateGL();
}

void SceneWidget::IncrementThreeSixtyTick(){
    int move_speed = 1;
    this->threeSixtyTick += move_speed;
    this->threeSixtyTick %= 360;

    //TODO: same for fly0 and fly1
    updateGL();
}

void SceneWidget::ToggleSpecular(){
    //SceneWidget::UseSpecular = !SceneWidget::UseSpecular;
    updateGL();
}


void SceneWidget::pyramid(){
    // these are (hopefully) correctly calculated normals for the pyramid
    GLfloat normals[5][3] = {{0, -1, 0}, {0, 2, 1}, {-1, 2, 0}, {0, 2, -1}, {1, 2, 0}};

    // base
    glNormal3fv(normals[0]);
    glBegin(GL_POLYGON);
    glVertex3f(1, 0, 1);
    glVertex3f(1, 0, -1);
    glVertex3f(-1, 0, -1);
    glVertex3f(-1, 0, 1);
    glEnd();

    // triangle walls
    glNormal3fv(normals[1]);
    glBegin(GL_POLYGON);
    glVertex3f(0, 2, 0);
    glVertex3f(-1, 0, 1);
    glVertex3f(1, 0, 1);
    glEnd();

    glNormal3fv(normals[2]);
    glBegin(GL_POLYGON);
    glVertex3f(0, 2, 0);
    glVertex3f(-1, 0, -1);
    glVertex3f(-1, 0, 1);
    glEnd();

    glNormal3fv(normals[3]);
    glBegin(GL_POLYGON);
    glVertex3f(0, 2, 0);
    glVertex3f(1, 0, -1);
    glVertex3f(-1, 0, -1);
    glEnd();

    glNormal3fv(normals[4]);
    glBegin(GL_POLYGON);
    glVertex3f(0, 2, 0);
    glVertex3f(1, 0, 1);
    glVertex3f(1, 0, -1);
    glEnd();

}

void SceneWidget::cube(){

  // Here are the normals, correctly calculated for the cube faces below  
  GLfloat normals[][3] = { {1., 0. ,0.}, {-1., 0., 0.}, {0., 0., 1.}, {0., 0., -1.} };

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

void SceneWidget::textured_cube(QImage* texture_qimg){

    // Here are the normals, correctly calculated for the cube faces below
    GLfloat normals[][3] = { {1., 0. ,0.}, {-1., 0., 0.}, {0., 0., 1.}, {0., 0., -1.} };

    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, this->bindCount++);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture_qimg->width(), texture_qimg->height(),
                 0, GL_RGBA, GL_UNSIGNED_BYTE, texture_qimg->bits());

    glNormal3fv(normals[3]);
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(1.0, -1.0, -1.0);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(-1.0, 1.0, -1.0);
    glEnd();

    glDisable(GL_TEXTURE_2D);

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
}

//just a function to place other test functions in, so that the main loop is clean
void SceneWidget::test_things(){


}


void SceneWidget::scene_objects(){

    glPushMatrix();
      glTranslatef(0, -0.7, 0);
      this->spider_web();
    glPopMatrix();
    this->spider_circular_motion();

    glPushMatrix();
      glTranslatef(0, -2, 0);
      glRotatef(90, 1, 0, 0);
      glScalef(10, 10, 1);
      this->textured_cube(earthQimg);
    glPopMatrix();

    glPushMatrix();
      glTranslatef(0, 2, 0);
      this->fly_animated_circular_motion(marcQimg, 45);
      this->fly_animated_circular_motion(markusQimg, 90);
    glPopMatrix();
}

// called every time the widget needs painting
void SceneWidget::paintGL()
{
    this->bindCount = 0;

	// clear the widget
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// You must set the matrix mode to model view directly before enabling the depth test
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST); // comment out depth test to observe the result


    // do transformation and drawing stuff
    {

        // if you would like to test things in isolation,
        // uncomment scene_objects and either write some code here or in this->test_things()

        this->scene_objects();


    }



    GLfloat light_pos[4] = {5, 5, -5, 1.};
    GLfloat light_dir_towards_origin[3] = {0-light_pos[0], 0-light_pos[1], 0-light_pos[2]}; // make the light point to the origin
    GLfloat point_of_focus[4] = {10, 0 , 0, 1};
    GLfloat light_dir_towards_point[3] = {point_of_focus[0]-light_pos[0], point_of_focus[1]-light_pos[1], point_of_focus[2]-light_pos[2]};
    GLfloat light_dir_custom[3] = {0, -1, 1};

    glPushMatrix();
      glTranslatef(light_pos[0], light_pos[1], light_pos[2]);
      glScalef(0.1, 0.1, 0.1);
      setMaterial(whiteShinyMaterial);
      this->cube();
    glPopMatrix();


    // put a light in the world
    glPushMatrix();
    {

        glEnable(GL_NORMALIZE); // all transformations done. Do some lighting!

        glLightfv(GL_LIGHT0, GL_POSITION, light_pos); // set light position
        glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, light_dir_towards_origin); //set light direction
        glLighti (GL_LIGHT0, GL_SPOT_EXPONENT, 120);
        glLightf (GL_LIGHT0, GL_SPOT_CUTOFF, 180); // set light cutoff

        // draw a cube where the light is, for debugging
        glPushMatrix();
          glTranslatef(light_pos[0], light_pos[1], light_pos[2]);
          glScalef(0.1, 0.1, 0.1);
          this->cube();
        glPopMatrix();
    }
    glPopMatrix();

    glLoadIdentity(); // Not really sure what this does

    // camera zoom controlled by user slider
    gluLookAt(0, 0, -this->cameraZoom, 0.0,0,0.0, 0.0,1,0);
    // user controlled camera rotation
    glRotatef(-this->cameraAngleVert, 1, 0, 0);
    glRotatef(-this->cameraAngleHori, 0, 1, 0);

    if (this->bindCount > NUM_TEXTURES){ qDebug() << bindCount << " textures binded, expected no more than " << NUM_TEXTURES;}
    if (glGetError()) { qDebug() << "GL Error : " << glGetError(); }
	glFlush();	

}
