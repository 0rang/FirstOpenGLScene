#ifndef MATERIALS_H
#define MATERIALS_H

#include <GL/gl.h>

// Setting up material properties
typedef struct materialStruct {
  GLfloat ambient[4];
  GLfloat diffuse[4];
  GLfloat specular[4];
  GLfloat shininess;
} materialStruct;

extern void setMaterial(const materialStruct& mat);

extern materialStruct whiteShinyMaterial;

// materials from http://devernay.free.fr/cours/opengl/materials.ht

extern materialStruct brassMaterial;

extern materialStruct obsidianMaterial;

extern materialStruct blackPlasticMaterial;

//candidates for Spider Web

//bare colours
extern materialStruct ambientRed;

#endif // MATERIALS_H
