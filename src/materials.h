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

static materialStruct whiteShinyMaterials = {
  { 1.0, 1.0, 1.0, 1.0},
  { 1.0, 1.0, 1.0, 1.0},
  { 1.0, 1.0, 1.0, 1.0},
  100.0
};

#pragma region materials from http://devernay.free.fr/cours/opengl/materials.ht

static materialStruct brassMaterials = {
  { 0.33, 0.22, 0.03, 1.0},
  { 0.78, 0.57, 0.11, 1.0},
  { 0.99, 0.91, 0.81, 1.0},
  27.8
};


static materialStruct obsidianMaterial = {
    {0.05375, 0.05, 0.06625},
    {0.18275, 0.17, 0.22525},
    {0.332741, 0.328634, 0.34643},
    0.3
};

#pragma endregion


#endif // MATERIALS_H
