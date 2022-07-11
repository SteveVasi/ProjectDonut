
#include <stdlib.h>
#include <math.h>
#include "matrix.h"

int main() {

    float K1 = 50; // distance from eye to screen aka z'
    // a circle of radius R1 centered at R2
    float R1 = 3;
    float R2 = 5;

    for (int theta = 0; theta < 360; ++theta) {

        matrix4x4 t = create_zero_matrix();
        t.data[0][0] = R2 + R1 * cosf((float) theta);
        t.data[1][0] = R1 * sinf((float) theta);

        for (int phi = 0; phi < 360; ++phi) {

        }
    }



    // reciprocal z buffer (z⁽⁻¹⁾)
    // 0 means infinitely far away
    char z_rec_buffer[60][60] = {0};

    // create a donut by rotating about the y axis

    // spin the donut around the x and z axes

    // project donut onto 2D screen

    // Determine illumination by calculating surface normal (given a light source)

    // ASCII luminance: .,.~:;=!#$@

    return 0;
}
