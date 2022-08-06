
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "matrix.h"



// a circle of radius R1 centered at R2
const float R1 = 3;
const float R2 = 5;

// distance from eye to screen aka z'
const float K1 = 50;
// distance from the viewer to donut
const float K2 = 100;

const int THETA_SPACING = 4;
const int PHI_SPACING = 1;
const int BUFFER_SIZE = 60;

const float A = 55;
const float B = 55;

int main() {

    // reciprocal z buffer (z⁽⁻¹⁾)
    // 0 means infinitely far away
    float zm1[BUFFER_SIZE][BUFFER_SIZE];
    char out[BUFFER_SIZE][BUFFER_SIZE];

    memset(zm1, INFINITY, sizeof (float) * BUFFER_SIZE * BUFFER_SIZE);
    memset(zm1, ' ', sizeof (float) * BUFFER_SIZE * BUFFER_SIZE);


    // create a donut using rotations. radius -> circle -> donut

    for (int theta = 0; theta < 360; theta += THETA_SPACING) {

        matrix4x4 t = create_zero_matrix();
        t.data[0][0] = R2 + R1 * cosf((float) theta);
        t.data[1][0] = R1 * sinf((float) theta);

        for (int phi = 0; phi < 360; phi += PHI_SPACING) {

            // rotate circle around the y-axis and
            // rotate x-axis by A degrees
            // rotate y-axis by B degrees
            matrix4x4 rotator = rotate(A, (float) phi, B);

        }
    }

    // spin the donut around the x and z axes

    // project donut onto 2D screen

    // Determine illumination by calculating surface normal (given a light source)

    // ASCII luminance: .,.~:;=!#$@

    return 0;
}
