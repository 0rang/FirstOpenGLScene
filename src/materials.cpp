#include "materials.h"

void setMaterial(const materialStruct& mat){
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat.ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat.diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat.specular);
    glMaterialf(GL_FRONT, GL_SHININESS, mat.shininess);
}

materialStruct spiderWebMaterial = {
  { 0.4, 0.4, 0.4, 1},
  { 1.0, 0.9, 0.85, 1.0},
  { 1.0, 1.0, 1.0, 1.0},
  100.0
};

#pragma region materials from http://devernay.free.fr/cours/opengl/materials.ht

materialStruct brassMaterial = {
  { 0.33, 0.22, 0.03, 1.0},
  { 0.78, 0.57, 0.11, 1.0},
  { 0.99, 0.91, 0.81, 1.0},
  27.8
};


materialStruct obsidianMaterial = {
    {0.05375, 0.05, 0.06625, 1},
    {0.18275, 0.17, 0.22525, 1},
    {0.332741, 3286340., 0.34643, 1}, //{0.332741, 0.328634, 0.34643, 1}
    0.3
};

materialStruct spiderBodyMaterial = {
    {0.0, 0.0, 0.0, 1},
    {0.50, 0.25, 0.1, 1},
    {0.7, 0.7, 0.7, 1}, // {0.50, 0.50, 0.50, 1}
    100
};

//ambient only colours
materialStruct ambientRed = {
    {0, 0, 1, 1},
    {0, 0, 0, 1},
    {0, 0, 0, 0},
    0
};


materialStruct spiderLegsMaterial = {
    {0,	0,	0, 1},
    {0.50754,	0.25,	0.1, 1},
    {0.508273,	0.508273,	0.508273, 1},
    0.1
};

materialStruct whiteRubberMaterial = {
    {0.05,	0.05,	0.05},
    {0.5,	0.5,	0.5	},
    {0.7,	0.7,	0.7	},
    .078125
};

materialStruct rubyMaterial = {
    {0.1745,	0.01175,	0.01175}, //0.1745
    {0.61424,	0.04136,	0.04136},
    {1,	0.626959,	0.626959}, //{0.727811,	0.626959,	0.626959}
    0
};


#pragma endregion
