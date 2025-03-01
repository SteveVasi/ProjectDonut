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
int isInBounds(vector3_int *point, screen *screen) {
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
int isClosest(vector3_int *point, screen *screen) {
    return point->z > screen->zBuffer.buffer[point->x][point->y];
}
float getLuminance(matrix4x4 *surface_normal, light *l) {
    matrix4x4 light_matrix = v3f_to_matrix(l);
    return m_times_n(surface_normal, l).data[0][0];
}

int hasLight(matrix4x4 *surface_normal, light *l) {
    return getLuminance(surface_normal, l) > 0;
}

void printCharBuffer(screen *screen) {
    for (int i = 0; i < screen->dimensions.x; i++) {
        for (int j = 0; j < screen->dimensions.y; j++) {
            putchar(screen->frame_buffer.buffer[i][j]);
        }
        putchar('\n');
    }
}

void showScreen(screen *screen) {
    print_frameBuffer(&screen->frame_buffer);
}


void resetScreen(screen *screen) {
    reset_zBuffer(&screen->zBuffer, 0.0f);
    reset_frameBuffer(&screen->frame_buffer);
}
