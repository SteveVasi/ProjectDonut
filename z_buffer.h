//
// Created by stefan on 09.08.23.
//

#ifndef DONUT_Z_BUFFER_H
#define DONUT_Z_BUFFER_H

typedef struct z_buffer_t {
    int width;
    int height;
    float **buffer;
} z_buffer;

z_buffer initialize_buffer(int width, int height);


#endif //DONUT_Z_BUFFER_H
