
#include "matrix.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "vector2.h"


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

void print_matrix(matrix4x4 *matrix) {
    if (matrix == NULL)
        return;

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

// Operations on matrices

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

matrix4x4 v2_times_n(vector2_f *m, matrix4x4 *n) {
    matrix4x4 helper = create_zero_matrix();
    helper.data[0][0] = m->x;
    helper.data[0][1] = m->y;
    return m_times_n(&helper, n);
}

matrix4x4 m_plus_n(matrix4x4* m, matrix4x4* n){
    // TODO: implement
}


// transformational matrices

matrix4x4 rotate_x(float degree) {
    matrix4x4 rotational = create_identity();

    rotational.data[1][1] = cosf(degree);
    rotational.data[1][2] = -sinf(degree);
    rotational.data[2][1] = sinf(degree);
    rotational.data[2][2] = cosf(degree);

    return rotational;
}

matrix4x4 rotate_y(float degree) {
    matrix4x4 rotational = create_identity();

    rotational.data[0][0] = cosf(degree);
    rotational.data[0][2] = -sinf(degree);
    rotational.data[2][1] = sinf(degree);
    rotational.data[2][2] = cosf(degree);

    return rotational;
}

matrix4x4 rotate_z(float degree) {
    matrix4x4 rotational = create_identity();

    rotational.data[0][0] = cosf(degree);
    rotational.data[0][1] = -sinf(degree);
    rotational.data[1][0] = sinf(degree);
    rotational.data[1][1] = cosf(degree);

    return rotational;
}

matrix4x4 rotate(float x_degree, float y_degree, float z_degree){
    matrix4x4 x_rotator = rotate_x(x_degree);
    matrix4x4 y_rotator = rotate_y(y_degree);
    matrix4x4 z_rotator = rotate_z(z_degree);
    matrix4x4 xy_rotator = m_times_n(&x_rotator, &y_rotator);
    matrix4x4 xyz_rotator = m_times_n(&xy_rotator, &z_rotator);

    return xyz_rotator;
}


matrix4x4 translate(float x, float y, float z) {
    matrix4x4 translator = create_identity();

    translator.data[0][3] = x;
    translator.data[1][3] = y;
    translator.data[2][3] = z;

    return translator;
}

matrix4x4 scale(matrix4x4 *matrix4X4, float x, float y, float z) {
    matrix4x4 scaler = create_identity();

    scaler.data[0][0] = x;
    scaler.data[1][1] = y;
    scaler.data[2][2] = z;

    return scaler;
}

