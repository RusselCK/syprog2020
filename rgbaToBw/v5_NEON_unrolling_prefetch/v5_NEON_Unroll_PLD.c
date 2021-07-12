#include <stdint.h>
#include <time.h>
#include <arm_neon.h>
#include "libattopng.h"

#define W 2048
#define H 1024

#define RGBA(r, g, b, a) ((r) | ((g) << 8) | ((b) << 16) | ((a) << 24))

#define BW_SHIFT 8

void rgba_to_bw(uint32_t *bitmap, int width, int height) {

    uint8_t *pixel = (uint8_t*) bitmap;

    const uint8_t R2BW = 77, G2BW = 151, B2BW = 28;
    uint8x8_t _R2BW = vdup_n_u8(R2BW);
    uint8x8_t _G2BW = vdup_n_u8(G2BW);
    uint8x8_t _B2BW = vdup_n_u8(B2BW);
    
    int capacity = width * height;
    int round = capacity >> 3;
#pragma unroll
    for (int i = 0; i < round; ++i) {
		uint8x8x4_t _pixel = vld4_u8(pixel);
			
		uint16x8_t bw16;
		bw16 = vmull_u8(      _pixel.val[2], _B2BW);
		bw16 = vmlal_u8(bw16, _pixel.val[1], _G2BW);
		bw16 = vmlal_u8(bw16, _pixel.val[0], _R2BW);
	
		_pixel.val[0] = vshrn_n_u16(bw16, BW_SHIFT);
		_pixel.val[1] = _pixel.val[0];
		_pixel.val[2] = _pixel.val[1];   
        
		vst4_u8(pixel, _pixel);
	
        pixel += (4*8);
    }
    
    int remain = capacity & 0x7;
    uint8_t *r, *g, *b;
    uint8_t bw;
    for (int i = 0; i < remain; ++i) {
		r = pixel + 2; 
        g = pixel + 1;
        b = pixel;
        bw = ((*r)*R2BW + (*g)*G2BW + (*b)*B2BW) >> BW_SHIFT;

        *r = *g = *b = bw;

        pixel += 4;
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
    libattopng_save(png, "v5_rgba.png");
    rgba_to_bw((uint32_t *)png->data, W, H);
    libattopng_save(png, "v5_rgba_to_bw.png");
	
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
