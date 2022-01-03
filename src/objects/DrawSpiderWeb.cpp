#include "SceneWidget.h"
#include "materials.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <cmath>

static GLfloat strand_thickness = 0.1;
static GLuint num_strands = 8;
static GLfloat web_radius = 10;

void SceneWidget::spider_web(){
    setMaterial(whiteShinyMaterial);

    gluSphere(quadric, strand_thickness, 20, 20);

    // create web strands as 8 cylinders connected at the centre and pointing outwards
    for (GLuint i = 0; i < num_strands; i++) {
        GLfloat angle = ((float)i / (float)num_strands) * (float)360;

        glPushMatrix();
          glRotatef(angle, 0, 1, 0);
          gluCylinder(quadric, strand_thickness, strand_thickness, web_radius, 20, 20);
        glPopMatrix();
    }

    // draw hollow octagons scaled out in intervals up to the edges of the web
    for (GLuint i = 1; i < web_radius + 1; i++) {
        glPushMatrix();
          glScalef(i, 1, i);
          octagon_from_cylinders(i);
        glPopMatrix();
    }
}


// length of octagon edges calulated by multiplying unit cylinders by this constant (based on cosine rule)
static GLfloat scale_factor = sqrt(2 - 2*cosf((1./num_strands) * 360.));
void SceneWidget::octagon_from_cylinders(GLfloat radius_scale_compensation){
    setMaterial(whiteShinyMaterial);

    GLfloat scale_factor = sqrt(2. - sqrt(2.));
    for (GLuint i = 0; i < num_strands; i++) {
        glPushMatrix();
          // calculate the angle of
          GLfloat angle = ((float)i / (float)num_strands) * (float)360;
          glRotatef(angle, 0, 1, 0);

          glTranslatef(0, 0, 1);
          // MAYBE: De-hardcode this angle, here's my last attempt 180.-((180.-(((float)1 / (float)num_strands) * (float)360))/2.)
          glRotatef(112.5, 0, 1, 0);
          glScalef(1, 1, scale_factor);
          gluCylinder(quadric, strand_thickness / radius_scale_compensation, strand_thickness/radius_scale_compensation, 1, 20, 20);
        glPopMatrix();
    }
}
