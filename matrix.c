
#include "matrix.h"

#include <string.h>
#include <stdio.h>
#include <math.h>

// additive identity
matrix4x4 create_zero_matrix(){
    matrix4x4 identity;
    memset(identity.data, 0, sizeof(identity.data));
    return identity;
}

//multiplicative identity
matrix4x4 create_identity() {
    matrix4x4 identity = create_zero_matrix();

    identity.data[0] = 1.0f;
    identity.data[5] = 1.0f;
    identity.data[10] = 1.0f;
    identity.data[15] = 1.0f;

    return identity;
}



int getIndex(int x, int y){
    return x + y * 4;
}


matrix4x4 m_times_n(matrix4x4* m, matrix4x4* n){
    matrix4x4 helper = create_zero_matrix();

    // row times column
    // https://www.researchgate.net/figure/Pseudocode-for-matrix-multiplication_fig3_258926922#:~:text=Matrix%20multiplication%20is%20a%20computationally,processing%2C%20graphics%20and%20robotic%20applications.

    // maybe make function to get vector of length 4

    // TODO make this work

    for (int y = 0; y < 4; ++y) {
        for (int x = 0; x < 4; ++x) {
            helper.data[getIndex(x, y)] = m->data[4*y + x] * n->data[4*x + y];
        }
    }

    return helper;
}

//sinf, cosf
void rotate_x(matrix4x4* matrix, float degree) {
    matrix4x4 rotational = create_identity();

    rotational.data[getIndex(1,1)] = cosf(degree);
    rotational.data[getIndex(2,1)] = -sinf(degree);
    rotational.data[getIndex(1,3)] = sinf(degree);
    rotational.data[getIndex(3,3)] = cosf(degree);

    *matrix = m_times_n(matrix, &rotational);

    return;
}



void print_matrix(matrix4x4 *matrix) {
    if(matrix == NULL)
        return;

    printf("-----------------------------\n");
    for (int i = 0; i < 16; i += 4) {
        printf("| %.2f | %.2f | %.2f | %.2f |\n",
               matrix->data[i],             // (*matrix).data[i] == matrix->data[i]
               matrix->data[i + 1],
               matrix->data[i + 2],
               matrix->data[i + 3]);
        printf("-----------------------------\n");
    }
}