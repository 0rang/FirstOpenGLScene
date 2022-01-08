#include "SceneWidget.h"
#include "materials.h"
#include <GL/gl.h>
#include <cmath>
#include <QDebug>

class QImage;

void SceneWidget::fly(QImage* texture_qimg, GLfloat wing_angle){
    setMaterial(blackishMaterial);
    this->textured_cube(texture_qimg);
    setMaterial(whiteRubberMaterial);
    glPushMatrix();
      glTranslatef(-0.5, 1, 0);
      glRotatef(-wing_angle, 0, 0, 1);
      glScalef(0.1, 1, 1);
      this->pyramid_for_fly();
    glPopMatrix();
    glPushMatrix();
      glTranslatef(0.5, 1, 0);
      glRotatef(wing_angle, 0, 0, 1);
      glScalef(0.1, 1, 1);
      this->pyramid_for_fly();
    glPopMatrix();
}

void SceneWidget::fly_animated(QImage* texture_qimg){
    glPushMatrix();
      glTranslatef(0, 1 * sin(threeSixtyTick * 8 * F_DEG_TO_RAD), 0 );
      glRotatef(threeSixtyTick * 2, 0, 1, 0);
      glScalef(0.5, 0.5, 0.5 );
      this->fly(texture_qimg, 135 + 10 * 4 * sin(threeSixtyTick * 8 * F_DEG_TO_RAD));
    glPopMatrix();
}

void SceneWidget::fly_animated_circular_motion(QImage* texture_qimg, GLfloat offset){
    glPushMatrix();
      glRotatef(this->threeSixtyTick + offset, 0, 1, 0);
      glTranslatef(0, 0, 5);
      glRotatef(-90, 0, 1, 0);
      this->fly_animated(texture_qimg);
    glPopMatrix();
}

void SceneWidget::pyramid_for_fly(){
    GLfloat normals[5][3] = {{0, -1, 0}, {0, 2, 1}, {-1, 2, 0}, {0, 2, -1}, {1, 2, 0}};

    // base
    glNormal3fv(normals[0]);
    glBegin(GL_POLYGON);
    glVertex3f(1, -2, 1);
    glVertex3f(1, -2, -1);
    glVertex3f(-1, -2, -1);
    glVertex3f(-1, -2, 1);
    glEnd();

    // triangle walls
    glNormal3fv(normals[1]);
    glBegin(GL_POLYGON);
    glVertex3f(0, 0, 0);
    glVertex3f(-1, -2, 1);
    glVertex3f(1, -2, 1);
    glEnd();

    glNormal3fv(normals[2]);
    glBegin(GL_POLYGON);
    glVertex3f(0, 0, 0);
    glVertex3f(-1, -2, -1);
    glVertex3f(-1, -2, 1);
    glEnd();

    glNormal3fv(normals[3]);
    glBegin(GL_POLYGON);
    glVertex3f(0, 0, 0);
    glVertex3f(1, -2, -1);
    glVertex3f(-1, -2, -1);
    glEnd();

    glNormal3fv(normals[4]);
    glBegin(GL_POLYGON);
    glVertex3f(0, 0, 0);
    glVertex3f(1, -2, 1);
    glVertex3f(1, -2, -1);
    glEnd();
}
