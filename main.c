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

            vector2_f torus_circle;
            torus_circle.x = R2 + R1 * cosf(theta);
            torus_circle.y = R1 * sinf(theta);
            
            
            for (int _p = 0; _p < 360; _p += PHI_SPACING) {
                float phi = (float) _p;
                
                //torus torus = create_torus(torus_circle, );

                // rotate circle around the y-axis and
                // rotate x-axis by A degrees
                // rotate y-axis by B degrees
                matrix4x4 rotator = rotate(A % 360, phi, B % 360);
                matrix4x4 xyz = v2_times_n(&torus_circle, &rotator);

                vector3_f torusSurface = {
                    .x = xyz.data[0][0],
                    .y = xyz.data[0][1],
                    .z = xyz.data[0][2]
                };

                // x and y projection
                vector2_int projection = {
                    .x = (int) ((float) screen_dimensions.x / 2 + K1 * torusSurface.x / torusSurface.z),
                    .y = (int) ((float) screen_dimensions.y / 2 - 1 - (int) (K1 * torusSurface.y / torusSurface.z))
                };

                // create surface normal
                matrix4x4 surface_normal = create_zero_matrix();
                surface_normal.data[0][0] = cosf(theta);
                surface_normal.data[0][1] = sinf(theta);

                // create light and calculate luminance by multiplying it with surface normal
                vector3_f light = create_light(create_vector3_f(0, 1, -1));

                float luminance = getLuminance(&surface_normal, &light);


                vector3_int point = {.x = projection.x, .y = projection.y, .z = torusSurface.z};
                if (hasLight(&surface_normal, &light) && isClosest(&point, &screen)) {
                    int luminance_index = (int) (10.0f * luminance);
                    screen.frame_buffer.buffer[projection.y][projection.x] = screen.pixelValues[luminance_index];
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
