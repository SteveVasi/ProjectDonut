#pragma once

#include "math/vector2.h"

#ifndef DONUT_Z_BUFFER_H
#define DONUT_Z_BUFFER_H

typedef struct z_buffer_t {
    vector2_int dimensions;
    // reciprocal z buffer (z⁽⁻¹⁾)
    // 0 means infinitely far away
    float **buffer;
} z_buffer;

typedef struct frame_buffer_t {
    vector2_int dimensions;
    char **buffer;
} frame_buffer;

z_buffer initialize_zBuffer(vector2_int dimensions);

frame_buffer initialize_frameBuffer(vector2_int dimensions);

void reset_zBuffer(z_buffer *zBuffer, float value);
void reset_frameBuffer(frame_buffer *frameBuffer);

void print_frameBuffer(frame_buffer *frameBuffer);
int z_buffer_get_pixel(z_buffer *buffer, vector2_int coords);




#endif //DONUT_Z_BUFFER_H
