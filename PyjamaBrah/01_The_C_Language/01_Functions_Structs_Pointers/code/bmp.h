#include <stdio.h>
#include <string.h>

#define SQUARE_SIZE 24 // 24 pixels x 24 pixles

typedef struct { // define a new type named bmp_header
    struct {
        char signature[2];      // 2 character signature "BM" to identify the file as BMP
        unsigned int file_size; // size of the BMP file in bytes
        unsigned int reserved;
        unsigned int data_offset;
    } __attribute__((packed)) header; // __attribute__((packed)) prevents the compiler from adding padding between struct members
    struct {
        unsigned int dib_size;
        signed   int width;
        signed   int height;
        unsigned short num_planes;
        unsigned short bpp;
        unsigned int compression;
        unsigned int image_size;
        signed   int x_ppm;
        signed   int y_ppm;
        unsigned int num_colors;
        unsigned int important_colors;
    } __attribute__((packed)) dib_header;
    
} __attribute__((packed)) bmp_header; // the outer __attribute__((packed)) applies to the whole bmp_header struct

typedef struct {
    /* Nothing */
} __attribute__((packed)) color_palette;

typedef struct {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} __attribute__((packed)) pixel;

typedef struct {
    bmp_header file_header;
    color_palette palette;
    pixel pixel_data[SQUARE_SIZE][SQUARE_SIZE];
} __attribute__((packed)) image;