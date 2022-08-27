#pragma once

#include <stdint.h>

typedef struct registers
{
   uint32_t ds;                  
   uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax; 
   uint32_t int_no, err_code;   
   uint32_t eip, cs, eflags, useresp, ss;
} registers_t; 

typedef struct registers16 {
    uint16_t di, si, bp, sp, bx, dx, cx, ax;
    uint16_t ds, es, fs, gs, ss, eflags;
} registers16_t;

void isr_handler(registers_t regs);