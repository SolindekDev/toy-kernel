#include <bios32.h>
#include <vga.h>
#include <gdt.h>
#include <isr.h>
#include <utils.h>
#include <kstring.h>

idt_ptr_t g_real_mode_gdt;
idt_ptr_t g_real_mode_idt;

extern gdt_entry_t gdt_entries[5];

void (*exec_bios32_function)() = (void *)0x7c00;

void bios32_init() {
    gdt_set_gate(6, 0, 0xffffffff, 0x9A, 0x0f);
    gdt_set_gate(7, 0, 0xffffffff, 0x92, 0x0f);
    g_real_mode_gdt.base = (uint32_t)gdt_entries;
    g_real_mode_gdt.limit = sizeof(gdt_entries) - 1;
    g_real_mode_idt.base = 0;
    g_real_mode_idt.limit = 0x3ff;
}

void *memcpy(void *dst, const void *src, uint32_t n) {
    char *ret = dst;
    char *p = dst;
    const char *q = src;
    while (n--)
        *p++ = *q++;
    return ret;
}

void bios32_service(uint8_t interrupt, registers16_t *in, registers16_t *out) {
    void *new_code_base = (void *)0x7c00;

    memcpy(&bios32_gdt_entries, gdt_entries, sizeof(gdt_entries));
    g_real_mode_gdt.base = (uint32_t)REBASE_ADDRESS((&bios32_gdt_entries));
    memcpy(&bios32_gdt_ptr, &g_real_mode_gdt, sizeof(idt_ptr_t));
    memcpy(&bios32_idt_ptr, &g_real_mode_idt, sizeof(idt_ptr_t));
    memcpy(&bios32_in_reg16_ptr, in, sizeof(registers16_t));
    void *in_reg16_address = REBASE_ADDRESS(&bios32_in_reg16_ptr);
    memcpy(&bios32_int_number_ptr, &interrupt, sizeof(uint8_t));

    uint32_t size = (uint32_t)BIOS32_END - (uint32_t)BIOS32_START;
    memcpy(new_code_base, BIOS32_START, size);
    exec_bios32_function();
    in_reg16_address = REBASE_ADDRESS(&bios32_out_reg16_ptr);
    memcpy(out, in_reg16_address, sizeof(registers16_t));

    init_descriptor_tables();
}