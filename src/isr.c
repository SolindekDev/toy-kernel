#include <isr.h>
#include <vga.h>

void isr_handler(registers_t regs) {
   printf("Received interrupt: 0x%x\n", regs.int_no);
} 