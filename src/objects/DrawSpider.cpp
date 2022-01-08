#include "SceneWidget.h"
#include "materials.h"
#include <GL/glu.h>

void SceneWidget::spider(){
    setMaterial(spiderBodyMaterial);

    // draw the butt
    glPushMatrix();
      glTranslatef(0, 0.2, 1.5);
      glRotatef(80, 1, 0, 0);
      glScalef(0.35, 0.5, 0.4);
      gluSphere(quadric, 2, 20, 20);
    glPopMatrix();


    // draw main body
    glPushMatrix();
      glScalef(0.6, 0.6, 0.8);
      gluSphere(quadric, 1, 20, 20);
    glPopMatrix();


    // draw eyes
    setMaterial(rubyMaterial);
    glPushMatrix();
      glTranslatef(0.3, 0.7, -0.5);
      glRotatef(160, 1, 0, 0);
      glScalef(0.2, 0.2, 0.2);
      this->pyramid();
    glPopMatrix();
    glPushMatrix();
      glTranslatef(-0.3, 0.7, -0.5);
      glRotatef(160, 1, 0, 0);
      glScalef(0.2, 0.2, 0.2);
      this->pyramid();
    glPopMatrix();


    // draw legs
    {
        setMaterial(spiderLegsMaterial);
        // front legs
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

        // middle front legs
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

        // middle rear legs
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


        // rear legs
        glPushMatrix();
        glTranslatef(0.8, 0.65 ,0.6);
        glRotatef(140, 0, 1, 0);
        glScalef(0.5, 0.5, 0.35);
        spider_leg(2, 50, 2, 50);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-0.8, 0.65 ,0.6);
        glRotatef(50, 0, 1, 0);
        glScalef(0.5, 0.5, 0.35);
        spider_leg(2, 50, 2, 50);
        glPopMatrix();
    }


}

// leg consisting of two cylinders and one sphere joint
void SceneWidget::spider_leg(float base_length, float base_angle, float tip_length, float tip_angle){
    // "knee"
    gluSphere(quadric, 0.2, 20, 20);

    // "thigh"
    glPushMatrix();
      glRotatef(90, 0, 1, 0);
      glRotatef(base_angle, 1, 0, 0);
      gluCylinder(quadric, 0.2, 0.2, base_length, 20, 20);
    glPopMatrix();

    // "calf"
    glPushMatrix();
      glRotatef(-90, 0, 1, 0);
      glRotatef(tip_angle, 1, 0, 0);
      gluCylinder(quadric, 0.2, 0, tip_length, 20, 20);
    glPopMatrix();
}

void SceneWidget::spider_circular_motion(){
    glPushMatrix();
      glRotatef(this->threeSixtyTick, 0, 1, 0);
      glTranslatef(0, 0, 5);
      glRotatef(-90, 0, 1, 0);
      this->spider();
    glPopMatrix();
}
