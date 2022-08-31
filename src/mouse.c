#include <mouse.h>
#include <ports.h>
#include <utils.h>
#include <isr.h>
#include <graphics.h>

unsigned char mouse_cycle = 0; 
char mouse_byte[3];   
int mouse_x = 0; 
int mouse_y = 0;

int get_mouse_x() {
    return mouse_x;
}

int get_mouse_y() {
    return mouse_y;
}

void mouse_wait(unsigned char type) {
    unsigned int _time_out=100000;
    if (type == 0) {
        while (_time_out--) {
            if ((inb(0x64) & 1) == 1) {
                return;
            }
        }
        return;
    } else {
        while (_time_out--) {
            if ((inb(0x64) & 2) == 0) {
                return;
            }
        }
        return;
    }
}

void mouse_write(unsigned char write) {
    mouse_wait(1);
    outb(0x64, 0xD4);
    mouse_wait(1);
    outb(0x60, write);
}

unsigned char mouse_read() {
    mouse_wait(0);
    return inb(0x60);
}

void mouse_handler(registers_t regs) {
    switch(mouse_cycle) {
        case 0:
            mouse_byte[0] = inb(0x60);
            mouse_cycle++;
            break;
        case 1:
            mouse_byte[1] = inb(0x60);
            mouse_cycle++;
            break;
        case 2:
            mouse_byte[2] = inb(0x60);
            int dx, dy;
            dx = (mouse_byte[0] & (1 << 4)) ? (char)mouse_byte[1] : mouse_byte[1];
            dy = (mouse_byte[0] & (1 << 5)) ? (char)mouse_byte[2] : mouse_byte[2];
            mouse_x += dx;
            mouse_y -= dy;
            mouse_cycle = 0;
            break;
    }
}

void mouse_init() {
    unsigned char status; 

    mouse_x = 640;
    mouse_y = 360;

    mouse_wait(1);
    outb(0x64, 0xA8);
 
    outb(0x60, 0xF2);
    status = mouse_read();
    ok_print("Detect mouse with ID: ");
    printf("0x%x\n", status);

    mouse_wait(1);
    outb(0x64, 0x20);
    mouse_wait(0);
    status=(inb(0x60) | 2);
    mouse_wait(1);
    outb(0x64, 0x60);
    mouse_wait(1);
    outb(0x60, status);
 
    mouse_write(0xF6);
    mouse_read();  
    mouse_write(0xF4);
    mouse_read(); 

    isr_register_interrupt_handler(IRQ_BASE + 12, mouse_handler);
}