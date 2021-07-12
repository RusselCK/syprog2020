#include "libattopng.h"
#include <stdio.h>
#include <arm_neon.h>

#define W 250
#define H 200

#define RGBA(r, g, b, a) ((r) | ((g) << 8) | ((b) << 16) | ((a) << 24))
#define RGB(r, g, b) RGBA(r, g, b, 0xff)

float *rgb_to_gray(const uint8_t *rgb, int w, int h, float *m)
{
    const uint8_t Y_shift = 8;
    const uint8_t R2Y = 77, G2Y = 151, B2Y = 28;
    float *ptr = m;
    int size = w * h;

    int nn = size >> 3;
    int remain = size - (nn << 3);
    uint8x8_t _R2Y = vdup_n_u8(R2Y);
    uint8x8_t _G2Y = vdup_n_u8(G2Y);
    uint8x8_t _B2Y = vdup_n_u8(B2Y);

    for (; nn > 0; nn--) {
		uint8x8x3_t _rgb = vld3_u8(rgb);

		uint16x8_t y16 = vmull_u8(_rgb.val[0], _R2Y);
		y16 = vmlal_u8(y16, _rgb.val[1], _G2Y);
		y16 = vmlal_u8(y16, _rgb.val[2], _B2Y);
		y16 = vshrq_n_u16(y16, Y_shift);
		
		float32x4_t _ylow = vcvtq_f32_u32(vmovl_u16(vget_low_u16(y16)));
		float32x4_t _yhigh = vcvtq_f32_u32(vmovl_u16(vget_high_u16(y16)));

		vst1q_f32(ptr, _ylow);     // OFFSET1 = 0
		vst1q_f32(ptr + 4, _yhigh);    // OFFSET2 = 4

		rgb += 3 * 8, ptr += 8;
		
	}

	for (; remain > 0; remain--) {
	        *ptr = (rgb[0] * R2Y + rgb[1] * G2Y + rgb[2] * B2Y) >> Y_shift;
		rgb += 3, ptr++;
		
	}


	return m;
}


int main(int argc, char *argv[]) {

    // -----------------

    libattopng_t *png = libattopng_new(W, H, PNG_RGB);

    int x, y;
    for (y = 0; y < H; y++) {
        for (x = 0; x < W; x++) {
            libattopng_set_pixel(png, x, y, RGB(x & 255, y & 255, 128));
        }
    }
    libattopng_save(png, "quiz10_rgb.png");
    
    float *m;
    //rgb_to_gray((const uint8_t *)png->data, W, H, m);
    png->data = (char *)m;
    libattopng_save(png, "quiz10_rgb_to_gray.png");
	
	
    libattopng_destroy(png);

    // -----------------
	
	return 0;
}
