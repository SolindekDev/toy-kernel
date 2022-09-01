#include <gui.h>
#include <graphics.h>
#include <ports.h>
#include <multiboot.h>
#include <keyboard.h>
#include <keycodes.h>
#include <entry.h>
#include <mouse.h>
#include <cmos.h>
#include <kmath.h>
#include <terminal.h>
#include <print.h>

MULTIBOOT_INFO *mboot_info_cp;
int type_nav = 0;

void draw_nav() {
    draw_rect(0, 0, get_width(), 25, 0xD6D6D6);
    draw_line(0, 25, get_width(), 25, 0xC4C2C2);
    draw_line(0, 24, get_width(), 24, 0xC4C2C2);

    set_background_color(0xD6D6D6);
    set_font_color(0x000000);

    if (type_nav == 1) {
        set_y(5);
        set_x(5);
        printf("Capybaras are cute ^-^");
    } else {
        set_y(5);
        set_x(5);
        printf("root");
    }

    set_x(get_width() / 2 - (6 * 10) / 2);
    printf("HoinOS");

    set_x(get_width() - (18 * 9));
    set_font_color(0x000000);
    set_background_color(0xD6D6D6);
    Date date = get_date_cmos();
    printf("%s%d:%s%d:%s%d %d%d:%s%d:%s%d\n", date.hour <= 9 ? "0" : "",date.hour, date.minut <= 9 ? "0" : "", date.minut, date.second <= 9 ? "0" : "", date.second, date.century, date.year, date.month <= 9 ? "0" : "", date.month, date.day <= 9 ? "0" : "", date.day);
}

void draw_btn(char* label, int x, int y, int width, int height) {
    draw_rect(x, y, width, height, 0xD6D6D6);
    draw_line(x, y, x, y+height, 0xC4C2C2);
    draw_line(x, y, get_width(), y, 0xC4C2C2);
    set_font_color(0x000000);
    set_background_color(0xD6D6D6);
    set_x(width + x);
    // printf("%s", label);
}

void draw_bg() {
    draw_rect(0, 0, get_width(), get_height(), LIGHT_GREEN_COLOR);
}

void loop_(unsigned long addr) {
    mboot_info_cp = (MULTIBOOT_INFO*)addr;
    long frame_count = 0;
    long tick_frame_end = 0;
    while (1) {
        if (get_key().scancode == F1) {
            if (type_nav == 0) {
                type_nav = 1;
            } else {
                type_nav = 0;
            }
        }

        frame_count++;
        if (frame_count > 60) {
            continue;
        }

        clear_back_buffer();
        draw_desktop();
        swap_buffers();
        frame_count = 0;
    }
}

void draw_desktop() {
    // draw_bg();
    draw_nav();
    draw_terminal();
    draw_cursor(get_mouse_x(), get_mouse_y());
}

void draw_cursor(int x, int y) {
    // draw beautiful cursor..
    draw_line(x-6, y, x+6, y, CURSOR_BG_COLOR);
    putpixel(x, y-6, CURSOR_BG_COLOR);
    putpixel(x, y-5, CURSOR_BG_COLOR);
    putpixel(x, y-4, CURSOR_BG_COLOR);
    putpixel(x, y-3, CURSOR_BG_COLOR);
    putpixel(x, y-2, CURSOR_BG_COLOR);
    putpixel(x, y-1, CURSOR_BG_COLOR);
    putpixel(x, y, CURSOR_BG_COLOR);
    putpixel(x, y+1, CURSOR_BG_COLOR);
    putpixel(x, y+2, CURSOR_BG_COLOR);
    putpixel(x, y+3, CURSOR_BG_COLOR);
    putpixel(x, y+4, CURSOR_BG_COLOR);
    putpixel(x, y+5, CURSOR_BG_COLOR);
    putpixel(x, y+6, CURSOR_BG_COLOR);
    // printf(" Cursor position: x: %d, y: %d", x, y);
}