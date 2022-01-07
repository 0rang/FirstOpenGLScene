#include "SceneWidget.h"
#include "materials.h"
#include <GL/glu.h>

void SceneWidget::test_pyramid(){
    this->pyramid();
    glPushMatrix();
     glTranslatef(1, 0, -4);
     this->pyramid();
    glPopMatrix();
}

void SceneWidget::test_earth_textured_sphere(){

}

void SceneWidget::test_textured_cube(){

}


// RGB for positive d
void SceneWidget::highlight_axes(){
    GLUquadric* quadric = gluNewQuadric();

    float axes_length = 5;
}
