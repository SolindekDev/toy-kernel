#include <graphics.h>
#include <print.h>
#include <utils.h>
#include <isr.h>

ISR g_interrupt_handlers[NO_INTERRUPT_HANDLERS];

char *exception_messages[32] = {
   "Division By Zero",
   "Debug",
   "Non Maskable Interrupt",
   "Breakpoint",
   "Overflow",
   "BOUND Range Exceeded",
   "Invalid Opcode",
   "Device Not Available (No Math Coprocessor)",
   "Double Fault",
   "Coprocessor Segment Overrun",
   "Invalid TSS",
   "Segment Not Present",
   "Stack-Segment Fault",
   "General Protection",
   "Page Fault",
   "Unknown Interrupt (intel reserved)",
   "x87 FPU Floating-Point Error (Math Fault)",
   "Alignment Check",
   "Machine Check",
   "SIMD Floating-Point Exception",
   "Virtualization Exception",
   "Reserved",
   "Reserved",
   "Reserved",
   "Reserved",
   "Reserved",
   "Reserved",
   "Reserved",
   "Reserved",
   "Reserved",
   "Reserved",
   "Reserved"
};

void isr_register_interrupt_handler(int num, ISR handler) {
   // printf("IRQ %d registered\n", num);
   if (num < NO_INTERRUPT_HANDLERS)
      g_interrupt_handlers[num] = handler;
}

void isr_end_interrupt(int num) {
   pic8259_eoi((uint8_t)num);
}

void isr_irq_handler(registers_t *reg) {
   if (g_interrupt_handlers[reg->int_no] != NULL) {
      ISR handler = g_interrupt_handlers[reg->int_no];
      handler(reg);
   }
   pic8259_eoi((uint8_t)reg->int_no);
}

static void print_registers(registers_t *reg) {
   printf("REGISTERS:\n");
   printf("err_code=%d\n", reg->err_code);
   printf("eax=0x%x, ebx=0x%x, ecx=0x%x, edx=0x%x\n", reg->eax, reg->ebx, reg->ecx, reg->edx);
   printf("edi=0x%x, esi=0x%x, ebp=0x%x, esp=0x%x\n", reg->edi, reg->esi, reg->ebp, reg->esp);
   printf("eip=0x%x, cs=0x%x, ss=0x%x, eflags=0x%x, useresp=0x%x\n", reg->eip, reg->ss, reg->eflags, reg->useresp);
}

void isr_exception_handler(registers_t reg) {
   if (reg.int_no < 32) {
         printf("[");
         set_font_color(RED_COLOR);
         printf("ERROR");
         set_font_color(WHITE_COLOR);
         printf("] %s\n", exception_messages[reg.int_no]);
         printf("[");
         set_font_color(RED_COLOR);
         printf("ERROR");
         set_font_color(WHITE_COLOR);
         printf("] Halting system work\n");
      for (;;) {
         asm("hlt");
      }
   }
   if (g_interrupt_handlers[reg.int_no] != NULL) {
      ISR handler = g_interrupt_handlers[reg.int_no];
      handler(&reg);
   }
}

// void isr_handler(registers_t regs) {
//    set_font_color(RED_COLOR);
//    printf("Received interrupt:");
//    set_font_color(WHITE_COLOR);
//    printf(" 0x%x\n", regs.int_no);
// } 