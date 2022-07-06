
#include <stdlib.h>
#include "matrix.h"

int main() {

    matrix4x4 rotation = create_identity();
    rotate_x(&rotation, 45.0f);
    //printf()

    print_matrix(&rotation);

    return 0;
}
