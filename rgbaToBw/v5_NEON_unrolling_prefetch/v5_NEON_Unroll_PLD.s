	.arch armv6
	.eabi_attribute 28, 1
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 6
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.file	"v5_NEON_Unroll_PLD.c"
	.text
	.align	2
	.global	rgba_to_bw
	.arch armv6
	.syntax unified
	.arm
	.fpu neon
	.type	rgba_to_bw, %function
rgba_to_bw:
	@ args = 0, pretend = 0, frame = 304
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	sub	sp, sp, #308
	str	r0, [fp, #-296]
	str	r1, [fp, #-300]
	str	r2, [fp, #-304]
	ldr	r3, [fp, #-296]
	str	r3, [fp, #-8]
	mov	r3, #77
	strb	r3, [fp, #-17]
	mvn	r3, #104
	strb	r3, [fp, #-18]
	mov	r3, #28
	strb	r3, [fp, #-19]
	ldrb	r3, [fp, #-17]
	strb	r3, [fp, #-88]
	ldrsb	r3, [fp, #-88]
	vdup.8	d16, r3
	vstr	d16, [fp, #-28]
	ldrb	r3, [fp, #-18]
	strb	r3, [fp, #-87]
	ldrsb	r3, [fp, #-87]
	vdup.8	d16, r3
	vstr	d16, [fp, #-36]
	ldrb	r3, [fp, #-19]
	strb	r3, [fp, #-86]
	ldrsb	r3, [fp, #-86]
	vdup.8	d16, r3
	vstr	d16, [fp, #-44]
	ldr	r3, [fp, #-300]
	ldr	r2, [fp, #-304]
	mul	r3, r2, r3
	str	r3, [fp, #-48]
	ldr	r3, [fp, #-48]
	asr	r3, r3, #3
	str	r3, [fp, #-52]
	mov	r3, #0
	str	r3, [fp, #-12]
	b	.L5
.L11:
	ldr	r3, [fp, #-8]
	str	r3, [fp, #-192]
	ldr	r3, [fp, #-192]
	vld4.8	{d16-d19}, [r3]
	sub	r3, fp, #4
	sub	r3, r3, #224
	vst1.64	{d16-d19}, [r3:64]
	sub	r3, fp, #4
	sub	r3, r3, #224
	vld1.64	{d16-d19}, [r3:64]
	sub	r3, fp, #4
	sub	r3, r3, #288
	vst1.64	{d16-d19}, [r3:64]
	sub	r3, fp, #292
	pld	[r3]
	sub	r3, fp, #292
	add	r3, r3, #8
	pld	[r3]
	sub	r3, fp, #292
	add	r3, r3, #16
	pld	[r3]
	sub	r3, fp, #4
	sub	r3, r3, #288
	vldr	d16, [r3, #16]
	vstr	d16, [fp, #-180]
	vldr	d16, [fp, #-44]
	vstr	d16, [fp, #-188]
	vldr	d16, [fp, #-180]
	vldr	d17, [fp, #-188]
	vmull.u8	q8, d16, d17
	vstr	d16, [fp, #-68]
	vstr	d17, [fp, #-60]
	sub	r3, fp, #4
	sub	r3, r3, #288
	vldr	d18, [r3, #8]
	vldr	d16, [fp, #-68]
	vldr	d17, [fp, #-60]
	vstr	d16, [fp, #-156]
	vstr	d17, [fp, #-148]
	vstr	d18, [fp, #-164]
	vldr	d16, [fp, #-36]
	vstr	d16, [fp, #-172]
	vldr	d16, [fp, #-156]
	vldr	d17, [fp, #-148]
	vldr	d18, [fp, #-164]
	vldr	d19, [fp, #-172]
	vmlal.u8	q8, d18, d19
	vstr	d16, [fp, #-68]
	vstr	d17, [fp, #-60]
	sub	r3, fp, #4
	sub	r3, r3, #288
	vldr	d18, [r3]
	vldr	d16, [fp, #-68]
	vldr	d17, [fp, #-60]
	vstr	d16, [fp, #-124]
	vstr	d17, [fp, #-116]
	vstr	d18, [fp, #-132]
	vldr	d16, [fp, #-28]
	vstr	d16, [fp, #-140]
	vldr	d16, [fp, #-124]
	vldr	d17, [fp, #-116]
	vldr	d18, [fp, #-132]
	vldr	d19, [fp, #-140]
	vmlal.u8	q8, d18, d19
	vstr	d16, [fp, #-68]
	vstr	d17, [fp, #-60]
	vldr	d16, [fp, #-68]
	vldr	d17, [fp, #-60]
	vstr	d16, [fp, #-108]
	vstr	d17, [fp, #-100]
	vldr	d16, [fp, #-108]
	vldr	d17, [fp, #-100]
	vshrn.i16	d16, q8, #8
	sub	r3, fp, #4
	sub	r3, r3, #288
	vstr	d16, [r3]
	sub	r3, fp, #4
	sub	r3, r3, #288
	vldr	d16, [r3]
	sub	r3, fp, #4
	sub	r3, r3, #288
	vstr	d16, [r3, #8]
	sub	r3, fp, #4
	sub	r3, r3, #288
	vldr	d16, [r3, #8]
	sub	r3, fp, #4
	sub	r3, r3, #288
	vstr	d16, [r3, #16]
	ldr	r3, [fp, #-8]
	str	r3, [fp, #-92]
	sub	r3, fp, #4
	sub	r3, r3, #256
	sub	r2, fp, #4
	sub	r2, r2, #288
	vld1.64	{d16-d19}, [r2:64]
	vst1.64	{d16-d19}, [r3:64]
	sub	r3, fp, #4
	sub	r3, r3, #224
	sub	r2, fp, #4
	sub	r2, r2, #256
	vld1.64	{d16-d19}, [r2:64]
	vst1.64	{d16-d19}, [r3:64]
	sub	r3, fp, #4
	sub	r3, r3, #224
	vld1.64	{d16-d19}, [r3:64]
	ldr	r3, [fp, #-92]
	vst4.8	{d16-d19}, [r3]
	ldr	r3, [fp, #-8]
	add	r3, r3, #32
	str	r3, [fp, #-8]
	ldr	r3, [fp, #-12]
	add	r3, r3, #1
	str	r3, [fp, #-12]
.L5:
	ldr	r2, [fp, #-12]
	ldr	r3, [fp, #-52]
	cmp	r2, r3
	blt	.L11
	ldr	r3, [fp, #-48]
	and	r3, r3, #7
	str	r3, [fp, #-72]
	mov	r3, #0
	str	r3, [fp, #-16]
	b	.L12
.L13:
	ldr	r3, [fp, #-8]
	add	r3, r3, #2
	str	r3, [fp, #-76]
	ldr	r3, [fp, #-8]
	add	r3, r3, #1
	str	r3, [fp, #-80]
	ldr	r3, [fp, #-8]
	str	r3, [fp, #-84]
	ldr	r3, [fp, #-76]
	ldrb	r3, [r3]	@ zero_extendqisi2
	mov	r2, r3
	ldrb	r3, [fp, #-17]	@ zero_extendqisi2
	mul	r2, r3, r2
	ldr	r3, [fp, #-80]
	ldrb	r3, [r3]	@ zero_extendqisi2
	mov	r1, r3
	ldrb	r3, [fp, #-18]	@ zero_extendqisi2
	mul	r3, r3, r1
	add	r2, r2, r3
	ldr	r3, [fp, #-84]
	ldrb	r3, [r3]	@ zero_extendqisi2
	mov	r1, r3
	ldrb	r3, [fp, #-19]	@ zero_extendqisi2
	mul	r3, r3, r1
	add	r3, r2, r3
	asr	r3, r3, #8
	strb	r3, [fp, #-85]
	ldr	r3, [fp, #-84]
	ldrb	r2, [fp, #-85]
	strb	r2, [r3]
	ldr	r3, [fp, #-84]
	ldrb	r2, [r3]	@ zero_extendqisi2
	ldr	r3, [fp, #-80]
	strb	r2, [r3]
	ldr	r3, [fp, #-80]
	ldrb	r2, [r3]	@ zero_extendqisi2
	ldr	r3, [fp, #-76]
	strb	r2, [r3]
	ldr	r3, [fp, #-8]
	add	r3, r3, #4
	str	r3, [fp, #-8]
	ldr	r3, [fp, #-16]
	add	r3, r3, #1
	str	r3, [fp, #-16]
.L12:
	ldr	r2, [fp, #-16]
	ldr	r3, [fp, #-72]
	cmp	r2, r3
	blt	.L13
	nop
	add	sp, fp, #0
	@ sp needed
	ldr	fp, [sp], #4
	bx	lr
	.size	rgba_to_bw, .-rgba_to_bw
	.section	.rodata
	.align	2
.LC0:
	.ascii	"v5_rgba.png\000"
	.align	2
.LC1:
	.ascii	"v5_rgba_to_bw.png\000"
	.align	2
.LC2:
	.ascii	"Execution time of rgbaToBw() : %lf \012\000"
	.text
	.align	2
	.global	main
	.syntax unified
	.arm
	.fpu neon
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 32
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #32
	mov	r2, #6
	mov	r1, #1024
	mov	r0, #2048
	bl	libattopng_new
	str	r0, [fp, #-20]
	mov	r3, #0
	str	r3, [fp, #-12]
	b	.L15
.L18:
	mov	r3, #0
	str	r3, [fp, #-8]
	b	.L16
.L17:
	ldr	r0, [fp, #-8]
	ldr	ip, [fp, #-12]
	ldr	r3, [fp, #-8]
	uxtb	r2, r3
	ldr	r3, [fp, #-12]
	lsl	r3, r3, #8
	uxth	r3, r3
	orr	r3, r2, r3
	orr	r2, r3, #8388608
	ldr	r3, [fp, #-8]
	lsr	r1, r3, #31
	add	r3, r1, r3
	asr	r3, r3, #1
	mvn	r3, r3
	lsl	r3, r3, #24
	orr	r3, r2, r3
	mov	r2, ip
	mov	r1, r0
	ldr	r0, [fp, #-20]
	bl	libattopng_set_pixel
	ldr	r3, [fp, #-8]
	add	r3, r3, #1
	str	r3, [fp, #-8]
.L16:
	ldr	r3, [fp, #-8]
	cmp	r3, #2048
	blt	.L17
	ldr	r3, [fp, #-12]
	add	r3, r3, #1
	str	r3, [fp, #-12]
.L15:
	ldr	r3, [fp, #-12]
	cmp	r3, #1024
	blt	.L18
	ldr	r1, .L22+8
	ldr	r0, [fp, #-20]
	bl	libattopng_save
	ldr	r3, [fp, #-20]
	ldr	r3, [r3, #8]
	mov	r2, #1024
	mov	r1, #2048
	mov	r0, r3
	bl	rgba_to_bw
	ldr	r1, .L22+12
	ldr	r0, [fp, #-20]
	bl	libattopng_save
	mov	r3, #100
	str	r3, [fp, #-24]
	mov	r3, #0
	str	r3, [fp, #-28]
	mov	r3, #0
	str	r3, [fp, #-32]
	bl	clock
	str	r0, [fp, #-28]
	mov	r3, #0
	str	r3, [fp, #-16]
	b	.L19
.L20:
	ldr	r3, [fp, #-20]
	ldr	r3, [r3, #8]
	mov	r2, #1024
	mov	r1, #2048
	mov	r0, r3
	bl	rgba_to_bw
	ldr	r3, [fp, #-16]
	add	r3, r3, #1
	str	r3, [fp, #-16]
.L19:
	ldr	r2, [fp, #-16]
	ldr	r3, [fp, #-24]
	cmp	r2, r3
	blt	.L20
	bl	clock
	str	r0, [fp, #-32]
	ldr	r2, [fp, #-32]
	ldr	r3, [fp, #-28]
	sub	r3, r2, r3
	vmov	s15, r3	@ int
	vcvt.f64.s32	d16, s15
	vldr.64	d18, .L22
	vdiv.f64	d17, d16, d18
	ldr	r3, [fp, #-24]
	vmov	s15, r3	@ int
	vcvt.f64.s32	d16, s15
	vdiv.f64	d18, d17, d16
	vmov	r2, r3, d18
	ldr	r0, .L22+16
	bl	printf
	ldr	r0, [fp, #-20]
	bl	libattopng_destroy
	mov	r3, #0
	mov	r0, r3
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, pc}
.L23:
	.align	3
.L22:
	.word	0
	.word	1093567616
	.word	.LC0
	.word	.LC1
	.word	.LC2
	.size	main, .-main
	.ident	"GCC: (Raspbian 8.3.0-6+rpi1) 8.3.0"
	.section	.note.GNU-stack,"",%progbits
