#include <stdint.h>
#include <time.h>
#include "libattopng.h"

#define W 2048
#define H 1024

#define RGBA(r, g, b, a) ((r) | ((g) << 8) | ((b) << 16) | ((a) << 24))

void rgba_to_bw(uint32_t *bitmap, int width, int height) {
    int row, col;
    uint32_t *pixel = bitmap;
    uint8_t *r, *g, *b;
    uint8_t bw;
    
    for (row = 0; row < height; row++) {
        for (col = 0; col < width; col++) {
            b = (uint8_t*) pixel + 2; 
            g = (uint8_t*) pixel + 1;
            r = (uint8_t*) pixel;
            bw = ((*r) * 0.299) + ((*g) * 0.587) + ((*b) * 0.114);

            *r = *g = *b = bw;

            pixel++;
        }
    }
}

int main() {

    libattopng_t *png = libattopng_new(W, H, PNG_RGBA);
    
    int x, y;
    for (y = 0; y < H; y++) {
        for (x = 0; x < W; x++) {
            libattopng_set_pixel(png, x, y, RGBA(x & 255, y & 255, 128, (255 - ((x / 2) & 255))));
        }
    }
    libattopng_save(png, "v2_rgba.png");
    rgba_to_bw((uint32_t *)png->data, W, H);
    libattopng_save(png, "v2_rgba_to_bw.png");
        
    int i, loop = 100;
    clock_t start = 0;
    clock_t end = 0;

    start = clock();
    for (i = 0; i < loop; i++) {
        rgba_to_bw((uint32_t *)png->data, W, H);
    }
    end = clock();
    printf("Execution time of rgbaToBw() : %lf \n", ((double) (end - start)) / CLOCKS_PER_SEC / loop);

    libattopng_destroy(png);
    
    return 0;
}
