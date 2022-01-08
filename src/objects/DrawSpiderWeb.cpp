#include "SceneWidget.h"
#include "materials.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <cmath>
#include <QDebug>

static GLfloat strand_thickness = 0.1;
static GLuint num_strands = 8; // MAYBE: Refactor to num_edges
static GLfloat web_radius = 10;

void SceneWidget::spider_web(){
    setMaterial(spiderWebMaterial);

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
          polygon_from_cylinders(i); // use i to keep thickness the same as we scale up
        glPopMatrix();
    }
}


// length of octagon edges calulated by multiplying unit cylinders by this constant (based on cosine rule)
static GLfloat scale_factor = sqrt(                                                             // a^2 =
                                   2.                                                           // b^2 + c^2
                                   - 2.*cos(((1./(double)num_strands) * 360. * F_DEG_TO_RAD))   // - 2bccosA
                              );

void SceneWidget::polygon_from_cylinders(GLfloat radius_scale_compensation){
    setMaterial(spiderWebMaterial);

    // calculate the angles, lengths and postions of the polygon edges, and draw the cylinders
    for (GLuint i = 0; i < num_strands; i++) {
        glPushMatrix();
          GLfloat sector_angle = ((float)i / (float)num_strands) * (float)360;
          glRotatef(sector_angle, 0, 1, 0);

          glTranslatef(0, 0, 1);

          GLfloat interior_angle = ((num_strands - 2) * 180) / num_strands;
          glRotatef(180. - interior_angle/2., 0, 1, 0);
          glScalef(1, 1, scale_factor);
          gluCylinder(quadric, strand_thickness / radius_scale_compensation, strand_thickness/radius_scale_compensation, 1, 20, 20);
        glPopMatrix();
    }
}
