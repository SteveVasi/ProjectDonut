//
// Created by stefa on 01/09/2024.
//

#ifndef VECTOR2_H
#define VECTOR2_H

typedef struct vector2f_t {
    float x;
    float y;
} vector2_f;

typedef struct vector2int_t {
    int x;
    int y;
} vector2_int;

float dot_product(vector2_f a, vector2_f b);

#endif //VECTOR2_H
