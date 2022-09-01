#include <ports.h>

unsigned char inb(unsigned short port) {
    unsigned char result;
    __asm__("in %%dx, %%al" : "=a" (result) : "d" (port));
    return result;
}

void outb(unsigned short port, unsigned char data) {
    __asm__("out %%al, %%dx" : : "a" (data), "d" (port));
}

void outw(unsigned short port, unsigned short data) {
    __asm__("out %%ax, %%dx" : : "a" (data), "d" (port));
}

unsigned int inportl(unsigned short port) {
    unsigned int rv;
    asm volatile ("inl %%dx, %%eax" : "=a" (rv) : "dN" (port));
    return rv;
}

void outportl(unsigned short port, unsigned int data) {
    asm volatile ("outl %%eax, %%dx" : : "dN" (port), "a" (data));
}