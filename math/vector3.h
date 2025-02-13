//
// Created by stefa on 02/09/2024.
//

#ifndef VECTOR3_H
#define VECTOR3_H

typedef struct vector3_f_t {
    float x;
    float y;
    float z;
} vector3_f;

typedef struct vector3_int_t {
    int x;
    int y;
    int z;
} vector3_int;

vector3_f create_zero_vector();
vector3_f normalize(vector3_f v);
vector3_f create_vector3_f(float x, float y, float z);

#endif //VECTOR3_H
