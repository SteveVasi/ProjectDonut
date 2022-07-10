
#ifndef DONUT_MATRIX_H
#define DONUT_MATRIX_H

typedef struct matrix4x4_t {
    // 3x3 homogeneous coordinates
    float data[4][4];
} matrix4x4;


// no side effects, pure functions
matrix4x4 create_identity();
matrix4x4 rotate(float x_degree, float y_degree, float z_degree);
matrix4x4 rotate_x(float degree);
matrix4x4 rotate_y(float degree);
matrix4x4 rotate_z(float degree);
matrix4x4 m_times_n(matrix4x4* m, matrix4x4* n);


void print_matrix(matrix4x4* matrix);

#endif //DONUT_MATRIX_H