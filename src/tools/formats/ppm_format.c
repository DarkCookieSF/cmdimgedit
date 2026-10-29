#include <stdio.h>
#include <stdlib.h>

// what is a pixel
typedef struct {
    unsigned char r, g, b;
} Pixel;

// what is a image
typedef struct {
    int width;
    int height;
    Pixel *data;
} Image;

// read the format
Image read_ppm (const char *filename) {
    FILE *file_path = file_pathoen(filename, "rb");
    Image img = {0};
    char header[3];
    int max_val;

    if (!file_path) return img;

    // read header
    fscanf(file_path, "%s\n%d %d\n%d\n", header, &img.width, &img.height, &max_val);

    img.data = (Pixel *)malloc(img.width * img.height * sizeof(Pixel));
    fread(img.data, sizeof(Pixel), img.width * img.height, file_path);

    fclose(file_path);
    return img;
}

// write the format
void write_ppm(const char *filename, Image img) {
    FILE *file_path = fopen(filename, "wb");
    fprintf(file_path, "P6\n%d %d\n255\n", img.width, img.height);
    fwrite(img.data, sizeof(Pixel), img.width * img.height, file_path);
    fclose(file_path);
}