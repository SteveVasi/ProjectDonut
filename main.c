#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"


int main() {

    // a circle of radius R1 centered at R2
    const float R1 = 1;
    const float R2 = 1;

    // distance from the viewer to donut
    const float K2 = 5;

    const int THETA_SPACING = 4;
    const int PHI_SPACING = 1;
    const int ROTATION_SPEED_A = 4;
    const int ROTATION_SPEED_B = 2;

    const int SCREEN_WIDTH = 30;
    const int SCREEN_HEIGHT = 30;

    // distance from eye to screen aka z'
    const float K1 = ((float) SCREEN_WIDTH) * 3.0f / (8.0f * (R1 + R2));

    // rotation
    int A = 55;
    int B = 55;


    // reciprocal z buffer (z⁽⁻¹⁾)
    // 0 means infinitely far away
    float **z_buff = (float **) malloc(SCREEN_HEIGHT * sizeof(float *));
    char **out_buff = (char **) malloc(SCREEN_HEIGHT * sizeof(char *));

    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        z_buff[i] = (float *) malloc(SCREEN_WIDTH * sizeof(float));
        out_buff[i] = (char *) malloc(SCREEN_WIDTH * sizeof(char));
    }


    while (1) {

        A += ROTATION_SPEED_A;
        B += ROTATION_SPEED_B;

        // create a donut using rotations. radius -> circle -> donut

        for (int _t = 0; _t < 360; _t += THETA_SPACING) {
            float theta = (float) _t;


            float circleX = R2 + R1 * cosf(theta);
            float circleY = R1 * sinf(theta);
            float circleZ = 0; // never used but for

            matrix4x4 torus = create_zero_matrix();
            torus.data[0][0] = circleX;
            torus.data[0][1] = circleY;


            for (int _p = 0; _p < 360; _p += PHI_SPACING) {
                float phi = (float) _p;


                // rotate circle around the y-axis and
                // rotate x-axis by A degrees
                // rotate y-axis by B degrees
                matrix4x4 rotator = rotate(A % 360, (float) phi, B % 360);
                matrix4x4 xyz = m_times_n(&torus, &rotator);

                float x = xyz.data[0][0];
                float y = xyz.data[0][1];
                float z = xyz.data[0][2];

                // x and y projection

                int xp = (int) (K1 * x / (K2 + z));
                int yp = (int) ( SCREEN_HEIGHT - 1 - (int)(K1 * y / (K2 + z)));

                // create surface normal
                matrix4x4 surface_normal = create_zero_matrix();
                surface_normal.data[0][0] = cosf((float) theta);
                surface_normal.data[0][1] = sinf((float) theta);

                // create light and calculate luminance by multiplying it with surface normal
                matrix4x4 light = create_zero_matrix();
                //light.data    -=+ 1 / sqrtf(2);
                light.data[1][0] = 0.70710678118f;
                light.data[2][0] = -0.70710678118f;

                float luminance = m_times_n(&surface_normal, &light).data[0][0];
                int isInBounds = xp >= 0 && xp < SCREEN_WIDTH && yp >= 0 && yp < SCREEN_HEIGHT && xp >= 0 && xp < SCREEN_WIDTH && yp >= 0 && yp < SCREEN_HEIGHT;


                if (luminance > 0 && isInBounds == 1) {
                    //print_matrix(&xyz);
                    if (1 / z > z_buff[xp][yp]) {
                        int luminance_index = (int) (10.0f * luminance);
                        out_buff[xp][yp] = ".,.~:;=!#$@"[luminance_index];
                    }
                }

            }

            printf("\x1b[H");
            for (int i = 0; i < SCREEN_HEIGHT; i++) {
                for (int j = 0; j < SCREEN_WIDTH; j++) {
                    putchar(out_buff[j][i]);
                }
                putchar('\n');
            }
        }



        // spin the donut around the x and z axes

        // project donut onto 2D screen

        // Determine illumination by calculating surface normal (given a light source)

        // ASCII luminance: .,.~:;=!#$@
    }


    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        free(z_buff[i]);
        free(out_buff[i]);
    }

    free(z_buff);
    free(out_buff);
}
