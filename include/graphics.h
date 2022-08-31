#pragma once

#include <multiboot.h>

/* Pallete of colors */
#define BLACK_COLOR           0x000000
#define BLUE_COLOR            0x0000FF
#define GREEN_COLOR           0x00FF00
#define CYAN_COLOR            0x00FFFF
#define RED_COLOR             0xFF0000
#define MAGENTA_COLOR         0xDF00FF
#define BROWN_COLOR           0x664228
#define LIGHT_GREY_COLOR      0xD3D3D3
#define DARK_GREY_COLOR       0x313537
#define LIGHT_BLUE_COLOR      0x2E88B6
#define LIGHT_GREEN_COLOR     0xB3E6B5
#define LIGHT_CYAN_COLOR      0x80C5C5
#define LIGHT_RED_COLOR       0xFF7F7F
#define LIGHT_MAGENTA_COLOR   0xFF77FF
#define LIGHT_BROWN_COLOR     0xD4B37F
#define WHITE_COLOR           0xFFFFFF

uint64_t get_buffer_addr();
int get_pitch();
int get_width();
int get_height();
int get_bpp();
void init_graphics(MULTIBOOT_INFO* mboot_info);
unsigned long rgb_to_hex(int r, int g, int b);
void putpixel(int x, int y, int color);
void draw_rect(int x, int y, int width, int height, int color);
void draw_triangle(int x1, int y1, int x2, int y2, int x3, int y3, int color);
void draw_line(int x1, int y1, int x2, int y2, int color);
void swap_buffers();
void clear_back_buffer();