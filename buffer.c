#include <malloc.h>
#include <string.h>
#include "buffer.h"

#include <stdio.h>

#include "math/vector2.h"

z_buffer initialize_zBuffer(vector2_int dimensions) {
    z_buffer buffer;

    buffer.dimensions = dimensions;

    int height = dimensions.x;
    int width = dimensions.y;

    buffer.buffer = (float **) malloc(height * sizeof(float *));;

    for (int i = 0; i < height; ++i) {
        buffer.buffer[i] = (float *) malloc(width * sizeof(float));
        if (!buffer.buffer[i]) {
            printf("Error allocating memory for buffer\n");
            exit(1);
        }
        1
        memset(buffer.buffer[i], 0, width * sizeof(float));
    }

    return buffer;
}

frame_buffer initialize_frameBuffer(vector2_int dimensions) {
    frame_buffer buffer;
    buffer.dimensions = dimensions;

    int height = dimensions.x;
    int width = dimensions.y;

    buffer.buffer = (char **) malloc(height * sizeof(char *));;

    for (int i = 0; i < height; ++i) {
        buffer.buffer[i] = (char *) malloc(width * sizeof(char));
        if (!buffer.buffer[i]) {
            printf("Error allocating memory for buffer\n");
            exit(1);
        }
        memset(buffer.buffer[i], ' ', width * sizeof(char));
    }

    return buffer;
}

void reset_zBuffer(z_buffer *zBuffer, float value) {
    for (int i = 0; i < zBuffer->dimensions.x; ++i) {
        memset(zBuffer->buffer[i], value, zBuffer->dimensions.x * sizeof(float));
    }
}

void reset_frameBuffer(frame_buffer *frameBuffer) {
    for (int i = 0; i < frameBuffer->dimensions.x; ++i) {
        memset(frameBuffer->buffer[i], ' ', frameBuffer->dimensions.y * sizeof(char));
    }
}

void print_frameBuffer(frame_buffer *frameBuffer) {
    for (int i = 0; i < frameBuffer->dimensions.x; ++i) {
        for (int j = 0; j < frameBuffer->dimensions.y; ++j) {
            putchar(frameBuffer->buffer[i][j]);
        }
    }
}
