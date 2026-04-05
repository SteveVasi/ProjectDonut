#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "buffer.h"
#include "screen.h"
#include "math/matrix.h"
#include "math/vector3.h"
#include "objects.h"

int main() {
    // a circle of radius R1 centered at R2
    const float R1 = 1;
    const float R2 = 1;

    // distance from the viewer to donut
    const float K2 = 10;


    static const int SCREEN_WIDTH = 80; // x
    static const int SCREEN_HEIGHT = 22; // y
    vector2_int screen_dimensions = {.x = SCREEN_HEIGHT, .y = SCREEN_WIDTH};

    // distance from eye to screen aka z'
    const float K1 = ((float) screen_dimensions.y) * K2 * 3.0f / (8.0f * (R1 + R2));

    // rotation
    float x_rotation = 0.0f;
    float y_rotation = 0.0f;


    screen screen = create_screen(screen_dimensions);

    // reciprocal z buffer (z⁽⁻¹⁾)
    // 0 means infinitely far away

    const float THETA_SPACING = 4 * M_PI / 180.0f;
    const float PHI_SPACING = 1 * M_PI / 180.0f;
    const float ROTATION_SPEED_X = 4 * M_PI / 180.0f;
    const float ROTATION_SPEED_Y = 2 * M_PI / 180.0f;

    while (1) {
        resetScreen(&screen);


        x_rotation += ROTATION_SPEED_X;
        y_rotation += ROTATION_SPEED_Y;

        // create a donut using rotations. radius -> circle -> donut

        for (float theta = 0; theta < M_PI * 2; theta += THETA_SPACING) {

            // we draw the circle by rotating around the angle theta
            vector2_f torus_circle = {
            R2 + R1 * cosf(theta),
            R1 * sinf(theta)
            };

            for (float phi = 0; phi < M_PI * 2; phi += PHI_SPACING) {

                // we draw the torus by rotating the circle around the angle phi
                torus torus = create_torus(torus_circle, (vector3_f){0, 0, 0});

                // rotate circle around the y-axis and
                // rotate x-axis by A degrees
                // rotate y-axis by B degrees
                matrix4x4 rotator = rotate(x_rotation, phi, y_rotation);
                matrix4x4 xyz = v2_times_n(&torus.circle, &rotator);

                vector3_f torusSurface = {
                    .x = xyz.data[0][0],
                    .y = xyz.data[0][1],
                    .z = xyz.data[0][2]
                };

                // x and y projection
                vector2_int projection = {
                    .x = (int) ((float) screen_dimensions.x / 2 + K1 * torusSurface.x / (torusSurface.z + K2)),
                    .y = (int) ((float) screen_dimensions.y / 2 + K1 * torusSurface.y / (torusSurface.z + K2))
                };

                // create surface normal
                vector3_f surface_normal = {
                    .x = cosf(theta),
                    .y = sinf(theta),
                    .z = 0
                };
                surface_normal = vector3_times_matrix(&surface_normal, &rotator);

                // create light and calculate luminance by multiplying it with surface normal
                vector3_f light = create_light(create_vector3_f(0, 1, -1));

                float luminance = getLuminance(&surface_normal, &light);


                vector3_f point = {.x = projection.x, .y = projection.y, .z = torusSurface.z};
                if (
                    isInBounds(&point, &screen) &&
                    hasLight(&surface_normal, &light) &&
                    isClosest(&point, &screen)
                    ) {
                    int luminance_index = (int) (10.0f * luminance);
                    screen.frame_buffer.buffer[projection.x][projection.y] = screen.pixelValues[luminance_index];
                    screen.zBuffer.buffer[projection.x][projection.y] = point.z;
                }
            }
        }

        printScreen(&screen);

        //sleep(1);
    }


    // spin the donut around the x and z axes

    // project donut onto 2D screen

    // Determine illumination by calculating surface normal (given a light source)

    // ASCII luminance: .,.~:;=!#$@
}
