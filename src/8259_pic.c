#include <8259_pic.h>
#include <stdint.h>
#include <isr.h>
#include <idt.h>
#include <ports.h>

void pic8259_init() {
    uint8_t a1, a2;

    a1 = inb(PIC1_DATA);
    a2 = inb(PIC2_DATA);

    outb(PIC1_COMMAND, ICW1);
    outb(PIC2_COMMAND, ICW1);

    outb(PIC1_DATA, 0x20);
    outb(PIC2_DATA, 0x28);

    outb(PIC1_DATA, 4);
    outb(PIC2_DATA, 2);

    outb(PIC1_DATA, ICW4_8086);
    outb(PIC2_DATA, ICW4_8086);

    outb(PIC1_DATA, a1);
    outb(PIC2_DATA, a2);
}

void pic8259_eoi(uint8_t irq) {
    if(irq >= 0x28)
        outb(PIC2, PIC_EOI);
    outb(PIC1, PIC_EOI);
}
