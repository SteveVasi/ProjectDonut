
#include "matrix.h"

#include <string.h>
#include <stdio.h>
#include <math.h>

matrix4x4 create_identity() {
    matrix4x4 identity;
    memset(identity.data, 0, sizeof(identity.data));

    identity.data[0] = 1.0f;
    identity.data[5] = 1.0f;
    identity.data[10] = 1.0f;
    identity.data[15] = 1.0f;

    return identity;
}
//sinf, cosf
void rotate_x(matrix4x4* matrix, float degree) {
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