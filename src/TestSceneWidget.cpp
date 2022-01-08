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


void SceneWidget::test_textured_cube(){

    glPushMatrix();

      glTranslatef(0, 1, 0);


      this->textured_cube(this->marcQimg);

      glTranslatef(0, 2, 0);

      this->textured_cube(this->markusQimg);

      glTranslatef(0, 2, 0);


      this->textured_cube(this->earthQimg);
    glPopMatrix();
}
