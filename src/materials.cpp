#include "materials.h"

void setMaterial(const materialStruct& mat){
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat.ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat.diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat.specular);
    glMaterialf(GL_FRONT, GL_SHININESS, mat.shininess);
}

materialStruct whiteShinyMaterial = {
  { 1.0, 1.0, 1.0, 1.0},
  { 1.0, 1.0, 1.0, 1.0},
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
    {0.332741, 0.328634, 0.34643, 1},
    0.3
};

materialStruct blackPlasticMaterial = {
    {0.0, 0.0, 0.0, 1},
    {0.01, 0.01, 0.01, 1},
    {0.50, 0.50, 0.50, 1},
        .25
};

//ambient only colours
materialStruct ambientRed = {
    {0, 0, 1, 1},
    {0, 0, 0, 1},
    {0, 0, 0, 0},
    0
};


materialStruct silverMaterial = {
    {0.19225,	0.19225,	0.19225},
    {0.50754,	0.50754,	0.50754},
    {0.508273,	0.508273,	0.508273},
    0.4
};

materialStruct whiteRubberMaterial = {
    {0.05,	0.05,	0.05},
    {0.5,	0.5,	0.5	},
    {0.7,	0.7,	0.7	},
    .078125
};




#pragma endregion
