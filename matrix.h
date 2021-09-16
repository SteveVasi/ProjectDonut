
#ifndef DONUT_MATRIX_H
#define DONUT_MATRIX_H

typedef struct matrix4x4_t {
    float data[16];
} matrix4x4;

matrix4x4 create_identity();

void rotate(matrix4x4* matrix, float x_degree, float y_degree, float z_degree);

void rotate_x(matrix4x4* matrix, float degree);
void rotate_y(matrix4x4* matrix, float degree);
void rotate_z(matrix4x4* matrix, float degree);

void print_matrix(matrix4x4* matrix);

#endif //DONUT_MATRIX_H