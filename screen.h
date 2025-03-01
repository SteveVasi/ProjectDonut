#include "buffer.h"
#include "math/matrix.h"
#include "math/vector2.h"
#include "math/vector3.h"

#ifndef SCREEN_H
#define SCREEN_H

typedef struct screen_t {
    z_buffer zBuffer;
    frame_buffer frame_buffer;
    vector2_int dimensions;
    char* pixelValues;
} screen;

screen create_screen(vector2_int dimensions);
int isInBounds(vector3_int *point, screen *screen);
int isClosest(vector3_int *point, screen *screen);
void showScreen(screen *screen);
void resetScreen(screen *screen);
float getLuminance(matrix4x4 *surface_normal, vector3_f *light);
int hasLight(matrix4x4 *surface_normal, matrix4x4 *light);

inline int isVisible(vector3_int *point, screen *screen) {
    return isInBounds(point, screen) && isClosest(point, screen);
}

#endif //SCREEN_H
