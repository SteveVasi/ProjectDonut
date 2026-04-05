#ifndef SCREEN_H
#define SCREEN_H

#include "buffer.h"
#include "objects.h"
#include "math/matrix.h"
#include "math/vector2.h"
#include "math/vector3.h"

typedef struct screen_t {
    z_buffer zBuffer;
    frame_buffer frame_buffer;
    vector2_int dimensions;
    char* pixelValues;
} screen;

screen create_screen(vector2_int dimensions);
int isInBounds(vector3_f *point, screen *screen);
int isClosest(vector3_f *point, screen *screen);
void printScreen(screen *screen);
void resetScreen(screen *screen);
float getLuminance(vector3_f *surface_normal, vector3_f *light);
int hasLight(vector3_f *surface_normal, vector3_f *light);

inline int isVisible(vector3_f *point, screen *screen) {
    return isInBounds(point, screen) && isClosest(point, screen);
}

#endif //SCREEN_H
