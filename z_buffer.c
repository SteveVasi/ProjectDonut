//
// Created by stefan on 09.08.23.
//

#include <malloc.h>
#include <string.h>
#include "z_buffer.h"

z_buffer initialize_buffer(int width, int height){
    z_buffer buffer;
  buffer.height = height;
  buffer.width = width;

  buffer.buffer = (float **)  malloc(height * sizeof(float *));;

    for (int i = 0; i < height; ++i) {
        buffer.buffer[i] = (float *) malloc(width * sizeof (float ));
        memset(buffer.buffer[i], 0, width * sizeof (float ));
    }

    return buffer;
}