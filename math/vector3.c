#include "vector3.h"
#include <math.h>

vector3_f create_zero_vector(){
    return create_vector3_f(0, 0, 0);
};

vector3_f normalize(vector3_f v){
    return divide(v, getLength(v));
}

float getLength(vector3_f v){
    return sqrt( v.x + v.y + v.z);
}

vector3_f multiply(vector3_f vector, float factor){
    vector3_f result;
    result.x = vector.x * factor;
    result.y = vector.y * factor;
    result.z = vector.z * factor;
}

vector3_f divide(vector3_f vector, float d){
    return multiply(vector, 1/d);
}

vector3_f create_vector3_f(float x, float y, float z){
    vector3_f v;
    v.x = x;
    v.y = y;
    v.z = z;
    return v;
}