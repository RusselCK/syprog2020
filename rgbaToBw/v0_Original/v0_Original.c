#include <stdint.h>
#include "libattopng.h"
#include <time.h>

#define W 2048
#define H 1024

#define RGBA(r, g, b, a) ((r) | ((g) << 8) | ((b) << 16) | ((a) << 24))

void rgba_to_bw(uint32_t *bitmap, int width, int height) {
    int row, col;
    uint32_t pixel, r, g, b, a, bw;
    
    for (row = 0; row < height; row++) {
        for (col = 0; col < width; col++) {
            pixel = bitmap[col + row * width];
            
            a = (pixel >> 24) & 0xff;
            b = (pixel >> 16) & 0xff;
            g = (pixel >> 8) & 0xff;
            r = pixel & 0xff;
            bw = (uint32_t) (r * 0.299 + g * 0.587 + b * 0.114);
            
            bitmap[col + row * width] = (a << 24) + (bw << 16) + (bw << 8) + (bw);
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
    libattopng_save(png, "v0_rgba.png");
    rgba_to_bw((uint32_t *)png->data, W, H);
    libattopng_save(png, "v0_rgba_to_bw.png");
    
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
