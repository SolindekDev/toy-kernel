#pragma once

#include <isr.h>

int get_mouse_x();
int get_mouse_y();
void mouse_wait(unsigned char type);
void mouse_write(unsigned char write);
unsigned char mouse_read();
void mouse_handler(registers_t regs);
void mouse_init();