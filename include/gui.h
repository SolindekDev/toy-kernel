#pragma once

#define CURSOR_BG_COLOR      0xF2F2F2

#define NAVBAR_COLOR         0x232B4A

void draw_cursor(int x, int y);
void draw_bg();
void draw_desktop();
void draw_nav();
void loop_(unsigned long addr);
void draw_btn(char* label, int x, int y, int width, int height);
void draw_terminal();