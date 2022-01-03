#include "SceneWidget.h"
#include "materials.h"
#include <GL/glu.h>

void SceneWidget::spider(){
    setMaterial(blackPlasticMaterial);

    // draw the butt
    glPushMatrix();
      glTranslatef(0, 0.2, 1);
      glRotatef(80, 1, 0, 0);
      glScalef(0.35, 0.5, 0.4);
      gluSphere(quadric, 2, 20, 20);
    glPopMatrix();


    //draw main body
    glPushMatrix();
      glScalef(0.6, 0.6, 0.8);
      gluSphere(quadric, 1, 20, 20);
    glPopMatrix();


    // draw legs

}

// leg consisting of two cylinders and one sphere joint
void SceneWidget::spider_leg(){
    gluSphere(quadric, 0.2, 20, 20);

    glPushMatrix();
      glRotatef(90, 0, 1, 0);
      glRotatef(30, 1, 0, 0);
      gluCylinder(quadric, 0.2, 0.2, 2, 20, 20);
    glPopMatrix();

    glPushMatrix();
      glRotatef(-90, 0, 1, 0);
      glRotatef(30, 1, 0, 0);
      gluCylinder(quadric, 0.2, 0.2, 2, 20, 20);
    glPopMatrix();
}

//slap an earth onto a sphere
void earth_textured_sphere(){

}
