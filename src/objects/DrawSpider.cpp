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

    glPushMatrix();
      glTranslatef(0.8, 0.2 ,-0.4);
      glRotatef(-170, 0, 1, 0);
      glScalef(0.25, 0.25, 0.2);
      spider_leg();
    glPopMatrix();
    glPushMatrix();
      glTranslatef(-0.8, 0.2 ,-0.4);
      glRotatef(-10, 0, 1, 0);
      glScalef(0.25, 0.25, 0.2);
      spider_leg();
    glPopMatrix();

    // middle legs
    glPushMatrix();
      glTranslatef(0.5, 0.2 ,-.9);
      glRotatef(-120, 0, 1, 0);
      glScalef(0.35, 0.35, 0.35);
      spider_leg();
    glPopMatrix();
    glPushMatrix();
      glTranslatef(-0.5, 0.2 ,-.9);
      glRotatef(-60, 0, 1, 0);
      glScalef(0.35, 0.35, 0.35);
      spider_leg();
    glPopMatrix();

    //middle rear legs
    glPushMatrix();
      glTranslatef(0.8, 0.2 ,-0);
      glRotatef(170, 0, 1, 0);
      glScalef(0.25, 0.25, 0.2);
      spider_leg();
    glPopMatrix();
    glPushMatrix();
      glTranslatef(-0.8, 0.2 ,-0);
      glRotatef(10, 0, 1, 0);
      glScalef(0.25, 0.25, 0.2);
      spider_leg();
    glPopMatrix();

//    glPushMatrix();
//      glTranslatef();


}

// leg consisting of two cylinders and one sphere joint
void SceneWidget::spider_leg(float base_length, float base_angle, float tip_length, float tip_angle){
    setMaterial(silverMaterial);

    gluSphere(quadric, 0.2, 20, 20);

    glPushMatrix();
      glRotatef(90, 0, 1, 0);
      glRotatef(base_angle, 1, 0, 0);
      gluCylinder(quadric, 0.2, 0.2, base_length, 20, 20);
    glPopMatrix();

    glPushMatrix();
      glRotatef(-90, 0, 1, 0);
      glRotatef(tip_angle, 1, 0, 0);
      gluCylinder(quadric, 0.2, 0, tip_length, 20, 20);
    glPopMatrix();
}

//slap an earth onto a sphere
void earth_textured_sphere(){

}
