#include <stdio.h>
#include <stdlib.h>

#include <formats/ppm_format.c>

void invert_colors(Image img) {
    int total_pixels = img.width * img.height;
    for (int i = 0; i < total_pixels; i++) {
        img.data[i].r = 255 - img.data[i].r;
        img.data[i].g = 255 - img.data[i].g;
        img.data[i].b = 255 - img.data[i].b;
    }
}