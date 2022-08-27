#pragma once

#include <isr.h>
#include <stdint.h>

extern void BIOS32_START();
extern void BIOS32_END();
extern void *bios32_gdt_ptr;
extern void *bios32_gdt_entries;
extern void *bios32_idt_ptr;
extern void *bios32_in_reg16_ptr;
extern void *bios32_out_reg16_ptr;
extern void *bios32_int_number_ptr;

#define REBASE_ADDRESS(x)  (void*)(0x7c00 + (void*)x - (uint32_t)BIOS32_START)

void bios32_init();
void bios32_service(uint8_t int_num, registers16_t * in_reg, registers16_t * out_reg);