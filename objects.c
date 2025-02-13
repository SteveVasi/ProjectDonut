#include "objects.h"
#include "math/vector3.h"

vector3_f create_light(vector3_f direction){
    return normalize(direction);
}