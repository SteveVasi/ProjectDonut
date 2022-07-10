
#include <stdlib.h>
#include "matrix.h"

int main() {

    matrix4x4 id = create_identity();
    print_matrix(&id);
    matrix4x4 r45 = rotate_x(45.0f);
    id = m_times_n(&id, &r45);

    print_matrix(&id);

    return 0;
}
