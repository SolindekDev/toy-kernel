#include <multiboot.h>
#include <graphics.h>
#include <utils.h>

int bpp;
int pitch;
int width;
int height;
unsigned char* buffer; 
unsigned char back_buffer[3691520];

uint64_t get_buffer_addr() {
    return (uint64_t)&buffer;
}

int get_pitch() {
    return pitch;
}

int get_width() {
    return width;
}

int get_height() {
    return height;
}

int get_bpp() {
    return bpp;
}

void init_graphics(MULTIBOOT_INFO* mboot_info) {
    pitch = mboot_info->framebuffer_pitch;
    width = mboot_info->framebuffer_width;
    height = mboot_info->framebuffer_height;
    bpp = mboot_info->framebuffer_bpp;
    buffer = (unsigned char*)mboot_info->framebuffer_addr;
}

void putpixel(int x, int y, int color) {
    unsigned where = x * 4 + y * pitch;
    back_buffer[where] = color & 255;
    back_buffer[where + 1] = (color >> 8) & 255;
    back_buffer[where + 2] = (color >> 16) & 255;
}

unsigned long rgb_to_hex(int r, int g, int b) {
    return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

void draw_rect(int x, int y, int width, int height, int color) {
    for (int rx = 0; rx < width; rx++) {
        for (int ry = 0; ry < height; ry++) {
            unsigned where = (rx + x) * 4 + (ry + y) * pitch;
            back_buffer[where] = color & 255;
            back_buffer[where + 1] = (color >> 8) & 255;
            back_buffer[where + 2] = (color >> 16) & 255;
        }
    }
}

// void draw_triangle(int x1, int y1, int x2, int y2, int x3, int y3, int color) {
    
// }

void clear_back_buffer() {
    memset(back_buffer, 0, get_width() * 4 + get_height() * get_pitch());
}

void swap_buffers() {
    memcopy(buffer, back_buffer, get_width() * 4 + get_height() * get_pitch());
}

void draw_line(int x1, int y1, int x2, int y2, int color) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int d = 2 * dy - dx;
    int y = y1;

    for (int x = x1; x <= x2; x++) {
        putpixel(x, y, color);
        if (d > 0) {
            y = y + 1;
            d = d - 2 * dx;
        }
        d = d + 2 * dy;
    }
}