#pragma once

#include <multiboot.h>

void vga_init(MULTIBOOT_INFO* mb_info);
void putchar(char c);
void printf(const char* str, ...);
void vga_disable_cursor();
void vga_debug();