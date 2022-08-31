#pragma once

#include <isr.h>

typedef struct Key {
    char key;
    unsigned char scancode;
} Key;

Key get_key();
void reset_key();
char get_char();
char get_scancode();
void keyboard_init();
void keyboard_handler(registers_t* regs);