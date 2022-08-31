#include <keyboard.h>
#include <keycodes.h>
#include <stdbool.h>
#include <ports.h>
#include <print.h>
#include <isr.h>

char global_key;
char global_scancode;
bool global_capslook;
bool global_shift;

Key get_key() {
    Key key;
    key.key = global_key;
    key.scancode = global_scancode;

    return key;
}

void reset_key() {
    global_key = '\0';
    global_scancode = '\0';
}

char get_char() {
    char key;

    while (global_key <= 0);
    key = global_key;
    global_key = '\0';
    global_scancode = '\0';

    return key;
}

char get_scancode() {
    char code;

    while (global_scancode <= 0);
    code = global_scancode;
    global_key = '\0';
    global_scancode = '\0';

    return code;
}

void keyboard_handler(registers_t* regs) {
    unsigned char scancode = inb(0x60);
    global_scancode = scancode;

    char cscode = scancode_to_char(scancode);

    if (cscode >= '0' && cscode <= '9') {
        if (global_shift == true) {
            char alternative_key = alternative_keys_with_shift(cscode);
            global_key = alternative_key;
        } else {
            global_key = cscode;
        }
    } else if (cscode >= 'a' && cscode <= 'z') {
        if (global_capslook == true || global_shift == true) {
            global_key = to_uppercase(cscode);
        } else {
            global_key = cscode;
        }
    } else if ((scancode == LSHIFT_PRESS || scancode == LSHIFT_REALEASE) || (scancode == RSHIFT_PRESS || scancode == RSHIFT_REALEASE)) {
        if (global_shift == true) {
            global_shift = false;
        } else {
            global_shift = true;
        }
    } else if (scancode == CAPSLOOK) {
        if (global_capslook == true) {
            global_capslook = false;
        } else {
            global_capslook = true;
        }
    } else if (scancode == MINUS_KEY) {
        if (global_shift == true) {
            global_key = '_';
        } else {
            global_key = '-';
        }
    } else if (scancode == EQUALS_KEY) {
        if (global_shift == true) {
            global_key = '+';
        } else {
            global_key = '=';
        }
    } else if (scancode == GRAVE_KEY) {
        if (global_shift == true) {
            global_key = '~';
        } else {
            global_key = '`';
        }
    } else {
        // Support more keys
    }
}

void keyboard_init() {
    global_key = '\0';
    global_scancode = '\0';
    global_capslook = false;
    global_shift = false;

    isr_register_interrupt_handler(IRQ_BASE + 1, keyboard_handler);
}