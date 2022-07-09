
#include "matrix.h"

#include <string.h>
#include <stdio.h>
#include <math.h>


// additive identity
matrix4x4 create_zero_matrix() {
    matrix4x4 identity;
    memset(identity.data, 0, sizeof(identity.data));
    return identity;
}

//multiplicative identity
matrix4x4 create_identity() {
    matrix4x4 identity = create_zero_matrix();

    identity.data[0][0] = 1.0f;
    identity.data[1][1] = 1.0f;
    identity.data[2][2] = 1.0f;
    identity.data[3][3] = 1.0f;

    return identity;
}

matrix4x4 m_times_n(matrix4x4 *m, matrix4x4 *n) {
    matrix4x4 helper = create_zero_matrix();

    // row times column
    // https://www.researchgate.net/figure/Pseudocode-for-matrix-multiplication_fig3_258926922#:~:text=Matrix%20multiplication%20is%20a%20computationally,processing%2C%20graphics%20and%20robotic%20applications.

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                helper.data[i][j] += m->data[i][k] * n->data[k][j];
            }
        }
    }

    return helper;
}

//sinf, cosf
void rotate_x(matrix4x4 *matrix, float degree) {
    matrix4x4 rotational = create_identity();

    rotational.data[1][1] = cosf(degree);
    rotational.data[1][2] = -sinf(degree);
    rotational.data[2][1] = sinf(degree);
    rotational.data[2][2] = cosf(degree);

    *matrix = m_times_n(matrix, &rotational);

    printf("rotated matrix is: \n");
    print_matrix(matrix);

    return;
}


void print_matrix(matrix4x4 *matrix) {
    if (matrix == NULL)
        return;


/*
    printf("-----------------------------\n");
    for (int i = 0; i < 16; i += 4) {
        printf("| %.2f | %.2f | %.2f | %.2f |\n",
               matrix->data[i],             // (*matrix).data[i] == matrix->data[i]
               matrix->data[i + 1],
               matrix->data[i + 2],
               matrix->data[i + 3]);
        printf("-----------------------------\n");
    }
*/

    printf("-----------------------------\n");
    for (int i = 0; i < 4; ++i) {
        printf("| %.2f | %.2f | %.2f | %.2f |\n",
              matrix->data[i][0],             // (*matrix).data[i] == matrix->data[i]
              matrix->data[i][1],
              matrix->data[i][2],
              matrix->data[i][3]);
        printf("-----------------------------\n");
    }

}