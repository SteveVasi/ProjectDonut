#include "screen.h"
#include <stdio.h>
#include "objects.h"
#include "math/matrix.h"
#include "math/vector3.h"
#include "math/vector2.h"

char* getPixelValues() {
    return ".,.~:;=!#$@";
}

screen create_screen(vector2_int dimensions) {
    screen screen;

    screen.dimensions = dimensions;
    screen.zBuffer = initialize_zBuffer(dimensions);
    // reciprocal z buffer (z⁽⁻¹⁾)
    // 0 means infinitely far away
    screen.frame_buffer = initialize_frameBuffer(dimensions);
    screen.pixelValues = getPixelValues();

    return screen;
}

//int isInBounds = xp >= 0 && xp < SCREEN_WIDTH && yp >= 0 && yp < SCREEN_HEIGHT;
//int isNearest = isInBounds ? (z > z_buff[yp][xp]) : 0;

// pre: projection vorher
int isInBounds(vector3_f *point, screen *screen) {
    return point->x >= 0 && point->x < screen->dimensions.x
           && point->y >= 0 && point->y < screen->dimensions.y;
}


// pre: projection vorher
/**
 *
 * @param point pre: point has to be projected
 * @param screen
 * @return int bool
 */
int isClosest(vector3_f *point, screen *screen) {
    return point->z > screen->zBuffer.buffer[(int)point->x][(int)point->y];
}
float getLuminance(vector3_f *surface_normal, vector3_f *light) {
    return dot(surface_normal, light);
}

int hasLight(vector3_f *surface_normal, vector3_f *light) {
    return getLuminance(surface_normal, light) > 0;
}


void printScreen(screen *screen) {
    printf("\x1b[2J");
    print_frameBuffer(&screen->frame_buffer);
    printf("\x1b[H");
}


void resetScreen(screen *screen) {
    reset_zBuffer(&screen->zBuffer, 0.0f);
    reset_frameBuffer(&screen->frame_buffer);
}
