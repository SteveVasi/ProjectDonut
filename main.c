#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "math/matrix.h"
#include "buffer.h"
#include "screen.h"
#include "math/vector3.h"

int main() {
    // a circle of radius R1 centered at R2
    const float R1 = 1;
    const float R2 = 1;

    // distance from the viewer to donut
    const float K2 = 10;


    static const int SCREEN_WIDTH = 15 * 3; // x
    static const int SCREEN_HEIGHT = 15; // y
    vector2_int screen_dimensions = {.x = SCREEN_WIDTH, .y = SCREEN_HEIGHT};

    // distance from eye to screen aka z'
    const float K1 = ((float) screen_dimensions.x) * K2 * 3.0f / (8.0f * (R1 + R2));

    // rotation
    int A = 55;
    int B = 55;


    screen screen = create_screen(screen_dimensions);

    // reciprocal z buffer (z⁽⁻¹⁾)
    // 0 means infinitely far away


    while (1) {
        const int THETA_SPACING = 4;
        const int PHI_SPACING = 1;
        const int ROTATION_SPEED_A = 4;
        const int ROTATION_SPEED_B = 2;

        resetScreen(&screen);


        A += ROTATION_SPEED_A;
        B += ROTATION_SPEED_B;

        // create a donut using rotations. radius -> circle -> donut

        for (int _t = 0; _t < 360; _t += THETA_SPACING) {
            float theta = (float) _t;


            vector3_f circle = {
                .x = R2 + R1 * cosf(theta),
                .y = R1 * sinf(theta),
                .z = 0.0f
            };

            matrix4x4 torus = create_zero_matrix();
            // TODO make a function instead of direct access of members
            torus.data[0][0] = circle.x;
            torus.data[0][1] = circle.y;

            for (int _p = 0; _p < 360; _p += PHI_SPACING) {
                float phi = (float) _p;


                // rotate circle around the y-axis and
                // rotate x-axis by A degrees
                // rotate y-axis by B degrees
                matrix4x4 rotator = rotate(A % 360, phi, B % 360);
                matrix4x4 xyz = m_times_n(&torus, &rotator);

                vector3_f torusSurface = {
                    .x = xyz.data[0][0],
                    .y = xyz.data[0][1],
                    .z = xyz.data[0][2]
                };

                // x and y projection
                vector2_int projection = {
                    .x = (int) ((float) screen_dimensions.x / 2 + K1 * torusSurface.x / torusSurface.z),
                    .y = (int) (screen_dimensions.y / 2 - 1 - (int) (K1 * torusSurface.y / torusSurface.z))
                };

                // create surface normal
                matrix4x4 surface_normal = create_zero_matrix();
                surface_normal.data[0][0] = cosf(theta);
                surface_normal.data[0][1] = sinf(theta);

                // create light and calculate luminance by multiplying it with surface normal
                matrix4x4 light = create_zero_matrix();
                // light.data is equal to plus and minus inverse square root of 2;
                light.data[1][0] = 0.70710678118f;
                light.data[2][0] = -0.70710678118f;

                float luminance = getLuminance(&surface_normal, &light);
                int hasLight = hasLight(&surface_normal, &light);


                vector3_int point = {.x = projection.x, .y = projection.y, .z = torusSurface.z};
                if (hasLight && isInBounds(&point, &screen) && isClosest(&point, &screen)) {
                    int luminance_index = (int) (10.0f * luminance);
                    screen.frame_buffer.buffer[projection.y][projection.x] = ".,.~:;=!#$@"[luminance_index];
                }
            }
        }

        printf("\x1b[H");
        showScreen(&screen);

        sleep(1000);
    }


    // spin the donut around the x and z axes

    // project donut onto 2D screen

    // Determine illumination by calculating surface normal (given a light source)

    // ASCII luminance: .,.~:;=!#$@
}
