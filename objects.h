#pragma once

#include "math/matrix.h"
#include "math/vector3.h"

#ifndef OBJECTS_H
#define OBJECTS_H

typedef struct torus_t {
    // draw a 2D circle around some point in 3D space, 
    // and then rotate it around the central axis of the torus
    vector3_f axis;
    vector2_f circle;
} torus;

typedef vector2_f circle;


vector3_f create_light(vector3_f direction);
vector2_f create_circle(vector2_f point);
torus create_torus(vector2_f circle, vector3_f position);


#endif