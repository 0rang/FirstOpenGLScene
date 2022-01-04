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

extern materialStruct spiderWebMaterial;

// materials from http://devernay.free.fr/cours/opengl/materials.html

extern materialStruct brassMaterial;

extern materialStruct obsidianishMaterial;

extern materialStruct spiderBodyMaterial;

//Spider Web?

extern materialStruct whiteRubberMaterial;

//Spider Legs?

extern materialStruct spiderLegsMaterial;

// Spider Eyes?

extern materialStruct rubyMaterial;



#endif // MATERIALS_H
